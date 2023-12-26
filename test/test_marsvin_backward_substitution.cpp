
#include "gtest/gtest.h"
#include "marsvin/triangular_systems/backward_substitution.hpp"
#include "marsvin/tools/logger.hpp"
#include "marsvin/tools/compare.hpp"

/*
 * Description:
 *  Check algorithm by an example.
 *  Operation: U*x = b
 *  Choose value for U and b, and calculate "x".
 *  Then check if U*x == b
 *  x_expected = {1,2,3,4}
 */
TEST(BackwardSubstitution, Test_x_empty_4x4) {
    marsvin::Logger logger_;
    marsvin::Matrix<float> U = {{3,2,1,1},
                                {0,1,2,1},
                                {0,0,1,1},
                                {0,0,0,1}};
    marsvin::Vector<float> b = {14,12,7,4};
    marsvin::Vector<float> x_real = {1,2,3,4};
    marsvin::Vector<float> x;
    marsvin::backward_substitution(U, b, x);
    EXPECT_EQ(x.size(), b.size());
    EXPECT_TRUE(marsvin::tools::compare(x,x_real));
    EXPECT_TRUE(marsvin::tools::compare(U*x,b));
}

TEST(BackwardSubstitution, Test_x_empty_5x5) {
    marsvin::Logger logger_;
    marsvin::Matrix<float> U = {{1,2,3,4,5},
                                {0,6,7,8,9},
                                {0,0,10,11,12},
                                {0,0,0,13,14},
                                {0,0,0,0,15}};
    marsvin::Vector<float> b = {55,110,134,122,75};
    marsvin::Vector<float> x_real = {1,2,3,4,5};
    marsvin::Vector<float> x;
    marsvin::backward_substitution(U, b, x);
    EXPECT_EQ(x.size(), b.size());
    EXPECT_TRUE(marsvin::tools::compare(x,x_real));
    EXPECT_TRUE(marsvin::tools::compare(U*x,b));
}

