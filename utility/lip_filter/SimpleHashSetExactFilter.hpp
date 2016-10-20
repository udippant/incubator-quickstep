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

#ifndef QUICKSTEP_UTILITY_LIP_FILTER_SIMPLE_HASH_SET_EXACT_FILTER_HPP_
#define QUICKSTEP_UTILITY_LIP_FILTER_SIMPLE_HASH_SET_EXACT_FILTER_HPP_

#include "storage/StorageConstants.hpp"
#include "storage/StorageBlob.hpp"
#include "storage/StorageBlockInfo.hpp"
#include "storage/StorageManager.hpp"
#include "storage/ValueAccessor.hpp"
#include "storage/ValueAccessorUtil.hpp"
#include "types/Type.hpp"
#include "utility/Alignment.hpp"
#include "utility/Macros.hpp"
#include "utility/PrimeNumber.hpp"
#include "utility/lip_filter/LIPFilter.hpp"

#include "glog/logging.h"

namespace quickstep {

/** \addtogroup Utility
 *  @{
 */

template <typename KeyCppType>
class SimpleHashSetExactFilter : public LIPFilter {
 public:
  SimpleHashSetExactFilter(const std::size_t num_entries,
                           StorageManager *storage_manager)
      : LIPFilter(LIPFilterType::kSimpleHashSetExactFilter),
        storage_manager_(storage_manager) {
    // Pick out a prime number of slots and calculate storage requirements.
    std::size_t num_slots_tmp = get_next_prime_number(num_entries * kHashTableLoadFactor);
    std::size_t required_memory = sizeof(Header)
                                  + num_slots_tmp * sizeof(std::atomic<std::size_t>)
                                  + (num_slots_tmp / kHashTableLoadFactor) * sizeof(Bucket);
    std::size_t num_storage_slots = storage_manager_->SlotsNeededForBytes(required_memory);

    // Get a StorageBlob to hold the hash table.
    const block_id blob_id = storage_manager_->createBlob(num_storage_slots);
    blob_ = storage_manager_->getBlobMutable(blob_id);

    void *aligned_memory_start = blob_->getMemoryMutable();
    std::size_t available_memory = num_storage_slots * kSlotSizeBytes;

    // Locate the header.
    header_ = static_cast<Header*>(aligned_memory_start);
    aligned_memory_start = static_cast<char*>(aligned_memory_start) + sizeof(Header);
    available_memory -= sizeof(Header);

    // Recompute the number of slots & buckets using the actual available memory.
    std::size_t num_buckets_tmp
        = available_memory / (kHashTableLoadFactor * sizeof(std::atomic<std::size_t>)
                              + sizeof(Bucket));
    num_slots_tmp = get_previous_prime_number(num_buckets_tmp * kHashTableLoadFactor);
    num_buckets_tmp = num_slots_tmp / kHashTableLoadFactor;
    DCHECK_GT(num_slots_tmp, 0u);
    DCHECK_GT(num_buckets_tmp, 0u);

    // Locate the slot array.
    slots_ = static_cast<std::atomic<std::size_t>*>(aligned_memory_start);
    aligned_memory_start = static_cast<char*>(aligned_memory_start)
                           + sizeof(std::atomic<std::size_t>) * num_slots_tmp;
    available_memory -= sizeof(std::atomic<std::size_t>) * num_slots_tmp;

    // Locate the buckets.
    buckets_ = static_cast<Bucket*>(aligned_memory_start);

    // Fill in the header.
    header_->num_slots = num_slots_tmp;
    header_->num_buckets = num_buckets_tmp;
    header_->buckets_allocated.store(0, std::memory_order_relaxed);
  }


  void insertValueAccessor(ValueAccessor *accessor,
                           const attribute_id attr_id,
                           const Type *attr_type) override {
    InvokeOnAnyValueAccessor(
        accessor,
        [&](auto *accessor) -> void {  // NOLINT(build/c++11)
      if (attr_type->isNullable()) {
        this->insertValueAccessorInternal<true>(accessor, attr_id);
      } else {
        this->insertValueAccessorInternal<false>(accessor, attr_id);
      }
    });
  }

  std::size_t filterBatch(ValueAccessor *accessor,
                          const attribute_id attr_id,
                          const bool is_attr_nullable,
                          std::vector<tuple_id> *batch,
                          const std::size_t batch_size) const override {
    return InvokeOnAnyValueAccessor(
        accessor,
        [&](auto *accessor) -> std::size_t {  // NOLINT(build/c++11)
      if (is_attr_nullable) {
        return this->filterBatchInternal<true>(accessor, attr_id, batch, batch_size);
      } else {
        return this->filterBatchInternal<false>(accessor, attr_id, batch, batch_size);
      }
    });
  }

