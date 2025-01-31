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
// google/cloud/compute/region_target_https_proxies/v1/region_target_https_proxies.proto

#include "google/cloud/compute/region_target_https_proxies/v1/region_target_https_proxies_connection_idempotency_policy.h"
#include <memory>

namespace google {
namespace cloud {
namespace compute_region_target_https_proxies_v1 {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

using ::google::cloud::Idempotency;

RegionTargetHttpsProxiesConnectionIdempotencyPolicy::
    ~RegionTargetHttpsProxiesConnectionIdempotencyPolicy() = default;

std::unique_ptr<RegionTargetHttpsProxiesConnectionIdempotencyPolicy>
RegionTargetHttpsProxiesConnectionIdempotencyPolicy::clone() const {
  return std::make_unique<RegionTargetHttpsProxiesConnectionIdempotencyPolicy>(
      *this);
}

Idempotency RegionTargetHttpsProxiesConnectionIdempotencyPolicy::
    DeleteRegionTargetHttpsProxies(
        google::cloud::cpp::compute::region_target_https_proxies::v1::
            DeleteRegionTargetHttpsProxiesRequest const&) {
  return Idempotency::kNonIdempotent;
}

Idempotency RegionTargetHttpsProxiesConnectionIdempotencyPolicy::
    GetRegionTargetHttpsProxies(
        google::cloud::cpp::compute::region_target_https_proxies::v1::
            GetRegionTargetHttpsProxiesRequest const&) {
  return Idempotency::kIdempotent;
}

Idempotency RegionTargetHttpsProxiesConnectionIdempotencyPolicy::
    InsertRegionTargetHttpsProxies(
        google::cloud::cpp::compute::region_target_https_proxies::v1::
            InsertRegionTargetHttpsProxiesRequest const&) {
  return Idempotency::kNonIdempotent;
}

Idempotency RegionTargetHttpsProxiesConnectionIdempotencyPolicy::
    ListRegionTargetHttpsProxies(
        google::cloud::cpp::compute::region_target_https_proxies::v1::
            ListRegionTargetHttpsProxiesRequest) {  // NOLINT
  return Idempotency::kIdempotent;
}

Idempotency RegionTargetHttpsProxiesConnectionIdempotencyPolicy::
    PatchRegionTargetHttpsProxies(
        google::cloud::cpp::compute::region_target_https_proxies::v1::
            PatchRegionTargetHttpsProxiesRequest const&) {
  return Idempotency::kNonIdempotent;
}

Idempotency
RegionTargetHttpsProxiesConnectionIdempotencyPolicy::SetSslCertificates(
    google::cloud::cpp::compute::region_target_https_proxies::v1::
        SetSslCertificatesRequest const&) {
  return Idempotency::kNonIdempotent;
}

Idempotency RegionTargetHttpsProxiesConnectionIdempotencyPolicy::SetUrlMap(
    google::cloud::cpp::compute::region_target_https_proxies::v1::
        SetUrlMapRequest const&) {
  return Idempotency::kNonIdempotent;
}

std::unique_ptr<RegionTargetHttpsProxiesConnectionIdempotencyPolicy>
MakeDefaultRegionTargetHttpsProxiesConnectionIdempotencyPolicy() {
  return std::make_unique<
      RegionTargetHttpsProxiesConnectionIdempotencyPolicy>();
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace compute_region_target_https_proxies_v1
}  // namespace cloud
}  // namespace google
