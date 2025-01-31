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
// source: google/cloud/support/v2/case_service.proto

#ifndef GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_SUPPORT_V2_CASE_CLIENT_H
#define GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_SUPPORT_V2_CASE_CLIENT_H

#include "google/cloud/support/v2/case_connection.h"
#include "google/cloud/future.h"
#include "google/cloud/options.h"
#include "google/cloud/polling_policy.h"
#include "google/cloud/status_or.h"
#include "google/cloud/version.h"
#include <memory>

namespace google {
namespace cloud {
namespace support_v2 {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

///
/// A service to manage Google Cloud support cases.
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
class CaseServiceClient {
 public:
  explicit CaseServiceClient(std::shared_ptr<CaseServiceConnection> connection,
                             Options opts = {});
  ~CaseServiceClient();

  ///@{
  /// @name Copy and move support
  CaseServiceClient(CaseServiceClient const&) = default;
  CaseServiceClient& operator=(CaseServiceClient const&) = default;
  CaseServiceClient(CaseServiceClient&&) = default;
  CaseServiceClient& operator=(CaseServiceClient&&) = default;
  ///@}

  ///@{
  /// @name Equality
  friend bool operator==(CaseServiceClient const& a,
                         CaseServiceClient const& b) {
    return a.connection_ == b.connection_;
  }
  friend bool operator!=(CaseServiceClient const& a,
                         CaseServiceClient const& b) {
    return !(a == b);
  }
  ///@}

  // clang-format off
  ///
  /// Retrieve the specified case.
  ///
  /// @param name  Required. The fully qualified name of a case to be retrieved.
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return the result of the RPC. The response message type
  ///     ([google.cloud.support.v2.Case])
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
  /// [google.cloud.support.v2.Case]: @googleapis_reference_link{google/cloud/support/v2/case.proto#L33}
  /// [google.cloud.support.v2.GetCaseRequest]: @googleapis_reference_link{google/cloud/support/v2/case_service.proto#L143}
  ///
  // clang-format on
  StatusOr<google::cloud::support::v2::Case> GetCase(std::string const& name,
                                                     Options opts = {});

  // clang-format off
  ///
  /// Retrieve the specified case.
  ///
  /// @param request Unary RPCs, such as the one wrapped by this
  ///     function, receive a single `request` proto message which includes all
  ///     the inputs for the RPC. In this case, the proto message is a
  ///     [google.cloud.support.v2.GetCaseRequest].
  ///     Proto messages are converted to C++ classes by Protobuf, using the
  ///     [Protobuf mapping rules].
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return the result of the RPC. The response message type
  ///     ([google.cloud.support.v2.Case])
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
  /// [google.cloud.support.v2.Case]: @googleapis_reference_link{google/cloud/support/v2/case.proto#L33}
  /// [google.cloud.support.v2.GetCaseRequest]: @googleapis_reference_link{google/cloud/support/v2/case_service.proto#L143}
  ///
  // clang-format on
  StatusOr<google::cloud::support::v2::Case> GetCase(
      google::cloud::support::v2::GetCaseRequest const& request,
      Options opts = {});

  // clang-format off
  ///
  /// Retrieve all cases under the specified parent.
  ///
  /// Note: Listing cases under an Organization returns only the cases directly
  /// parented by that organization. To retrieve all cases under an organization,
  /// including cases parented by projects under that organization, use
  /// `cases.search`.
  ///
  /// @param parent  Required. The fully qualified name of parent resource to list cases under.
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
  ///     [google.cloud.support.v2.Case], or rather,
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
  /// [google.cloud.support.v2.Case]: @googleapis_reference_link{google/cloud/support/v2/case.proto#L33}
  /// [google.cloud.support.v2.ListCasesRequest]: @googleapis_reference_link{google/cloud/support/v2/case_service.proto#L169}
  ///
  // clang-format on
  StreamRange<google::cloud::support::v2::Case> ListCases(
      std::string const& parent, Options opts = {});

  // clang-format off
  ///
  /// Retrieve all cases under the specified parent.
  ///
  /// Note: Listing cases under an Organization returns only the cases directly
  /// parented by that organization. To retrieve all cases under an organization,
  /// including cases parented by projects under that organization, use
  /// `cases.search`.
  ///
  /// @param request Unary RPCs, such as the one wrapped by this
  ///     function, receive a single `request` proto message which includes all
  ///     the inputs for the RPC. In this case, the proto message is a
  ///     [google.cloud.support.v2.ListCasesRequest].
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
  ///     [google.cloud.support.v2.Case], or rather,
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
  /// [google.cloud.support.v2.Case]: @googleapis_reference_link{google/cloud/support/v2/case.proto#L33}
  /// [google.cloud.support.v2.ListCasesRequest]: @googleapis_reference_link{google/cloud/support/v2/case_service.proto#L169}
  ///
  // clang-format on
  StreamRange<google::cloud::support::v2::Case> ListCases(
      google::cloud::support::v2::ListCasesRequest request, Options opts = {});

