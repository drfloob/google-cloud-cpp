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

#ifndef GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_IAP_V1_IDENTITY_AWARE_PROXY_O_AUTH_CLIENT_H
#define GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_IAP_V1_IDENTITY_AWARE_PROXY_O_AUTH_CLIENT_H

#include "google/cloud/iap/v1/identity_aware_proxy_o_auth_connection.h"
#include "google/cloud/future.h"
#include "google/cloud/options.h"
#include "google/cloud/polling_policy.h"
#include "google/cloud/status_or.h"
#include "google/cloud/version.h"
#include <memory>

namespace google {
namespace cloud {
namespace iap_v1 {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

///
/// API to programmatically create, list and retrieve Identity Aware Proxy (IAP)
/// OAuth brands; and create, retrieve, delete and reset-secret of IAP OAuth
/// clients.
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
class IdentityAwareProxyOAuthServiceClient {
 public:
  explicit IdentityAwareProxyOAuthServiceClient(
      std::shared_ptr<IdentityAwareProxyOAuthServiceConnection> connection,
      Options opts = {});
  ~IdentityAwareProxyOAuthServiceClient();

  ///@{
  /// @name Copy and move support
  IdentityAwareProxyOAuthServiceClient(
      IdentityAwareProxyOAuthServiceClient const&) = default;
  IdentityAwareProxyOAuthServiceClient& operator=(
      IdentityAwareProxyOAuthServiceClient const&) = default;
  IdentityAwareProxyOAuthServiceClient(IdentityAwareProxyOAuthServiceClient&&) =
      default;
  IdentityAwareProxyOAuthServiceClient& operator=(
      IdentityAwareProxyOAuthServiceClient&&) = default;
  ///@}

  ///@{
  /// @name Equality
  friend bool operator==(IdentityAwareProxyOAuthServiceClient const& a,
                         IdentityAwareProxyOAuthServiceClient const& b) {
    return a.connection_ == b.connection_;
  }
  friend bool operator!=(IdentityAwareProxyOAuthServiceClient const& a,
                         IdentityAwareProxyOAuthServiceClient const& b) {
    return !(a == b);
  }
  ///@}

  // clang-format off
  ///
  /// Lists the existing brands for the project.
  ///
  /// @param request Unary RPCs, such as the one wrapped by this
  ///     function, receive a single `request` proto message which includes all
  ///     the inputs for the RPC. In this case, the proto message is a
  ///     [google.cloud.iap.v1.ListBrandsRequest].
  ///     Proto messages are converted to C++ classes by Protobuf, using the
  ///     [Protobuf mapping rules].
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return the result of the RPC. The response message type
  ///     ([google.cloud.iap.v1.ListBrandsResponse])
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
  /// [google.cloud.iap.v1.ListBrandsRequest]: @googleapis_reference_link{google/cloud/iap/v1/service.proto#L610}
  /// [google.cloud.iap.v1.ListBrandsResponse]: @googleapis_reference_link{google/cloud/iap/v1/service.proto#L617}
  ///
  // clang-format on
  StatusOr<google::cloud::iap::v1::ListBrandsResponse> ListBrands(
      google::cloud::iap::v1::ListBrandsRequest const& request,
      Options opts = {});

  // clang-format off
  ///
  /// Constructs a new OAuth brand for the project if one does not exist.
  /// The created brand is "internal only", meaning that OAuth clients created
  /// under it only accept requests from users who belong to the same Google
  /// Workspace organization as the project. The brand is created in an
  /// un-reviewed status. NOTE: The "internal only" status can be manually
  /// changed in the Google Cloud Console. Requires that a brand does not already
  /// exist for the project, and that the specified support email is owned by the
  /// caller.
  ///
  /// @param request Unary RPCs, such as the one wrapped by this
  ///     function, receive a single `request` proto message which includes all
  ///     the inputs for the RPC. In this case, the proto message is a
  ///     [google.cloud.iap.v1.CreateBrandRequest].
  ///     Proto messages are converted to C++ classes by Protobuf, using the
  ///     [Protobuf mapping rules].
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return the result of the RPC. The response message type
  ///     ([google.cloud.iap.v1.Brand])
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
  /// [google.cloud.iap.v1.Brand]: @googleapis_reference_link{google/cloud/iap/v1/service.proto#L709}
  /// [google.cloud.iap.v1.CreateBrandRequest]: @googleapis_reference_link{google/cloud/iap/v1/service.proto#L623}
  ///
  // clang-format on
  StatusOr<google::cloud::iap::v1::Brand> CreateBrand(
      google::cloud::iap::v1::CreateBrandRequest const& request,
      Options opts = {});

