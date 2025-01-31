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
// source: google/cloud/compute/region_operations/v1/region_operations.proto

#ifndef GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_COMPUTE_REGION_OPERATIONS_V1_REGION_OPERATIONS_CONNECTION_IDEMPOTENCY_POLICY_H
#define GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_COMPUTE_REGION_OPERATIONS_V1_REGION_OPERATIONS_CONNECTION_IDEMPOTENCY_POLICY_H

#include "google/cloud/idempotency.h"
#include "google/cloud/version.h"
#include <google/cloud/compute/region_operations/v1/region_operations.pb.h>
#include <memory>

namespace google {
namespace cloud {
namespace compute_region_operations_v1 {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

class RegionOperationsConnectionIdempotencyPolicy {
 public:
  virtual ~RegionOperationsConnectionIdempotencyPolicy();

  /// Create a new copy of this object.
  virtual std::unique_ptr<RegionOperationsConnectionIdempotencyPolicy> clone()
      const;

  virtual google::cloud::Idempotency DeleteRegionOperations(
      google::cloud::cpp::compute::region_operations::v1::
          DeleteRegionOperationsRequest const& request);

  virtual google::cloud::Idempotency GetRegionOperations(
      google::cloud::cpp::compute::region_operations::v1::
          GetRegionOperationsRequest const& request);

  virtual google::cloud::Idempotency ListRegionOperations(
      google::cloud::cpp::compute::region_operations::v1::
          ListRegionOperationsRequest request);

  virtual google::cloud::Idempotency Wait(
      google::cloud::cpp::compute::region_operations::v1::WaitRequest const&
          request);
};

std::unique_ptr<RegionOperationsConnectionIdempotencyPolicy>
MakeDefaultRegionOperationsConnectionIdempotencyPolicy();

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace compute_region_operations_v1
}  // namespace cloud
}  // namespace google

#endif  // GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_COMPUTE_REGION_OPERATIONS_V1_REGION_OPERATIONS_CONNECTION_IDEMPOTENCY_POLICY_H
