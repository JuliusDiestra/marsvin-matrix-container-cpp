
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

TEST(Vector, Move_Constructor) {
    EXPECT_EQ(0, marsvin::Vector<int>::GetInstanceCounter());
    marsvin::Vector<int> cut_ = {1,2,3,4,5,6};
    EXPECT_EQ(1, cut_.GetId());
    EXPECT_EQ(1, marsvin::Vector<int>::GetInstanceCounter());
    marsvin::Vector<int> cut_moved = std::move(cut_);
    EXPECT_EQ(1, cut_moved.GetId());
    EXPECT_EQ(1, marsvin::Vector<int>::GetInstanceCounter());
    EXPECT_TRUE(cut_.empty());
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
