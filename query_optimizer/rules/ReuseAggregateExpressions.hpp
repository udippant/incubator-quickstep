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

#ifndef QUICKSTEP_QUERY_OPTIMIZER_RULES_REUSE_AGGREGATE_EXPRESSIONS_HPP_
#define QUICKSTEP_QUERY_OPTIMIZER_RULES_REUSE_AGGREGATE_EXPRESSIONS_HPP_

#include <cstddef>
#include <memory>
#include <string>
#include <vector>

#include "query_optimizer/cost_model/StarSchemaSimpleCostModel.hpp"
#include "query_optimizer/expressions/Scalar.hpp"
#include "query_optimizer/physical/Physical.hpp"
#include "query_optimizer/rules/BottomUpRule.hpp"
#include "utility/Macros.hpp"

namespace quickstep {
namespace optimizer {

class OptimizerContext;

/** \addtogroup OptimizerRules
 *  @{
 */

class ReuseAggregateExpressions : public BottomUpRule<physical::Physical> {
 public:
  ReuseAggregateExpressions(OptimizerContext *optimizer_context)
      : optimizer_context_(optimizer_context) {}

  std::string getName() const override {
    return "ReuseAggregateExpressions";
  }

 protected:
  void init(const physical::PhysicalPtr &input) override;

  physical::PhysicalPtr applyToNode(const physical::PhysicalPtr &input) override;

 private:
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

  struct AggregateReference {
    enum Kind {
      kDirect = 0,
      kAvg
    };

    AggregateReference(const std::size_t ref)
        : kind(kDirect), first_ref(ref), second_ref(0) {}

    AggregateReference(const std::size_t sum_ref, const std::size_t count_ref)
        : kind(kAvg), first_ref(sum_ref), second_ref(count_ref) {}

    const Kind kind;
    const std::size_t first_ref;
    const std::size_t second_ref;
  };

  OptimizerContext *optimizer_context_;

  std::unique_ptr<cost::StarSchemaSimpleCostModel> cost_model_;

  DISALLOW_COPY_AND_ASSIGN(ReuseAggregateExpressions);
};

}  // namespace optimizer
}  // namespace quickstep

#endif  // QUICKSTEP_QUERY_OPTIMIZER_RULES_REUSE_AGGREGATE_EXPRESSIONS_HPP_
