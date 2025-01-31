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
// source: google/cloud/resourcemanager/v3/tag_holds.proto

#ifndef GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_RESOURCEMANAGER_V3_INTERNAL_TAG_HOLDS_CONNECTION_IMPL_H
#define GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_RESOURCEMANAGER_V3_INTERNAL_TAG_HOLDS_CONNECTION_IMPL_H

#include "google/cloud/resourcemanager/v3/internal/tag_holds_retry_traits.h"
#include "google/cloud/resourcemanager/v3/internal/tag_holds_stub.h"
#include "google/cloud/resourcemanager/v3/tag_holds_connection.h"
#include "google/cloud/resourcemanager/v3/tag_holds_connection_idempotency_policy.h"
#include "google/cloud/resourcemanager/v3/tag_holds_options.h"
#include "google/cloud/background_threads.h"
#include "google/cloud/backoff_policy.h"
#include "google/cloud/future.h"
#include "google/cloud/options.h"
#include "google/cloud/polling_policy.h"
#include "google/cloud/status_or.h"
#include "google/cloud/stream_range.h"
#include "google/cloud/version.h"
#include <google/longrunning/operations.grpc.pb.h>
#include <memory>

namespace google {
namespace cloud {
namespace resourcemanager_v3_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

class TagHoldsConnectionImpl : public resourcemanager_v3::TagHoldsConnection {
 public:
  ~TagHoldsConnectionImpl() override = default;

  TagHoldsConnectionImpl(
      std::unique_ptr<google::cloud::BackgroundThreads> background,
      std::shared_ptr<resourcemanager_v3_internal::TagHoldsStub> stub,
      Options options);

  Options options() override { return options_; }

  future<StatusOr<google::cloud::resourcemanager::v3::TagHold>> CreateTagHold(
      google::cloud::resourcemanager::v3::CreateTagHoldRequest const& request)
      override;

  future<StatusOr<google::cloud::resourcemanager::v3::DeleteTagHoldMetadata>>
  DeleteTagHold(google::cloud::resourcemanager::v3::DeleteTagHoldRequest const&
                    request) override;

  StreamRange<google::cloud::resourcemanager::v3::TagHold> ListTagHolds(
      google::cloud::resourcemanager::v3::ListTagHoldsRequest request) override;

 private:
  std::unique_ptr<resourcemanager_v3::TagHoldsRetryPolicy> retry_policy() {
    auto const& options = internal::CurrentOptions();
    if (options.has<resourcemanager_v3::TagHoldsRetryPolicyOption>()) {
      return options.get<resourcemanager_v3::TagHoldsRetryPolicyOption>()
          ->clone();
    }
    return options_.get<resourcemanager_v3::TagHoldsRetryPolicyOption>()
        ->clone();
  }

  std::unique_ptr<BackoffPolicy> backoff_policy() {
    auto const& options = internal::CurrentOptions();
    if (options.has<resourcemanager_v3::TagHoldsBackoffPolicyOption>()) {
      return options.get<resourcemanager_v3::TagHoldsBackoffPolicyOption>()
          ->clone();
    }
    return options_.get<resourcemanager_v3::TagHoldsBackoffPolicyOption>()
        ->clone();
  }

  std::unique_ptr<resourcemanager_v3::TagHoldsConnectionIdempotencyPolicy>
  idempotency_policy() {
    auto const& options = internal::CurrentOptions();
    if (options.has<
            resourcemanager_v3::TagHoldsConnectionIdempotencyPolicyOption>()) {
      return options
          .get<resourcemanager_v3::TagHoldsConnectionIdempotencyPolicyOption>()
          ->clone();
    }
    return options_
        .get<resourcemanager_v3::TagHoldsConnectionIdempotencyPolicyOption>()
        ->clone();
  }

  std::unique_ptr<PollingPolicy> polling_policy() {
    auto const& options = internal::CurrentOptions();
    if (options.has<resourcemanager_v3::TagHoldsPollingPolicyOption>()) {
      return options.get<resourcemanager_v3::TagHoldsPollingPolicyOption>()
          ->clone();
    }
    return options_.get<resourcemanager_v3::TagHoldsPollingPolicyOption>()
        ->clone();
  }

  std::unique_ptr<google::cloud::BackgroundThreads> background_;
  std::shared_ptr<resourcemanager_v3_internal::TagHoldsStub> stub_;
  Options options_;
};

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace resourcemanager_v3_internal
}  // namespace cloud
}  // namespace google

#endif  // GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_RESOURCEMANAGER_V3_INTERNAL_TAG_HOLDS_CONNECTION_IMPL_H
