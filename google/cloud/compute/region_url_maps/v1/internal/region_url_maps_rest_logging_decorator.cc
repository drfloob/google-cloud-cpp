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
// source: google/cloud/compute/region_url_maps/v1/region_url_maps.proto

#include "google/cloud/compute/region_url_maps/v1/internal/region_url_maps_rest_logging_decorator.h"
#include "google/cloud/internal/log_wrapper.h"
#include "google/cloud/status_or.h"
#include <memory>

namespace google {
namespace cloud {
namespace compute_region_url_maps_v1_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

RegionUrlMapsRestLogging::RegionUrlMapsRestLogging(
    std::shared_ptr<RegionUrlMapsRestStub> child,
    TracingOptions tracing_options, std::set<std::string> components)
    : child_(std::move(child)),
      tracing_options_(std::move(tracing_options)),
      components_(std::move(components)) {}

future<StatusOr<google::cloud::cpp::compute::v1::Operation>>
RegionUrlMapsRestLogging::AsyncDeleteRegionUrlMaps(
    CompletionQueue& cq,
    std::unique_ptr<rest_internal::RestContext> rest_context,
    google::cloud::cpp::compute::region_url_maps::v1::
        DeleteRegionUrlMapsRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](CompletionQueue& cq,
             std::unique_ptr<rest_internal::RestContext> rest_context,
             google::cloud::cpp::compute::region_url_maps::v1::
                 DeleteRegionUrlMapsRequest const& request) {
        return child_->AsyncDeleteRegionUrlMaps(cq, std::move(rest_context),
                                                request);
      },
      cq, std::move(rest_context), request, __func__, tracing_options_);
}

StatusOr<google::cloud::cpp::compute::v1::UrlMap>
RegionUrlMapsRestLogging::GetRegionUrlMaps(
    rest_internal::RestContext& rest_context,
    google::cloud::cpp::compute::region_url_maps::v1::
        GetRegionUrlMapsRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](rest_internal::RestContext& rest_context,
             google::cloud::cpp::compute::region_url_maps::v1::
                 GetRegionUrlMapsRequest const& request) {
        return child_->GetRegionUrlMaps(rest_context, request);
      },
      rest_context, request, __func__, tracing_options_);
}

future<StatusOr<google::cloud::cpp::compute::v1::Operation>>
RegionUrlMapsRestLogging::AsyncInsertRegionUrlMaps(
    CompletionQueue& cq,
    std::unique_ptr<rest_internal::RestContext> rest_context,
    google::cloud::cpp::compute::region_url_maps::v1::
        InsertRegionUrlMapsRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](CompletionQueue& cq,
             std::unique_ptr<rest_internal::RestContext> rest_context,
             google::cloud::cpp::compute::region_url_maps::v1::
                 InsertRegionUrlMapsRequest const& request) {
        return child_->AsyncInsertRegionUrlMaps(cq, std::move(rest_context),
                                                request);
      },
      cq, std::move(rest_context), request, __func__, tracing_options_);
}

StatusOr<google::cloud::cpp::compute::v1::UrlMapList>
RegionUrlMapsRestLogging::ListRegionUrlMaps(
    rest_internal::RestContext& rest_context,
    google::cloud::cpp::compute::region_url_maps::v1::
        ListRegionUrlMapsRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](rest_internal::RestContext& rest_context,
             google::cloud::cpp::compute::region_url_maps::v1::
                 ListRegionUrlMapsRequest const& request) {
        return child_->ListRegionUrlMaps(rest_context, request);
      },
      rest_context, request, __func__, tracing_options_);
}

future<StatusOr<google::cloud::cpp::compute::v1::Operation>>
RegionUrlMapsRestLogging::AsyncPatchRegionUrlMaps(
    CompletionQueue& cq,
    std::unique_ptr<rest_internal::RestContext> rest_context,
    google::cloud::cpp::compute::region_url_maps::v1::
        PatchRegionUrlMapsRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](CompletionQueue& cq,
             std::unique_ptr<rest_internal::RestContext> rest_context,
             google::cloud::cpp::compute::region_url_maps::v1::
                 PatchRegionUrlMapsRequest const& request) {
        return child_->AsyncPatchRegionUrlMaps(cq, std::move(rest_context),
                                               request);
      },
      cq, std::move(rest_context), request, __func__, tracing_options_);
}

future<StatusOr<google::cloud::cpp::compute::v1::Operation>>
RegionUrlMapsRestLogging::AsyncUpdateRegionUrlMaps(
    CompletionQueue& cq,
    std::unique_ptr<rest_internal::RestContext> rest_context,
    google::cloud::cpp::compute::region_url_maps::v1::
        UpdateRegionUrlMapsRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](CompletionQueue& cq,
             std::unique_ptr<rest_internal::RestContext> rest_context,
             google::cloud::cpp::compute::region_url_maps::v1::
                 UpdateRegionUrlMapsRequest const& request) {
        return child_->AsyncUpdateRegionUrlMaps(cq, std::move(rest_context),
                                                request);
      },
      cq, std::move(rest_context), request, __func__, tracing_options_);
}

StatusOr<google::cloud::cpp::compute::v1::UrlMapsValidateResponse>
RegionUrlMapsRestLogging::Validate(
    rest_internal::RestContext& rest_context,
    google::cloud::cpp::compute::region_url_maps::v1::ValidateRequest const&
        request) {
  return google::cloud::internal::LogWrapper(
      [this](rest_internal::RestContext& rest_context,
             google::cloud::cpp::compute::region_url_maps::v1::
                 ValidateRequest const& request) {
        return child_->Validate(rest_context, request);
      },
      rest_context, request, __func__, tracing_options_);
}

future<StatusOr<google::cloud::cpp::compute::v1::Operation>>
RegionUrlMapsRestLogging::AsyncGetOperation(
    google::cloud::CompletionQueue& cq,
    std::unique_ptr<rest_internal::RestContext> rest_context,
    google::cloud::cpp::compute::region_operations::v1::
        GetRegionOperationsRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](CompletionQueue& cq,
             std::unique_ptr<rest_internal::RestContext> rest_context,
             google::cloud::cpp::compute::region_operations::v1::
                 GetRegionOperationsRequest const& request) {
        return child_->AsyncGetOperation(cq, std::move(rest_context), request);
      },
      cq, std::move(rest_context), request, __func__, tracing_options_);
}

future<Status> RegionUrlMapsRestLogging::AsyncCancelOperation(
    google::cloud::CompletionQueue& cq,
    std::unique_ptr<rest_internal::RestContext> rest_context,
    google::cloud::cpp::compute::region_operations::v1::
        DeleteRegionOperationsRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](CompletionQueue& cq,
             std::unique_ptr<rest_internal::RestContext> rest_context,
             google::cloud::cpp::compute::region_operations::v1::
                 DeleteRegionOperationsRequest const& request) {
        return child_->AsyncCancelOperation(cq, std::move(rest_context),
                                            request);
      },
      cq, std::move(rest_context), request, __func__, tracing_options_);
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace compute_region_url_maps_v1_internal
}  // namespace cloud
}  // namespace google
