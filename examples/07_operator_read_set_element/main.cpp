#include <iostream>
#include "marsvin.hpp"

int main() {
    // Create logger instance.
    marsvin::Logger logger_;
    // Create matrix instance
    marsvin::Matrix<float> my_matrix(2,2);
    // Print matrix with zeros
    std::cout << "Initial status of matrix:" << std::endl;
    logger_ << my_matrix;
    // Set value
    my_matrix(1,1) = 10;
    my_matrix(2,2) = 20;
    std::cout << "Matrix after setting value:" << std::endl;
    logger_ << my_matrix;
    std::cout << "Element (2,2) in Matrix: " << my_matrix(2,2) << std::endl;
}

