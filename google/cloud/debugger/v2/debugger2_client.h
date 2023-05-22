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
// source: google/devtools/clouddebugger/v2/debugger.proto

#ifndef GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_DEBUGGER_V2_DEBUGGER2_CLIENT_H
#define GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_DEBUGGER_V2_DEBUGGER2_CLIENT_H

#include "google/cloud/debugger/v2/debugger2_connection.h"
#include "google/cloud/future.h"
#include "google/cloud/options.h"
#include "google/cloud/polling_policy.h"
#include "google/cloud/status_or.h"
#include "google/cloud/version.h"
#include <memory>

namespace google {
namespace cloud {
namespace debugger_v2 {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

///
/// The Debugger service provides the API that allows users to collect run-time
/// information from a running application, without stopping or slowing it down
/// and without modifying its state.  An application may include one or
/// more replicated processes performing the same work.
///
/// A debugged application is represented using the Debuggee concept. The
/// Debugger service provides a way to query for available debuggees, but does
/// not provide a way to create one.  A debuggee is created using the Controller
/// service, usually by running a debugger agent with the application.
///
/// The Debugger service enables the client to set one or more Breakpoints on a
/// Debuggee and collect the results of the set Breakpoints.
///
/// @par Equality
///
/// Instances of this class created via copy-construction or copy-assignment
/// always compare equal. Instances created with equal
/// `std::shared_ptr<*Connection>` objects compare equal. Objects that compare
/// equal share the same underlying resources.
///
/// @par Performance
///
/// Creating a new instance of this class is a relatively expensive operation,
/// new objects establish new connections to the service. In contrast,
/// copy-construction, move-construction, and the corresponding assignment
/// operations are relatively efficient as the copies share all underlying
/// resources.
///
/// @par Thread Safety
///
/// Concurrent access to different instances of this class, even if they compare
/// equal, is guaranteed to work. Two or more threads operating on the same
/// instance of this class is not guaranteed to work. Since copy-construction
/// and move-construction is a relatively efficient operation, consider using
/// such a copy when using this class from multiple threads.
///
class Debugger2Client {
 public:
  explicit Debugger2Client(std::shared_ptr<Debugger2Connection> connection,
                           Options opts = {});
  ~Debugger2Client();

  ///@{
  /// @name Copy and move support
  Debugger2Client(Debugger2Client const&) = default;
  Debugger2Client& operator=(Debugger2Client const&) = default;
  Debugger2Client(Debugger2Client&&) = default;
  Debugger2Client& operator=(Debugger2Client&&) = default;
  ///@}

  ///@{
  /// @name Equality
  friend bool operator==(Debugger2Client const& a, Debugger2Client const& b) {
    return a.connection_ == b.connection_;
  }
  friend bool operator!=(Debugger2Client const& a, Debugger2Client const& b) {
    return !(a == b);
  }
  ///@}

  // clang-format off
  ///
  /// Sets the breakpoint to the debuggee.
  ///
  /// @param debuggee_id  Required. ID of the debuggee where the breakpoint is to be set.
  /// @param breakpoint  Required. Breakpoint specification to set.
  ///  The field `location` of the breakpoint must be set.
  /// @param client_version  Required. The client version making the call.
  ///  Schema: `domain/type/version` (e.g., `google.com/intellij/v1`).
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return the result of the RPC. The response message type
  ///     ([google.devtools.clouddebugger.v2.SetBreakpointResponse])
  ///     is mapped to a C++ class using the [Protobuf mapping rules].
  ///     If the request fails, the [`StatusOr`] contains the error details.
  ///
  /// [Protobuf mapping rules]: https://protobuf.dev/reference/cpp/cpp-generated/
  /// [input iterator requirements]: https://en.cppreference.com/w/cpp/named_req/InputIterator
  /// [Long Running Operation]: https://google.aip.dev/151
  /// [`std::string`]: https://en.cppreference.com/w/cpp/string/basic_string
  /// [`future`]: @ref google::cloud::future
  /// [`StatusOr`]: @ref google::cloud::StatusOr
  /// [`Status`]: @ref google::cloud::Status
  /// [google.devtools.clouddebugger.v2.SetBreakpointRequest]: @googleapis_reference_link{google/devtools/clouddebugger/v2/debugger.proto#L95}
  /// [google.devtools.clouddebugger.v2.SetBreakpointResponse]: @googleapis_reference_link{google/devtools/clouddebugger/v2/debugger.proto#L109}
  ///
  // clang-format on
  StatusOr<google::devtools::clouddebugger::v2::SetBreakpointResponse>
  SetBreakpoint(
      std::string const& debuggee_id,
      google::devtools::clouddebugger::v2::Breakpoint const& breakpoint,
      std::string const& client_version, Options opts = {});

