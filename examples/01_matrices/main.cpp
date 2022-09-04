#include <iostream>
#include "marsvin.hpp"

int main() {
    // Create logger instance.
    marsvin::Logger logger_;
    marsvin::Matrix<float> matrix(4,3);
    std::cout << "Number of Rows: " <<matrix.GetNumberOfRows() << std::endl;
    std::cout << "Number of Columns: " <<matrix.GetNumberOfColumns() << std::endl;
    std::cout << "Matrix: Empty Initialized" << std::endl;
    logger_ << matrix;
    // Check if is square matrix
    std::cout << "Is Square matrix? : " << matrix.IsSquareMatrix() << std::endl;
    // Set Entry
    std::cout << "Matrix: Set single entry" << std::endl;
    matrix.SetEntry(3,2,123);
    logger_ << matrix;
    // Set Row
    std::cout << "Matrix: Set single Row" << std::endl;
    std::vector<float> row1(3,10);
    matrix.SetRow(1, row1);
    logger_ << matrix;
    // Set Column
    std::cout << "Matrix: Set single Column" << std::endl;
    std::vector<float> column2(4,77);
    matrix.SetColumn(3,column2);
    logger_ << matrix;
    std::cout << "Matrix : Get diagonal from a non-square matrix" << std::endl;
    std::vector<float> vec = matrix.GetDiagonal();
    std::cout << "Diagonal vector size of non square matrix: " << vec.size() << std::endl;

    // Create square matrix
    std::cout << "Matrix: Create square matrix" << std::endl;
    marsvin::Matrix<float> matrixSquare(4);
    logger_ << matrixSquare;
    std::cout << "Is Square matrix? : " << matrixSquare.IsSquareMatrix() << std::endl;
    // Set diagonal in matrix
    std::cout << "Matrix: Set diagonal in Matrix" << std::endl;
    std::vector<float> diagonal_{1,2,3,4};
    std::cout << "Diagonal vector input:" << std::endl;
    logger_ << diagonal_;
    matrixSquare.SetDiagonal(diagonal_);
    std::cout << "Square Matrix 4x4. Diagonal Set:" << std::endl;
    logger_ << matrixSquare;
    matrixSquare.SwapRows(1,2);
    std::cout << "Swap Rows 1 and 2" << std::endl;
    logger_ << matrixSquare;
    std::vector<float> matrix_diagonal = matrixSquare.GetDiagonal();
    std::cout << "Matrix read diagonal:" << std::endl;
    logger_ << matrix_diagonal;

    // ##############################

    std::cout << "Matrix: Initialize a diagonal matrix" << std::endl;
    std::cout << "Diagonal vector input:" << std::endl;
    std::vector<float> diag_{10,20,30,40};
    logger_ << diag_;
    std::cout << "Matrix:" << std::endl;
    marsvin::Matrix<float> matrixDiagonal(diag_);
    logger_ << matrixDiagonal;

    /*
    // Initialize using another matrix
    marsvin::Matrix<float> matrixCopied(matrixDiagonal);
    std::cout << "Initialize new matrix using another :" << std::endl;
    logger_ << matrixCopied;
    std::cout << "Submatrix initialization" << std::endl;
    std::cout << "matrisDiagonal number of Rows: " <<matrixDiagonal.GetNumberOfRows()  << std::endl;
    // Initialize using sub matrix
    marsvin::Matrix<float> subMatrix(matrixDiagonal,1,1,3,2);
    std::cout << "Initialize as a submatrix from anoter matrix :" << std::endl;
    logger_ << subMatrix;
    // Set values using vector
    marsvin::Matrix<float> newMatrix(2,2);
    std::vector<float> vec_new_{1,2,3,4};
    newMatrix.SetVectorData(vec_new_);
    std::cout << "New matrix" << std::endl;
    logger_ << newMatrix;
    */
}

