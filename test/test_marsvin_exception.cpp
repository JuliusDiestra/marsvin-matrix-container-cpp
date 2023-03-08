
#include "marsvin_exception.hpp"

#include "gtest/gtest.h"

TEST(Exception, Constructor_01) {
    marsvin::ErrorCode error_code_(marsvin::ErrorCode::TypeNoError());
    bool flag_{false};
    try {
        marsvin::Exception cut_(error_code_);
    } catch (const std::invalid_argument& exception_) {
        flag_ = true;
    }
    ASSERT_TRUE(flag_);
}

TEST(Exception, Constructor_02) {
    marsvin::ErrorCode error_code_(marsvin::ErrorCode::TypeColumn());
    marsvin::Exception cut_(error_code_);
    ASSERT_EQ(cut_.error_code().error_type(), error_code_.error_type());
}

