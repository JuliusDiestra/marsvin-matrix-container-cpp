
#include "gtest/gtest.h"

#include "marsvin/containers/base_matrix.hpp"
#include "marsvin/tools/logger.hpp"
#include "marsvin/tools/compare.hpp"

TEST(Tools, Compare_Matrix_true) {
    constexpr std::size_t ROWS_ = 2;
    constexpr std::size_t COLUMNS_ = 3;
    marsvin::BaseMatrix<int> A(ROWS_, COLUMNS_, {1,2,3,4,5,6});
    marsvin::BaseMatrix<int> B(ROWS_, COLUMNS_, {1,2,3,4,5,6});
    int tolerance = 0;
    EXPECT_TRUE(marsvin::tools::compare(A, B, tolerance));
}

TEST(Tools, Compare_Matrix_false) {
    constexpr std::size_t ROWS_ = 2;
    constexpr std::size_t COLUMNS_ = 3;
    marsvin::BaseMatrix<int> A(ROWS_, COLUMNS_, {1,2,3,4,5,6});
    marsvin::BaseMatrix<int> B(ROWS_, COLUMNS_, {1,2,3,7,5,6});
    int tolerance = 0;
    EXPECT_FALSE(marsvin::tools::compare(A, B, tolerance));
}

TEST(Tools, Compare_Matrix_false_size_mismatch) {
    constexpr std::size_t ROWS_ = 2;
    constexpr std::size_t COLUMNS_ = 3;
    marsvin::BaseMatrix<int> A(ROWS_, COLUMNS_, {1,2,3,4,5,6});
    marsvin::BaseMatrix<int> B(ROWS_ + 1, COLUMNS_, {1,2,3,4,5,6,7,8,9});
    int tolerance = 0;
    EXPECT_FALSE(marsvin::tools::compare(A, B, tolerance));
}

