// Copyright 2020 Google LLC
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     https://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_INTERNAL_RETRY_LOOP_HELPERS_H
#define GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_INTERNAL_RETRY_LOOP_HELPERS_H

#include "google/cloud/status_or.h"
#include "google/cloud/version.h"

namespace google {
namespace cloud {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN
namespace internal {

/// Generic programming adapter for `RetryLoop()` and `AsyncRetryLoop()`.
inline Status GetResultStatus(Status status) { return status; }

/// @copydoc GetResultStatus(Status)
template <typename T>
Status GetResultStatus(StatusOr<T> result) {
  return std::move(result).status();
}

/// Use this if the retry loop detects any error on a non-idempotent RPC.
Status RetryLoopNonIdempotentError(Status status, char const* location);

/// Use this if the retry loop finished with an error.
///
/// Set @p exhausted to true if the retry policy has been exhausted.
Status RetryLoopError(Status const& s, char const* location, bool exhausted);

/// Use this if the retry loop detects any permanent errors.
Status RetryLoopPermanentError(Status const& status, char const* location);

/// Use this if the retry loop exits because the retry policy has been
/// exhausted.
Status RetryLoopPolicyExhaustedError(Status const& status,
                                     char const* location);

/// Use this if the retry loop is cancelled by the caller.
///
/// This is only applicable for asynchronous RPCs, as unary RPCs cannot be
/// cancelled.
Status RetryLoopCancelled(Status const& status, char const* location);

}  // namespace internal
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace cloud
}  // namespace google

#endif  // GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_INTERNAL_RETRY_LOOP_HELPERS_H
