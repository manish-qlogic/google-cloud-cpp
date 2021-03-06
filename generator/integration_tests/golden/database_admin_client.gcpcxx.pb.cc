// Copyright 2020 Google LLC
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
// source: generator/integration_tests/test.proto

#include "generator/integration_tests/golden/database_admin_client.gcpcxx.pb.h"
#include <memory>

namespace google {
namespace cloud {
inline namespace GOOGLE_CLOUD_CPP_NS {
namespace golden {

DatabaseAdminClient::DatabaseAdminClient(std::shared_ptr<DatabaseAdminConnection> connection) : connection_(std::move(connection)) {}
DatabaseAdminClient::~DatabaseAdminClient() = default;

ListDatabasesRange
DatabaseAdminClient::ListDatabases(std::string const& parent) {
  ::google::test::admin::database::v1::ListDatabasesRequest request;
  request.set_parent(parent);
  return connection_->ListDatabases(request);
}

future<StatusOr<::google::test::admin::database::v1::Database>>
DatabaseAdminClient::CreateDatabase(std::string const& parent, std::string const& create_statement) {
  ::google::test::admin::database::v1::CreateDatabaseRequest request;
  request.set_parent(parent);
  request.set_create_statement(create_statement);
  return connection_->CreateDatabase(request);
}

StatusOr<::google::test::admin::database::v1::Database>
DatabaseAdminClient::GetDatabase(std::string const& name) {
  ::google::test::admin::database::v1::GetDatabaseRequest request;
  request.set_name(name);
  return connection_->GetDatabase(request);
}

future<StatusOr<::google::test::admin::database::v1::UpdateDatabaseDdlMetadata>>
DatabaseAdminClient::UpdateDatabaseDdl(std::string const& database, std::vector<std::string> const& statements) {
  ::google::test::admin::database::v1::UpdateDatabaseDdlRequest request;
  request.set_database(database);
  *request.mutable_statements() = {statements.begin(), statements.end()};
  return connection_->UpdateDatabaseDdl(request);
}

Status
DatabaseAdminClient::DropDatabase(std::string const& database) {
  ::google::test::admin::database::v1::DropDatabaseRequest request;
  request.set_database(database);
  return connection_->DropDatabase(request);
}

StatusOr<::google::test::admin::database::v1::GetDatabaseDdlResponse>
DatabaseAdminClient::GetDatabaseDdl(std::string const& database) {
  ::google::test::admin::database::v1::GetDatabaseDdlRequest request;
  request.set_database(database);
  return connection_->GetDatabaseDdl(request);
}

StatusOr<::google::iam::v1::Policy>
DatabaseAdminClient::SetIamPolicy(std::string const& resource, ::google::iam::v1::Policy const& policy) {
  ::google::iam::v1::SetIamPolicyRequest request;
  request.set_resource(resource);
  *request.mutable_policy() = policy;
  return connection_->SetIamPolicy(request);
}

StatusOr<::google::iam::v1::Policy>
DatabaseAdminClient::GetIamPolicy(std::string const& resource) {
  ::google::iam::v1::GetIamPolicyRequest request;
  request.set_resource(resource);
  return connection_->GetIamPolicy(request);
}

StatusOr<::google::iam::v1::TestIamPermissionsResponse>
DatabaseAdminClient::TestIamPermissions(std::string const& resource, std::vector<std::string> const& permissions) {
  ::google::iam::v1::TestIamPermissionsRequest request;
  request.set_resource(resource);
  *request.mutable_permissions() = {permissions.begin(), permissions.end()};
  return connection_->TestIamPermissions(request);
}

future<StatusOr<::google::test::admin::database::v1::Backup>>
DatabaseAdminClient::CreateBackup(std::string const& parent, ::google::test::admin::database::v1::Backup const& backup, std::string const& backup_id) {
  ::google::test::admin::database::v1::CreateBackupRequest request;
  request.set_parent(parent);
  *request.mutable_backup() = backup;
  request.set_backup_id(backup_id);
  return connection_->CreateBackup(request);
}

StatusOr<::google::test::admin::database::v1::Backup>
DatabaseAdminClient::GetBackup(std::string const& name) {
  ::google::test::admin::database::v1::GetBackupRequest request;
  request.set_name(name);
  return connection_->GetBackup(request);
}

StatusOr<::google::test::admin::database::v1::Backup>
DatabaseAdminClient::UpdateBackup(::google::test::admin::database::v1::Backup const& backup, ::google::protobuf::FieldMask const& update_mask) {
  ::google::test::admin::database::v1::UpdateBackupRequest request;
  *request.mutable_backup() = backup;
  *request.mutable_update_mask() = update_mask;
  return connection_->UpdateBackup(request);
}

Status
DatabaseAdminClient::DeleteBackup(std::string const& name) {
  ::google::test::admin::database::v1::DeleteBackupRequest request;
  request.set_name(name);
  return connection_->DeleteBackup(request);
}

ListBackupsRange
DatabaseAdminClient::ListBackups(std::string const& parent) {
  ::google::test::admin::database::v1::ListBackupsRequest request;
  request.set_parent(parent);
  return connection_->ListBackups(request);
}

future<StatusOr<::google::test::admin::database::v1::Database>>
DatabaseAdminClient::RestoreDatabase(std::string const& parent, std::string const& database_id, std::string const& backup) {
  ::google::test::admin::database::v1::RestoreDatabaseRequest request;
  request.set_parent(parent);
  request.set_database_id(database_id);
  request.set_backup(backup);
  return connection_->RestoreDatabase(request);
}

ListDatabaseOperationsRange
DatabaseAdminClient::ListDatabaseOperations(std::string const& parent) {
  ::google::test::admin::database::v1::ListDatabaseOperationsRequest request;
  request.set_parent(parent);
  return connection_->ListDatabaseOperations(request);
}

ListBackupOperationsRange
DatabaseAdminClient::ListBackupOperations(std::string const& parent) {
  ::google::test::admin::database::v1::ListBackupOperationsRequest request;
  request.set_parent(parent);
  return connection_->ListBackupOperations(request);
}

ListDatabasesRange
DatabaseAdminClient::ListDatabases(::google::test::admin::database::v1::ListDatabasesRequest request) {
  return connection_->ListDatabases(request);
}

future<StatusOr<::google::test::admin::database::v1::Database>>
DatabaseAdminClient::CreateDatabase(::google::test::admin::database::v1::CreateDatabaseRequest const& request) {
  return connection_->CreateDatabase(request);
}

StatusOr<::google::test::admin::database::v1::Database>
DatabaseAdminClient::GetDatabase(::google::test::admin::database::v1::GetDatabaseRequest const& request) {
  return connection_->GetDatabase(request);
}

future<StatusOr<::google::test::admin::database::v1::UpdateDatabaseDdlMetadata>>
DatabaseAdminClient::UpdateDatabaseDdl(::google::test::admin::database::v1::UpdateDatabaseDdlRequest const& request) {
  return connection_->UpdateDatabaseDdl(request);
}

Status
DatabaseAdminClient::DropDatabase(::google::test::admin::database::v1::DropDatabaseRequest const& request) {
  return connection_->DropDatabase(request);
}

StatusOr<::google::test::admin::database::v1::GetDatabaseDdlResponse>
DatabaseAdminClient::GetDatabaseDdl(::google::test::admin::database::v1::GetDatabaseDdlRequest const& request) {
  return connection_->GetDatabaseDdl(request);
}

StatusOr<::google::iam::v1::Policy>
DatabaseAdminClient::SetIamPolicy(::google::iam::v1::SetIamPolicyRequest const& request) {
  return connection_->SetIamPolicy(request);
}

StatusOr<::google::iam::v1::Policy>
DatabaseAdminClient::GetIamPolicy(::google::iam::v1::GetIamPolicyRequest const& request) {
  return connection_->GetIamPolicy(request);
}

StatusOr<::google::iam::v1::TestIamPermissionsResponse>
DatabaseAdminClient::TestIamPermissions(::google::iam::v1::TestIamPermissionsRequest const& request) {
  return connection_->TestIamPermissions(request);
}

future<StatusOr<::google::test::admin::database::v1::Backup>>
DatabaseAdminClient::CreateBackup(::google::test::admin::database::v1::CreateBackupRequest const& request) {
  return connection_->CreateBackup(request);
}

StatusOr<::google::test::admin::database::v1::Backup>
DatabaseAdminClient::GetBackup(::google::test::admin::database::v1::GetBackupRequest const& request) {
  return connection_->GetBackup(request);
}

StatusOr<::google::test::admin::database::v1::Backup>
DatabaseAdminClient::UpdateBackup(::google::test::admin::database::v1::UpdateBackupRequest const& request) {
  return connection_->UpdateBackup(request);
}

Status
DatabaseAdminClient::DeleteBackup(::google::test::admin::database::v1::DeleteBackupRequest const& request) {
  return connection_->DeleteBackup(request);
}

ListBackupsRange
DatabaseAdminClient::ListBackups(::google::test::admin::database::v1::ListBackupsRequest request) {
  return connection_->ListBackups(request);
}

future<StatusOr<::google::test::admin::database::v1::Database>>
DatabaseAdminClient::RestoreDatabase(::google::test::admin::database::v1::RestoreDatabaseRequest const& request) {
  return connection_->RestoreDatabase(request);
}

ListDatabaseOperationsRange
DatabaseAdminClient::ListDatabaseOperations(::google::test::admin::database::v1::ListDatabaseOperationsRequest request) {
  return connection_->ListDatabaseOperations(request);
}

ListBackupOperationsRange
DatabaseAdminClient::ListBackupOperations(::google::test::admin::database::v1::ListBackupOperationsRequest request) {
  return connection_->ListBackupOperations(request);
}

}  // namespace golden
}  // namespace GOOGLE_CLOUD_CPP_NS
}  // namespace cloud
}  // namespace google

