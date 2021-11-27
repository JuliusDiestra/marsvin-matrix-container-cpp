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
    matrix.SetEntry(99,3,2);
    matrix.Print();
}

