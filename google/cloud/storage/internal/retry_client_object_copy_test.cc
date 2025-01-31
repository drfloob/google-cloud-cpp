// Copyright 2023 Google LLC
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

#include "google/cloud/storage/internal/object_requests.h"
#include "google/cloud/storage/internal/retry_client.h"
#include "google/cloud/storage/testing/canonical_errors.h"
#include "google/cloud/storage/testing/mock_generic_stub.h"
#include "google/cloud/storage/testing/retry_tests.h"
#include <gmock/gmock.h>

namespace google {
namespace cloud {
namespace storage {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN
namespace internal {
namespace {

using ::google::cloud::storage::testing::MockGenericStub;
using ::google::cloud::storage::testing::MockRetryClientFunction;
using ::google::cloud::storage::testing::RetryClientTestOptions;
using ::google::cloud::storage::testing::RetryLoopUsesOptions;
using ::google::cloud::storage::testing::RetryLoopUsesSingleToken;
using ::google::cloud::storage::testing::StoppedOnPermanentError;
using ::google::cloud::storage::testing::StoppedOnTooManyTransients;
using ::google::cloud::storage::testing::canonical_errors::PermanentError;
using ::google::cloud::storage::testing::canonical_errors::TransientError;

TEST(RetryClient, CopyObjectTooManyFailures) {
  auto transient = MockRetryClientFunction(TransientError());
  auto mock = std::make_unique<MockGenericStub>();
  EXPECT_CALL(*mock, options);
  EXPECT_CALL(*mock, CopyObject).Times(3).WillRepeatedly(transient);
  auto client = RetryClient::Create(std::move(mock), RetryClientTestOptions());
  google::cloud::internal::OptionsSpan span(client->options());
  auto response = client->CopyObject(CopyObjectRequest()).status();
  EXPECT_THAT(response, StoppedOnTooManyTransients("CopyObject"));
  EXPECT_THAT(transient.captured_tokens(), RetryLoopUsesSingleToken());
  EXPECT_THAT(transient.captured_authority_options(), RetryLoopUsesOptions());
}

TEST(RetryClient, CopyObjectPermanentFailure) {
  auto permanent = MockRetryClientFunction(PermanentError());
  auto mock = std::make_unique<MockGenericStub>();
  EXPECT_CALL(*mock, options);
  EXPECT_CALL(*mock, CopyObject).WillOnce(permanent);
  auto client = RetryClient::Create(std::move(mock), RetryClientTestOptions());
  google::cloud::internal::OptionsSpan span(client->options());
  auto response = client->CopyObject(CopyObjectRequest()).status();
  EXPECT_THAT(response, StoppedOnPermanentError("CopyObject"));
  EXPECT_THAT(permanent.captured_tokens(), RetryLoopUsesSingleToken());
  EXPECT_THAT(permanent.captured_authority_options(), RetryLoopUsesOptions());
}

TEST(RetryClient, ComposeObjectTooManyFailures) {
  auto transient = MockRetryClientFunction(TransientError());
  auto mock = std::make_unique<MockGenericStub>();
  EXPECT_CALL(*mock, options);
  EXPECT_CALL(*mock, ComposeObject).Times(3).WillRepeatedly(transient);
  auto client = RetryClient::Create(std::move(mock), RetryClientTestOptions());
  google::cloud::internal::OptionsSpan span(client->options());
  auto response = client->ComposeObject(ComposeObjectRequest()).status();
  EXPECT_THAT(response, StoppedOnTooManyTransients("ComposeObject"));
  EXPECT_THAT(transient.captured_tokens(), RetryLoopUsesSingleToken());
  EXPECT_THAT(transient.captured_authority_options(), RetryLoopUsesOptions());
}

TEST(RetryClient, ComposeObjectPermanentFailure) {
  auto permanent = MockRetryClientFunction(PermanentError());
  auto mock = std::make_unique<MockGenericStub>();
  EXPECT_CALL(*mock, options);
  EXPECT_CALL(*mock, ComposeObject).WillOnce(permanent);
  auto client = RetryClient::Create(std::move(mock), RetryClientTestOptions());
  google::cloud::internal::OptionsSpan span(client->options());
  auto response = client->ComposeObject(ComposeObjectRequest()).status();
  EXPECT_THAT(response, StoppedOnPermanentError("ComposeObject"));
  EXPECT_THAT(permanent.captured_tokens(), RetryLoopUsesSingleToken());
  EXPECT_THAT(permanent.captured_authority_options(), RetryLoopUsesOptions());
}

TEST(RetryClient, RewriteObjectTooManyFailures) {
  auto transient = MockRetryClientFunction(TransientError());
  auto mock = std::make_unique<MockGenericStub>();
  EXPECT_CALL(*mock, options);
  EXPECT_CALL(*mock, RewriteObject).Times(3).WillRepeatedly(transient);
  auto client = RetryClient::Create(std::move(mock), RetryClientTestOptions());
  google::cloud::internal::OptionsSpan span(client->options());
  auto response = client->RewriteObject(RewriteObjectRequest()).status();
  EXPECT_THAT(response, StoppedOnTooManyTransients("RewriteObject"));
  EXPECT_THAT(transient.captured_tokens(), RetryLoopUsesSingleToken());
  EXPECT_THAT(transient.captured_authority_options(), RetryLoopUsesOptions());
}

TEST(RetryClient, RewriteObjectPermanentFailure) {
  auto permanent = MockRetryClientFunction(PermanentError());
  auto mock = std::make_unique<MockGenericStub>();
  EXPECT_CALL(*mock, options);
  EXPECT_CALL(*mock, RewriteObject).WillOnce(permanent);
  auto client = RetryClient::Create(std::move(mock), RetryClientTestOptions());
  google::cloud::internal::OptionsSpan span(client->options());
  auto response = client->RewriteObject(RewriteObjectRequest()).status();
  EXPECT_THAT(response, StoppedOnPermanentError("RewriteObject"));
  EXPECT_THAT(permanent.captured_tokens(), RetryLoopUsesSingleToken());
  EXPECT_THAT(permanent.captured_authority_options(), RetryLoopUsesOptions());
}

}  // namespace
}  // namespace internal
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace storage
}  // namespace cloud
}  // namespace google
