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
// source: google/cloud/iap/v1/service.proto

#include "google/cloud/iap/v1/internal/identity_aware_proxy_o_auth_option_defaults.h"
#include "google/cloud/iap/v1/identity_aware_proxy_o_auth_connection.h"
#include "google/cloud/iap/v1/identity_aware_proxy_o_auth_options.h"
#include "google/cloud/internal/populate_common_options.h"
#include "google/cloud/internal/populate_grpc_options.h"
#include <memory>

namespace google {
namespace cloud {
namespace iap_v1_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

namespace {
auto constexpr kBackoffScaling = 2.0;
}  // namespace

Options IdentityAwareProxyOAuthServiceDefaultOptions(Options options) {
  options = google::cloud::internal::PopulateCommonOptions(
      std::move(options),
      "GOOGLE_CLOUD_CPP_IDENTITY_AWARE_PROXY_O_AUTH_SERVICE_ENDPOINT", "",
      "GOOGLE_CLOUD_CPP_IDENTITY_AWARE_PROXY_O_AUTH_SERVICE_AUTHORITY",
      "iap.googleapis.com");
  options =
      google::cloud::internal::PopulateGrpcOptions(std::move(options), "");
  if (!options.has<iap_v1::IdentityAwareProxyOAuthServiceRetryPolicyOption>()) {
    options.set<iap_v1::IdentityAwareProxyOAuthServiceRetryPolicyOption>(
        iap_v1::IdentityAwareProxyOAuthServiceLimitedTimeRetryPolicy(
            std::chrono::minutes(30))
            .clone());
  }
  if (!options
           .has<iap_v1::IdentityAwareProxyOAuthServiceBackoffPolicyOption>()) {
    options.set<iap_v1::IdentityAwareProxyOAuthServiceBackoffPolicyOption>(
        ExponentialBackoffPolicy(
            std::chrono::seconds(0), std::chrono::seconds(1),
            std::chrono::minutes(5), kBackoffScaling, kBackoffScaling)
            .clone());
  }
  if (!options.has<
          iap_v1::
              IdentityAwareProxyOAuthServiceConnectionIdempotencyPolicyOption>()) {
    options.set<
        iap_v1::
            IdentityAwareProxyOAuthServiceConnectionIdempotencyPolicyOption>(
        iap_v1::
            MakeDefaultIdentityAwareProxyOAuthServiceConnectionIdempotencyPolicy());
  }

  return options;
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace iap_v1_internal
}  // namespace cloud
}  // namespace google
