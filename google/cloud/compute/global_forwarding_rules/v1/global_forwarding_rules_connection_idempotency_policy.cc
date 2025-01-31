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
// google/cloud/compute/global_forwarding_rules/v1/global_forwarding_rules.proto

#include "google/cloud/compute/global_forwarding_rules/v1/global_forwarding_rules_connection_idempotency_policy.h"
#include <memory>

namespace google {
namespace cloud {
namespace compute_global_forwarding_rules_v1 {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

using ::google::cloud::Idempotency;

GlobalForwardingRulesConnectionIdempotencyPolicy::
    ~GlobalForwardingRulesConnectionIdempotencyPolicy() = default;

std::unique_ptr<GlobalForwardingRulesConnectionIdempotencyPolicy>
GlobalForwardingRulesConnectionIdempotencyPolicy::clone() const {
  return std::make_unique<GlobalForwardingRulesConnectionIdempotencyPolicy>(
      *this);
}

Idempotency
GlobalForwardingRulesConnectionIdempotencyPolicy::DeleteGlobalForwardingRules(
    google::cloud::cpp::compute::global_forwarding_rules::v1::
        DeleteGlobalForwardingRulesRequest const&) {
  return Idempotency::kNonIdempotent;
}

Idempotency
GlobalForwardingRulesConnectionIdempotencyPolicy::GetGlobalForwardingRules(
    google::cloud::cpp::compute::global_forwarding_rules::v1::
        GetGlobalForwardingRulesRequest const&) {
  return Idempotency::kIdempotent;
}

Idempotency
GlobalForwardingRulesConnectionIdempotencyPolicy::InsertGlobalForwardingRules(
    google::cloud::cpp::compute::global_forwarding_rules::v1::
        InsertGlobalForwardingRulesRequest const&) {
  return Idempotency::kNonIdempotent;
}

Idempotency
GlobalForwardingRulesConnectionIdempotencyPolicy::ListGlobalForwardingRules(
    google::cloud::cpp::compute::global_forwarding_rules::v1::
        ListGlobalForwardingRulesRequest) {  // NOLINT
  return Idempotency::kIdempotent;
}

Idempotency
GlobalForwardingRulesConnectionIdempotencyPolicy::PatchGlobalForwardingRules(
    google::cloud::cpp::compute::global_forwarding_rules::v1::
        PatchGlobalForwardingRulesRequest const&) {
  return Idempotency::kNonIdempotent;
}

Idempotency GlobalForwardingRulesConnectionIdempotencyPolicy::SetLabels(
    google::cloud::cpp::compute::global_forwarding_rules::v1::
        SetLabelsRequest const&) {
  return Idempotency::kNonIdempotent;
}

Idempotency GlobalForwardingRulesConnectionIdempotencyPolicy::SetTarget(
    google::cloud::cpp::compute::global_forwarding_rules::v1::
        SetTargetRequest const&) {
  return Idempotency::kNonIdempotent;
}

std::unique_ptr<GlobalForwardingRulesConnectionIdempotencyPolicy>
MakeDefaultGlobalForwardingRulesConnectionIdempotencyPolicy() {
  return std::make_unique<GlobalForwardingRulesConnectionIdempotencyPolicy>();
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace compute_global_forwarding_rules_v1
}  // namespace cloud
}  // namespace google
