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

#ifndef QUICKSTEP_STORAGE_THREAD_PRIVATE_COMPACT_KEY_HASH_TABLE_HPP_
#define QUICKSTEP_STORAGE_THREAD_PRIVATE_COMPACT_KEY_HASH_TABLE_HPP_

#include <algorithm>
#include <cstddef>
#include <cstdint>
#include <unordered_map>
#include <vector>

#include "catalog/CatalogTypedefs.hpp"
#include "expressions/aggregation/AggregationHandle.hpp"
#include "expressions/aggregation/AggregationID.hpp"
#include "storage/HashTableBase.hpp"
#include "storage/ValueAccessorMultiplexer.hpp"
#include "storage/ValueAccessorUtil.hpp"
#include "types/Type.hpp"
#include "types/TypeID.hpp"
#include "types/containers/ColumnVector.hpp"
#include "types/containers/ColumnVectorsValueAccessor.hpp"
#include "utility/Macros.hpp"
#include "utility/ScopedBuffer.hpp"

#include "glog/logging.h"

namespace quickstep {

class ThreadPrivateCompactKeyHashTable : public AggregationStateHashTableBase {
 public:
  ThreadPrivateCompactKeyHashTable(
      const std::vector<const Type *> &key_types,
      const std::size_t num_entries,
      const std::vector<AggregationHandle *> &handles,
      StorageManager *storage_manager)
      : key_types_(key_types),
        handles_(handles),
        bucket_size_(0),
        num_buckets_(num_entries),
        buckets_allocated_(0) {
    for (const Type *key_type : key_types) {
      DCHECK(!key_type->isVariableLength());

      const std::size_t key_size = key_type->maximumByteLength();
      DCHECK(key_size == 1u || key_size == 2u || key_size == 4u || key_size == 8u);

      key_sizes_.emplace_back(key_size);
    }

    for (const AggregationHandle *handle : handles) {
      state_offsets_.emplace_back(bucket_size_);

      const std::vector<const Type*> arg_types = handle->getArgumentTypes();
      DCHECK_LE(arg_types.size(), 1u);

      std::size_t state_size = 0;
      switch (handle->getAggregationID()) {
        case AggregationID::kCount: {
          state_size = sizeof(std::int64_t);
          break;
        }
        case AggregationID::kSum: {
          DCHECK_EQ(1u, arg_types.size());
          switch (arg_types.front()->getTypeID()) {
            case TypeID::kInt:  // Fall through
            case TypeID::kLong:
              state_size = sizeof(std::int64_t);
              break;
            case TypeID::kFloat:  // Fall through
            case TypeID::kDouble:
              state_size = sizeof(double);
              break;
            default:
              LOG(FATAL) << "Not implemented";
          }
          break;
        }
        default:
          LOG(FATAL) << "Not implemented";
      }
      bucket_size_ += state_size;
    }

    keys_.reset(sizeof(std::uint64_t) * num_buckets_);
    buckets_.reset(bucket_size_ * num_buckets_);
  }

  ~ThreadPrivateCompactKeyHashTable() override {}

  HashTableImplType getImplType() const override {
    return HashTableImplType::kThreadPrivateCompactKey;
  }

  void destroyPayload() override {}

  std::size_t getMemoryConsumptionBytes() const override {
    return num_buckets_ * (bucket_size_ + sizeof(std::uint64_t));
  }

  inline std::size_t numEntries() const {
    return buckets_allocated_;
  }