  // clang-format off
  ///
  /// Sets the breakpoint to the debuggee.
  ///
  /// @param request Unary RPCs, such as the one wrapped by this
  ///     function, receive a single `request` proto message which includes all
  ///     the inputs for the RPC. In this case, the proto message is a
  ///     [google.devtools.clouddebugger.v2.SetBreakpointRequest].
  ///     Proto messages are converted to C++ classes by Protobuf, using the
  ///     [Protobuf mapping rules].
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return the result of the RPC. The response message type
  ///     ([google.devtools.clouddebugger.v2.SetBreakpointResponse])
  ///     is mapped to a C++ class using the [Protobuf mapping rules].
  ///     If the request fails, the [`StatusOr`] contains the error details.
  ///
  /// [Protobuf mapping rules]: https://protobuf.dev/reference/cpp/cpp-generated/
  /// [input iterator requirements]: https://en.cppreference.com/w/cpp/named_req/InputIterator
  /// [Long Running Operation]: https://google.aip.dev/151
  /// [`std::string`]: https://en.cppreference.com/w/cpp/string/basic_string
  /// [`future`]: @ref google::cloud::future
  /// [`StatusOr`]: @ref google::cloud::StatusOr
  /// [`Status`]: @ref google::cloud::Status
  /// [google.devtools.clouddebugger.v2.SetBreakpointRequest]: @googleapis_reference_link{google/devtools/clouddebugger/v2/debugger.proto#L95}
  /// [google.devtools.clouddebugger.v2.SetBreakpointResponse]: @googleapis_reference_link{google/devtools/clouddebugger/v2/debugger.proto#L109}
  ///
  // clang-format on
  StatusOr<google::devtools::clouddebugger::v2::SetBreakpointResponse>
  SetBreakpoint(
      google::devtools::clouddebugger::v2::SetBreakpointRequest const& request,
      Options opts = {});

  // clang-format off
  ///
  /// Gets breakpoint information.
  ///
  /// @param debuggee_id  Required. ID of the debuggee whose breakpoint to get.
  /// @param breakpoint_id  Required. ID of the breakpoint to get.
  /// @param client_version  Required. The client version making the call.
  ///  Schema: `domain/type/version` (e.g., `google.com/intellij/v1`).
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return the result of the RPC. The response message type
  ///     ([google.devtools.clouddebugger.v2.GetBreakpointResponse])
  ///     is mapped to a C++ class using the [Protobuf mapping rules].
  ///     If the request fails, the [`StatusOr`] contains the error details.
  ///
  /// [Protobuf mapping rules]: https://protobuf.dev/reference/cpp/cpp-generated/
  /// [input iterator requirements]: https://en.cppreference.com/w/cpp/named_req/InputIterator
  /// [Long Running Operation]: https://google.aip.dev/151
  /// [`std::string`]: https://en.cppreference.com/w/cpp/string/basic_string
  /// [`future`]: @ref google::cloud::future
  /// [`StatusOr`]: @ref google::cloud::StatusOr
  /// [`Status`]: @ref google::cloud::Status
  /// [google.devtools.clouddebugger.v2.GetBreakpointRequest]: @googleapis_reference_link{google/devtools/clouddebugger/v2/debugger.proto#L116}
  /// [google.devtools.clouddebugger.v2.GetBreakpointResponse]: @googleapis_reference_link{google/devtools/clouddebugger/v2/debugger.proto#L129}
  ///
  // clang-format on
  StatusOr<google::devtools::clouddebugger::v2::GetBreakpointResponse>
  GetBreakpoint(std::string const& debuggee_id,
                std::string const& breakpoint_id,
                std::string const& client_version, Options opts = {});

