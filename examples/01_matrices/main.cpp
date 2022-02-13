#include <iostream>
#include "marsvin.hpp"

int main() {
    marsvin::Matrix<float> matrix(4,3);
    std::cout << "Number of Rows: " <<matrix.GetNumberOfRows() << std::endl;
    std::cout << "Number of Columns: " <<matrix.GetNumberOfColumns() << std::endl;
    std::cout << "Matrix: Empty Initialized " << std::endl;
    matrix.Print();
    // Set matrix with values
    std::vector<float> row1(3,10);
    std::vector<float> row2(3,20);
    std::vector<float> row3(3,30);
    std::vector<float> row4(3,40);
    matrix.SetRow(1, row1);
    matrix.SetRow(2, row2);
    matrix.SetRow(3, row3);
    matrix.SetRow(4, row4);
    std::cout << "Matrix with Values: " << std::endl;
    matrix.Print();
    std::cout << "Is Square matrix? :" << matrix.IsSquare() << std::endl;
    matrix.SetEntry(3,2,99);
    matrix.Print();
    // Set matrix with values per row
    std::vector<float> column2(4,77);
    matrix.SetColumn(2,column2);
    std::cout << "Matrix after inserting column in row 2" << std::endl;
    matrix.Print();
    // Set matrix diagonal
    marsvin::Matrix<float> matrixSquare(4);
    std::cout << "Square Matrix 4x4" << std::endl;
    matrixSquare.Print();
    std::vector<float> diagonal_{1,2,3,4};
    std::cout << "Diagonal length: " << diagonal_.size() << std::endl;
    matrixSquare.SetDiagonal(diagonal_);
    std::cout << "Square Matrix 4x4. Diagonal Set:" << std::endl;
    matrixSquare.Print();
    std::vector<float> vec = matrixSquare.GetDiagonal();
    std::cout << "Diagonal vector size: " << vec.size() << std::endl;
    std::cout << "Diagonal vector third element: " << vec.at(2) << std::endl;
    vec = matrix.GetDiagonal();
    std::cout << "Diagonal vector size of non square matrix: " << vec.size() << std::endl;
    // Initialize Diagonal Matrix
    std::vector<float> diag_{10,20,30,40};
    marsvin::Matrix<float> matrixDiagonal(diag_);
    matrixDiagonal.Print();
    matrixDiagonal.SwapRows(1,2);
    std::cout << "Swap Rows 1 and 2" << std::endl; 
    matrixDiagonal.Print();
    // Initialize using another matrix
    marsvin::Matrix<float> matrixCopied(matrixDiagonal);
    std::cout << "Initialize new matrix using another :" << std::endl; 
    matrixCopied.Print();
}

