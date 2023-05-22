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
// source: google/cloud/sql/v1/cloud_sql_connect.proto

#ifndef GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_SQL_V1_SQL_CONNECT_CLIENT_H
#define GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_SQL_V1_SQL_CONNECT_CLIENT_H

#include "google/cloud/sql/v1/sql_connect_rest_connection.h"
#include "google/cloud/experimental_tag.h"
#include "google/cloud/future.h"
#include "google/cloud/options.h"
#include "google/cloud/polling_policy.h"
#include "google/cloud/status_or.h"
#include "google/cloud/version.h"
#include <memory>

namespace google {
namespace cloud {
namespace sql_v1 {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

///
/// Cloud SQL connect service.
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
class SqlConnectServiceClient {
 public:
  explicit SqlConnectServiceClient(
      ExperimentalTag, std::shared_ptr<SqlConnectServiceConnection> connection,
      Options opts = {});
  ~SqlConnectServiceClient();

  ///@{
  /// @name Copy and move support
  SqlConnectServiceClient(SqlConnectServiceClient const&) = default;
  SqlConnectServiceClient& operator=(SqlConnectServiceClient const&) = default;
  SqlConnectServiceClient(SqlConnectServiceClient&&) = default;
  SqlConnectServiceClient& operator=(SqlConnectServiceClient&&) = default;
  ///@}

  ///@{
  /// @name Equality
  friend bool operator==(SqlConnectServiceClient const& a,
                         SqlConnectServiceClient const& b) {
    return a.connection_ == b.connection_;
  }
  friend bool operator!=(SqlConnectServiceClient const& a,
                         SqlConnectServiceClient const& b) {
    return !(a == b);
  }
  ///@}

  // clang-format off
  ///
  /// Retrieves connect settings about a Cloud SQL instance.
  ///
  /// @param request Unary RPCs, such as the one wrapped by this
  ///     function, receive a single `request` proto message which includes all
  ///     the inputs for the RPC. In this case, the proto message is a
  ///     [google.cloud.sql.v1.GetConnectSettingsRequest].
  ///     Proto messages are converted to C++ classes by Protobuf, using the
  ///     [Protobuf mapping rules].
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return the result of the RPC. The response message type
  ///     ([google.cloud.sql.v1.ConnectSettings])
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
  /// [google.cloud.sql.v1.ConnectSettings]: @googleapis_reference_link{google/cloud/sql/v1/cloud_sql_connect.proto#L71}
  /// [google.cloud.sql.v1.GetConnectSettingsRequest]: @googleapis_reference_link{google/cloud/sql/v1/cloud_sql_connect.proto#L59}
  ///
  // clang-format on
  StatusOr<google::cloud::sql::v1::ConnectSettings> GetConnectSettings(
      google::cloud::sql::v1::GetConnectSettingsRequest const& request,
      Options opts = {});

  // clang-format off
  ///
  /// Generates a short-lived X509 certificate containing the provided public key
  /// and signed by a private key specific to the target instance. Users may use
  /// the certificate to authenticate as themselves when connecting to the
  /// database.
  ///
  /// @param request Unary RPCs, such as the one wrapped by this
  ///     function, receive a single `request` proto message which includes all
  ///     the inputs for the RPC. In this case, the proto message is a
  ///     [google.cloud.sql.v1.GenerateEphemeralCertRequest].
  ///     Proto messages are converted to C++ classes by Protobuf, using the
  ///     [Protobuf mapping rules].
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return the result of the RPC. The response message type
  ///     ([google.cloud.sql.v1.GenerateEphemeralCertResponse])
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
  /// [google.cloud.sql.v1.GenerateEphemeralCertRequest]: @googleapis_reference_link{google/cloud/sql/v1/cloud_sql_connect.proto#L104}
  /// [google.cloud.sql.v1.GenerateEphemeralCertResponse]: @googleapis_reference_link{google/cloud/sql/v1/cloud_sql_connect.proto#L122}
  ///
  // clang-format on
  StatusOr<google::cloud::sql::v1::GenerateEphemeralCertResponse>
  GenerateEphemeralCert(
      google::cloud::sql::v1::GenerateEphemeralCertRequest const& request,
      Options opts = {});

 private:
  std::shared_ptr<SqlConnectServiceConnection> connection_;
  Options options_;
};

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace sql_v1
}  // namespace cloud
}  // namespace google

#endif  // GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_SQL_V1_SQL_CONNECT_CLIENT_H
