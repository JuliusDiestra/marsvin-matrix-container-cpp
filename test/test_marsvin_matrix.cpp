
#include "gtest/gtest.h"
#include "marsvin_matrix.hpp"
#include "marsvin_logger.hpp"
#include "marsvin_tools.hpp"

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
    marsvin::Matrix<int> cut_moved =  std::move(cut_);
    EXPECT_EQ(1, cut_moved.GetId());
    EXPECT_EQ(1, marsvin::Matrix<int>::GetInstanceCounter());
    EXPECT_TRUE(cut_.empty());
}

TEST(Matrix, GetId) {
    marsvin::Matrix<int> one_;
    EXPECT_EQ(1, one_.GetId());
    marsvin::Matrix<int> two_;
    EXPECT_EQ(2, two_.GetId());
}

TEST(Matrix, GetInstanceCounter) {
    marsvin::Matrix<float> one_;
    marsvin::Matrix<float> two_;
    marsvin::Matrix<float> three_;
    EXPECT_EQ(3, marsvin::Matrix<float>::GetInstanceCounter());
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


TEST(Matrix, swap_rows) {
    marsvin::Matrix<int> cut_ = {{1,2,3},
                                 {4,5,6},
                                 {7,8,9}};
    cut_.swap_rows(0,2);
    EXPECT_EQ(cut_.at(0,0),7);
    EXPECT_EQ(cut_.at(0,1),8);
    EXPECT_EQ(cut_.at(0,2),9);
    EXPECT_EQ(cut_.at(2,0),1);
    EXPECT_EQ(cut_.at(2,1),2);
    EXPECT_EQ(cut_.at(2,2),3);
}

TEST(Matrix, method_matrix_multiplication) {
    constexpr std::size_t lhs_kRows = 3;
    constexpr std::size_t lhs_kColumns = 2;
    constexpr std::size_t rhs_kRows = 2;
    constexpr std::size_t rhs_kColumns = 4;
    marsvin::Matrix<int> m_lhs(lhs_kRows, lhs_kColumns, {1,2,3,4,5,6});
    marsvin::Matrix<int> m_rhs(rhs_kRows, rhs_kColumns, {1,2,3,4,5,6,7,8});
    marsvin::Matrix<int> m_result_expected(lhs_kRows, rhs_kColumns, {11,14,17,20,23,30,37,44,35,46,57,68});
    auto m_result = m_lhs*m_rhs;
    EXPECT_EQ(m_result.rows(), lhs_kRows);
    EXPECT_EQ(m_result.columns(), rhs_kColumns);
    int tolerance = 0;
    EXPECT_TRUE(marsvin::tools::CompareMatrix(m_result,m_result_expected,tolerance));
}
