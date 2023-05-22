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
// source: google/devtools/cloudprofiler/v2/profiler.proto

#ifndef GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_PROFILER_V2_PROFILER_CLIENT_H
#define GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_PROFILER_V2_PROFILER_CLIENT_H

#include "google/cloud/profiler/v2/profiler_connection.h"
#include "google/cloud/future.h"
#include "google/cloud/options.h"
#include "google/cloud/polling_policy.h"
#include "google/cloud/status_or.h"
#include "google/cloud/version.h"
#include <map>
#include <memory>

namespace google {
namespace cloud {
namespace profiler_v2 {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

///
/// Manage the collection of continuous profiling data provided by profiling
/// agents running in the cloud or by an offline provider of profiling data.
///
/// General guidelines:
/// * Profiles for a single deployment must be created in ascending time order.
/// * Profiles can be created in either online or offline mode, see below.
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
class ProfilerServiceClient {
 public:
  explicit ProfilerServiceClient(
      std::shared_ptr<ProfilerServiceConnection> connection, Options opts = {});
  ~ProfilerServiceClient();

  ///@{
  /// @name Copy and move support
  ProfilerServiceClient(ProfilerServiceClient const&) = default;
  ProfilerServiceClient& operator=(ProfilerServiceClient const&) = default;
  ProfilerServiceClient(ProfilerServiceClient&&) = default;
  ProfilerServiceClient& operator=(ProfilerServiceClient&&) = default;
  ///@}

  ///@{
  /// @name Equality
  friend bool operator==(ProfilerServiceClient const& a,
                         ProfilerServiceClient const& b) {
    return a.connection_ == b.connection_;
  }
  friend bool operator!=(ProfilerServiceClient const& a,
                         ProfilerServiceClient const& b) {
    return !(a == b);
  }
  ///@}

  // clang-format off
  ///
  /// CreateProfile creates a new profile resource in the online mode.
  ///
  /// The server ensures that the new profiles are created at a constant rate per
  /// deployment, so the creation request may hang for some time until the next
  /// profile session is available.
  ///
  /// The request may fail with ABORTED error if the creation is not available
  /// within ~1m, the response will indicate the duration of the backoff the
  /// client should take before attempting creating a profile again. The backoff
  /// duration is returned in google.rpc.RetryInfo extension on the response
  /// status. To a gRPC client, the extension will be return as a
  /// binary-serialized proto in the trailing metadata item named
  /// "google.rpc.retryinfo-bin".
  ///
  ///
  /// @param request Unary RPCs, such as the one wrapped by this
  ///     function, receive a single `request` proto message which includes all
  ///     the inputs for the RPC. In this case, the proto message is a
  ///     [google.devtools.cloudprofiler.v2.CreateProfileRequest].
  ///     Proto messages are converted to C++ classes by Protobuf, using the
  ///     [Protobuf mapping rules].
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return the result of the RPC. The response message type
  ///     ([google.devtools.cloudprofiler.v2.Profile])
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
  /// [google.devtools.cloudprofiler.v2.CreateProfileRequest]: @googleapis_reference_link{google/devtools/cloudprofiler/v2/profiler.proto#L97}
  /// [google.devtools.cloudprofiler.v2.Profile]: @googleapis_reference_link{google/devtools/cloudprofiler/v2/profiler.proto#L135}
  ///
  // clang-format on
  StatusOr<google::devtools::cloudprofiler::v2::Profile> CreateProfile(
      google::devtools::cloudprofiler::v2::CreateProfileRequest const& request,
      Options opts = {});

  // clang-format off
  ///
  /// CreateOfflineProfile creates a new profile resource in the offline mode.
  /// The client provides the profile to create along with the profile bytes, the
  /// server records it.
  ///
  /// @param parent  Parent project to create the profile in.
  /// @param profile  Contents of the profile to create.
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return the result of the RPC. The response message type
  ///     ([google.devtools.cloudprofiler.v2.Profile])
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
  /// [google.devtools.cloudprofiler.v2.CreateOfflineProfileRequest]: @googleapis_reference_link{google/devtools/cloudprofiler/v2/profiler.proto#L112}
  /// [google.devtools.cloudprofiler.v2.Profile]: @googleapis_reference_link{google/devtools/cloudprofiler/v2/profiler.proto#L135}
  ///
  // clang-format on
  StatusOr<google::devtools::cloudprofiler::v2::Profile> CreateOfflineProfile(
      std::string const& parent,
      google::devtools::cloudprofiler::v2::Profile const& profile,
      Options opts = {});

