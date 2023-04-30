
#include "gtest/gtest.h"
#include "marsvin_error_code.hpp"

TEST(ErrorCode, StaticMethods) {
    ASSERT_EQ(marsvin::ErrorType::kNoError, marsvin::ErrorCode::TypeNoError());
    ASSERT_EQ(marsvin::ErrorType::kRow, marsvin::ErrorCode::TypeRow());
    ASSERT_EQ(marsvin::ErrorType::kColumn, marsvin::ErrorCode::TypeColumn());
    ASSERT_EQ(marsvin::ErrorType::kRowAndColumn, marsvin::ErrorCode::TypeRowAndColumn());
    ASSERT_EQ(marsvin::ErrorType::kAddition, marsvin::ErrorCode::TypeAddition());
    ASSERT_EQ(marsvin::ErrorType::kSubtraction, marsvin::ErrorCode::TypeSubtraction());
    ASSERT_EQ(marsvin::ErrorType::kMultiplication, marsvin::ErrorCode::TypeMultiplication());
    ASSERT_EQ(marsvin::ErrorType::kInitializerList, marsvin::ErrorCode::TypeInitializerList());
}

TEST(ErrorCode, Constructor_01) {
    marsvin::ErrorCode cut_;
    ASSERT_EQ(cut_.error_type(), marsvin::ErrorCode::TypeNoError());
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

TEST(ErrorCode, NoError_method) {
    marsvin::ErrorCode cut_;
    cut_.set_error_type(marsvin::ErrorCode::TypeColumn());
    ASSERT_FALSE(cut_.NoError());
    cut_.set_error_type(marsvin::ErrorCode::TypeNoError());
    ASSERT_TRUE(cut_.NoError());
}
