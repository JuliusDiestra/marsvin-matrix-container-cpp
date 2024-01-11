#include "gtest/gtest.h"
#include "marsvin/triangular_systems/upper_inverse.hpp"
#include "marsvin/tools/logger.hpp"
#include "marsvin/tools/compare.hpp"

TEST(UpperTriangularMatrixInverse, Test_X_empty) {
    marsvin::Logger logger_;
    marsvin::Matrix<float> L = {{2,2},
                                {0,1}};
    // Expected :
    // L_inv :
    //      0.5     -1
    //      0        1
    marsvin::Matrix<float> L_inv_expected = {{0.5,-1},
                                             {0,1}};
    marsvin::Matrix<float> L_inv;
    marsvin::triangular_matrix::upper_inverse(L, L_inv);
    marsvin::Matrix<float> I(2);
    I.set_diagonal(1);
    EXPECT_TRUE(marsvin::tools::compare(L*L_inv,I));
    EXPECT_TRUE(marsvin::tools::compare(L_inv,L_inv_expected));
}
