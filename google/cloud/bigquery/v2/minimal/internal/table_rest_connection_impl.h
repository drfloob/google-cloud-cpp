// Copyright 2023 Google LLC
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      https://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_BIGQUERY_V2_MINIMAL_INTERNAL_TABLE_REST_CONNECTION_IMPL_H
#define GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_BIGQUERY_V2_MINIMAL_INTERNAL_TABLE_REST_CONNECTION_IMPL_H

#include "google/cloud/bigquery/v2/minimal/internal/table_connection.h"
#include "google/cloud/bigquery/v2/minimal/internal/table_idempotency_policy.h"
#include "google/cloud/bigquery/v2/minimal/internal/table_options.h"
#include "google/cloud/bigquery/v2/minimal/internal/table_rest_stub.h"
#include "google/cloud/bigquery/v2/minimal/internal/table_retry_policy.h"
#include "google/cloud/backoff_policy.h"
#include "google/cloud/options.h"
#include "google/cloud/status_or.h"
#include "google/cloud/stream_range.h"
#include "google/cloud/version.h"
#include <memory>

namespace google {
namespace cloud {
namespace bigquery_v2_minimal_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

class TableRestConnectionImpl : public TableConnection {
 public:
  ~TableRestConnectionImpl() override = default;

  TableRestConnectionImpl(std::shared_ptr<TableRestStub> stub, Options options);

  Options options() override { return options_; }

  StatusOr<Table> GetTable(GetTableRequest const& request) override;
  StreamRange<ListFormatTable> ListTables(
      ListTablesRequest const& request) override;

 private:
  std::unique_ptr<TableRetryPolicy> retry_policy() {
    auto const& options = internal::CurrentOptions();
    if (options.has<TableRetryPolicyOption>()) {
      return options.get<TableRetryPolicyOption>()->clone();
    }
    return options_.get<TableRetryPolicyOption>()->clone();
  }

  std::unique_ptr<BackoffPolicy> backoff_policy() {
    auto const& options = internal::CurrentOptions();
    if (options.has<TableBackoffPolicyOption>()) {
      return options.get<TableBackoffPolicyOption>()->clone();
    }
    return options_.get<TableBackoffPolicyOption>()->clone();
  }

  std::unique_ptr<TableIdempotencyPolicy> idempotency_policy() {
    auto const& options = internal::CurrentOptions();
    if (options.has<TableIdempotencyPolicyOption>()) {
      return options.get<TableIdempotencyPolicyOption>()->clone();
    }
    return options_.get<TableIdempotencyPolicyOption>()->clone();
  }

  std::shared_ptr<TableRestStub> stub_;
  Options options_;
};

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace bigquery_v2_minimal_internal
}  // namespace cloud
}  // namespace google

#endif  // GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_BIGQUERY_V2_MINIMAL_INTERNAL_TABLE_REST_CONNECTION_IMPL_H