  // clang-format off
  ///
  /// Gets breakpoint information.
  ///
  /// @param request Unary RPCs, such as the one wrapped by this
  ///     function, receive a single `request` proto message which includes all
  ///     the inputs for the RPC. In this case, the proto message is a
  ///     [google.devtools.clouddebugger.v2.GetBreakpointRequest].
  ///     Proto messages are converted to C++ classes by Protobuf, using the
  ///     [Protobuf mapping rules].
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return the result of the RPC. The response message type
  ///     ([google.devtools.clouddebugger.v2.GetBreakpointResponse])
  ///     is mapped to a C++ class using the [Protobuf mapping rules].
  ///     If the request fails, the [`StatusOr`] contains the error details.
  ///
  /// [Protobuf mapping rules]: https://protobuf.dev/reference/cpp/cpp-generated/
  /// [input iterator requirements]: https://en.cppreference.com/w/cpp/named_req/InputIterator
  /// [Long Running Operation]: https://google.aip.dev/151
  /// [`std::string`]: https://en.cppreference.com/w/cpp/string/basic_string
  /// [`future`]: @ref google::cloud::future
  /// [`StatusOr`]: @ref google::cloud::StatusOr
  /// [`Status`]: @ref google::cloud::Status
  /// [google.devtools.clouddebugger.v2.GetBreakpointRequest]: @googleapis_reference_link{google/devtools/clouddebugger/v2/debugger.proto#L116}
  /// [google.devtools.clouddebugger.v2.GetBreakpointResponse]: @googleapis_reference_link{google/devtools/clouddebugger/v2/debugger.proto#L129}
  ///
  // clang-format on
  StatusOr<google::devtools::clouddebugger::v2::GetBreakpointResponse>
  GetBreakpoint(
      google::devtools::clouddebugger::v2::GetBreakpointRequest const& request,
      Options opts = {});

  // clang-format off
  ///
  /// Deletes the breakpoint from the debuggee.
  ///
  /// @param debuggee_id  Required. ID of the debuggee whose breakpoint to delete.
  /// @param breakpoint_id  Required. ID of the breakpoint to delete.
  /// @param client_version  Required. The client version making the call.
  ///  Schema: `domain/type/version` (e.g., `google.com/intellij/v1`).
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return a [`Status`] object. If the request failed, the
  ///     status contains the details of the failure.
  ///
  /// [Protobuf mapping rules]: https://protobuf.dev/reference/cpp/cpp-generated/
  /// [input iterator requirements]: https://en.cppreference.com/w/cpp/named_req/InputIterator
  /// [Long Running Operation]: https://google.aip.dev/151
  /// [`std::string`]: https://en.cppreference.com/w/cpp/string/basic_string
  /// [`future`]: @ref google::cloud::future
  /// [`StatusOr`]: @ref google::cloud::StatusOr
  /// [`Status`]: @ref google::cloud::Status
  /// [google.devtools.clouddebugger.v2.DeleteBreakpointRequest]: @googleapis_reference_link{google/devtools/clouddebugger/v2/debugger.proto#L136}
  ///
  // clang-format on
  Status DeleteBreakpoint(std::string const& debuggee_id,
                          std::string const& breakpoint_id,
                          std::string const& client_version, Options opts = {});

