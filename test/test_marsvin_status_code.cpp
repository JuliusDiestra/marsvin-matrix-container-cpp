
#include "gtest/gtest.h"
#include "marsvin/error_handling/status_code.hpp"

TEST(StatusCode, StaticMethods) {
    ASSERT_EQ(marsvin::StatusType::kSuccess, marsvin::StatusCode::TypeSuccess());
    ASSERT_EQ(marsvin::StatusType::kErrorRowIndex, marsvin::StatusCode::TypeErrorRowIndex());
    ASSERT_EQ(marsvin::StatusType::kErrorColumnIndex, marsvin::StatusCode::TypeErrorColumnIndex());
    ASSERT_EQ(marsvin::StatusType::kErrorRowAndColumnIndex, marsvin::StatusCode::TypeErrorRowAndColumnIndex());
    ASSERT_EQ(marsvin::StatusType::kErrorAdditionDimension, marsvin::StatusCode::TypeErrorAdditionDimension());
    ASSERT_EQ(marsvin::StatusType::kErrorSubtractionDimension, marsvin::StatusCode::TypeErrorSubtractionDimension());
    ASSERT_EQ(marsvin::StatusType::kErrorMultiplicationDimension, marsvin::StatusCode::TypeErrorMultiplicationDimension());
    ASSERT_EQ(marsvin::StatusType::kErrorInitializerList, marsvin::StatusCode::TypeErrorInitializerList());
    ASSERT_EQ(marsvin::StatusType::kErrorDoubleInitializerList, marsvin::StatusCode::TypeErrorDoubleInitializerList());
    ASSERT_EQ(marsvin::StatusType::kErrorSquareMatrix, marsvin::StatusCode::TypeErrorSquareMatrix());
    ASSERT_EQ(marsvin::StatusType::kErrorEqualSize, marsvin::StatusCode::TypeErrorEqualSize());
    ASSERT_EQ(marsvin::StatusType::kErrorSolveLinearEquantionDimensions, marsvin::StatusCode::TypeErrorSolveLinearEquantionDimensions());
}

TEST(StatusCode, Constructor_01) {
    marsvin::StatusCode cut_;
    ASSERT_EQ(cut_.status_type(), marsvin::StatusCode::TypeSuccess());
    ASSERT_TRUE(cut_.success());
}

TEST(StatusCode, Constructor_02) {
    marsvin::StatusCode cut_(marsvin::StatusCode::TypeErrorColumnIndex());
    ASSERT_EQ(cut_.status_type(), marsvin::StatusCode::TypeErrorColumnIndex());
}

TEST(StatusCode, set_and_get_status_type) {
    marsvin::StatusCode cut_;
    cut_.set_status_type(marsvin::StatusCode::TypeErrorRowAndColumnIndex());
    ASSERT_EQ(cut_.status_type(), marsvin::StatusCode::TypeErrorRowAndColumnIndex());
}

TEST(StatusCode, Success_method) {
    marsvin::StatusCode cut_;
    cut_.set_status_type(marsvin::StatusCode::TypeErrorColumnIndex());
    ASSERT_FALSE(cut_.success());
    cut_.set_status_type(marsvin::StatusCode::TypeSuccess());
    ASSERT_TRUE(cut_.success());
}
