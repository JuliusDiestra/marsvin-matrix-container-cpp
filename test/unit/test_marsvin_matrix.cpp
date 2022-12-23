
#include "gtest/gtest.h"
#include "marsvin_matrix.hpp"

class MatrixTest : public testing::Test {
    protected:
        void SetUp() override {}
        void TearDown() override {}
        marsvin::Matrix<float> cut_;
};

TEST_F(MatrixTest, Test_Constructor_Empty) {
    EXPECT_EQ(cut_.GetNumberOfRows(),0);
    EXPECT_EQ(cut_.GetNumberOfColumns(),0);
}


TEST_F(MatrixTest, Test_Constructor_SquareMatrix) {
    const std::size_t n_{5};
    cut_ = marsvin::Matrix<float>(n_);
    EXPECT_EQ(cut_.GetNumberOfRows(),n_);
    EXPECT_EQ(cut_.GetNumberOfColumns(),n_);
}

