
#include "marsvin/error_handling/exception.hpp"

#include "gtest/gtest.h"

TEST(Exception, Constructor_01) {
    marsvin::StatusCode status_code_(marsvin::StatusCode::TypeSuccess());
    bool flag_{false};
    try {
        marsvin::Exception cut_(status_code_);
    } catch (const std::invalid_argument& exception_) {
        flag_ = true;
    }
    ASSERT_TRUE(flag_);
}

TEST(Exception, Constructor_02) {
    marsvin::StatusCode status_code_(marsvin::StatusCode::TypeErrorColumnIndex());
    marsvin::Exception cut_(status_code_);
    ASSERT_EQ(cut_.status_code().status_type(), status_code_.status_type());
}

