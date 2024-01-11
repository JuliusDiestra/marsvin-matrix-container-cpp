
#include "gtest/gtest.h"
#include "marsvin/triangular_systems/lower_inverse.hpp"
#include "marsvin/tools/logger.hpp"
#include "marsvin/tools/compare.hpp"


TEST(LowerTriangularMatrixInverse, Test_X_empty) {
    marsvin::Logger logger_;
    marsvin::Matrix<float> L = {{2,0},
                                {2,1}};
    // Expected :
    // L_inv :
    //      0.5     0
    //      -1      1
    marsvin::Matrix<float> L_inv_expected = {{0.5,0},
                                             {-1,1}};
    marsvin::Matrix<float> L_inv;
    marsvin::triangular_matrix::lower_inverse(L, L_inv);
    marsvin::Matrix<float> I(2);
    I.set_diagonal(1);
    EXPECT_TRUE(marsvin::tools::compare(L*L_inv,I));
    EXPECT_TRUE(marsvin::tools::compare(L_inv,L_inv_expected));
}

TEST(LowerTriangularMatrixInverse, Test_X_empty_5x5) {
    marsvin::Logger logger_;
    marsvin::Matrix<float> L = {{1,0,0,0,0},
                                {2,4,0,0,0},
                                {2,1,1,0,0},
                                {1,1,2,4,0},
                                {1,2,2,1,2}};
    // Expected :
    marsvin::Matrix<float> L_inv_expected = {{1,0,0,0,0},
                                            {-1.0/2.0,1.0/4.0,0,0,0},
                                            {-3.0/2.0,-1.0/4.0,1.0,0,0},
                                            {5.0/8.0,1.0/16.0,-1.0/2.0,1.0/4.0,0},
                                            {19.0/16.0,-1/32.0,-3.0/4.0,-1.0/8.0,1.0/2.0}};
    marsvin::Matrix<float> L_inv;
    marsvin::triangular_matrix::lower_inverse(L, L_inv);
    marsvin::Matrix<float> I(5);
    I.set_diagonal(1);
    EXPECT_TRUE(marsvin::tools::compare(L*L_inv,I));
    EXPECT_TRUE(marsvin::tools::compare(L_inv,L_inv_expected));
}

TEST(LowerTriangularMatrixInverse, Test_return_X) {
    marsvin::Logger logger_;
    marsvin::Matrix<float> L = {{2,0},
                                {2,1}};
    // Expected :
    // L_inv :
    //      0.5     0
    //      -1      1
    marsvin::Matrix<float> L_inv_expected = {{0.5,0},
                                             {-1,1}};
    auto L_inv = marsvin::triangular_matrix::lower_inverse(L);
    marsvin::Matrix<float> I(2);
    I.set_diagonal(1);
    EXPECT_TRUE(marsvin::tools::compare(L*L_inv,I));
    EXPECT_TRUE(marsvin::tools::compare(L_inv,L_inv_expected));
}

TEST(LowerTriangularMatrixInverse, Test_memory_optimization) {
    marsvin::Logger logger_;
    marsvin::Matrix<float> L = {{2,0},
                                {2,1}};
    // Expected :
    // L_inv :
    //      0.5     0
    //      -1      1
    marsvin::Matrix<float> L_inv_expected = {{0.5,0},
                                             {-1,1}};
    marsvin::triangular_matrix::lower_inverse_memory(L);
    marsvin::Matrix<float> I(2);
    I.set_diagonal(1);
    EXPECT_TRUE(marsvin::tools::compare(L,L_inv_expected));
}