  bool upsertValueAccessorCompositeKey(
      const std::vector<std::vector<MultiSourceAttributeId>> &argument_ids,
      const std::vector<MultiSourceAttributeId> &key_attr_ids,
      const ValueAccessorMultiplexer &accessor_mux) override {
    ValueAccessor *base_accessor = accessor_mux.getBaseAccessor();
    ValueAccessor *derived_accessor = accessor_mux.getDerivedAccessor();

    DCHECK(base_accessor != nullptr);
    const std::size_t num_tuples = base_accessor->getNumTuplesVirtual();

    ScopedBuffer buffer(sizeof(std::uint64_t) * num_tuples);
    std::uint64_t *key_codes = static_cast<std::uint64_t*>(buffer.get());
    std::size_t key_code_offset = 0;
    for (std::size_t i = 0; i < key_attr_ids.size(); ++i) {
      const auto &key_attr_id = key_attr_ids[i];
      ValueAccessor *accessor =
          key_attr_id.source == ValueAccessorSource::kBase
              ? base_accessor
              : derived_accessor;
      DCHECK(accessor != nullptr);

      const std::size_t key_size = key_sizes_[i];
      switch (key_size) {
        case 1u:
          ConstructKeyCode<std::uint8_t>(
              key_code_offset, key_attr_id.attr_id, accessor, key_codes);
          break;
        case 2u:
          ConstructKeyCode<std::uint16_t>(
              key_code_offset, key_attr_id.attr_id, accessor, key_codes);
          break;
        case 4u:
          ConstructKeyCode<std::uint32_t>(
              key_code_offset, key_attr_id.attr_id, accessor, key_codes);
          break;
        case 8u:
          ConstructKeyCode<std::uint64_t>(
              key_code_offset, key_attr_id.attr_id, accessor, key_codes);
          break;
        default:
          LOG(FATAL) << "Not implemented";
      }

      key_code_offset += key_size;
    }

    std::vector<BucketIndex> bucket_indices;
    bucket_indices.reserve(num_tuples);
    std::uint64_t *keys = static_cast<std::uint64_t*>(keys_.get());
    for (std::size_t i = 0; i < num_tuples; ++i) {
      const std::size_t code = key_codes[i];
      const auto index_it = index_.find(code);
      if (index_it == index_.end()) {
        // TODO: Resize if overflow
        index_.emplace(code, buckets_allocated_);
        bucket_indices.emplace_back(buckets_allocated_);
        keys[buckets_allocated_] = code;
        ++buckets_allocated_;
      } else {
        bucket_indices.emplace_back(index_it->second);
      }
    }

    // Dispatch
    for (std::size_t i = 0; i < handles_.size(); ++i) {
      const AggregationHandle *handle = handles_[i];
      switch (handle->getAggregationID()) {
        case AggregationID::kCount: {
          upsertValueAccessorCount(bucket_indices, state_offsets_[i]);
          break;
        }
        case AggregationID::kSum: {
          DCHECK_EQ(1u, argument_ids[i].size());
          const auto &argument_id = argument_ids[i].front();
          ValueAccessor *accessor =
              argument_id.source == ValueAccessorSource::kBase
                  ? base_accessor
                  : derived_accessor;
          DCHECK(accessor != nullptr);

          DCHECK_EQ(1u, handle->getArgumentTypes().size());
          const Type *argument_type = handle->getArgumentTypes().front();
          switch (argument_type->getTypeID()) {
            case kInt: {
              upsertValueAccessorSum<int, std::int64_t>(
                  bucket_indices, state_offsets_[i], argument_id.attr_id, accessor);
              break;
            }
            case kLong: {
              upsertValueAccessorSum<std::int64_t, std::int64_t>(
                  bucket_indices, state_offsets_[i], argument_id.attr_id, accessor);
              break;
            }
            case kFloat: {
              upsertValueAccessorSum<float, double>(
                  bucket_indices, state_offsets_[i], argument_id.attr_id, accessor);
              break;
            }
            case kDouble: {
              upsertValueAccessorSum<double, double>(
                  bucket_indices, state_offsets_[i], argument_id.attr_id, accessor);
              break;
            }
            default:
              LOG(FATAL) << "Not implemented";
          }
          break;
        }
        default:
          LOG(FATAL) << "Not implemented";
      }
    }

    return true;
  }

