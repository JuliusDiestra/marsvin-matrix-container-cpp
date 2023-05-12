
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

TEST(Vector, GetId) {
    class TestClass {};
    marsvin::Vector<TestClass> one_;
    EXPECT_EQ(1, one_.GetId());
    marsvin::Vector<TestClass> two_;
    EXPECT_EQ(2, two_.GetId());
}

TEST(Matrix, GetInstanceCounter) {
    class TestClass {};
    marsvin::Vector<TestClass> one_;
    marsvin::Vector<TestClass> two_;
    marsvin::Vector<TestClass> three_;
    EXPECT_EQ(3, marsvin::Vector<TestClass>::GetInstanceCounter());
}