  // clang-format off
  ///
  /// Search cases using the specified query.
  ///
  /// @param request Unary RPCs, such as the one wrapped by this
  ///     function, receive a single `request` proto message which includes all
  ///     the inputs for the RPC. In this case, the proto message is a
  ///     [google.cloud.support.v2.SearchCasesRequest].
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
  ///     [google.cloud.support.v2.Case], or rather,
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
  /// [google.cloud.support.v2.Case]: @googleapis_reference_link{google/cloud/support/v2/case.proto#L33}
  /// [google.cloud.support.v2.SearchCasesRequest]: @googleapis_reference_link{google/cloud/support/v2/case_service.proto#L218}
  ///
  // clang-format on
  StreamRange<google::cloud::support::v2::Case> SearchCases(
      google::cloud::support::v2::SearchCasesRequest request,
      Options opts = {});

  // clang-format off
  ///
  /// Create a new case and associate it with the given Google Cloud Resource.
  /// The case object must have the following fields set: `display_name`,
  /// `description`, `classification`, and `priority`.
  ///
  /// @param parent  Required. The name of the Google Cloud Resource under which the case should
  ///  be created.
  /// @param case_  Required. The case to be created.
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return the result of the RPC. The response message type
  ///     ([google.cloud.support.v2.Case])
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
  /// [google.cloud.support.v2.Case]: @googleapis_reference_link{google/cloud/support/v2/case.proto#L33}
  /// [google.cloud.support.v2.CreateCaseRequest]: @googleapis_reference_link{google/cloud/support/v2/case_service.proto#L154}
  ///
  // clang-format on
  StatusOr<google::cloud::support::v2::Case> CreateCase(
      std::string const& parent, google::cloud::support::v2::Case const& case_,
      Options opts = {});

  // clang-format off
  ///
  /// Create a new case and associate it with the given Google Cloud Resource.
  /// The case object must have the following fields set: `display_name`,
  /// `description`, `classification`, and `priority`.
  ///
  /// @param request Unary RPCs, such as the one wrapped by this
  ///     function, receive a single `request` proto message which includes all
  ///     the inputs for the RPC. In this case, the proto message is a
  ///     [google.cloud.support.v2.CreateCaseRequest].
  ///     Proto messages are converted to C++ classes by Protobuf, using the
  ///     [Protobuf mapping rules].
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return the result of the RPC. The response message type
  ///     ([google.cloud.support.v2.Case])
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
  /// [google.cloud.support.v2.Case]: @googleapis_reference_link{google/cloud/support/v2/case.proto#L33}
  /// [google.cloud.support.v2.CreateCaseRequest]: @googleapis_reference_link{google/cloud/support/v2/case_service.proto#L154}
  ///
  // clang-format on
  StatusOr<google::cloud::support::v2::Case> CreateCase(
      google::cloud::support::v2::CreateCaseRequest const& request,
      Options opts = {});

  // clang-format off
  ///
  /// Update the specified case. Only a subset of fields can be updated.
  ///
  /// @param case_  Required. The case object to update.
  /// @param update_mask  A list of attributes of the case object that should be updated
  ///  as part of this request. Supported values are `priority`, `display_name`,
  ///  and `subscriber_email_addresses`. If no fields are specified, all supported
  ///  fields are updated.
  ///  @n
  ///  WARNING: If you do not provide a field mask, then you might accidentally
  ///  clear some fields. For example, if you leave the field mask empty and do
  ///  not provide a value for `subscriber_email_addresses`, then
  ///  `subscriber_email_addresses` is updated to empty.
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return the result of the RPC. The response message type
  ///     ([google.cloud.support.v2.Case])
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
  /// [google.cloud.support.v2.Case]: @googleapis_reference_link{google/cloud/support/v2/case.proto#L33}
  /// [google.cloud.support.v2.UpdateCaseRequest]: @googleapis_reference_link{google/cloud/support/v2/case_service.proto#L295}
  ///
  // clang-format on
  StatusOr<google::cloud::support::v2::Case> UpdateCase(
      google::cloud::support::v2::Case const& case_,
      google::protobuf::FieldMask const& update_mask, Options opts = {});

