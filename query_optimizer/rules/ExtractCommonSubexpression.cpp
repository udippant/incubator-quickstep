/**
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.
 **/

#include "query_optimizer/rules/ExtractCommonSubexpression.hpp"

#include <memory>
#include <unordered_set>
#include <vector>

#include "query_optimizer/OptimizerContext.hpp"
#include "query_optimizer/expressions/Alias.hpp"
#include "query_optimizer/expressions/CommonSubexpression.hpp"
#include "query_optimizer/expressions/ExpressionType.hpp"
#include "query_optimizer/expressions/NamedExpression.hpp"
#include "query_optimizer/expressions/PatternMatcher.hpp"
#include "query_optimizer/expressions/Scalar.hpp"
#include "query_optimizer/physical/Aggregate.hpp"
#include "query_optimizer/physical/Physical.hpp"
#include "query_optimizer/physical/PhysicalType.hpp"
#include "query_optimizer/physical/Selection.hpp"
#include "utility/HashError.hpp"

#include "glog/logging.h"

namespace quickstep {
namespace optimizer {

namespace E = ::quickstep::optimizer::expressions;
namespace P = ::quickstep::optimizer::physical;

ExtractCommonSubexpression::ExtractCommonSubexpression(
    OptimizerContext *optimizer_context)
    : optimizer_context_(optimizer_context) {
  const std::vector<E::ExpressionType> whitelist = {
      E::ExpressionType::kAlias,
      E::ExpressionType::kAttributeReference,
      E::ExpressionType::kAggregateFunction,
      E::ExpressionType::kBinaryExpression,
      E::ExpressionType::kCast,
      E::ExpressionType::kCommonSubexpression,
      E::ExpressionType::kScalarLiteral,
      E::ExpressionType::kUnaryExpression
  };

  for (const auto &expr_type : whitelist) {
    homogeneous_whitelist_.emplace(static_cast<int>(expr_type));
  }
}

P::PhysicalPtr ExtractCommonSubexpression::apply(const P::PhysicalPtr &input) {
  DCHECK(input->getPhysicalType() == P::PhysicalType::kTopLevelPlan);

  return applyInternal(input);
}

P::PhysicalPtr ExtractCommonSubexpression::applyInternal(
    const P::PhysicalPtr &input) {
  std::vector<P::PhysicalPtr> new_children;
  for (const auto &child : input->children()) {
    new_children.emplace_back(applyInternal(child));
  }

  const P::PhysicalPtr node =
      new_children == input->children()
          ? input
          : input->copyWithNewChildren(new_children);

  switch (node->getPhysicalType()) {
    case P::PhysicalType::kSelection: {
      const P::SelectionPtr selection =
          std::static_pointer_cast<const P::Selection>(node);

      const std::vector<E::NamedExpressionPtr> new_expressions =
          DownCast<E::NamedExpression>(
              transformExpressions(UpCast(selection->project_expressions())));

      if (new_expressions != selection->project_expressions()) {
        return P::Selection::Create(selection->input(),
                                    new_expressions,
                                    selection->filter_predicate());
      }
      break;
    }
    case P::PhysicalType::kAggregate: {
      const P::AggregatePtr aggregate =
          std::static_pointer_cast<const P::Aggregate>(node);
      std::vector<E::ExpressionPtr> expressions =
          UpCast(aggregate->aggregate_expressions());
      for (const auto &expr : aggregate->grouping_expressions()) {
        expressions.emplace_back(expr);
      }

      const std::vector<E::ExpressionPtr> new_expressions =
          transformExpressions(expressions);

      if (new_expressions != expressions) {
        std::vector<E::AliasPtr> new_aggregate_expressions;
        std::vector<E::NamedExpressionPtr> new_grouping_expressions;
        const std::size_t num_aggrs = aggregate->aggregate_expressions().size();

        for (std::size_t i = 0; i < num_aggrs; ++i) {
          DCHECK(E::SomeAlias::Matches(new_expressions[i]));
          new_aggregate_expressions.emplace_back(
              std::static_pointer_cast<const E::Alias>(new_expressions[i]));
        }
        for (std::size_t i = num_aggrs; i < new_expressions.size(); ++i) {
          DCHECK(E::SomeNamedExpression::Matches(new_expressions[i]));
          new_grouping_expressions.emplace_back(
              std::static_pointer_cast<const E::NamedExpression>(new_expressions[i]));
        }
        return P::Aggregate::Create(aggregate->input(),
                                    new_grouping_expressions,
                                    new_aggregate_expressions,
                                    aggregate->filter_predicate());
      }
      break;
    }
    default:
      break;
  }

  return node;
}

std::vector<E::ExpressionPtr> ExtractCommonSubexpression::transformExpressions(
    const std::vector<E::ExpressionPtr> &expressions) {
  ScalarCounter counter;
  ScalarHashable hashable;
  for (const auto &expr : expressions) {
    visitAndCount(expr, &counter, &hashable);
  }

  ScalarMap substitution_map;
  std::vector<E::ExpressionPtr> new_expressions;
  for (const auto &expr : expressions) {
    new_expressions.emplace_back(
        visitAndTransform(expr, 1, counter, hashable, &substitution_map));
  }
  return new_expressions;
}

E::ExpressionPtr ExtractCommonSubexpression::transformExpression(
    const E::ExpressionPtr &expression) {
  return transformExpressions({expression}).front();
}

bool ExtractCommonSubexpression::visitAndCount(
    const E::ExpressionPtr &expression,
    ScalarCounter *counter,
    ScalarHashable *hashable) {
  bool children_hashable = true;

  const auto homogeneous_whitelist_it =
      homogeneous_whitelist_.find(static_cast<int>(expression->getExpressionType()));
  if (homogeneous_whitelist_it != homogeneous_whitelist_.end()) {
    for (const auto &child : expression->children()) {
      children_hashable &= visitAndCount(child, counter, hashable);
    }
  }

  E::ScalarPtr scalar;
  if (children_hashable &&
      E::SomeScalar::MatchesWithConditionalCast(expression, &scalar)) {
    try {
      ++(*counter)[scalar];
    } catch (const HashNotSupported &e) {
      return false;
    }
    hashable->emplace(scalar);
    return true;
  }
  return false;
}

E::ExpressionPtr ExtractCommonSubexpression::visitAndTransform(
    const E::ExpressionPtr &expression,
    const std::size_t max_reference_count,
    const ScalarCounter &counter,
    const ScalarHashable &hashable,
    ScalarMap *substitution_map) {
  // TODO: figure out whether it is beneficial.
  if (expression->getExpressionType() == E::ExpressionType::kScalarLiteral ||
      expression->getExpressionType() == E::ExpressionType::kAttributeReference) {
    return expression;
  }

  E::ScalarPtr scalar;
  const bool is_hashable =
      E::SomeScalar::MatchesWithConditionalCast(expression, &scalar)
          && hashable.find(scalar) != hashable.end();

  std::size_t new_max_reference_count;
  if (is_hashable) {
    // CommonSubexpression node already generated.
    const auto substitution_map_it = substitution_map->find(scalar);
    if (substitution_map_it != substitution_map->end()) {
      return substitution_map_it->second;
    }

    const auto counter_it = counter.find(scalar);
    DCHECK(counter_it != counter.end());
    DCHECK_LE(max_reference_count, counter_it->second);
    new_max_reference_count = counter_it->second;
  } else {
    new_max_reference_count = max_reference_count;
  }

  std::vector<E::ExpressionPtr> new_children;
  const auto homogeneous_whitelist_it =
      homogeneous_whitelist_.find(static_cast<int>(expression->getExpressionType()));
  if (homogeneous_whitelist_it == homogeneous_whitelist_.end()) {
    for (const auto &child : expression->children()) {
      new_children.emplace_back(transformExpression(child));
    }
  } else {
    for (const auto &child : expression->children()) {
      new_children.emplace_back(
          visitAndTransform(child,
                            new_max_reference_count,
                            counter,
                            hashable,
                            substitution_map));
    }
  }

  E::ExpressionPtr output;
  if (new_children == expression->children()) {
    output = expression;
  } else {
    output = std::static_pointer_cast<const E::Scalar>(
        expression->copyWithNewChildren(new_children));
  }

  if (is_hashable && new_max_reference_count > max_reference_count) {
    DCHECK(E::SomeScalar::Matches(output));
    const E::CommonSubexpressionPtr common_subexpression =
        E::CommonSubexpression::Create(
            optimizer_context_->nextExprId(),
            std::static_pointer_cast<const E::Scalar>(output));
    substitution_map->emplace(scalar, common_subexpression);
    output = common_subexpression;
  }

  return output;
}

}  // namespace optimizer
}  // namespace quickstep
