
#include "gtest/gtest.h"
#include "marsvin_exception.hpp"

TEST(Exception, Constructor_01) {
    marsvin::Exception cut_;
    ASSERT_TRUE(cut_.error_code().Ok());
}