 private:
  template <bool is_attr_nullable, typename ValueAccessorT>
  inline void insertValueAccessorInternal(ValueAccessorT *accessor,
                                          const attribute_id attr_id) {
    accessor->beginIteration();
    while (accessor->next()) {
      const void *value = accessor->template getUntypedValue<is_attr_nullable>(attr_id);
      if (!is_attr_nullable || value != nullptr) {
        insert(static_cast<const KeyCppType *>(value));
      }
    }
  }

  inline void insert(const KeyCppType *key) {
    const std::size_t hash_code = *key;
    std::atomic<std::size_t> *pending_chain_ptr = &(slots_[hash_code % header_->num_slots]);

    for (;;) {
      std::size_t existing_chain_ptr = 0;
      if (pending_chain_ptr->compare_exchange_strong(existing_chain_ptr,
                                                     std::numeric_limits<std::size_t>::max(),
                                                     std::memory_order_acq_rel)) {
        // Got to the end of the chain. Allocate a new bucket.
        const std::size_t allocated_bucket_num =
            header_->buckets_allocated.fetch_add(1, std::memory_order_relaxed);
        if (allocated_bucket_num >= header_->num_buckets) {
          // TODO(jianqiao): implement resize code.
          LOG(FATAL) << "SimpleHashSetExactFilter run out of buckets\n";
        } else {
          // Write hash code into the bucket.
          Bucket *bucket = buckets_ + allocated_bucket_num;
          bucket->hash = hash_code;

          // Update the previous chain pointer to point to the new bucket.
          pending_chain_ptr->store(allocated_bucket_num + 1, std::memory_order_release);

          // Inserted the key into the hash table, done.
          return;
        }
      }
      // Spin until the real "next" pointer is available.
      while (existing_chain_ptr == std::numeric_limits<std::size_t>::max()) {
        existing_chain_ptr = pending_chain_ptr->load(std::memory_order_acquire);
      }
      if (existing_chain_ptr == 0) {
        // Other thread had to roll back, so try again.
        continue;
      }
      // Chase the next pointer.
      Bucket *bucket = buckets_ + (existing_chain_ptr - 1);
      if (bucket->hash == hash_code) {
        // The key is already in the hash table, done.
        return;
      }
      pending_chain_ptr = &(bucket->next);
    }
  }

  template <bool is_attr_nullable, typename ValueAccessorT>
  inline std::size_t filterBatchInternal(const ValueAccessorT *accessor,
                                         const attribute_id attr_id,
                                         std::vector<tuple_id> *batch,
                                         const std::size_t batch_size) const {
    std::size_t out_size = 0;
    for (std::size_t i = 0; i < batch_size; ++i) {
      const tuple_id tid = batch->at(i);
      const void *value =
          accessor->template getUntypedValueAtAbsolutePosition(attr_id, tid);
      if (is_attr_nullable && value == nullptr) {
        continue;
      }
      if (contains(static_cast<const KeyCppType *>(value))) {
        batch->at(out_size) = tid;
        ++out_size;
      }
    }
    return out_size;
  }

  inline bool contains(const KeyCppType *key) const {
    const std::size_t hash_code = *key;
    std::size_t bucket_ref =
        slots_[hash_code % header_->num_slots].load(std::memory_order_relaxed);
    while (bucket_ref != 0) {
      DCHECK_NE(bucket_ref, std::numeric_limits<std::size_t>::max());

      const Bucket &bucket = buckets_[bucket_ref - 1];
      if (bucket.hash == hash_code) {
        return true;
      }
      bucket_ref = bucket.next.load(std::memory_order_relaxed);
    }
    return false;
  }

  struct Header {
    std::size_t num_slots;
    std::size_t num_buckets;
    alignas(kCacheLineBytes)
        std::atomic<std::size_t> buckets_allocated;
  };

  struct Bucket {
    std::atomic<std::size_t> next;
    std::size_t hash;
  };

  // In-memory structure is as follows:
  //   - SimpleHashSetExactFilter::Header
  //   - Array of slots, interpreted as follows:
  //       - 0 = Points to nothing (empty)
  //       - SIZE_T_MAX = Pending (some thread is starting a chain from this
  //         slot and will overwrite it soon)
  //       - Anything else = The number of the first bucket in the chain for
  //         this slot PLUS ONE (i.e. subtract one to get the actual bucket
  //         number).
  //   - Array of buckets, each of which is:
  //       - atomic size_t "next" pointer, interpreted the same as slots above.
  //       - size_t hash value
  Header *header_;

  std::atomic<std::size_t> *slots_;
  Bucket *buckets_;

  StorageManager *storage_manager_;
  MutableBlobReference blob_;

  DISALLOW_COPY_AND_ASSIGN(SimpleHashSetExactFilter);
};

/** @} */

}  // namespace quickstep

#endif  // QUICKSTEP_UTILITY_LIP_FILTER_SIMPLE_HASH_SET_EXACT_FILTER_HPP_
