#include <iostream>
#include "marsvin.hpp"

int main() {
    // Create logger instance.
    marsvin::Logger logger_;
    std::cout << "Matrix: Initialize a diagonal matrix" << std::endl;
    std::cout << "Diagonal vector input:" << std::endl;
    std::vector<float> diag_{10,20,30,40};
    logger_ << diag_;
    std::cout << "Matrix:" << std::endl;
    marsvin::Matrix<float> matrixDiagonal(diag_);
    logger_ << matrixDiagonal;

    std::cout << "Matrix: Initialize using another Matrix" << std::endl;
    marsvin::Matrix<float> matrixCopied(matrixDiagonal);
    logger_ << matrixCopied;
    std::cout << "Matrix: Initialize using a submatrix from another Matrix" << std::endl;
    marsvin::Matrix<float> subMatrix(matrixDiagonal,1,1,3,2);
    logger_ << subMatrix;
    // Set values using vector
    std::cout << "Matrix: Set all matrix elements values using a vector" << std::endl;
    marsvin::Matrix<float> newMatrix(2,2);
    std::cout << "Vector input:" << std::endl;
    std::vector<float> vec_new_{1,2,3,4};
    logger_ << vec_new_;
    std::cout << "Matrix:" << std::endl;
    newMatrix.SetVectorData(vec_new_);
    logger_ << newMatrix;
}