  void merge(const ThreadPrivateCompactKeyHashTable *other) {
    std::vector<BucketIndex> dst_bucket_indices;
    std::uint64_t *dst_keys = static_cast<std::uint64_t*>(keys_.get());

    const char *src_buckets_start =
        static_cast<const char*>(other->buckets_.get());
    const std::uint64_t *src_keys =
        static_cast<const std::uint64_t*>(other->keys_.get());

    for (std::size_t i = 0; i < other->buckets_allocated_; ++i) {
      const std::uint64_t code = src_keys[i];
      const auto index_it = index_.find(code);

      if (index_it == index_.end()) {
        // TODO: Resize if overflow
        index_.emplace(code, buckets_allocated_);
        dst_bucket_indices.emplace_back(buckets_allocated_);
        dst_keys[buckets_allocated_] = code;
        ++buckets_allocated_;
      } else {
        dst_bucket_indices.emplace_back(index_it->second);
      }
    }

    // Dispatch
    for (std::size_t i = 0; i < handles_.size(); ++i) {
      const AggregationHandle *handle = handles_[i];
      switch (handle->getAggregationID()) {
        case AggregationID::kCount: {
          mergeStateSum<std::int64_t>(
              dst_bucket_indices, src_buckets_start, state_offsets_[i]);
          break;
        }
        case AggregationID::kSum: {
          const Type *argument_type = handle->getArgumentTypes().front();
          switch (argument_type->getTypeID()) {
            case kInt:  // Fall through
            case kLong: {
              mergeStateSum<std::int64_t>(
                  dst_bucket_indices, src_buckets_start, state_offsets_[i]);
              break;
            }
            case kFloat:  // Fall through
            case kDouble: {
              mergeStateSum<double>(
                  dst_bucket_indices, src_buckets_start, state_offsets_[i]);
              break;
            }
            default:
              LOG(FATAL) << "Not implemented";
          }
          break;
        }
        default:
          LOG(FATAL) << "Not implemented";
      }
    }
  }

  void print() const {
    std::cout << "num_entries = " << buckets_allocated_ << "\n";
    const double *values = static_cast<const double*>(buckets_.get());
    for (std::size_t i = 0; i < buckets_allocated_; ++i) {
      std::cout << values[i] << "\n";
    }
  }

  void finalize(ColumnVectorsValueAccessor *output) const {
    std::size_t key_offset = 0;
    for (std::size_t i = 0; i < key_types_.size(); ++i) {
      const Type &key_type = *key_types_[i];
      std::unique_ptr<NativeColumnVector> native_cv(
          new NativeColumnVector(key_type, buckets_allocated_));

      const std::size_t key_size = key_sizes_[i];
      switch (key_size) {
        case 1u:
          finalizeKey<std::uint8_t>(key_offset, native_cv.get());
          break;
        case 2u:
          finalizeKey<std::uint16_t>(key_offset, native_cv.get());
          break;
        case 4u:
          finalizeKey<std::uint32_t>(key_offset, native_cv.get());
          break;
        case 8u:
          finalizeKey<std::uint64_t>(key_offset, native_cv.get());
          break;
        default:
          LOG(FATAL) << "Not implemented";
      }
      output->addColumn(native_cv.release());

      key_offset += key_size;
    }

    // Dispatch
    for (std::size_t i = 0; i < handles_.size(); ++i) {
      const AggregationHandle *handle = handles_[i];
      const Type &result_type = *handle->getResultType();
      std::unique_ptr<NativeColumnVector> native_cv(
          new NativeColumnVector(result_type, buckets_allocated_));

      switch (handle->getAggregationID()) {
        case AggregationID::kCount: {
          finalizeStateSum<std::int64_t, std::int64_t>(
              state_offsets_[i], native_cv.get());
          break;
        }
        case AggregationID::kSum: {
          const Type *argument_type = handle->getArgumentTypes().front();
          switch (argument_type->getTypeID()) {
            case kInt:  // Fall through
            case kLong: {
              finalizeStateSum<std::int64_t, std::int64_t>(
                  state_offsets_[i], native_cv.get());
              break;
            }
            case kFloat:  // Fall through
            case kDouble: {
              finalizeStateSum<double, double>(
                  state_offsets_[i], native_cv.get());
              break;
            }
            default:
              LOG(FATAL) << "Not implemented";
          }
          break;
        }
        default:
          LOG(FATAL) << "Not implemented";
      }
      output->addColumn(native_cv.release());
    }
  }

 private:
  using BucketIndex = std::uint32_t;

