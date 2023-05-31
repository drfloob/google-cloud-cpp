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
// source: google/cloud/storageinsights/v1/storageinsights.proto

#include "google/cloud/storageinsights/v1/internal/storage_insights_option_defaults.h"
#include "google/cloud/storageinsights/v1/storage_insights_connection.h"
#include "google/cloud/storageinsights/v1/storage_insights_options.h"
#include "google/cloud/internal/populate_common_options.h"
#include "google/cloud/internal/populate_grpc_options.h"
#include <memory>

namespace google {
namespace cloud {
namespace storageinsights_v1_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

namespace {
auto constexpr kBackoffScaling = 2.0;
}  // namespace

Options StorageInsightsDefaultOptions(Options options) {
  options = google::cloud::internal::PopulateCommonOptions(
      std::move(options), "GOOGLE_CLOUD_CPP_STORAGE_INSIGHTS_ENDPOINT", "",
      "GOOGLE_CLOUD_CPP_STORAGE_INSIGHTS_AUTHORITY",
      "storageinsights.googleapis.com");
  options =
      google::cloud::internal::PopulateGrpcOptions(std::move(options), "");
  if (!options.has<storageinsights_v1::StorageInsightsRetryPolicyOption>()) {
    options.set<storageinsights_v1::StorageInsightsRetryPolicyOption>(
        storageinsights_v1::StorageInsightsLimitedTimeRetryPolicy(
            std::chrono::minutes(30))
            .clone());
  }
  if (!options.has<storageinsights_v1::StorageInsightsBackoffPolicyOption>()) {
    options.set<storageinsights_v1::StorageInsightsBackoffPolicyOption>(
        ExponentialBackoffPolicy(
            std::chrono::seconds(0), std::chrono::seconds(1),
            std::chrono::minutes(5), kBackoffScaling, kBackoffScaling)
            .clone());
  }
  if (!options.has<storageinsights_v1::
                       StorageInsightsConnectionIdempotencyPolicyOption>()) {
    options.set<
        storageinsights_v1::StorageInsightsConnectionIdempotencyPolicyOption>(
        storageinsights_v1::
            MakeDefaultStorageInsightsConnectionIdempotencyPolicy());
  }

  return options;
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace storageinsights_v1_internal
}  // namespace cloud
}  // namespace google
