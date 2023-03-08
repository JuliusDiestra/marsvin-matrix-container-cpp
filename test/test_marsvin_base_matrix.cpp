
#include "gtest/gtest.h"
#include "marsvin_base_matrix.hpp"

TEST(BaseMatrix, ConstructEmptyBaseMatrix) {
    marsvin::BaseMatrix<int> cut_;
    EXPECT_TRUE(cut_.empty());
    EXPECT_EQ(0,cut_.rows());
    EXPECT_EQ(0,cut_.columns());
}

TEST(BaseMatrix, ConstructBaseMatrix) {
    constexpr std::size_t ROWS_ = 3;
    constexpr std::size_t COLUMNS_ = 4;
    marsvin::BaseMatrix<int> cut_(ROWS_, COLUMNS_);
    EXPECT_EQ(ROWS_,cut_.rows());
    EXPECT_EQ(COLUMNS_,cut_.columns());
}


TEST(BaseMatrix, method_empty_01) {
    marsvin::BaseMatrix<int> cut_;
    EXPECT_TRUE(cut_.empty());
}

TEST(BaseMatrix, method_empty_02) {
    marsvin::BaseMatrix<int> cut_(2,5);
    EXPECT_FALSE(cut_.empty());
}
TEST(BaseMatrix, method_at_ReadAndSet) {
    constexpr std::size_t ROWS_ = 2;
    constexpr std::size_t COLUMNS_ = 2;
    marsvin::BaseMatrix<int> cut_(ROWS_, COLUMNS_);
    cut_.at(0,0) = 1;
    cut_.at(0,1) = 2;
    cut_.at(1,0) = 3;
    cut_.at(1,1) = 4;
    EXPECT_EQ(cut_.at(0,0),1);
    EXPECT_EQ(cut_.at(0,1),2);
    EXPECT_EQ(cut_.at(1,0),3);
    EXPECT_EQ(cut_.at(1,1),4);
}

TEST(BaseMatrix, method_at_Exception_ErrorRowType) {
    constexpr std::size_t ROWS_ = 2;
    constexpr std::size_t COLUMNS_ = 2;
    marsvin::BaseMatrix<int> cut_(ROWS_, COLUMNS_);
    try {
        cut_.at(2,1) = 10;
    } catch (const marsvin::Exception& exception_) {
        EXPECT_EQ(exception_.error_code().error_type(), marsvin::ErrorCode::TypeRow());
    }
}

TEST(BaseMatrix, method_at_Exception_ErrorColumnType) {
    constexpr std::size_t ROWS_ = 2;
    constexpr std::size_t COLUMNS_ = 2;
    marsvin::BaseMatrix<int> cut_(ROWS_, COLUMNS_);
    try {
        cut_.at(1,2) = 10;
    } catch (const marsvin::Exception& exception_) {
        EXPECT_EQ(exception_.error_code().error_type(), marsvin::ErrorCode::TypeColumn());
    }
}

TEST(BaseMatrix, method_at_Exception_ErrorRowAndColumnType) {
    constexpr std::size_t ROWS_ = 2;
    constexpr std::size_t COLUMNS_ = 2;
    marsvin::BaseMatrix<int> cut_(ROWS_, COLUMNS_);
    try {
        cut_.at(2,2) = 10;
    } catch (const marsvin::Exception& exception_) {
        EXPECT_EQ(exception_.error_code().error_type(), marsvin::ErrorCode::TypeRowAndColumn());
    }
}