  // clang-format off
  ///
  /// Retrieves the OAuth brand of the project.
  ///
  /// @param request Unary RPCs, such as the one wrapped by this
  ///     function, receive a single `request` proto message which includes all
  ///     the inputs for the RPC. In this case, the proto message is a
  ///     [google.cloud.iap.v1.GetBrandRequest].
  ///     Proto messages are converted to C++ classes by Protobuf, using the
  ///     [Protobuf mapping rules].
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return the result of the RPC. The response message type
  ///     ([google.cloud.iap.v1.Brand])
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
  /// [google.cloud.iap.v1.Brand]: @googleapis_reference_link{google/cloud/iap/v1/service.proto#L709}
  /// [google.cloud.iap.v1.GetBrandRequest]: @googleapis_reference_link{google/cloud/iap/v1/service.proto#L633}
  ///
  // clang-format on
  StatusOr<google::cloud::iap::v1::Brand> GetBrand(
      google::cloud::iap::v1::GetBrandRequest const& request,
      Options opts = {});

  // clang-format off
  ///
  /// Creates an Identity Aware Proxy (IAP) OAuth client. The client is owned
  /// by IAP. Requires that the brand for the project exists and that it is
  /// set for internal-only use.
  ///
  /// @param request Unary RPCs, such as the one wrapped by this
  ///     function, receive a single `request` proto message which includes all
  ///     the inputs for the RPC. In this case, the proto message is a
  ///     [google.cloud.iap.v1.CreateIdentityAwareProxyClientRequest].
  ///     Proto messages are converted to C++ classes by Protobuf, using the
  ///     [Protobuf mapping rules].
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return the result of the RPC. The response message type
  ///     ([google.cloud.iap.v1.IdentityAwareProxyClient])
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
  /// [google.cloud.iap.v1.CreateIdentityAwareProxyClientRequest]: @googleapis_reference_link{google/cloud/iap/v1/service.proto#L671}
  /// [google.cloud.iap.v1.IdentityAwareProxyClient]: @googleapis_reference_link{google/cloud/iap/v1/service.proto#L727}
  ///
  // clang-format on
  StatusOr<google::cloud::iap::v1::IdentityAwareProxyClient>
  CreateIdentityAwareProxyClient(
      google::cloud::iap::v1::CreateIdentityAwareProxyClientRequest const&
          request,
      Options opts = {});

  // clang-format off
  ///
  /// Lists the existing clients for the brand.
  ///
  /// @param request Unary RPCs, such as the one wrapped by this
  ///     function, receive a single `request` proto message which includes all
  ///     the inputs for the RPC. In this case, the proto message is a
  ///     [google.cloud.iap.v1.ListIdentityAwareProxyClientsRequest].
  ///     Proto messages are converted to C++ classes by Protobuf, using the
  ///     [Protobuf mapping rules].
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return a [StreamRange](@ref google::cloud::StreamRange)
  ///     to iterate of the results. See the documentation of this type for
  ///     details. In brief, this class has `begin()` and `end()` member
  ///     functions returning a iterator class meeting the
  ///     [input iterator requirements]. The value type for this iterator is a
  ///     [`StatusOr`] as the iteration may fail even after some values are
  ///     retrieved successfully, for example, if there is a network disconnect.
  ///     An empty set of results does not indicate an error, it indicates
  ///     that there are no resources meeting the request criteria.
  ///     On a successful iteration the `StatusOr<T>` contains elements of type
  ///     [google.cloud.iap.v1.IdentityAwareProxyClient], or rather,
  ///     the C++ class generated by Protobuf from that type. Please consult the
  ///     Protobuf documentation for details on the [Protobuf mapping rules].
  ///
  /// [Protobuf mapping rules]: https://protobuf.dev/reference/cpp/cpp-generated/
  /// [input iterator requirements]: https://en.cppreference.com/w/cpp/named_req/InputIterator
  /// [Long Running Operation]: https://google.aip.dev/151
  /// [`std::string`]: https://en.cppreference.com/w/cpp/string/basic_string
  /// [`future`]: @ref google::cloud::future
  /// [`StatusOr`]: @ref google::cloud::StatusOr
  /// [`Status`]: @ref google::cloud::Status
  /// [google.cloud.iap.v1.IdentityAwareProxyClient]: @googleapis_reference_link{google/cloud/iap/v1/service.proto#L727}
  /// [google.cloud.iap.v1.ListIdentityAwareProxyClientsRequest]: @googleapis_reference_link{google/cloud/iap/v1/service.proto#L640}
  ///
  // clang-format on
  StreamRange<google::cloud::iap::v1::IdentityAwareProxyClient>
  ListIdentityAwareProxyClients(
      google::cloud::iap::v1::ListIdentityAwareProxyClientsRequest request,
      Options opts = {});

