// Copyright 2021 Google LLC
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

#include "generator/internal/auth_decorator_generator.h"
#include "absl/memory/memory.h"
#include "absl/strings/str_split.h"
#include "generator/internal/codegen_utils.h"
#include "generator/internal/predicate_utils.h"
#include "generator/internal/printer.h"
#include <google/protobuf/descriptor.h>

namespace google {
namespace cloud {
namespace generator_internal {

AuthDecoratorGenerator::AuthDecoratorGenerator(
    google::protobuf::ServiceDescriptor const* service_descriptor,
    VarsDictionary service_vars,
    std::map<std::string, VarsDictionary> service_method_vars,
    google::protobuf::compiler::GeneratorContext* context)
    : ServiceCodeGenerator("auth_header_path", "auth_cc_path",
                           service_descriptor, std::move(service_vars),
                           std::move(service_method_vars), context) {}

Status AuthDecoratorGenerator::GenerateHeader() {
  HeaderPrint(CopyrightLicenseFileHeader());
  HeaderPrint(
      R"""(
// Generated by the Codegen C++ plugin.
// If you make any local changes, they will be lost.
// source: $proto_file_name$

#ifndef $header_include_guard$
#define $header_include_guard$
)""");

  // includes
  HeaderPrint("\n");
  HeaderLocalIncludes({vars("stub_header_path"),
                       "google/cloud/internal/unified_grpc_credentials.h",
                       "google/cloud/version.h"});
  HeaderSystemIncludes(
      {HasLongrunningMethod() ? "google/longrunning/operations.grpc.pb.h" : "",
       "memory", "set", "string"});

  auto result = HeaderOpenNamespaces(NamespaceType::kInternal);
  if (!result.ok()) return result;

  // Abstract interface Auth base class
  HeaderPrint(
      R"""(
class $auth_class_name$ : public $stub_class_name$ {
 public:
  ~$auth_class_name$() override = default;
  $auth_class_name$(
      std::shared_ptr<google::cloud::internal::GrpcAuthenticationStrategy> auth,
      std::shared_ptr<$stub_class_name$> child);
)""");

  for (auto const& method : methods()) {
    if (IsStreamingWrite(method)) {
      HeaderPrintMethod(method, __FILE__, __LINE__, R"""(
  std::unique_ptr<::google::cloud::internal::StreamingWriteRpc<
      $request_type$,
      $response_type$>> $method_name$(
      std::unique_ptr<grpc::ClientContext> context) override;
)""");
      continue;
    }
    if (IsBidirStreaming(method)) {
      HeaderPrintMethod(method, __FILE__, __LINE__, R"""(
  std::unique_ptr<::google::cloud::AsyncStreamingReadWriteRpc<
      $request_type$,
      $response_type$>>
  Async$method_name$(
      google::cloud::CompletionQueue const& cq,
      std::unique_ptr<grpc::ClientContext> context) override;
)""");
      continue;
    }
    HeaderPrintMethod(
        method,
        {MethodPattern({{IsResponseTypeEmpty,
                         R"""(
  Status $method_name$(
      grpc::ClientContext& context,
      $request_type$ const& request) override;
)""",
                         R"""(
  StatusOr<$response_type$> $method_name$(
      grpc::ClientContext& context,
      $request_type$ const& request) override;
)"""},
                        {""}},
                       And(IsNonStreaming, Not(IsLongrunningOperation))),
         MethodPattern({{R"""(
  future<StatusOr<google::longrunning::Operation>> Async$method_name$(
      google::cloud::CompletionQueue& cq,
      std::unique_ptr<grpc::ClientContext> context,
      $request_type$ const& request) override;
)"""}},
                       IsLongrunningOperation),
         MethodPattern({{R"""(
  std::unique_ptr<google::cloud::internal::StreamingReadRpc<$response_type$>>
  $method_name$(
      std::unique_ptr<grpc::ClientContext> context,
      $request_type$ const& request) override;
)"""}},
                       IsStreamingRead)},
        __FILE__, __LINE__);
  }

  for (auto const& method : async_methods()) {
    if (IsStreamingRead(method)) {
      auto constexpr kDeclaration = R"""(
  std::unique_ptr<::google::cloud::internal::AsyncStreamingReadRpc<
      $response_type$>>
  Async$method_name$(
      google::cloud::CompletionQueue const& cq,
      std::unique_ptr<grpc::ClientContext> context,
      $request_type$ const& request) override;
)""";
      HeaderPrintMethod(method, __FILE__, __LINE__, kDeclaration);
      continue;
    }
    if (IsStreamingWrite(method)) {
      auto constexpr kDeclaration = R"""(
  std::unique_ptr<::google::cloud::internal::AsyncStreamingWriteRpc<
      $request_type$, $response_type$>>
  Async$method_name$(
      google::cloud::CompletionQueue const& cq,
      std::unique_ptr<grpc::ClientContext> context) override;
)""";
      HeaderPrintMethod(method, __FILE__, __LINE__, kDeclaration);
      continue;
    }
    HeaderPrintMethod(
        method,
        {MethodPattern({{IsResponseTypeEmpty,
                         R"""(
  future<Status> Async$method_name$(
      google::cloud::CompletionQueue& cq,
      std::unique_ptr<grpc::ClientContext> context,
      $request_type$ const& request) override;
)""",
                         R"""(
  future<StatusOr<$response_type$>> Async$method_name$(
      google::cloud::CompletionQueue& cq,
      std::unique_ptr<grpc::ClientContext> context,
      $request_type$ const& request) override;
)"""},
                        {""}},
                       And(IsNonStreaming, Not(IsLongrunningOperation)))},
        __FILE__, __LINE__);
  }

  if (HasLongrunningMethod()) {
    HeaderPrint(R"""(
  future<StatusOr<google::longrunning::Operation>> AsyncGetOperation(
      google::cloud::CompletionQueue& cq,
      std::unique_ptr<grpc::ClientContext> context,
      google::longrunning::GetOperationRequest const& request) override;

  future<Status> AsyncCancelOperation(
      google::cloud::CompletionQueue& cq,
      std::unique_ptr<grpc::ClientContext> context,
      google::longrunning::CancelOperationRequest const& request) override;)""");
  }

  HeaderPrint(R"""(
 private:
  std::shared_ptr<google::cloud::internal::GrpcAuthenticationStrategy> auth_;
  std::shared_ptr<$stub_class_name$> child_;
};
)""");

  HeaderCloseNamespaces();
  // close header guard
  HeaderPrint("\n#endif  // $header_include_guard$\n");
  return {};
}

Status AuthDecoratorGenerator::GenerateCc() {
  CcPrint(CopyrightLicenseFileHeader());
  CcPrint(
      R"""(
// Generated by the Codegen C++ plugin.
// If you make any local changes, they will be lost.
// source: $proto_file_name$
)""");

  // includes
  CcPrint("\n");
  CcLocalIncludes({
      vars("auth_header_path"),
      HasBidirStreamingMethod()
          ? "google/cloud/internal/async_read_write_stream_auth.h"
          : "",
      HasAsynchronousStreamingReadMethod()
          ? "google/cloud/internal/async_streaming_read_rpc_auth.h"
          : "",
      HasAsynchronousStreamingWriteMethod()
          ? "google/cloud/internal/async_streaming_write_rpc_auth.h"
          : "",
  });
  CcSystemIncludes({vars("proto_grpc_header_path"), "memory"});

  auto result = CcOpenNamespaces(NamespaceType::kInternal);
  if (!result.ok()) return result;

  // constructor
  CcPrint(
      R"""(
$auth_class_name$::$auth_class_name$(
    std::shared_ptr<google::cloud::internal::GrpcAuthenticationStrategy> auth,
    std::shared_ptr<$stub_class_name$> child)
    : auth_(std::move(auth)), child_(std::move(child)) {}
)""");

  // Auth decorator class member methods
  for (auto const& method : methods()) {
    if (IsStreamingWrite(method)) {
      CcPrintMethod(method, __FILE__, __LINE__, R"""(
std::unique_ptr<::google::cloud::internal::StreamingWriteRpc<
    $request_type$,
    $response_type$>>
$auth_class_name$::$method_name$(
    std::unique_ptr<grpc::ClientContext> context) {
  using ErrorStream = ::google::cloud::internal::StreamingWriteRpcError<
      $request_type$, $response_type$>;
  auto status = auth_->ConfigureContext(*context);
  if (!status.ok()) return absl::make_unique<ErrorStream>(std::move(status));
  return child_->$method_name$(std::move(context));
}
)""");
      continue;
    }
    if (IsBidirStreaming(method)) {
      CcPrintMethod(method, __FILE__, __LINE__, R"""(
std::unique_ptr<::google::cloud::AsyncStreamingReadWriteRpc<
    $request_type$,
    $response_type$>>
$auth_class_name$::Async$method_name$(
    google::cloud::CompletionQueue const& cq,
    std::unique_ptr<grpc::ClientContext> context) {
  using StreamAuth = google::cloud::internal::AsyncStreamingReadWriteRpcAuth<
    $request_type$, $response_type$>;

  auto child = child_;
  auto call = [child, cq](std::unique_ptr<grpc::ClientContext> ctx) {
    return child->Async$method_name$(cq, std::move(ctx));
  };
  return absl::make_unique<StreamAuth>(
    std::move(context), auth_, StreamAuth::StreamFactory(std::move(call)));
}
)""");
      continue;
    }
    CcPrintMethod(
        method,
        {MethodPattern({{IsResponseTypeEmpty,
                         R"""(
Status $auth_class_name$::$method_name$()""",
                         R"""(
StatusOr<$response_type$> $auth_class_name$::$method_name$()"""},
                        {R"""(
    grpc::ClientContext& context,
    $request_type$ const& request) {
  auto status = auth_->ConfigureContext(context);
  if (!status.ok()) return status;
  return child_->$method_name$(context, request);
}
)"""}},
                       And(IsNonStreaming, Not(IsLongrunningOperation))),
         MethodPattern({{R"""(
future<StatusOr<google::longrunning::Operation>>
$auth_class_name$::Async$method_name$(
      google::cloud::CompletionQueue& cq,
      std::unique_ptr<grpc::ClientContext> context,
      $request_type$ const& request) {
  using ReturnType = StatusOr<google::longrunning::Operation>;
  auto child = child_;
  return auth_->AsyncConfigureContext(std::move(context)).then(
      [cq, child, request](
          future<StatusOr<std::unique_ptr<grpc::ClientContext>>> f) mutable {
        auto context = f.get();
        if (!context) {
          return make_ready_future(ReturnType(std::move(context).status()));
        }
        return child->Async$method_name$(cq, *std::move(context), request);
      });
}
)"""}},
                       IsLongrunningOperation),
         MethodPattern({{R"""(
std::unique_ptr<google::cloud::internal::StreamingReadRpc<$response_type$>>
$auth_class_name$::$method_name$(
   std::unique_ptr<grpc::ClientContext> context,
   $request_type$ const& request) {
  using ErrorStream = ::google::cloud::internal::StreamingReadRpcError<
      $response_type$>;
  auto status = auth_->ConfigureContext(*context);
  if (!status.ok()) return absl::make_unique<ErrorStream>(std::move(status));
  return child_->$method_name$(std::move(context), request);
}
)"""}},
                       IsStreamingRead)},
        __FILE__, __LINE__);
  }

  for (auto const& method : async_methods()) {
    if (IsStreamingRead(method)) {
      auto constexpr kDefinition = R"""(
std::unique_ptr<::google::cloud::internal::AsyncStreamingReadRpc<
    $response_type$>>
$auth_class_name$::Async$method_name$(
    google::cloud::CompletionQueue const& cq,
    std::unique_ptr<grpc::ClientContext> context,
    $request_type$ const& request) {
  using StreamAuth = google::cloud::internal::AsyncStreamingReadRpcAuth<
    $response_type$>;

  auto child = child_;
  auto call = [child, cq, request](std::unique_ptr<grpc::ClientContext> ctx) {
    return child->Async$method_name$(cq, std::move(ctx), request);
  };
  return absl::make_unique<StreamAuth>(
    std::move(context), auth_, StreamAuth::StreamFactory(std::move(call)));
}
)""";
      CcPrintMethod(method, __FILE__, __LINE__, kDefinition);
      continue;
    }
    if (IsStreamingWrite(method)) {
      auto constexpr kDefinition = R"""(
std::unique_ptr<::google::cloud::internal::AsyncStreamingWriteRpc<
    $request_type$, $response_type$>>
$auth_class_name$::Async$method_name$(
    google::cloud::CompletionQueue const& cq,
    std::unique_ptr<grpc::ClientContext> context) {
  using StreamAuth = google::cloud::internal::AsyncStreamingWriteRpcAuth<
    $request_type$, $response_type$>;

  auto child = child_;
  auto call = [child, cq](std::unique_ptr<grpc::ClientContext> ctx) {
    return child->Async$method_name$(cq, std::move(ctx));
  };
  return absl::make_unique<StreamAuth>(
    std::move(context), auth_, StreamAuth::StreamFactory(std::move(call)));
}
)""";
      CcPrintMethod(method, __FILE__, __LINE__, kDefinition);
      continue;
    }
    CcPrintMethod(
        method,
        {MethodPattern({{IsResponseTypeEmpty,
                         R"""(
future<Status> $auth_class_name$::Async$method_name$(
      google::cloud::CompletionQueue& cq,
      std::unique_ptr<grpc::ClientContext> context,
      $request_type$ const& request) {
  auto child = child_;
  return auth_->AsyncConfigureContext(std::move(context)).then(
      [cq, child, request](
          future<StatusOr<std::unique_ptr<grpc::ClientContext>>> f) mutable {
        auto context = f.get();
        if (!context) return make_ready_future(std::move(context).status());)""",
                         R"""(
future<StatusOr<$response_type$>> $auth_class_name$::Async$method_name$(
      google::cloud::CompletionQueue& cq,
      std::unique_ptr<grpc::ClientContext> context,
      $request_type$ const& request) {
  using ReturnType = StatusOr<$response_type$>;
  auto child = child_;
  return auth_->AsyncConfigureContext(std::move(context)).then(
      [cq, child, request](
          future<StatusOr<std::unique_ptr<grpc::ClientContext>>> f) mutable {
        auto context = f.get();
        if (!context) {
          return make_ready_future(ReturnType(std::move(context).status()));
        })"""},
                        {R"""(
        return child->Async$method_name$(cq, *std::move(context), request);
      });
}
)"""}},
                       And(IsNonStreaming, Not(IsLongrunningOperation)))},
        __FILE__, __LINE__);
  }

  // long running operation support methods
  if (HasLongrunningMethod()) {
    CcPrint(R"""(
future<StatusOr<google::longrunning::Operation>>
$auth_class_name$::AsyncGetOperation(
    google::cloud::CompletionQueue& cq,
    std::unique_ptr<grpc::ClientContext> context,
    google::longrunning::GetOperationRequest const& request) {
  using ReturnType = StatusOr<google::longrunning::Operation>;
  auto child = child_;
  return auth_->AsyncConfigureContext(std::move(context)).then(
      [cq, child, request](
          future<StatusOr<std::unique_ptr<grpc::ClientContext>>> f) mutable {
        auto context = f.get();
        if (!context) {
          return make_ready_future(ReturnType(std::move(context).status()));
        }
        return child->AsyncGetOperation(cq, *std::move(context), request);
      });
}

future<Status> $auth_class_name$::AsyncCancelOperation(
    google::cloud::CompletionQueue& cq,
    std::unique_ptr<grpc::ClientContext> context,
    google::longrunning::CancelOperationRequest const& request) {
  auto child = child_;
  return auth_->AsyncConfigureContext(std::move(context)).then(
      [cq, child, request](
          future<StatusOr<std::unique_ptr<grpc::ClientContext>>> f) mutable {
        auto context = f.get();
        if (!context) return make_ready_future(std::move(context).status());
        return child->AsyncCancelOperation(cq, *std::move(context), request);
      });
}
)""");
  }

  CcCloseNamespaces();
  return {};
}

}  // namespace generator_internal
}  // namespace cloud
}  // namespace google
