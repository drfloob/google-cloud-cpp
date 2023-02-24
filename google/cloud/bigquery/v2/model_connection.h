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
// source: google/cloud/bigquery/v2/model.proto

#ifndef GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_BIGQUERY_V2_MODEL_CONNECTION_H
#define GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_BIGQUERY_V2_MODEL_CONNECTION_H

#include "google/cloud/bigquery/v2/internal/model_retry_traits.h"
#include "google/cloud/bigquery/v2/internal/model_stub.h"
#include "google/cloud/bigquery/v2/model_connection_idempotency_policy.h"
#include "google/cloud/backoff_policy.h"
#include "google/cloud/options.h"
#include "google/cloud/status_or.h"
#include "google/cloud/version.h"
#include <memory>

namespace google {
namespace cloud {
namespace bigquery_v2 {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

using ModelServiceRetryPolicy =
    ::google::cloud::internal::TraitBasedRetryPolicy<
        bigquery_v2_internal::ModelServiceRetryTraits>;

using ModelServiceLimitedTimeRetryPolicy =
    ::google::cloud::internal::LimitedTimeRetryPolicy<
        bigquery_v2_internal::ModelServiceRetryTraits>;

using ModelServiceLimitedErrorCountRetryPolicy =
    ::google::cloud::internal::LimitedErrorCountRetryPolicy<
        bigquery_v2_internal::ModelServiceRetryTraits>;

/**
 * The `ModelServiceConnection` object for `ModelServiceClient`.
 *
 * This interface defines virtual methods for each of the user-facing overload
 * sets in `ModelServiceClient`. This allows users to inject custom behavior
 * (e.g., with a Google Mock object) when writing tests that use objects of type
 * `ModelServiceClient`.
 *
 * To create a concrete instance, see `MakeModelServiceConnection()`.
 *
 * For mocking, see `bigquery_v2_mocks::MockModelServiceConnection`.
 */
class ModelServiceConnection {
 public:
  virtual ~ModelServiceConnection() = 0;

  virtual Options options() { return Options{}; }

  virtual StatusOr<google::cloud::bigquery::v2::Model> GetModel(
      google::cloud::bigquery::v2::GetModelRequest const& request);

  virtual StatusOr<google::cloud::bigquery::v2::ListModelsResponse> ListModels(
      google::cloud::bigquery::v2::ListModelsRequest const& request);

  virtual StatusOr<google::cloud::bigquery::v2::Model> PatchModel(
      google::cloud::bigquery::v2::PatchModelRequest const& request);

  virtual Status DeleteModel(
      google::cloud::bigquery::v2::DeleteModelRequest const& request);
};

/**
 * A factory function to construct an object of type `ModelServiceConnection`.
 *
 * The returned connection object should not be used directly; instead it
 * should be passed as an argument to the constructor of ModelServiceClient.
 *
 * The optional @p options argument may be used to configure aspects of the
 * returned `ModelServiceConnection`. Expected options are any of the types in
 * the following option lists:
 *
 * - `google::cloud::CommonOptionList`
 * - `google::cloud::GrpcOptionList`
 * - `google::cloud::UnifiedCredentialsOptionList`
 * - `google::cloud::bigquery_v2::ModelServicePolicyOptionList`
 *
 * @note Unexpected options will be ignored. To log unexpected options instead,
 *     set `GOOGLE_CLOUD_CPP_ENABLE_CLOG=yes` in the environment.
 *
 * @param options (optional) Configure the `ModelServiceConnection` created by
 * this function.
 */
std::shared_ptr<ModelServiceConnection> MakeModelServiceConnection(
    Options options = {});

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace bigquery_v2
}  // namespace cloud
}  // namespace google

#endif  // GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_BIGQUERY_V2_MODEL_CONNECTION_H
