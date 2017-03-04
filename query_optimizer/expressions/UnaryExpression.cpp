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

#include "query_optimizer/expressions/UnaryExpression.hpp"

#include <string>
#include <unordered_map>
#include <vector>

#include "expressions/scalar/ScalarUnaryExpression.hpp"
#include "query_optimizer/OptimizerTree.hpp"
#include "query_optimizer/expressions/ExprId.hpp"
#include "query_optimizer/expressions/Expression.hpp"
#include "query_optimizer/expressions/PatternMatcher.hpp"
#include "query_optimizer/expressions/Scalar.hpp"
#include "query_optimizer/expressions/ScalarLiteral.hpp"
#include "types/operations/unary_operations/UnaryOperation.hpp"

#include "glog/logging.h"

namespace quickstep {
namespace optimizer {
namespace expressions {

std::string UnaryExpression::getName() const {
  return op_signature_->getName();
}

ExpressionPtr UnaryExpression::copyWithNewChildren(
    const std::vector<ExpressionPtr> &new_children) const {
  DCHECK_EQ(new_children.size(), children().size());
  DCHECK(SomeScalar::Matches(new_children[0]));
  return UnaryExpression::Create(
      op_signature_,
      operation_,
      std::static_pointer_cast<const Scalar>(new_children[0]),
      static_arguments_,
      static_argument_types_);
}

::quickstep::Scalar* UnaryExpression::concretize(
    const std::unordered_map<ExprId, const CatalogAttribute*> &substitution_map) const {
  return new ::quickstep::ScalarUnaryExpression(
      op_signature_,
      operation_,
      operand_->concretize(substitution_map),
      static_arguments_);
}

void UnaryExpression::getFieldStringItems(
    std::vector<std::string> *inline_field_names,
    std::vector<std::string> *inline_field_values,
    std::vector<std::string> *non_container_child_field_names,
    std::vector<OptimizerTreeBaseNodePtr> *non_container_child_fields,
    std::vector<std::string> *container_child_field_names,
    std::vector<std::vector<OptimizerTreeBaseNodePtr>> *container_child_fields) const {
  inline_field_names->emplace_back("op_signature");
  inline_field_values->emplace_back(op_signature_->toString());

  inline_field_names->emplace_back("result_type");
  inline_field_values->emplace_back(result_type_.getName());

  non_container_child_field_names->emplace_back("operand");
  non_container_child_fields->emplace_back(operand_);

  if (!static_arguments_->empty()) {
    container_child_field_names->emplace_back("static_arguments");
    container_child_fields->emplace_back();
    for (std::size_t i = 0; i < static_arguments_->size(); ++i) {
      container_child_fields->back().emplace_back(
          ScalarLiteral::Create(static_arguments_->at(i),
                                *static_argument_types_->at(i)));
    }
  }
}

}  // namespace expressions
}  // namespace optimizer
}  // namespace quickstep
