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
// source: google/cloud/networkconnectivity/v1/hub.proto

#include "google/cloud/networkconnectivity/v1/internal/hub_option_defaults.h"
#include "google/cloud/networkconnectivity/v1/hub_connection.h"
#include "google/cloud/networkconnectivity/v1/hub_options.h"
#include "google/cloud/internal/populate_common_options.h"
#include "google/cloud/internal/populate_grpc_options.h"
#include <memory>

namespace google {
namespace cloud {
namespace networkconnectivity_v1_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

namespace {
auto constexpr kBackoffScaling = 2.0;
}  // namespace

Options HubServiceDefaultOptions(Options options) {
  options = google::cloud::internal::PopulateCommonOptions(
      std::move(options), "GOOGLE_CLOUD_CPP_HUB_SERVICE_ENDPOINT", "",
      "GOOGLE_CLOUD_CPP_HUB_SERVICE_AUTHORITY",
      "networkconnectivity.googleapis.com");
  options =
      google::cloud::internal::PopulateGrpcOptions(std::move(options), "");
  if (!options.has<networkconnectivity_v1::HubServiceRetryPolicyOption>()) {
    options.set<networkconnectivity_v1::HubServiceRetryPolicyOption>(
        networkconnectivity_v1::HubServiceLimitedTimeRetryPolicy(
            std::chrono::minutes(30))
            .clone());
  }
  if (!options.has<networkconnectivity_v1::HubServiceBackoffPolicyOption>()) {
    options.set<networkconnectivity_v1::HubServiceBackoffPolicyOption>(
        ExponentialBackoffPolicy(
            std::chrono::seconds(0), std::chrono::seconds(1),
            std::chrono::minutes(5), kBackoffScaling, kBackoffScaling)
            .clone());
  }
  if (!options.has<networkconnectivity_v1::HubServicePollingPolicyOption>()) {
    options.set<networkconnectivity_v1::HubServicePollingPolicyOption>(
        GenericPollingPolicy<
            networkconnectivity_v1::HubServiceRetryPolicyOption::Type,
            networkconnectivity_v1::HubServiceBackoffPolicyOption::Type>(
            options.get<networkconnectivity_v1::HubServiceRetryPolicyOption>()
                ->clone(),
            ExponentialBackoffPolicy(std::chrono::seconds(1),
                                     std::chrono::minutes(5), kBackoffScaling)
                .clone())
            .clone());
  }
  if (!options.has<networkconnectivity_v1::
                       HubServiceConnectionIdempotencyPolicyOption>()) {
    options.set<
        networkconnectivity_v1::HubServiceConnectionIdempotencyPolicyOption>(
        networkconnectivity_v1::
            MakeDefaultHubServiceConnectionIdempotencyPolicy());
  }

  return options;
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace networkconnectivity_v1_internal
}  // namespace cloud
}  // namespace google
