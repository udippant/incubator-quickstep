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

#include "expressions/scalar/ScalarSharedExpression.hpp"

#include <string>
#include <utility>
#include <vector>

#include "catalog/CatalogTypedefs.hpp"
#include "expressions/Expressions.pb.h"
#include "expressions/scalar/ScalarCache.hpp"
#include "storage/ValueAccessor.hpp"
#include "types/TypedValue.hpp"
#include "types/containers/ColumnVector.hpp"

namespace quickstep {

struct SubBlocksReference;

ScalarSharedExpression::ScalarSharedExpression(const int share_id,
                                               Scalar *operand)
    : Scalar(operand->getType()),
      share_id_(share_id),
      operand_(operand) {
}

serialization::Scalar ScalarSharedExpression::getProto() const {
  serialization::Scalar proto;
  proto.set_data_source(serialization::Scalar::SHARED_EXPRESSION);
  proto.SetExtension(serialization::ScalarSharedExpression::share_id, share_id_);
  proto.MutableExtension(serialization::ScalarSharedExpression::operand)
      ->CopyFrom(operand_->getProto());

  return proto;
}

Scalar* ScalarSharedExpression::clone() const {
  return new ScalarSharedExpression(share_id_, operand_->clone());
}

TypedValue ScalarSharedExpression::getValueForSingleTuple(const ValueAccessor &accessor,
                                                          const tuple_id tuple) const {
  return operand_->getValueForSingleTuple(accessor, tuple);
}

TypedValue ScalarSharedExpression::getValueForJoinedTuples(
    const ValueAccessor &left_accessor,
    const relation_id left_relation_id,
    const tuple_id left_tuple_id,
    const ValueAccessor &right_accessor,
    const relation_id right_relation_id,
    const tuple_id right_tuple_id) const {
  return operand_->getValueForJoinedTuples(left_accessor,
                                           left_relation_id,
                                           left_tuple_id,
                                           right_accessor,
                                           right_relation_id,
                                           right_tuple_id);
}

ColumnVectorPtr ScalarSharedExpression::getAllValues(
    ValueAccessor *accessor,
    const SubBlocksReference *sub_blocks_ref,
    ScalarCache *scalar_cache) const {
  if (scalar_cache == nullptr) {
    return operand_->getAllValues(accessor, sub_blocks_ref, scalar_cache);
  } else {
    ColumnVectorPtr result;
    if (scalar_cache->has(share_id_)) {
      result = scalar_cache->get(share_id_);
    } else {
      result = operand_->getAllValues(accessor, sub_blocks_ref, scalar_cache);
      scalar_cache->set(share_id_, result);
    }
    return result;
  }
}

ColumnVectorPtr ScalarSharedExpression::getAllValuesForJoin(
    const relation_id left_relation_id,
    ValueAccessor *left_accessor,
    const relation_id right_relation_id,
    ValueAccessor *right_accessor,
    const std::vector<std::pair<tuple_id, tuple_id>> &joined_tuple_ids,
    ScalarCache *scalar_cache) const {
  if (scalar_cache == nullptr) {
    return operand_->getAllValuesForJoin(left_relation_id,
                                         left_accessor,
                                         right_relation_id,
                                         right_accessor,
                                         joined_tuple_ids,
                                         scalar_cache);
  } else {
    ColumnVectorPtr result;
    if (scalar_cache->has(share_id_)) {
      result = scalar_cache->get(share_id_);
    } else {
      result = operand_->getAllValuesForJoin(left_relation_id,
                                             left_accessor,
                                             right_relation_id,
                                             right_accessor,
                                             joined_tuple_ids,
                                             scalar_cache);
      scalar_cache->set(share_id_, result);
    }
    return result;
  }
}

void ScalarSharedExpression::getFieldStringItems(
    std::vector<std::string> *inline_field_names,
    std::vector<std::string> *inline_field_values,
    std::vector<std::string> *non_container_child_field_names,
    std::vector<const Expression*> *non_container_child_fields,
    std::vector<std::string> *container_child_field_names,
    std::vector<std::vector<const Expression*>> *container_child_fields) const {
  inline_field_names->emplace_back("share_id");
  inline_field_values->emplace_back(std::to_string(share_id_));

  non_container_child_field_names->emplace_back("operand");
  non_container_child_fields->emplace_back(operand_.get());
}

}  // namespace quickstep
