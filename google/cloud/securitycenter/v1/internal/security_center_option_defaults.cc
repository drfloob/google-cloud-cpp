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
// source: google/cloud/securitycenter/v1/securitycenter_service.proto

#include "google/cloud/securitycenter/v1/internal/security_center_option_defaults.h"
#include "google/cloud/securitycenter/v1/security_center_connection.h"
#include "google/cloud/securitycenter/v1/security_center_options.h"
#include "google/cloud/internal/populate_common_options.h"
#include "google/cloud/internal/populate_grpc_options.h"
#include <memory>

namespace google {
namespace cloud {
namespace securitycenter_v1_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

namespace {
auto constexpr kBackoffScaling = 2.0;
}  // namespace

Options SecurityCenterDefaultOptions(Options options) {
  options = google::cloud::internal::PopulateCommonOptions(
      std::move(options), "GOOGLE_CLOUD_CPP_SECURITY_CENTER_ENDPOINT", "",
      "GOOGLE_CLOUD_CPP_SECURITY_CENTER_AUTHORITY",
      "securitycenter.googleapis.com");
  options =
      google::cloud::internal::PopulateGrpcOptions(std::move(options), "");
  if (!options.has<securitycenter_v1::SecurityCenterRetryPolicyOption>()) {
    options.set<securitycenter_v1::SecurityCenterRetryPolicyOption>(
        securitycenter_v1::SecurityCenterLimitedTimeRetryPolicy(
            std::chrono::minutes(30))
            .clone());
  }
  if (!options.has<securitycenter_v1::SecurityCenterBackoffPolicyOption>()) {
    options.set<securitycenter_v1::SecurityCenterBackoffPolicyOption>(
        ExponentialBackoffPolicy(
            std::chrono::seconds(0), std::chrono::seconds(1),
            std::chrono::minutes(5), kBackoffScaling, kBackoffScaling)
            .clone());
  }
  if (!options.has<securitycenter_v1::SecurityCenterPollingPolicyOption>()) {
    options.set<securitycenter_v1::SecurityCenterPollingPolicyOption>(
        GenericPollingPolicy<
            securitycenter_v1::SecurityCenterRetryPolicyOption::Type,
            securitycenter_v1::SecurityCenterBackoffPolicyOption::Type>(
            options.get<securitycenter_v1::SecurityCenterRetryPolicyOption>()
                ->clone(),
            ExponentialBackoffPolicy(std::chrono::seconds(1),
                                     std::chrono::minutes(5), kBackoffScaling)
                .clone())
            .clone());
  }
  if (!options.has<securitycenter_v1::
                       SecurityCenterConnectionIdempotencyPolicyOption>()) {
    options.set<
        securitycenter_v1::SecurityCenterConnectionIdempotencyPolicyOption>(
        securitycenter_v1::
            MakeDefaultSecurityCenterConnectionIdempotencyPolicy());
  }

  return options;
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace securitycenter_v1_internal
}  // namespace cloud
}  // namespace google
