
#include "gtest/gtest.h"

#include "marsvin_base_matrix.hpp"
#include "marsvin_logger.hpp"
#include "marsvin_tools.hpp"

TEST(Tools, CompareMatrix_true) {
    constexpr std::size_t ROWS_ = 2;
    constexpr std::size_t COLUMNS_ = 3;
    marsvin::BaseMatrix<int> A(ROWS_, COLUMNS_, {1,2,3,4,5,6});
    marsvin::BaseMatrix<int> B(ROWS_, COLUMNS_, {1,2,3,4,5,6});
    int tolerance = 0;
    EXPECT_TRUE(marsvin::tools::CompareMatrix(A, B, tolerance));
}

TEST(Tools, CompareMatrix_false) {
    constexpr std::size_t ROWS_ = 2;
    constexpr std::size_t COLUMNS_ = 3;
    marsvin::BaseMatrix<int> A(ROWS_, COLUMNS_, {1,2,3,4,5,6});
    marsvin::BaseMatrix<int> B(ROWS_, COLUMNS_, {1,2,3,7,5,6});
    int tolerance = 0;
    EXPECT_FALSE(marsvin::tools::CompareMatrix(A, B, tolerance));
}

TEST(Tools, CompareMatrix_false_size_mismatch) {
    constexpr std::size_t ROWS_ = 2;
    constexpr std::size_t COLUMNS_ = 3;
    marsvin::BaseMatrix<int> A(ROWS_, COLUMNS_, {1,2,3,4,5,6});
    marsvin::BaseMatrix<int> B(ROWS_ + 1, COLUMNS_, {1,2,3,4,5,6,7,8,9});
    int tolerance = 0;
    EXPECT_FALSE(marsvin::tools::CompareMatrix(A, B, tolerance));
}