  // clang-format off
  ///
  /// Deletes the breakpoint from the debuggee.
  ///
  /// @param request Unary RPCs, such as the one wrapped by this
  ///     function, receive a single `request` proto message which includes all
  ///     the inputs for the RPC. In this case, the proto message is a
  ///     [google.devtools.clouddebugger.v2.DeleteBreakpointRequest].
  ///     Proto messages are converted to C++ classes by Protobuf, using the
  ///     [Protobuf mapping rules].
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return a [`Status`] object. If the request failed, the
  ///     status contains the details of the failure.
  ///
  /// [Protobuf mapping rules]: https://protobuf.dev/reference/cpp/cpp-generated/
  /// [input iterator requirements]: https://en.cppreference.com/w/cpp/named_req/InputIterator
  /// [Long Running Operation]: https://google.aip.dev/151
  /// [`std::string`]: https://en.cppreference.com/w/cpp/string/basic_string
  /// [`future`]: @ref google::cloud::future
  /// [`StatusOr`]: @ref google::cloud::StatusOr
  /// [`Status`]: @ref google::cloud::Status
  /// [google.devtools.clouddebugger.v2.DeleteBreakpointRequest]: @googleapis_reference_link{google/devtools/clouddebugger/v2/debugger.proto#L136}
  ///
  // clang-format on
  Status DeleteBreakpoint(
      google::devtools::clouddebugger::v2::DeleteBreakpointRequest const&
          request,
      Options opts = {});

  // clang-format off
  ///
  /// Lists all breakpoints for the debuggee.
  ///
  /// @param debuggee_id  Required. ID of the debuggee whose breakpoints to list.
  /// @param client_version  Required. The client version making the call.
  ///  Schema: `domain/type/version` (e.g., `google.com/intellij/v1`).
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return the result of the RPC. The response message type
  ///     ([google.devtools.clouddebugger.v2.ListBreakpointsResponse])
  ///     is mapped to a C++ class using the [Protobuf mapping rules].
  ///     If the request fails, the [`StatusOr`] contains the error details.
  ///
  /// [Protobuf mapping rules]: https://protobuf.dev/reference/cpp/cpp-generated/
  /// [input iterator requirements]: https://en.cppreference.com/w/cpp/named_req/InputIterator
  /// [Long Running Operation]: https://google.aip.dev/151
  /// [`std::string`]: https://en.cppreference.com/w/cpp/string/basic_string
  /// [`future`]: @ref google::cloud::future
  /// [`StatusOr`]: @ref google::cloud::StatusOr
  /// [`Status`]: @ref google::cloud::Status
  /// [google.devtools.clouddebugger.v2.ListBreakpointsRequest]: @googleapis_reference_link{google/devtools/clouddebugger/v2/debugger.proto#L149}
  /// [google.devtools.clouddebugger.v2.ListBreakpointsResponse]: @googleapis_reference_link{google/devtools/clouddebugger/v2/debugger.proto#L188}
  ///
  // clang-format on
  StatusOr<google::devtools::clouddebugger::v2::ListBreakpointsResponse>
  ListBreakpoints(std::string const& debuggee_id,
                  std::string const& client_version, Options opts = {});

  // clang-format off
  ///
  /// Lists all breakpoints for the debuggee.
  ///
  /// @param request Unary RPCs, such as the one wrapped by this
  ///     function, receive a single `request` proto message which includes all
  ///     the inputs for the RPC. In this case, the proto message is a
  ///     [google.devtools.clouddebugger.v2.ListBreakpointsRequest].
  ///     Proto messages are converted to C++ classes by Protobuf, using the
  ///     [Protobuf mapping rules].
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return the result of the RPC. The response message type
  ///     ([google.devtools.clouddebugger.v2.ListBreakpointsResponse])
  ///     is mapped to a C++ class using the [Protobuf mapping rules].
  ///     If the request fails, the [`StatusOr`] contains the error details.
  ///
  /// [Protobuf mapping rules]: https://protobuf.dev/reference/cpp/cpp-generated/
  /// [input iterator requirements]: https://en.cppreference.com/w/cpp/named_req/InputIterator
  /// [Long Running Operation]: https://google.aip.dev/151
  /// [`std::string`]: https://en.cppreference.com/w/cpp/string/basic_string
  /// [`future`]: @ref google::cloud::future
  /// [`StatusOr`]: @ref google::cloud::StatusOr
  /// [`Status`]: @ref google::cloud::Status
  /// [google.devtools.clouddebugger.v2.ListBreakpointsRequest]: @googleapis_reference_link{google/devtools/clouddebugger/v2/debugger.proto#L149}
  /// [google.devtools.clouddebugger.v2.ListBreakpointsResponse]: @googleapis_reference_link{google/devtools/clouddebugger/v2/debugger.proto#L188}
  ///
  // clang-format on
  StatusOr<google::devtools::clouddebugger::v2::ListBreakpointsResponse>
  ListBreakpoints(
      google::devtools::clouddebugger::v2::ListBreakpointsRequest const&
          request,
      Options opts = {});

