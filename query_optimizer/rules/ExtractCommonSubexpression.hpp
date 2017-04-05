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

#ifndef QUICKSTEP_QUERY_OPTIMIZER_RULES_EXTRACT_COMMON_SUBEXPRESSION_HPP_
#define QUICKSTEP_QUERY_OPTIMIZER_RULES_EXTRACT_COMMON_SUBEXPRESSION_HPP_

#include <memory>
#include <string>
#include <unordered_map>
#include <unordered_set>

#include "query_optimizer/expressions/CommonSubexpression.hpp"
#include "query_optimizer/expressions/Expression.hpp"
#include "query_optimizer/expressions/Scalar.hpp"
#include "query_optimizer/physical/Physical.hpp"
#include "query_optimizer/rules/Rule.hpp"
#include "utility/Macros.hpp"

namespace quickstep {
namespace optimizer {

class OptimizerContext;

/** \addtogroup OptimizerRules
 *  @{
 */

class ExtractCommonSubexpression : public Rule<physical::Physical> {
 public:
  /**
   * @brief Constructor.
   */
  ExtractCommonSubexpression(OptimizerContext *optimizer_context);

  ~ExtractCommonSubexpression() override {}

  std::string getName() const override {
    return "ExtractCommonSubexpression";
  }

  physical::PhysicalPtr apply(const physical::PhysicalPtr &input) override;

 private:
  physical::PhysicalPtr applyInternal(const physical::PhysicalPtr &input);

  struct ScalarHash {
    inline std::size_t operator()(const expressions::ScalarPtr &scalar) const {
      return scalar->hash();
    }
  };

  struct ScalarEqual {
    inline bool operator()(const expressions::ScalarPtr &lhs,
                           const expressions::ScalarPtr &rhs) const {
      return lhs->equals(rhs);
    }
  };

  using ScalarCounter =
      std::unordered_map<expressions::ScalarPtr, std::size_t, ScalarHash, ScalarEqual>;

  using ScalarMap =
      std::unordered_map<expressions::ScalarPtr,
                         expressions::CommonSubexpressionPtr,
                         ScalarHash,
                         ScalarEqual>;

  using ScalarHashable = std::unordered_set<expressions::ScalarPtr>;

  std::vector<expressions::ExpressionPtr> transformExpressions(
      const std::vector<expressions::ExpressionPtr> &expressions);

  expressions::ExpressionPtr transformExpression(
      const expressions::ExpressionPtr &expression);

  bool visitAndCount(
      const expressions::ExpressionPtr &expression,
      ScalarCounter *counter,
      ScalarHashable *hashable);

  expressions::ExpressionPtr visitAndTransform(
      const expressions::ExpressionPtr &expression,
      const std::size_t max_reference_count,
      const ScalarCounter &counter,
      const ScalarHashable &hashable,
      ScalarMap *substitution_map);

  template <typename ScalarSubclassT>
  static std::vector<expressions::ExpressionPtr> UpCast(
      const std::vector<std::shared_ptr<const ScalarSubclassT>> &expressions) {
    std::vector<expressions::ExpressionPtr> output;
    for (const auto &expr : expressions) {
      output.emplace_back(expr);
    }
    return output;
  }

  template <typename ScalarSubclassT>
  static std::vector<std::shared_ptr<const ScalarSubclassT>> DownCast(
      const std::vector<expressions::ExpressionPtr> &expressions) {
    std::vector<std::shared_ptr<const ScalarSubclassT>> output;
    for (const auto &expr : expressions) {
      output.emplace_back(std::static_pointer_cast<const ScalarSubclassT>(expr));
    }
    return output;
  }

  OptimizerContext *optimizer_context_;
  std::unordered_set<int> homogeneous_whitelist_;

  DISALLOW_COPY_AND_ASSIGN(ExtractCommonSubexpression);
};

/** @} */

}  // namespace optimizer
}  // namespace quickstep

#endif  // QUICKSTEP_QUERY_OPTIMIZER_RULES_EXTRACT_COMMON_SUBEXPRESSION_HPP_
