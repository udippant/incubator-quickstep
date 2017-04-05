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

#include "query_optimizer/rules/ReuseAggregateExpressions.hpp"

#include <cstddef>
#include <list>
#include <map>
#include <unordered_map>
#include <vector>

#include "expressions/aggregation/AggregateFunction.hpp"
#include "expressions/aggregation/AggregateFunctionFactory.hpp"
#include "expressions/aggregation/AggregationID.hpp"
#include "query_optimizer/OptimizerContext.hpp"
#include "query_optimizer/expressions/AggregateFunction.hpp"
#include "query_optimizer/expressions/Alias.hpp"
#include "query_optimizer/expressions/AttributeReference.hpp"
#include "query_optimizer/expressions/BinaryExpression.hpp"
#include "query_optimizer/expressions/ExpressionType.hpp"
#include "query_optimizer/expressions/ExpressionUtil.hpp"
#include "query_optimizer/expressions/NamedExpression.hpp"
#include "query_optimizer/expressions/Scalar.hpp"
#include "query_optimizer/physical/Aggregate.hpp"
#include "query_optimizer/physical/PatternMatcher.hpp"
#include "query_optimizer/physical/Physical.hpp"
#include "query_optimizer/physical/PhysicalType.hpp"
#include "query_optimizer/physical/Selection.hpp"
#include "query_optimizer/physical/TopLevelPlan.hpp"
#include "types/operations/binary_operations/BinaryOperation.hpp"
#include "types/operations/binary_operations/BinaryOperationFactory.hpp"
#include "types/operations/binary_operations/BinaryOperationID.hpp"
#include "utility/EqualsAnyConstant.hpp"
#include "utility/HashError.hpp"

#include "glog/logging.h"

