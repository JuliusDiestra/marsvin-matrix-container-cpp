
#include "gtest/gtest.h"
#include "marsvin_matrix.hpp"
#include "marsvin_logger.hpp"

TEST(Matrix, Test_Constructor_Empty) {
    marsvin::Matrix<int> cut_;
    EXPECT_TRUE(cut_.empty());
    EXPECT_EQ(0,cut_.rows());
    EXPECT_EQ(0,cut_.columns());
    EXPECT_EQ(0,cut_.size());
}

TEST(Matrix, Constructor_with_row_and_columns) {
    constexpr std::size_t ROWS_ = 3;
    constexpr std::size_t COLUMNS_ = 4;
    marsvin::Matrix<int> cut_(ROWS_, COLUMNS_);
    EXPECT_FALSE(cut_.empty());
    EXPECT_EQ(ROWS_,cut_.rows());
    EXPECT_EQ(COLUMNS_,cut_.columns());
    EXPECT_EQ(ROWS_*COLUMNS_,cut_.size());
}

TEST(Matrix, Constructor_square_matrix) {
    constexpr std::size_t SIZE_ = 3;
    marsvin::Matrix<int> cut_(SIZE_);
    EXPECT_FALSE(cut_.empty());
    EXPECT_EQ(SIZE_,cut_.rows());
    EXPECT_EQ(SIZE_,cut_.columns());
    EXPECT_EQ(SIZE_*SIZE_,cut_.size());
}

TEST(Matrix, Constructor_Initializer_List) {
    constexpr std::size_t ROWS_ = 2;
    constexpr std::size_t COLUMNS_ = 3;
    marsvin::Matrix<int> cut_(ROWS_, COLUMNS_, {1,2,3,4,5,6});
    EXPECT_EQ(cut_.size(),ROWS_*COLUMNS_);
    EXPECT_EQ(cut_.at(0,0), 1);
    EXPECT_EQ(cut_.at(0,1), 2);
    EXPECT_EQ(cut_.at(0,2), 3);
    EXPECT_EQ(cut_.at(1,0), 4);
    EXPECT_EQ(cut_.at(1,1), 5);
    EXPECT_EQ(cut_.at(1,2), 6);
}

TEST(Matrix, Constructor_Double_Initializer_List) {
    marsvin::Matrix<int> cut_ = {{1,2,3},{4,5,6}};
    EXPECT_EQ(cut_.size(), 6);
    EXPECT_EQ(cut_.rows(), 2);
    EXPECT_EQ(cut_.columns(), 3);
    EXPECT_EQ(cut_.at(0,0), 1);
    EXPECT_EQ(cut_.at(0,1), 2);
    EXPECT_EQ(cut_.at(0,2), 3);
    EXPECT_EQ(cut_.at(1,0), 4);
    EXPECT_EQ(cut_.at(1,1), 5);
    EXPECT_EQ(cut_.at(1,2), 6);
}

TEST(Matrix, Copy_Constructor) {
    EXPECT_EQ(0,marsvin::Matrix<int>::GetInstanceCounter());
    marsvin::Matrix<int> cut_ = {{1,2,3},{4,5,6}};
    EXPECT_EQ(1, cut_.GetId());
    EXPECT_EQ(1,marsvin::Matrix<int>::GetInstanceCounter());
    marsvin::Matrix<int> cut_copy = cut_;
    EXPECT_EQ(2, cut_copy.GetId());
    EXPECT_EQ(2,marsvin::Matrix<int>::GetInstanceCounter());
}

TEST(Matrix, Move_Constructor) {
    EXPECT_EQ(0, marsvin::Matrix<int>::GetInstanceCounter());
    marsvin::Matrix<int> cut_ = {{1,2,3},{4,5,6}};
    EXPECT_EQ(1, cut_.GetId());
    EXPECT_EQ(1, marsvin::Matrix<int>::GetInstanceCounter());
    marsvin::Matrix<int> cut_moved = std::move(cut_);
    EXPECT_EQ(1, cut_moved.GetId());
    EXPECT_EQ(1, marsvin::Matrix<int>::GetInstanceCounter());
    EXPECT_TRUE(cut_.empty());
}

TEST(Matrix, GetId) {
    class TestClass {};
    marsvin::Matrix<TestClass> one_;
    EXPECT_EQ(1, one_.GetId());
    marsvin::Matrix<TestClass> two_;
    EXPECT_EQ(2, two_.GetId());
}

TEST(Matrix, GetInstanceCounter) {
    class TestClass {};
    marsvin::Matrix<TestClass> one_;
    marsvin::Matrix<TestClass> two_;
    marsvin::Matrix<TestClass> three_;
    EXPECT_EQ(3, marsvin::Matrix<TestClass>::GetInstanceCounter());
}

TEST(Matrix, is_square_true) {
    constexpr std::size_t SIZE_ = 3;
    marsvin::Matrix<int> cut_(SIZE_);
    EXPECT_TRUE(cut_.is_square());
}

TEST(Matrix, is_square_false) {
    constexpr std::size_t ROWS_ = 2;
    constexpr std::size_t COLUMNS_ = 3;
    marsvin::Matrix<int> cut_(ROWS_, COLUMNS_);
    EXPECT_FALSE(cut_.is_square());
}
