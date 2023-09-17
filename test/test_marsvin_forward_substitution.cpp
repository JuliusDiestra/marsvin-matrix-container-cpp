
#include "gtest/gtest.h"
#include "marsvin/triangular_systems/forward_substitution.hpp"
#include "marsvin/tools/logger.hpp"
#include "marsvin/tools/compare.hpp"


/*
 * Description:
 *  Check algorithm by an example.
 *  Operation: L*x = b
 *  Choose value for L and b, and calculate "x".
 *  Then check if L*x == b
 *  x_expected = {1,2,3,4}
 */
TEST(ForwardSubstitution, Test_x_empty) {
    marsvin::Logger logger_;
    marsvin::Matrix<float> L = {{3,0,0,0},
                                {2,1,0,0},
                                {1,2,1,0},
                                {1,1,1,1}};
    marsvin::Vector<float> b = {3,4,8,10};
    marsvin::Vector<float> x_real = {1,2,3,4};
    marsvin::Vector<float> x;
    marsvin::forward_substitution(L, b, x);
    EXPECT_EQ(x.size(), b.size());
    EXPECT_TRUE(marsvin::tools::compare(x,x_real));
    EXPECT_TRUE(marsvin::tools::compare(L*x,b));
}

TEST(ForwardSubstitution, Test_return_x) {
    marsvin::Logger logger_;
    marsvin::Matrix<float> L = {{3,0,0,0},
                                {2,1,0,0},
                                {1,2,1,0},
                                {1,1,1,1}};
    marsvin::Vector<float> b = {3,4,8,10};
    marsvin::Vector<float> x_real = {1,2,3,4};
    auto x = marsvin::forward_substitution(L, b);
    EXPECT_EQ(x.size(), b.size());
    EXPECT_TRUE(marsvin::tools::compare(x,x_real));
    EXPECT_TRUE(marsvin::tools::compare(L*x,b));
}

TEST(ForwardSubstitution, Test_memory_optimization) {
    marsvin::Logger logger_;
    marsvin::Matrix<float> L = {{3,0,0,0},
                                {2,1,0,0},
                                {1,2,1,0},
                                {1,1,1,1}};
    marsvin::Vector<float> b = {3,4,8,10};
    marsvin::Vector<float> x_real = {1,2,3,4};
    marsvin::forward_substitution_memory(L, b);
    EXPECT_TRUE(marsvin::tools::compare(b,x_real));
}
