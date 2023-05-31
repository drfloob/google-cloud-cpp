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
// source: google/api/servicemanagement/v1/servicemanager.proto

#include "google/cloud/servicemanagement/v1/internal/service_manager_option_defaults.h"
#include "google/cloud/servicemanagement/v1/service_manager_connection.h"
#include "google/cloud/servicemanagement/v1/service_manager_options.h"
#include "google/cloud/internal/populate_common_options.h"
#include "google/cloud/internal/populate_grpc_options.h"
#include <memory>

namespace google {
namespace cloud {
namespace servicemanagement_v1_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

namespace {
auto constexpr kBackoffScaling = 2.0;
}  // namespace

Options ServiceManagerDefaultOptions(Options options) {
  options = google::cloud::internal::PopulateCommonOptions(
      std::move(options), "GOOGLE_CLOUD_CPP_SERVICE_MANAGER_ENDPOINT", "",
      "GOOGLE_CLOUD_CPP_SERVICE_MANAGER_AUTHORITY",
      "servicemanagement.googleapis.com");
  options =
      google::cloud::internal::PopulateGrpcOptions(std::move(options), "");
  if (!options.has<servicemanagement_v1::ServiceManagerRetryPolicyOption>()) {
    options.set<servicemanagement_v1::ServiceManagerRetryPolicyOption>(
        servicemanagement_v1::ServiceManagerLimitedTimeRetryPolicy(
            std::chrono::minutes(30))
            .clone());
  }
  if (!options.has<servicemanagement_v1::ServiceManagerBackoffPolicyOption>()) {
    options.set<servicemanagement_v1::ServiceManagerBackoffPolicyOption>(
        ExponentialBackoffPolicy(
            std::chrono::seconds(0), std::chrono::seconds(1),
            std::chrono::minutes(5), kBackoffScaling, kBackoffScaling)
            .clone());
  }
  if (!options.has<servicemanagement_v1::ServiceManagerPollingPolicyOption>()) {
    options.set<servicemanagement_v1::ServiceManagerPollingPolicyOption>(
        GenericPollingPolicy<
            servicemanagement_v1::ServiceManagerRetryPolicyOption::Type,
            servicemanagement_v1::ServiceManagerBackoffPolicyOption::Type>(
            options
                .get<servicemanagement_v1::ServiceManagerRetryPolicyOption>()
                ->clone(),
            ExponentialBackoffPolicy(std::chrono::seconds(1),
                                     std::chrono::minutes(5), kBackoffScaling)
                .clone())
            .clone());
  }
  if (!options.has<servicemanagement_v1::
                       ServiceManagerConnectionIdempotencyPolicyOption>()) {
    options.set<
        servicemanagement_v1::ServiceManagerConnectionIdempotencyPolicyOption>(
        servicemanagement_v1::
            MakeDefaultServiceManagerConnectionIdempotencyPolicy());
  }

  return options;
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace servicemanagement_v1_internal
}  // namespace cloud
}  // namespace google
