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
// source: google/cloud/bigquery/analyticshub/v1/analyticshub.proto

#ifndef GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_BIGQUERY_ANALYTICSHUB_V1_ANALYTICS_HUB_OPTIONS_H
#define GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_BIGQUERY_ANALYTICSHUB_V1_ANALYTICS_HUB_OPTIONS_H

#include "google/cloud/bigquery/analyticshub/v1/analytics_hub_connection.h"
#include "google/cloud/bigquery/analyticshub/v1/analytics_hub_connection_idempotency_policy.h"
#include "google/cloud/backoff_policy.h"
#include "google/cloud/options.h"
#include "google/cloud/version.h"
#include <memory>

namespace google {
namespace cloud {
namespace bigquery_analyticshub_v1 {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

/**
 * Use with `google::cloud::Options` to configure the retry policy.
 *
 * @ingroup google-cloud-bigquery-options
 */
struct AnalyticsHubServiceRetryPolicyOption {
  using Type = std::shared_ptr<AnalyticsHubServiceRetryPolicy>;
};

/**
 * Use with `google::cloud::Options` to configure the backoff policy.
 *
 * @ingroup google-cloud-bigquery-options
 */
struct AnalyticsHubServiceBackoffPolicyOption {
  using Type = std::shared_ptr<BackoffPolicy>;
};

/**
 * Use with `google::cloud::Options` to configure which operations are retried.
 *
 * @ingroup google-cloud-bigquery-options
 */
struct AnalyticsHubServiceConnectionIdempotencyPolicyOption {
  using Type = std::shared_ptr<AnalyticsHubServiceConnectionIdempotencyPolicy>;
};

/**
 * The options applicable to AnalyticsHubService.
 *
 * @ingroup google-cloud-bigquery-options
 */
using AnalyticsHubServicePolicyOptionList =
    OptionList<AnalyticsHubServiceRetryPolicyOption,
               AnalyticsHubServiceBackoffPolicyOption,
               AnalyticsHubServiceConnectionIdempotencyPolicyOption>;

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace bigquery_analyticshub_v1
}  // namespace cloud
}  // namespace google

#endif  // GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_BIGQUERY_ANALYTICSHUB_V1_ANALYTICS_HUB_OPTIONS_H
