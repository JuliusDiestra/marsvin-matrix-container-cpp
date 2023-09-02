
#include "gtest/gtest.h"
#include "marsvin/lu_decomposition/partial_pivoting.hpp"
#include "marsvin/tools/logger.hpp"
#include "marsvin/tools/compare_matrix.hpp"

TEST(PartialPivoting, Algorithm_2x2) {
    marsvin::Logger logger_;
    marsvin::Matrix<float> A = {{1,2},
                              {3,4}};
    auto lud_matrices = marsvin::lud::partial_pivoting(A);
    auto L = lud_matrices.at(0);
    auto U = lud_matrices.at(1);
    auto P = lud_matrices.at(2);
    std::cout << "P*A :" << "\n";
    logger_ << P*A;
    std::cout << "L*U :" << "\n";
    logger_ << L*U;
    float tolerance = 0.1;
    EXPECT_TRUE(marsvin::tools::CompareMatrix(P*A,L*U,tolerance));
}

TEST(PartialPivoting, Algorithm_3x3) {
    marsvin::Logger logger_;
    marsvin::Matrix<float> A = {{1.0,2.0,3.0},
                                {4.0,5.0,6.0},
                                {7.0,8.0,9.0}};
    auto lud_matrices = marsvin::lud::partial_pivoting(A);
    auto L = lud_matrices.at(0);
    auto U = lud_matrices.at(1);
    auto P = lud_matrices.at(2);
    std::cout << "P :" << "\n";
    logger_ << P;
    std::cout << "A :" << "\n";
    logger_ << A;
    std::cout << "L :" << "\n";
    logger_ << L;
    std::cout << "U :" << "\n";
    logger_ << U;
    std::cout << "P*A :" << "\n";
    logger_ << P*A;
    std::cout << "L*U :" << "\n";
    logger_ << L*U;
    float tolerance = 0.1;
    EXPECT_TRUE(marsvin::tools::CompareMatrix(P*A,L*U,tolerance));
}

TEST(PartialPivoting, Algorithm_4x4) {
    marsvin::Logger logger_;
    marsvin::Matrix<float> A = {{2.0,3.0,1.0,5.0},
                                {6.0,13.0,5.0,19.0},
                                {2.0,19.0,10.0,23.0},
                                {4.0,10.0,11.0,31.0}};
    auto lud_matrices = marsvin::lud::partial_pivoting(A);
    auto L = lud_matrices.at(0);
    auto U = lud_matrices.at(1);
    auto P = lud_matrices.at(2);
    std::cout << "P :" << "\n";
    logger_ << P;
    std::cout << "A :" << "\n";
    logger_ << A;
    std::cout << "L :" << "\n";
    logger_ << L;
    std::cout << "U :" << "\n";
    logger_ << U;
    std::cout << "P*A :" << "\n";
    logger_ << P*A;
    std::cout << "L*U :" << "\n";
    logger_ << L*U;
    float tolerance = 0.1;
    EXPECT_TRUE(marsvin::tools::CompareMatrix(P*A,L*U,tolerance));
}

