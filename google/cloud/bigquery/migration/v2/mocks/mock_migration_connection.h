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
// source: google/cloud/bigquery/migration/v2/migration_service.proto

#ifndef GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_BIGQUERY_MIGRATION_V2_MOCKS_MOCK_MIGRATION_CONNECTION_H
#define GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_BIGQUERY_MIGRATION_V2_MOCKS_MOCK_MIGRATION_CONNECTION_H

#include "google/cloud/bigquery/migration/v2/migration_connection.h"
#include <gmock/gmock.h>

namespace google {
namespace cloud {
namespace bigquery_migration_v2_mocks {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

/**
 * A class to mock `MigrationServiceConnection`.
 *
 * Application developers may want to test their code with simulated responses,
 * including errors, from an object of type `MigrationServiceClient`. To do so,
 * construct an object of type `MigrationServiceClient` with an instance of this
 * class. Then use the Google Test framework functions to program the behavior
 * of this mock.
 *
 * @see [This example][bq-mock] for how to test your application with GoogleTest.
 * While the example showcases types from the BigQuery library, the underlying
 * principles apply for any pair of `*Client` and `*Connection`.
 *
 * [bq-mock]: @googleapis_dev_link{bigquery,bigquery-read-mock.html}
 */
class MockMigrationServiceConnection
    : public bigquery_migration_v2::MigrationServiceConnection {
 public:
  MOCK_METHOD(Options, options, (), (override));

  MOCK_METHOD(
      StatusOr<google::cloud::bigquery::migration::v2::MigrationWorkflow>,
      CreateMigrationWorkflow,
      (google::cloud::bigquery::migration::v2::
           CreateMigrationWorkflowRequest const& request),
      (override));

  MOCK_METHOD(
      StatusOr<google::cloud::bigquery::migration::v2::MigrationWorkflow>,
      GetMigrationWorkflow,
      (google::cloud::bigquery::migration::v2::
           GetMigrationWorkflowRequest const& request),
      (override));

  MOCK_METHOD(
      StreamRange<google::cloud::bigquery::migration::v2::MigrationWorkflow>,
      ListMigrationWorkflows,
      (google::cloud::bigquery::migration::v2::ListMigrationWorkflowsRequest
           request),
      (override));

  MOCK_METHOD(Status, DeleteMigrationWorkflow,
              (google::cloud::bigquery::migration::v2::
                   DeleteMigrationWorkflowRequest const& request),
              (override));

  MOCK_METHOD(Status, StartMigrationWorkflow,
              (google::cloud::bigquery::migration::v2::
                   StartMigrationWorkflowRequest const& request),
              (override));

  MOCK_METHOD(
      StatusOr<google::cloud::bigquery::migration::v2::MigrationSubtask>,
      GetMigrationSubtask,
      (google::cloud::bigquery::migration::v2::GetMigrationSubtaskRequest const&
           request),
      (override));

  MOCK_METHOD(
      StreamRange<google::cloud::bigquery::migration::v2::MigrationSubtask>,
      ListMigrationSubtasks,
      (google::cloud::bigquery::migration::v2::ListMigrationSubtasksRequest
           request),
      (override));
};

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace bigquery_migration_v2_mocks
}  // namespace cloud
}  // namespace google

#endif  // GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_BIGQUERY_MIGRATION_V2_MOCKS_MOCK_MIGRATION_CONNECTION_H
