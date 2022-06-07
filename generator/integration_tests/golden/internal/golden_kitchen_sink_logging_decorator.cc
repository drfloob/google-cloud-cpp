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

#include "generator/integration_tests/golden/internal/golden_kitchen_sink_logging_decorator.h"
#include "google/cloud/internal/async_read_write_stream_logging.h"
#include "google/cloud/internal/async_streaming_read_rpc_logging.h"
#include "google/cloud/internal/async_streaming_write_rpc_logging.h"
#include "google/cloud/internal/log_wrapper.h"
#include "google/cloud/internal/streaming_read_rpc_logging.h"
#include "google/cloud/internal/streaming_write_rpc_logging.h"
#include "google/cloud/status_or.h"
#include <generator/integration_tests/test.grpc.pb.h>
#include <memory>

namespace google {
namespace cloud {
namespace golden_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

GoldenKitchenSinkLogging::GoldenKitchenSinkLogging(
    std::shared_ptr<GoldenKitchenSinkStub> child,
    TracingOptions tracing_options,
    std::set<std::string> components)
    : child_(std::move(child)), tracing_options_(std::move(tracing_options)),
      components_(std::move(components)) {}

StatusOr<google::test::admin::database::v1::GenerateAccessTokenResponse>
GoldenKitchenSinkLogging::GenerateAccessToken(
    grpc::ClientContext& context,
    google::test::admin::database::v1::GenerateAccessTokenRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context,
             google::test::admin::database::v1::GenerateAccessTokenRequest const& request) {
        return child_->GenerateAccessToken(context, request);
      },
      context, request, __func__, tracing_options_);
}

StatusOr<google::test::admin::database::v1::GenerateIdTokenResponse>
GoldenKitchenSinkLogging::GenerateIdToken(
    grpc::ClientContext& context,
    google::test::admin::database::v1::GenerateIdTokenRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context,
             google::test::admin::database::v1::GenerateIdTokenRequest const& request) {
        return child_->GenerateIdToken(context, request);
      },
      context, request, __func__, tracing_options_);
}

StatusOr<google::test::admin::database::v1::WriteLogEntriesResponse>
GoldenKitchenSinkLogging::WriteLogEntries(
    grpc::ClientContext& context,
    google::test::admin::database::v1::WriteLogEntriesRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context,
             google::test::admin::database::v1::WriteLogEntriesRequest const& request) {
        return child_->WriteLogEntries(context, request);
      },
      context, request, __func__, tracing_options_);
}

StatusOr<google::test::admin::database::v1::ListLogsResponse>
GoldenKitchenSinkLogging::ListLogs(
    grpc::ClientContext& context,
    google::test::admin::database::v1::ListLogsRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context,
             google::test::admin::database::v1::ListLogsRequest const& request) {
        return child_->ListLogs(context, request);
      },
      context, request, __func__, tracing_options_);
}

std::unique_ptr<google::cloud::internal::StreamingReadRpc<google::test::admin::database::v1::TailLogEntriesResponse>>
GoldenKitchenSinkLogging::TailLogEntries(
    std::unique_ptr<grpc::ClientContext> context,
    google::test::admin::database::v1::TailLogEntriesRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](std::unique_ptr<grpc::ClientContext> context,
             google::test::admin::database::v1::TailLogEntriesRequest const& request) ->
      std::unique_ptr<google::cloud::internal::StreamingReadRpc<
          google::test::admin::database::v1::TailLogEntriesResponse>> {
        auto stream = child_->TailLogEntries(std::move(context), request);
        if (components_.count("rpc-streams") > 0) {
          stream = absl::make_unique<google::cloud::internal::StreamingReadRpcLogging<
             google::test::admin::database::v1::TailLogEntriesResponse>>(
               std::move(stream), tracing_options_,
               google::cloud::internal::RequestIdForLogging());
        }
        return stream;
      },
      std::move(context), request, __func__, tracing_options_);
}

StatusOr<google::test::admin::database::v1::ListServiceAccountKeysResponse>
GoldenKitchenSinkLogging::ListServiceAccountKeys(
    grpc::ClientContext& context,
    google::test::admin::database::v1::ListServiceAccountKeysRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context,
             google::test::admin::database::v1::ListServiceAccountKeysRequest const& request) {
        return child_->ListServiceAccountKeys(context, request);
      },
      context, request, __func__, tracing_options_);
}

