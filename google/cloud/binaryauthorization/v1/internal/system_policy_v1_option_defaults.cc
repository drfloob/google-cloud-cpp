// Copyright 2022 Google LLC
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
// source: google/cloud/binaryauthorization/v1/service.proto

#include "google/cloud/binaryauthorization/v1/internal/system_policy_v1_option_defaults.h"
#include "google/cloud/binaryauthorization/v1/system_policy_v1_connection.h"
#include "google/cloud/binaryauthorization/v1/system_policy_v1_options.h"
#include "google/cloud/internal/populate_common_options.h"
#include "google/cloud/internal/populate_grpc_options.h"
#include <memory>

namespace google {
namespace cloud {
namespace binaryauthorization_v1_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

namespace {
auto constexpr kBackoffScaling = 2.0;
}  // namespace

Options SystemPolicyV1DefaultOptions(Options options) {
  options = google::cloud::internal::PopulateCommonOptions(
      std::move(options), "GOOGLE_CLOUD_CPP_SYSTEM_POLICY_V1_ENDPOINT", "",
      "GOOGLE_CLOUD_CPP_SYSTEM_POLICY_V1_AUTHORITY",
      "binaryauthorization.googleapis.com");
  options =
      google::cloud::internal::PopulateGrpcOptions(std::move(options), "");
  if (!options.has<binaryauthorization_v1::SystemPolicyV1RetryPolicyOption>()) {
    options.set<binaryauthorization_v1::SystemPolicyV1RetryPolicyOption>(
        binaryauthorization_v1::SystemPolicyV1LimitedTimeRetryPolicy(
            std::chrono::minutes(30))
            .clone());
  }
  if (!options
           .has<binaryauthorization_v1::SystemPolicyV1BackoffPolicyOption>()) {
    options.set<binaryauthorization_v1::SystemPolicyV1BackoffPolicyOption>(
        ExponentialBackoffPolicy(
            std::chrono::seconds(0), std::chrono::seconds(1),
            std::chrono::minutes(5), kBackoffScaling, kBackoffScaling)
            .clone());
  }
  if (!options.has<binaryauthorization_v1::
                       SystemPolicyV1ConnectionIdempotencyPolicyOption>()) {
    options.set<binaryauthorization_v1::
                    SystemPolicyV1ConnectionIdempotencyPolicyOption>(
        binaryauthorization_v1::
            MakeDefaultSystemPolicyV1ConnectionIdempotencyPolicy());
  }

  return options;
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace binaryauthorization_v1_internal
}  // namespace cloud
}  // namespace google