  // clang-format off
  ///
  /// Lists all the debuggees that the user has access to.
  ///
  /// @param project  Required. Project number of a Google Cloud project whose debuggees to list.
  /// @param client_version  Required. The client version making the call.
  ///  Schema: `domain/type/version` (e.g., `google.com/intellij/v1`).
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return the result of the RPC. The response message type
  ///     ([google.devtools.clouddebugger.v2.ListDebuggeesResponse])
  ///     is mapped to a C++ class using the [Protobuf mapping rules].
  ///     If the request fails, the [`StatusOr`] contains the error details.
  ///
  /// [Protobuf mapping rules]: https://protobuf.dev/reference/cpp/cpp-generated/
  /// [input iterator requirements]: https://en.cppreference.com/w/cpp/named_req/InputIterator
  /// [Long Running Operation]: https://google.aip.dev/151
  /// [`std::string`]: https://en.cppreference.com/w/cpp/string/basic_string
  /// [`future`]: @ref google::cloud::future
  /// [`StatusOr`]: @ref google::cloud::StatusOr
  /// [`Status`]: @ref google::cloud::Status
  /// [google.devtools.clouddebugger.v2.ListDebuggeesRequest]: @googleapis_reference_link{google/devtools/clouddebugger/v2/debugger.proto#L201}
  /// [google.devtools.clouddebugger.v2.ListDebuggeesResponse]: @googleapis_reference_link{google/devtools/clouddebugger/v2/debugger.proto#L215}
  ///
  // clang-format on
  StatusOr<google::devtools::clouddebugger::v2::ListDebuggeesResponse>
  ListDebuggees(std::string const& project, std::string const& client_version,
                Options opts = {});

  // clang-format off
  ///
  /// Lists all the debuggees that the user has access to.
  ///
  /// @param request Unary RPCs, such as the one wrapped by this
  ///     function, receive a single `request` proto message which includes all
  ///     the inputs for the RPC. In this case, the proto message is a
  ///     [google.devtools.clouddebugger.v2.ListDebuggeesRequest].
  ///     Proto messages are converted to C++ classes by Protobuf, using the
  ///     [Protobuf mapping rules].
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return the result of the RPC. The response message type
  ///     ([google.devtools.clouddebugger.v2.ListDebuggeesResponse])
  ///     is mapped to a C++ class using the [Protobuf mapping rules].
  ///     If the request fails, the [`StatusOr`] contains the error details.
  ///
  /// [Protobuf mapping rules]: https://protobuf.dev/reference/cpp/cpp-generated/
  /// [input iterator requirements]: https://en.cppreference.com/w/cpp/named_req/InputIterator
  /// [Long Running Operation]: https://google.aip.dev/151
  /// [`std::string`]: https://en.cppreference.com/w/cpp/string/basic_string
  /// [`future`]: @ref google::cloud::future
  /// [`StatusOr`]: @ref google::cloud::StatusOr
  /// [`Status`]: @ref google::cloud::Status
  /// [google.devtools.clouddebugger.v2.ListDebuggeesRequest]: @googleapis_reference_link{google/devtools/clouddebugger/v2/debugger.proto#L201}
  /// [google.devtools.clouddebugger.v2.ListDebuggeesResponse]: @googleapis_reference_link{google/devtools/clouddebugger/v2/debugger.proto#L215}
  ///
  // clang-format on
  StatusOr<google::devtools::clouddebugger::v2::ListDebuggeesResponse>
  ListDebuggees(
      google::devtools::clouddebugger::v2::ListDebuggeesRequest const& request,
      Options opts = {});

 private:
  std::shared_ptr<Debugger2Connection> connection_;
  Options options_;
};

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace debugger_v2
}  // namespace cloud
}  // namespace google

#endif  // GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_DEBUGGER_V2_DEBUGGER2_CLIENT_H