Status
GoldenKitchenSinkLogging::DoNothing(
    grpc::ClientContext& context,
    google::protobuf::Empty const& request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context,
             google::protobuf::Empty const& request) {
        return child_->DoNothing(context, request);
      },
      context, request, __func__, tracing_options_);
}

std::unique_ptr<::google::cloud::AsyncStreamingReadWriteRpc<
    google::test::admin::database::v1::AppendRowsRequest,
    google::test::admin::database::v1::AppendRowsResponse>>
GoldenKitchenSinkLogging::AsyncAppendRows(
    google::cloud::CompletionQueue const& cq,
    std::unique_ptr<grpc::ClientContext> context) {
  using LoggingStream =
     ::google::cloud::internal::AsyncStreamingReadWriteRpcLogging<google::test::admin::database::v1::AppendRowsRequest, google::test::admin::database::v1::AppendRowsResponse>;

  auto request_id = google::cloud::internal::RequestIdForLogging();
  GCP_LOG(DEBUG) << __func__ << "(" << request_id << ")";
  auto stream = child_->AsyncAppendRows(cq, std::move(context));
  if (components_.count("rpc-streams") > 0) {
    stream = absl::make_unique<LoggingStream>(
        std::move(stream), tracing_options_, std::move(request_id));
  }
  return stream;
}

std::unique_ptr<::google::cloud::internal::StreamingWriteRpc<
    google::test::admin::database::v1::WriteObjectRequest,
    google::test::admin::database::v1::WriteObjectResponse>>
GoldenKitchenSinkLogging::WriteObject(
    std::unique_ptr<grpc::ClientContext> context) {
  using LoggingStream = ::google::cloud::internal::StreamingWriteRpcLogging<
      google::test::admin::database::v1::WriteObjectRequest, google::test::admin::database::v1::WriteObjectResponse>;

  auto request_id = google::cloud::internal::RequestIdForLogging();
  GCP_LOG(DEBUG) << __func__ << "(" << request_id << ")";
  auto stream = child_->WriteObject(std::move(context));
  if (components_.count("rpc-streams") > 0) {
    stream = absl::make_unique<LoggingStream>(
        std::move(stream), tracing_options_, std::move(request_id));
  }
  return stream;
}

std::unique_ptr<::google::cloud::internal::AsyncStreamingReadRpc<
    google::test::admin::database::v1::TailLogEntriesResponse>>
GoldenKitchenSinkLogging::AsyncTailLogEntries(
    google::cloud::CompletionQueue const& cq,
    std::unique_ptr<grpc::ClientContext> context,
    google::test::admin::database::v1::TailLogEntriesRequest const& request) {
  using LoggingStream =
     ::google::cloud::internal::AsyncStreamingReadRpcLogging<google::test::admin::database::v1::TailLogEntriesResponse>;

  auto request_id = google::cloud::internal::RequestIdForLogging();
  GCP_LOG(DEBUG) << __func__ << "(" << request_id << ")";
  auto stream = child_->AsyncTailLogEntries(cq, std::move(context), request);
  if (components_.count("rpc-streams") > 0) {
    stream = absl::make_unique<LoggingStream>(
        std::move(stream), tracing_options_, std::move(request_id));
  }
  return stream;
}

std::unique_ptr<::google::cloud::internal::AsyncStreamingWriteRpc<
    google::test::admin::database::v1::WriteObjectRequest, google::test::admin::database::v1::WriteObjectResponse>>
GoldenKitchenSinkLogging::AsyncWriteObject(
    google::cloud::CompletionQueue const& cq,
    std::unique_ptr<grpc::ClientContext> context) {
  using LoggingStream = ::google::cloud::internal::AsyncStreamingWriteRpcLogging<
      google::test::admin::database::v1::WriteObjectRequest, google::test::admin::database::v1::WriteObjectResponse>;

  auto request_id = google::cloud::internal::RequestIdForLogging();
  GCP_LOG(DEBUG) << __func__ << "(" << request_id << ")";
  auto stream = child_->AsyncWriteObject(cq, std::move(context));
  if (components_.count("rpc-streams") > 0) {
    stream = absl::make_unique<LoggingStream>(
        std::move(stream), tracing_options_, std::move(request_id));
  }
  return stream;
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace golden_internal
}  // namespace cloud
}  // namespace google