namespace quickstep {
namespace optimizer {

namespace E = ::quickstep::optimizer::expressions;
namespace P = ::quickstep::optimizer::physical;

void ReuseAggregateExpressions::init(const P::PhysicalPtr &input) {
  DCHECK(input->getPhysicalType() == P::PhysicalType::kTopLevelPlan);

  const P::TopLevelPlanPtr top_level_plan =
     std::static_pointer_cast<const P::TopLevelPlan>(input);
  cost_model_.reset(
      new cost::StarSchemaSimpleCostModel(top_level_plan->shared_subplans()));
}

P::PhysicalPtr ReuseAggregateExpressions::applyToNode(
    const P::PhysicalPtr &input) {
  P::AggregatePtr aggregate;
  if (!P::SomeAggregate::MatchesWithConditionalCast(input, &aggregate)) {
    return input;
  }

  const std::vector<E::AliasPtr> &agg_exprs = aggregate->aggregate_expressions();

  std::unordered_map<E::ScalarPtr,
                     std::map<AggregationID, std::vector<std::size_t>>,
                     ScalarHash, ScalarEqual> agg_expr_info;

  std::list<std::size_t> count_star_info;

  for (std::size_t i = 0; i < agg_exprs.size(); ++i) {
    DCHECK(agg_exprs[i]->expression()->getExpressionType()
               == E::ExpressionType::kAggregateFunction);
    const E::AggregateFunctionPtr agg_expr =
        std::static_pointer_cast<const E::AggregateFunction>(
            agg_exprs[i]->expression());

    // Skip DISTINCT aggregations.
    if (agg_expr->is_distinct()) {
      continue;
    }

    const AggregationID agg_id = agg_expr->getAggregate().getAggregationID();
    const std::vector<E::ScalarPtr> &arguments = agg_expr->getArguments();

    // Currently we only consider aggregate functions with 0 or 1 argument.
    if (agg_id == AggregationID::kCount) {
      if (arguments.empty()) {
        count_star_info.emplace_front(i);
        continue;
      } else if (!arguments.front()->getValueType().isNullable()) {
        count_star_info.emplace_back(i);
        continue;
      }
    }
    if (arguments.size() == 1) {
      try {
        agg_expr_info[arguments.front()][agg_id].emplace_back(i);
      } catch (const HashNotSupported &e) {
        continue;
      }
    }
  }

  std::vector<std::unique_ptr<AggregateReference>> agg_refs(agg_exprs.size());

  constexpr std::size_t kInvalidRef = static_cast<std::size_t>(-1);
  std::size_t count_star_ref;

  if (count_star_info.empty()) {
    count_star_ref = kInvalidRef;
  } else {
    auto it = count_star_info.begin();
    count_star_ref = *it;

    for (++it; it != count_star_info.end(); ++it) {
      agg_refs[*it].reset(new AggregateReference(count_star_ref));
    }
  }

  for (const auto &it : agg_expr_info) {
    const auto &ref_map = it.second;

    // First, check whether AVG can be reduced to SUM/COUNT.
    bool is_avg_processed = false;

    const auto avg_it = ref_map.find(AggregationID::kAvg);
    if (avg_it != ref_map.end()) {
      std::size_t count_ref = kInvalidRef;

      if (it.first->getValueType().isNullable()) {
        const auto count_it = ref_map.find(AggregationID::kCount);
        if (count_it != ref_map.end()) {
          DCHECK(!count_it->second.empty());
          count_ref = count_it->second.front();
        }
      } else {
        count_ref = count_star_ref;
      }

      if (count_ref != kInvalidRef) {
        const auto sum_it = ref_map.find(AggregationID::kSum);
        const std::size_t sum_ref =
            sum_it == ref_map.end() ? kInvalidRef : sum_it->second.front();

        for (const std::size_t idx : avg_it->second) {
          agg_refs[idx].reset(new AggregateReference(sum_ref, count_ref));
        }
        is_avg_processed = true;
      }
    }

    // Then, eliminate duplicate aggregate expressions.
    for (const auto &ref_it : ref_map) {
      if (ref_it.first == AggregationID::kAvg && is_avg_processed) {
        continue;
      }

      const auto &indices = ref_it.second;
      DCHECK(!indices.empty());
      const std::size_t ref = indices.front();
      for (std::size_t i = 1; i < indices.size(); ++i) {
        agg_refs[indices[i]].reset(new AggregateReference(ref));
      }
    }
  }

  bool need_transform = false;
  for (const auto &agg_ref : agg_refs) {
    if (agg_ref != nullptr) {
      need_transform = true;
      break;
    }
  }

  if (!need_transform) {
    return input;
  }

  const std::vector<E::AttributeReferencePtr> agg_attrs = E::ToRefVector(agg_exprs);

  std::vector<E::AliasPtr> new_agg_exprs;
  std::vector<E::NamedExpressionPtr> new_select_exprs;

  for (const auto &grouping_expr : aggregate->grouping_expressions()) {
    new_select_exprs.emplace_back(E::ToRef(grouping_expr));
  }

  for (std::size_t i = 0; i < agg_refs.size(); ++i) {
    const auto &agg_ref = agg_refs[i];
    const E::AliasPtr &agg_expr = agg_exprs[i];

    if (agg_ref == nullptr) {
      new_agg_exprs.emplace_back(agg_expr);
      new_select_exprs.emplace_back(
          E::AttributeReference::Create(agg_expr->id(),
                                        agg_expr->attribute_name(),
                                        agg_expr->attribute_alias(),
                                        agg_expr->relation_name(),
                                        agg_expr->getValueType(),
                                        E::AttributeReferenceScope::kLocal));
    } else {
      switch (agg_ref->kind) {
        case AggregateReference::kDirect: {
          new_select_exprs.emplace_back(
              E::Alias::Create(agg_expr->id(),
                               agg_attrs[agg_ref->first_ref],
                               agg_expr->attribute_name(),
                               agg_expr->attribute_alias()));
          break;
        }
        case AggregateReference::kAvg: {
          E::AttributeReferencePtr sum_attr;
          if (agg_ref->first_ref == kInvalidRef) {
            const E::AggregateFunctionPtr avg_expr =
                std::static_pointer_cast<const E::AggregateFunction>(agg_expr->expression());

            const AggregateFunction &sum_func =
                AggregateFunctionFactory::Get(AggregationID::kSum);
            const E::AggregateFunctionPtr sum_expr =
                E::AggregateFunction::Create(sum_func,
                                             avg_expr->getArguments(),
                                             avg_expr->is_vector_aggregate(),
                                             avg_expr->is_distinct());
            new_agg_exprs.emplace_back(
                E::Alias::Create(optimizer_context_->nextExprId(),
                                 sum_expr,
                                 agg_expr->attribute_name(),
                                 agg_expr->attribute_alias()));

            sum_attr = E::ToRef(new_agg_exprs.back());
          } else {
            sum_attr = agg_attrs[agg_ref->first_ref];
          }

          const BinaryOperation &divide_op =
              BinaryOperationFactory::GetBinaryOperation(BinaryOperationID::kDivide);
          const E::BinaryExpressionPtr avg_expr =
              E::BinaryExpression::Create(divide_op,
                                          sum_attr,
                                          agg_attrs[agg_ref->second_ref]);
          new_select_exprs.emplace_back(
              E::Alias::Create(agg_expr->id(),
                               avg_expr,
                               agg_expr->attribute_name(),
                               agg_expr->attribute_alias()));
        }
      }
    }
  }

  const P::AggregatePtr new_aggregate =
      P::Aggregate::Create(aggregate->input(),
                           aggregate->grouping_expressions(),
                           new_agg_exprs,
                           aggregate->filter_predicate());

  return P::Selection::Create(new_aggregate, new_select_exprs, nullptr);
}


}  // namespace optimizer
}  // namespace quickstep
