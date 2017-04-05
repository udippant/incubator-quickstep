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

#ifndef QUICKSTEP_EXPRESSIONS_SCALAR_SCALAR_CACHE_HPP_
#define QUICKSTEP_EXPRESSIONS_SCALAR_SCALAR_CACHE_HPP_

#include <unordered_map>

#include "types/containers/ColumnVector.hpp"
#include "utility/Macros.hpp"

#include "glog/logging.h"

namespace quickstep {

/** \addtogroup Expressions
 *  @{
 */

class ScalarCache {
 public:
  ScalarCache() {}

  inline bool has(const int share_id) const {
    return cv_cache_.find(share_id) != cv_cache_.end();
  }

  inline ColumnVectorPtr get(const int share_id) const {
    DCHECK(has(share_id));
    return cv_cache_.at(share_id);
  }

  inline void set(const int share_id, const ColumnVectorPtr &cv) {
    DCHECK(!has(share_id));
    cv_cache_.emplace(share_id, cv);
  }

 private:
  std::unordered_map<int, ColumnVectorPtr> cv_cache_;

  DISALLOW_COPY_AND_ASSIGN(ScalarCache);
};

/** @} */

}  // namespace quickstep

#endif  // QUICKSTEP_EXPRESSIONS_SCALAR_SCALAR_CACHE_HPP_
