
#include "gtest/gtest.h"
#include "marsvin_vector.hpp"
#include "marsvin_logger.hpp"

TEST(Vector, Test_Constructor_Empty) {
    marsvin::Vector<int> cut_;
    EXPECT_TRUE(cut_.empty());
    EXPECT_EQ(0,cut_.rows());
    EXPECT_EQ(0,cut_.columns());
    EXPECT_EQ(0,cut_.size());
}