  // clang-format off
  ///
  /// Retrieves an Identity Aware Proxy (IAP) OAuth client.
  /// Requires that the client is owned by IAP.
  ///
  /// @param request Unary RPCs, such as the one wrapped by this
  ///     function, receive a single `request` proto message which includes all
  ///     the inputs for the RPC. In this case, the proto message is a
  ///     [google.cloud.iap.v1.GetIdentityAwareProxyClientRequest].
  ///     Proto messages are converted to C++ classes by Protobuf, using the
  ///     [Protobuf mapping rules].
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return the result of the RPC. The response message type
  ///     ([google.cloud.iap.v1.IdentityAwareProxyClient])
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
  /// [google.cloud.iap.v1.GetIdentityAwareProxyClientRequest]: @googleapis_reference_link{google/cloud/iap/v1/service.proto#L684}
  /// [google.cloud.iap.v1.IdentityAwareProxyClient]: @googleapis_reference_link{google/cloud/iap/v1/service.proto#L727}
  ///
  // clang-format on
  StatusOr<google::cloud::iap::v1::IdentityAwareProxyClient>
  GetIdentityAwareProxyClient(
      google::cloud::iap::v1::GetIdentityAwareProxyClientRequest const& request,
      Options opts = {});

  // clang-format off
  ///
  /// Resets an Identity Aware Proxy (IAP) OAuth client secret. Useful if the
  /// secret was compromised. Requires that the client is owned by IAP.
  ///
  /// @param request Unary RPCs, such as the one wrapped by this
  ///     function, receive a single `request` proto message which includes all
  ///     the inputs for the RPC. In this case, the proto message is a
  ///     [google.cloud.iap.v1.ResetIdentityAwareProxyClientSecretRequest].
  ///     Proto messages are converted to C++ classes by Protobuf, using the
  ///     [Protobuf mapping rules].
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return the result of the RPC. The response message type
  ///     ([google.cloud.iap.v1.IdentityAwareProxyClient])
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
  /// [google.cloud.iap.v1.IdentityAwareProxyClient]: @googleapis_reference_link{google/cloud/iap/v1/service.proto#L727}
  /// [google.cloud.iap.v1.ResetIdentityAwareProxyClientSecretRequest]: @googleapis_reference_link{google/cloud/iap/v1/service.proto#L692}
  ///
  // clang-format on
  StatusOr<google::cloud::iap::v1::IdentityAwareProxyClient>
  ResetIdentityAwareProxyClientSecret(
      google::cloud::iap::v1::ResetIdentityAwareProxyClientSecretRequest const&
          request,
      Options opts = {});

  // clang-format off
  ///
  /// Deletes an Identity Aware Proxy (IAP) OAuth client. Useful for removing
  /// obsolete clients, managing the number of clients in a given project, and
  /// cleaning up after tests. Requires that the client is owned by IAP.
  ///
  /// @param request Unary RPCs, such as the one wrapped by this
  ///     function, receive a single `request` proto message which includes all
  ///     the inputs for the RPC. In this case, the proto message is a
  ///     [google.cloud.iap.v1.DeleteIdentityAwareProxyClientRequest].
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
  /// [google.cloud.iap.v1.DeleteIdentityAwareProxyClientRequest]: @googleapis_reference_link{google/cloud/iap/v1/service.proto#L700}
  ///
  // clang-format on
  Status DeleteIdentityAwareProxyClient(
      google::cloud::iap::v1::DeleteIdentityAwareProxyClientRequest const&
          request,
      Options opts = {});

 private:
  std::shared_ptr<IdentityAwareProxyOAuthServiceConnection> connection_;
  Options options_;
};

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace iap_v1
}  // namespace cloud
}  // namespace google

#endif  // GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_IAP_V1_IDENTITY_AWARE_PROXY_O_AUTH_CLIENT_H
