// Copyright 2021-present StarRocks, Inc. All rights reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     https://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#pragma once

#include "column/vectorized_fwd.h"
#include "common/status.h"
#include "exprs/function_context.h"
#include "exprs/vectorized/function_helper.h"
#include "geo/geo_common.h"

namespace starrocks::vectorized {

class GroupingSetsFunctions {
public:
    /**
     * @param: [bigint]
     * Returns the grouping_id of columns
     */
    DEFINE_VECTORIZED_FN(grouping_id);

    /**
     * @param: [bigint]
     * Returns the grouping_id
     */
    DEFINE_VECTORIZED_FN(grouping);
};

} // namespace starrocks::vectorized
