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
// source:
// google/cloud/compute/region_health_checks/v1/region_health_checks.proto

#include "google/cloud/compute/region_health_checks/v1/region_health_checks_client.h"
#include <memory>

namespace google {
namespace cloud {
namespace compute_region_health_checks_v1 {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

RegionHealthChecksClient::RegionHealthChecksClient(
    ExperimentalTag, std::shared_ptr<RegionHealthChecksConnection> connection,
    Options opts)
    : connection_(std::move(connection)),
      options_(
          internal::MergeOptions(std::move(opts), connection_->options())) {}
RegionHealthChecksClient::~RegionHealthChecksClient() = default;

future<StatusOr<google::cloud::cpp::compute::v1::Operation>>
RegionHealthChecksClient::DeleteRegionHealthChecks(
    std::string const& project, std::string const& region,
    std::string const& health_check, Options opts) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(opts), options_));
  google::cloud::cpp::compute::region_health_checks::v1::
      DeleteRegionHealthChecksRequest request;
  request.set_project(project);
  request.set_region(region);
  request.set_health_check(health_check);
  return connection_->DeleteRegionHealthChecks(request);
}

future<StatusOr<google::cloud::cpp::compute::v1::Operation>>
RegionHealthChecksClient::DeleteRegionHealthChecks(
    google::cloud::cpp::compute::region_health_checks::v1::
        DeleteRegionHealthChecksRequest const& request,
    Options opts) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(opts), options_));
  return connection_->DeleteRegionHealthChecks(request);
}

StatusOr<google::cloud::cpp::compute::v1::HealthCheck>
RegionHealthChecksClient::GetRegionHealthChecks(std::string const& project,
                                                std::string const& region,
                                                std::string const& health_check,
                                                Options opts) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(opts), options_));
  google::cloud::cpp::compute::region_health_checks::v1::
      GetRegionHealthChecksRequest request;
  request.set_project(project);
  request.set_region(region);
  request.set_health_check(health_check);
  return connection_->GetRegionHealthChecks(request);
}

StatusOr<google::cloud::cpp::compute::v1::HealthCheck>
RegionHealthChecksClient::GetRegionHealthChecks(
    google::cloud::cpp::compute::region_health_checks::v1::
        GetRegionHealthChecksRequest const& request,
    Options opts) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(opts), options_));
  return connection_->GetRegionHealthChecks(request);
}

future<StatusOr<google::cloud::cpp::compute::v1::Operation>>
RegionHealthChecksClient::InsertRegionHealthChecks(
    std::string const& project, std::string const& region,
    google::cloud::cpp::compute::v1::HealthCheck const& health_check_resource,
    Options opts) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(opts), options_));
  google::cloud::cpp::compute::region_health_checks::v1::
      InsertRegionHealthChecksRequest request;
  request.set_project(project);
  request.set_region(region);
  *request.mutable_health_check_resource() = health_check_resource;
  return connection_->InsertRegionHealthChecks(request);
}

future<StatusOr<google::cloud::cpp::compute::v1::Operation>>
RegionHealthChecksClient::InsertRegionHealthChecks(
    google::cloud::cpp::compute::region_health_checks::v1::
        InsertRegionHealthChecksRequest const& request,
    Options opts) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(opts), options_));
  return connection_->InsertRegionHealthChecks(request);
}

StreamRange<google::cloud::cpp::compute::v1::HealthCheck>
RegionHealthChecksClient::ListRegionHealthChecks(std::string const& project,
                                                 std::string const& region,
                                                 Options opts) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(opts), options_));
  google::cloud::cpp::compute::region_health_checks::v1::
      ListRegionHealthChecksRequest request;
  request.set_project(project);
  request.set_region(region);
  return connection_->ListRegionHealthChecks(request);
}

StreamRange<google::cloud::cpp::compute::v1::HealthCheck>
RegionHealthChecksClient::ListRegionHealthChecks(
    google::cloud::cpp::compute::region_health_checks::v1::
        ListRegionHealthChecksRequest request,
    Options opts) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(opts), options_));
  return connection_->ListRegionHealthChecks(std::move(request));
}

future<StatusOr<google::cloud::cpp::compute::v1::Operation>>
RegionHealthChecksClient::PatchRegionHealthChecks(
    std::string const& project, std::string const& region,
    std::string const& health_check,
    google::cloud::cpp::compute::v1::HealthCheck const& health_check_resource,
    Options opts) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(opts), options_));
  google::cloud::cpp::compute::region_health_checks::v1::
      PatchRegionHealthChecksRequest request;
  request.set_project(project);
  request.set_region(region);
  request.set_health_check(health_check);
  *request.mutable_health_check_resource() = health_check_resource;
  return connection_->PatchRegionHealthChecks(request);
}

future<StatusOr<google::cloud::cpp::compute::v1::Operation>>
RegionHealthChecksClient::PatchRegionHealthChecks(
    google::cloud::cpp::compute::region_health_checks::v1::
        PatchRegionHealthChecksRequest const& request,
    Options opts) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(opts), options_));
  return connection_->PatchRegionHealthChecks(request);
}

future<StatusOr<google::cloud::cpp::compute::v1::Operation>>
RegionHealthChecksClient::UpdateRegionHealthChecks(
    std::string const& project, std::string const& region,
    std::string const& health_check,
    google::cloud::cpp::compute::v1::HealthCheck const& health_check_resource,
    Options opts) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(opts), options_));
  google::cloud::cpp::compute::region_health_checks::v1::
      UpdateRegionHealthChecksRequest request;
  request.set_project(project);
  request.set_region(region);
  request.set_health_check(health_check);
  *request.mutable_health_check_resource() = health_check_resource;
  return connection_->UpdateRegionHealthChecks(request);
}

future<StatusOr<google::cloud::cpp::compute::v1::Operation>>
RegionHealthChecksClient::UpdateRegionHealthChecks(
    google::cloud::cpp::compute::region_health_checks::v1::
        UpdateRegionHealthChecksRequest const& request,
    Options opts) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(opts), options_));
  return connection_->UpdateRegionHealthChecks(request);
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace compute_region_health_checks_v1
}  // namespace cloud
}  // namespace google