  // clang-format off
  ///
  /// Update the specified case. Only a subset of fields can be updated.
  ///
  /// @param request Unary RPCs, such as the one wrapped by this
  ///     function, receive a single `request` proto message which includes all
  ///     the inputs for the RPC. In this case, the proto message is a
  ///     [google.cloud.support.v2.UpdateCaseRequest].
  ///     Proto messages are converted to C++ classes by Protobuf, using the
  ///     [Protobuf mapping rules].
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return the result of the RPC. The response message type
  ///     ([google.cloud.support.v2.Case])
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
  /// [google.cloud.support.v2.Case]: @googleapis_reference_link{google/cloud/support/v2/case.proto#L33}
  /// [google.cloud.support.v2.UpdateCaseRequest]: @googleapis_reference_link{google/cloud/support/v2/case_service.proto#L295}
  ///
  // clang-format on
  StatusOr<google::cloud::support::v2::Case> UpdateCase(
      google::cloud::support::v2::UpdateCaseRequest const& request,
      Options opts = {});

  // clang-format off
  ///
  /// Escalate a case. Escalating a case will initiate the Google Cloud Support
  /// escalation management process.
  ///
  /// This operation is only available to certain Customer Care tiers. Go to
  /// https://cloud.google.com/support and look for 'Technical support
  /// escalations' in the feature list to find out which tiers are able to
  /// perform escalations.
  ///
  /// @param request Unary RPCs, such as the one wrapped by this
  ///     function, receive a single `request` proto message which includes all
  ///     the inputs for the RPC. In this case, the proto message is a
  ///     [google.cloud.support.v2.EscalateCaseRequest].
  ///     Proto messages are converted to C++ classes by Protobuf, using the
  ///     [Protobuf mapping rules].
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return the result of the RPC. The response message type
  ///     ([google.cloud.support.v2.Case])
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
  /// [google.cloud.support.v2.Case]: @googleapis_reference_link{google/cloud/support/v2/case.proto#L33}
  /// [google.cloud.support.v2.EscalateCaseRequest]: @googleapis_reference_link{google/cloud/support/v2/case_service.proto#L281}
  ///
  // clang-format on
  StatusOr<google::cloud::support::v2::Case> EscalateCase(
      google::cloud::support::v2::EscalateCaseRequest const& request,
      Options opts = {});

  // clang-format off
  ///
  /// Close the specified case.
  ///
  /// @param request Unary RPCs, such as the one wrapped by this
  ///     function, receive a single `request` proto message which includes all
  ///     the inputs for the RPC. In this case, the proto message is a
  ///     [google.cloud.support.v2.CloseCaseRequest].
  ///     Proto messages are converted to C++ classes by Protobuf, using the
  ///     [Protobuf mapping rules].
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return the result of the RPC. The response message type
  ///     ([google.cloud.support.v2.Case])
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
  /// [google.cloud.support.v2.Case]: @googleapis_reference_link{google/cloud/support/v2/case.proto#L33}
  /// [google.cloud.support.v2.CloseCaseRequest]: @googleapis_reference_link{google/cloud/support/v2/case_service.proto#L312}
  ///
  // clang-format on
  StatusOr<google::cloud::support::v2::Case> CloseCase(
      google::cloud::support::v2::CloseCaseRequest const& request,
      Options opts = {});

  // clang-format off
  ///
  /// Retrieve valid classifications to be used when creating a support case.
  /// The classications are hierarchical, with each classification containing
  /// all levels of the hierarchy, separated by " > ". For example "Technical
  /// Issue > Compute > Compute Engine".
  ///
  /// @param request Unary RPCs, such as the one wrapped by this
  ///     function, receive a single `request` proto message which includes all
  ///     the inputs for the RPC. In this case, the proto message is a
  ///     [google.cloud.support.v2.SearchCaseClassificationsRequest].
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
  ///     [google.cloud.support.v2.CaseClassification], or rather,
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
  /// [google.cloud.support.v2.CaseClassification]: @googleapis_reference_link{google/cloud/support/v2/case.proto#L149}
  /// [google.cloud.support.v2.SearchCaseClassificationsRequest]: @googleapis_reference_link{google/cloud/support/v2/case_service.proto#L323}
  ///
  // clang-format on
  StreamRange<google::cloud::support::v2::CaseClassification>
  SearchCaseClassifications(
      google::cloud::support::v2::SearchCaseClassificationsRequest request,
      Options opts = {});

 private:
  std::shared_ptr<CaseServiceConnection> connection_;
  Options options_;
};

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace support_v2
}  // namespace cloud
}  // namespace google

#endif  // GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_SUPPORT_V2_CASE_CLIENT_H
