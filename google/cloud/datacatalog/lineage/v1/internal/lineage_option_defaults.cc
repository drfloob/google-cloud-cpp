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

// Generated by the Codegen C++ plugin.
// If you make any local changes, they will be lost.
// source: google/cloud/datacatalog/lineage/v1/lineage.proto

#include "google/cloud/datacatalog/lineage/v1/internal/lineage_option_defaults.h"
#include "google/cloud/datacatalog/lineage/v1/lineage_connection.h"
#include "google/cloud/datacatalog/lineage/v1/lineage_options.h"
#include "google/cloud/internal/populate_common_options.h"
#include "google/cloud/internal/populate_grpc_options.h"
#include <memory>

namespace google {
namespace cloud {
namespace datacatalog_lineage_v1_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

namespace {
auto constexpr kBackoffScaling = 2.0;
}  // namespace

Options LineageDefaultOptions(Options options) {
  options = google::cloud::internal::PopulateCommonOptions(
      std::move(options), "GOOGLE_CLOUD_CPP_LINEAGE_ENDPOINT", "",
      "GOOGLE_CLOUD_CPP_LINEAGE_AUTHORITY", "datalineage.googleapis.com");
  options =
      google::cloud::internal::PopulateGrpcOptions(std::move(options), "");
  if (!options.has<datacatalog_lineage_v1::LineageRetryPolicyOption>()) {
    options.set<datacatalog_lineage_v1::LineageRetryPolicyOption>(
        datacatalog_lineage_v1::LineageLimitedTimeRetryPolicy(
            std::chrono::minutes(30))
            .clone());
  }
  if (!options.has<datacatalog_lineage_v1::LineageBackoffPolicyOption>()) {
    options.set<datacatalog_lineage_v1::LineageBackoffPolicyOption>(
        ExponentialBackoffPolicy(
            std::chrono::seconds(0), std::chrono::seconds(1),
            std::chrono::minutes(5), kBackoffScaling, kBackoffScaling)
            .clone());
  }
  if (!options.has<datacatalog_lineage_v1::LineagePollingPolicyOption>()) {
    options.set<datacatalog_lineage_v1::LineagePollingPolicyOption>(
        GenericPollingPolicy<
            datacatalog_lineage_v1::LineageRetryPolicyOption::Type,
            datacatalog_lineage_v1::LineageBackoffPolicyOption::Type>(
            options.get<datacatalog_lineage_v1::LineageRetryPolicyOption>()
                ->clone(),
            ExponentialBackoffPolicy(std::chrono::seconds(1),
                                     std::chrono::minutes(5), kBackoffScaling)
                .clone())
            .clone());
  }
  if (!options.has<
          datacatalog_lineage_v1::LineageConnectionIdempotencyPolicyOption>()) {
    options
        .set<datacatalog_lineage_v1::LineageConnectionIdempotencyPolicyOption>(
            datacatalog_lineage_v1::
                MakeDefaultLineageConnectionIdempotencyPolicy());
  }

  return options;
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace datacatalog_lineage_v1_internal
}  // namespace cloud
}  // namespace google
