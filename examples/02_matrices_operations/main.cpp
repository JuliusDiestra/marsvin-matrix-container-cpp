#include <iostream>
#include "marsvin.hpp"

int main() {
    // Create logger instance
    marsvin::Logger logger_;
    // m1
    marsvin::Matrix<float> m1(2,2);
    std::vector<float> row1(2,10);
    std::vector<float> row2(2,20);
    m1.SetRow(1, row1);
    m1.SetRow(2, row2);
    std::cout << "m1: " << std::endl;
    logger_ << m1;
    // Get Transpose
    marsvin::Matrix<float> m1_transpose;
    m1_transpose = m1.Transpose();
    std::cout << "m1 :" << std::endl;
    logger_ << m1;
    std::cout << "m1 transpose: " << std::endl;
    logger_ << m1_transpose;
}

