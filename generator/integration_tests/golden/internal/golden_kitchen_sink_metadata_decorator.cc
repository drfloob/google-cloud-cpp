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
// source: generator/integration_tests/test.proto

#include "generator/integration_tests/golden/internal/golden_kitchen_sink_metadata_decorator.h"
#include "google/cloud/common_options.h"
#include "google/cloud/internal/api_client_header.h"
#include "google/cloud/status_or.h"
#include <generator/integration_tests/test.grpc.pb.h>
#include <memory>

namespace google {
namespace cloud {
namespace golden_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

GoldenKitchenSinkMetadata::GoldenKitchenSinkMetadata(
    std::shared_ptr<GoldenKitchenSinkStub> child)
    : child_(std::move(child)),
      api_client_header_(google::cloud::internal::ApiClientHeader("generator")) {}

StatusOr<google::test::admin::database::v1::GenerateAccessTokenResponse>
GoldenKitchenSinkMetadata::GenerateAccessToken(
    grpc::ClientContext& context,
    google::test::admin::database::v1::GenerateAccessTokenRequest const& request) {
  SetMetadata(context, "name=" + request.name());
  return child_->GenerateAccessToken(context, request);
}

StatusOr<google::test::admin::database::v1::GenerateIdTokenResponse>
GoldenKitchenSinkMetadata::GenerateIdToken(
    grpc::ClientContext& context,
    google::test::admin::database::v1::GenerateIdTokenRequest const& request) {
  SetMetadata(context);
  return child_->GenerateIdToken(context, request);
}

StatusOr<google::test::admin::database::v1::WriteLogEntriesResponse>
GoldenKitchenSinkMetadata::WriteLogEntries(
    grpc::ClientContext& context,
    google::test::admin::database::v1::WriteLogEntriesRequest const& request) {
  SetMetadata(context);
  return child_->WriteLogEntries(context, request);
}

StatusOr<google::test::admin::database::v1::ListLogsResponse>
GoldenKitchenSinkMetadata::ListLogs(
    grpc::ClientContext& context,
    google::test::admin::database::v1::ListLogsRequest const& request) {
  SetMetadata(context, "parent=" + request.parent());
  return child_->ListLogs(context, request);
}

std::unique_ptr<google::cloud::internal::StreamingReadRpc<google::test::admin::database::v1::TailLogEntriesResponse>>
GoldenKitchenSinkMetadata::TailLogEntries(
    std::unique_ptr<grpc::ClientContext> context,
    google::test::admin::database::v1::TailLogEntriesRequest const& request) {
  SetMetadata(*context);
  return child_->TailLogEntries(std::move(context), request);
}

StatusOr<google::test::admin::database::v1::ListServiceAccountKeysResponse>
GoldenKitchenSinkMetadata::ListServiceAccountKeys(
    grpc::ClientContext& context,
    google::test::admin::database::v1::ListServiceAccountKeysRequest const& request) {
  SetMetadata(context, "name=" + request.name());
  return child_->ListServiceAccountKeys(context, request);
}

Status
GoldenKitchenSinkMetadata::DoNothing(
    grpc::ClientContext& context,
    google::protobuf::Empty const& request) {
  SetMetadata(context);
  return child_->DoNothing(context, request);
}

std::unique_ptr<::google::cloud::AsyncStreamingReadWriteRpc<
      google::test::admin::database::v1::AppendRowsRequest,
      google::test::admin::database::v1::AppendRowsResponse>>
GoldenKitchenSinkMetadata::AsyncAppendRows(
    google::cloud::CompletionQueue const& cq,
    std::unique_ptr<grpc::ClientContext> context) {
  SetMetadata(*context);
  return child_->AsyncAppendRows(cq, std::move(context));
}

std::unique_ptr<::google::cloud::internal::StreamingWriteRpc<
    google::test::admin::database::v1::WriteObjectRequest,
    google::test::admin::database::v1::WriteObjectResponse>>
GoldenKitchenSinkMetadata::WriteObject(
    std::unique_ptr<grpc::ClientContext> context) {
  SetMetadata(*context);
  return child_->WriteObject(std::move(context));
}

std::unique_ptr<::google::cloud::internal::AsyncStreamingReadRpc<
      google::test::admin::database::v1::TailLogEntriesResponse>>
GoldenKitchenSinkMetadata::AsyncTailLogEntries(
    google::cloud::CompletionQueue const& cq,
    std::unique_ptr<grpc::ClientContext> context,
    google::test::admin::database::v1::TailLogEntriesRequest const& request) {
  SetMetadata(*context);
  return child_->AsyncTailLogEntries(cq, std::move(context), request);
}

std::unique_ptr<::google::cloud::internal::AsyncStreamingWriteRpc<
    google::test::admin::database::v1::WriteObjectRequest, google::test::admin::database::v1::WriteObjectResponse>>
GoldenKitchenSinkMetadata::AsyncWriteObject(
    google::cloud::CompletionQueue const& cq,
    std::unique_ptr<grpc::ClientContext> context) {
  SetMetadata(*context);
  return child_->AsyncWriteObject(cq, std::move(context));
}

void GoldenKitchenSinkMetadata::SetMetadata(grpc::ClientContext& context,
                                        std::string const& request_params) {
  context.AddMetadata("x-goog-request-params", request_params);
  SetMetadata(context);
}

void GoldenKitchenSinkMetadata::SetMetadata(grpc::ClientContext& context) {
  context.AddMetadata("x-goog-api-client", api_client_header_);
  auto const& options = internal::CurrentOptions();
  if (options.has<UserProjectOption>()) {
    context.AddMetadata(
        "x-goog-user-project", options.get<UserProjectOption>());
  }
  auto const& authority = options.get<AuthorityOption>();
  if (!authority.empty()) context.set_authority(authority);
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace golden_internal
}  // namespace cloud
}  // namespace google
