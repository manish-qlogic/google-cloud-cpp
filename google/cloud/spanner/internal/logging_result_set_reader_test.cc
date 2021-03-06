// Copyright 2019 Google LLC
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "google/cloud/spanner/internal/logging_result_set_reader.h"
#include "google/cloud/spanner/testing/mock_partial_result_set_reader.h"
#include "google/cloud/spanner/tracing_options.h"
#include "google/cloud/log.h"
#include "google/cloud/testing_util/assert_ok.h"
#include "google/cloud/testing_util/capture_log_lines_backend.h"
#include "absl/memory/memory.h"
#include <gmock/gmock.h>

namespace google {
namespace cloud {
namespace spanner {
inline namespace SPANNER_CLIENT_NS {
namespace internal {
namespace {

using ::testing::Contains;
using ::testing::HasSubstr;
namespace spanner_proto = ::google::spanner::v1;

class LoggingResultSetReaderTest : public ::testing::Test {
 protected:
  void SetUp() override {
    backend_ =
        std::make_shared<google::cloud::testing_util::CaptureLogLinesBackend>();
    logger_id_ = google::cloud::LogSink::Instance().AddBackend(backend_);
  }

  void TearDown() override {
    google::cloud::LogSink::Instance().RemoveBackend(logger_id_);
    logger_id_ = 0;
  }

  std::vector<std::string> ClearLogLines() { return backend_->ClearLogLines(); }

 private:
  std::shared_ptr<google::cloud::testing_util::CaptureLogLinesBackend> backend_;
  long logger_id_ = 0;  // NOLINT
};

TEST_F(LoggingResultSetReaderTest, TryCancel) {
  auto mock = absl::make_unique<spanner_testing::MockPartialResultSetReader>();
  EXPECT_CALL(*mock, TryCancel()).Times(1);
  LoggingResultSetReader reader(std::move(mock), TracingOptions{});
  reader.TryCancel();

  EXPECT_THAT(ClearLogLines(), Contains(HasSubstr("TryCancel")));
}

TEST_F(LoggingResultSetReaderTest, Read) {
  auto mock = absl::make_unique<spanner_testing::MockPartialResultSetReader>();
  EXPECT_CALL(*mock, Read())
      .WillOnce([] {
        spanner_proto::PartialResultSet result;
        result.set_resume_token("test-token");
        return result;
      })
      .WillOnce(
          [] { return absl::optional<spanner_proto::PartialResultSet>{}; });
  LoggingResultSetReader reader(std::move(mock), TracingOptions{});
  auto result = reader.Read();
  ASSERT_TRUE(result.has_value());
  EXPECT_EQ("test-token", result->resume_token());

  auto log_lines = ClearLogLines();
  EXPECT_THAT(log_lines, Contains(HasSubstr("Read")));
  EXPECT_THAT(log_lines, Contains(HasSubstr("test-token")));

  result = reader.Read();
  ASSERT_FALSE(result.has_value());
  log_lines = ClearLogLines();
  EXPECT_THAT(log_lines, Contains(HasSubstr("(optional-with-no-value)")));
}

TEST_F(LoggingResultSetReaderTest, Finish) {
  Status const expected_status = Status(StatusCode::kOutOfRange, "weird");
  auto mock = absl::make_unique<spanner_testing::MockPartialResultSetReader>();
  EXPECT_CALL(*mock, Finish()).WillOnce([expected_status] {
    return expected_status;  // NOLINT(performance-no-automatic-move)
  });
  LoggingResultSetReader reader(std::move(mock), TracingOptions{});
  auto status = reader.Finish();
  EXPECT_EQ(expected_status, status);

  auto log_lines = ClearLogLines();
  EXPECT_THAT(log_lines, Contains(HasSubstr("Finish")));
  EXPECT_THAT(log_lines, Contains(HasSubstr("weird")));
}

}  // namespace
}  // namespace internal
}  // namespace SPANNER_CLIENT_NS
}  // namespace spanner
}  // namespace cloud
}  // namespace google
