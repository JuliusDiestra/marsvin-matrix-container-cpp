
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
    EXPECT_TRUE(!cut_.empty());
    EXPECT_EQ(ROWS_,cut_.rows());
    EXPECT_EQ(COLUMNS_,cut_.columns());
}


TEST(BaseMatrix, SetEntry_01) {
}
