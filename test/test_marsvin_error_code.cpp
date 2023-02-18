
#include "gtest/gtest.h"
#include "marsvin_error_code.hpp"

TEST(ErrorCode, StaticMethods) {
    ASSERT_EQ(marsvin::ErrorType::kOk, marsvin::ErrorCode::TypeOk());
    ASSERT_EQ(marsvin::ErrorType::kRow, marsvin::ErrorCode::TypeRow());
    ASSERT_EQ(marsvin::ErrorType::kColumn, marsvin::ErrorCode::TypeColumn());
    ASSERT_EQ(marsvin::ErrorType::kRowAndColumn, marsvin::ErrorCode::TypeRowAndColumn());
}

TEST(ErrorCode, Constructor_01) {
    marsvin::ErrorCode cut_;
    ASSERT_EQ(cut_.error_type(), marsvin::ErrorCode::TypeOk()); 
}

TEST(ErrorCode, Constructor_02) {
    marsvin::ErrorCode cut_(marsvin::ErrorCode::TypeColumn());
    ASSERT_EQ(cut_.error_type(), marsvin::ErrorCode::TypeColumn()); 
}

TEST(ErrorCode, set_and_get_error_type) {
    marsvin::ErrorCode cut_;
    cut_.set_error_type(marsvin::ErrorCode::TypeRowAndColumn());
    ASSERT_EQ(cut_.error_type(), marsvin::ErrorCode::TypeRowAndColumn());
}

TEST(ErrorCode, Ok_method) {
    marsvin::ErrorCode cut_;
    cut_.set_error_type(marsvin::ErrorCode::TypeColumn());
    ASSERT_TRUE(!cut_.Ok());
    cut_.set_error_type(marsvin::ErrorCode::TypeOk());
    ASSERT_TRUE(cut_.Ok());
}