  // clang-format off
  ///
  /// CreateOfflineProfile creates a new profile resource in the offline mode.
  /// The client provides the profile to create along with the profile bytes, the
  /// server records it.
  ///
  /// @param request Unary RPCs, such as the one wrapped by this
  ///     function, receive a single `request` proto message which includes all
  ///     the inputs for the RPC. In this case, the proto message is a
  ///     [google.devtools.cloudprofiler.v2.CreateOfflineProfileRequest].
  ///     Proto messages are converted to C++ classes by Protobuf, using the
  ///     [Protobuf mapping rules].
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return the result of the RPC. The response message type
  ///     ([google.devtools.cloudprofiler.v2.Profile])
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
  /// [google.devtools.cloudprofiler.v2.CreateOfflineProfileRequest]: @googleapis_reference_link{google/devtools/cloudprofiler/v2/profiler.proto#L112}
  /// [google.devtools.cloudprofiler.v2.Profile]: @googleapis_reference_link{google/devtools/cloudprofiler/v2/profiler.proto#L135}
  ///
  // clang-format on
  StatusOr<google::devtools::cloudprofiler::v2::Profile> CreateOfflineProfile(
      google::devtools::cloudprofiler::v2::CreateOfflineProfileRequest const&
          request,
      Options opts = {});

  // clang-format off
  ///
  /// UpdateProfile updates the profile bytes and labels on the profile resource
  /// created in the online mode. Updating the bytes for profiles created in the
  /// offline mode is currently not supported: the profile content must be
  /// provided at the time of the profile creation.
  ///
  /// @param profile  Profile to update.
  /// @param update_mask  Field mask used to specify the fields to be overwritten. Currently only
  ///  profile_bytes and labels fields are supported by UpdateProfile, so only
  ///  those fields can be specified in the mask. When no mask is provided, all
  ///  fields are overwritten.
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return the result of the RPC. The response message type
  ///     ([google.devtools.cloudprofiler.v2.Profile])
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
  /// [google.devtools.cloudprofiler.v2.Profile]: @googleapis_reference_link{google/devtools/cloudprofiler/v2/profiler.proto#L135}
  /// [google.devtools.cloudprofiler.v2.UpdateProfileRequest]: @googleapis_reference_link{google/devtools/cloudprofiler/v2/profiler.proto#L123}
  ///
  // clang-format on
  StatusOr<google::devtools::cloudprofiler::v2::Profile> UpdateProfile(
      google::devtools::cloudprofiler::v2::Profile const& profile,
      google::protobuf::FieldMask const& update_mask, Options opts = {});

  // clang-format off
  ///
  /// UpdateProfile updates the profile bytes and labels on the profile resource
  /// created in the online mode. Updating the bytes for profiles created in the
  /// offline mode is currently not supported: the profile content must be
  /// provided at the time of the profile creation.
  ///
  /// @param request Unary RPCs, such as the one wrapped by this
  ///     function, receive a single `request` proto message which includes all
  ///     the inputs for the RPC. In this case, the proto message is a
  ///     [google.devtools.cloudprofiler.v2.UpdateProfileRequest].
  ///     Proto messages are converted to C++ classes by Protobuf, using the
  ///     [Protobuf mapping rules].
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return the result of the RPC. The response message type
  ///     ([google.devtools.cloudprofiler.v2.Profile])
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
  /// [google.devtools.cloudprofiler.v2.Profile]: @googleapis_reference_link{google/devtools/cloudprofiler/v2/profiler.proto#L135}
  /// [google.devtools.cloudprofiler.v2.UpdateProfileRequest]: @googleapis_reference_link{google/devtools/cloudprofiler/v2/profiler.proto#L123}
  ///
  // clang-format on
  StatusOr<google::devtools::cloudprofiler::v2::Profile> UpdateProfile(
      google::devtools::cloudprofiler::v2::UpdateProfileRequest const& request,
      Options opts = {});

 private:
  std::shared_ptr<ProfilerServiceConnection> connection_;
  Options options_;
};

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace profiler_v2
}  // namespace cloud
}  // namespace google

#endif  // GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_PROFILER_V2_PROFILER_CLIENT_H