  template <typename KeyT>
  inline static void ConstructKeyCode(const std::size_t offset,
                                      const attribute_id attr_id,
                                      ValueAccessor *accessor,
                                      void *key_code_start) {
    InvokeOnAnyValueAccessor(
        accessor,
        [&](auto *accessor) -> void {  // NOLINT(build/c++11)
      char *key_code_ptr = static_cast<char*>(key_code_start) + offset;
      accessor->beginIteration();
      while (accessor->next()) {
        *reinterpret_cast<KeyT*>(key_code_ptr) =
            *static_cast<const KeyT*>(
                accessor->template getUntypedValue<false>(attr_id));
        key_code_ptr += sizeof(std::uint64_t);
      }
    });
  }

  inline void upsertValueAccessorCount(const std::vector<BucketIndex> &bucket_indices,
                                       const std::size_t state_offset) {
    char *state_start = static_cast<char*>(buckets_.get()) + state_offset;
    for (const BucketIndex idx : bucket_indices) {
      char *state_ptr = state_start + bucket_size_ * idx;
      *reinterpret_cast<std::int64_t*>(state_ptr) += 1;
    }
  }

  template <typename ArgumentT, typename StateT>
  inline void upsertValueAccessorSum(const std::vector<BucketIndex> &bucket_indices,
                                     const std::size_t state_offset,
                                     const attribute_id attr_id,
                                     ValueAccessor *accessor) {
    InvokeOnAnyValueAccessor(
        accessor,
        [&](auto *accessor) -> void {  // NOLINT(build/c++11)
      accessor->beginIteration();

      char *state_start = static_cast<char*>(buckets_.get()) + state_offset;
      std::size_t loc = 0;
      while (accessor->next()) {
        char *state_ptr = state_start + bucket_size_ * bucket_indices[loc];
        *reinterpret_cast<StateT*>(state_ptr) +=
            *static_cast<const ArgumentT*>(
                accessor->template getUntypedValue<false>(attr_id));
        ++loc;
      }
    });
  }

  template <typename StateT>
  inline void mergeStateSum(const std::vector<BucketIndex> &dst_bucket_indices,
                            const void *src_buckets_start,
                            const std::size_t state_offset) {
    char *dst_state_start = static_cast<char*>(buckets_.get()) + state_offset;
    const char* src_state_start =
        static_cast<const char*>(src_buckets_start) + state_offset;
    for (std::size_t i = 0; i < dst_bucket_indices.size(); ++i) {
      char *dst_state_ptr = dst_state_start + bucket_size_ * dst_bucket_indices[i];
      const char *src_state_ptr = src_state_start + bucket_size_ * i;
      *reinterpret_cast<StateT*>(dst_state_ptr) +=
          *reinterpret_cast<const StateT*>(src_state_ptr);
    }
  }

  template <typename KeyT>
  inline void finalizeKey(const std::size_t offset,
                          NativeColumnVector *output_cv) const {
    const char *key_ptr = static_cast<const char*>(keys_.get()) + offset;
    for (std::size_t i = 0; i < buckets_allocated_; ++i) {
      *static_cast<KeyT*>(output_cv->getPtrForDirectWrite()) =
          *reinterpret_cast<const KeyT*>(key_ptr);
      key_ptr += sizeof(std::uint64_t);
    }
  }

  template <typename StateT, typename ResultT>
  inline void finalizeStateSum(const std::size_t state_offset,
                               NativeColumnVector *output_cv) const {
    char *state_ptr = static_cast<char*>(buckets_.get()) + state_offset;
    for (std::size_t i = 0; i < buckets_allocated_; ++i) {
      *static_cast<ResultT*>(output_cv->getPtrForDirectWrite()) =
          *reinterpret_cast<const StateT*>(state_ptr);
      state_ptr += bucket_size_;
    }
  }

  const std::vector<const Type*> key_types_;
  const std::vector<AggregationHandle *> handles_;

  std::vector<std::size_t> key_sizes_;
  std::vector<std::size_t> state_offsets_;
  std::size_t bucket_size_;

  std::unordered_map<std::uint64_t, BucketIndex> index_;

  std::size_t num_buckets_;
  std::size_t buckets_allocated_;

  ScopedBuffer keys_;
  ScopedBuffer buckets_;

  DISALLOW_COPY_AND_ASSIGN(ThreadPrivateCompactKeyHashTable);
};

}  // namespace quickstep

#endif  // QUICKSTEP_STORAGE_THREAD_PRIVATE_COMPACT_KEY_HASH_TABLE_HPP_
