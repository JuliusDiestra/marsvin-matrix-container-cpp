#include <iostream>
#include "marsvin.hpp"

int main() {
    marsvin::Matrix<float> matrix(4,3);
    std::cout << "Number of Rows: " <<matrix.GetNumberOfRows() << std::endl;
    std::cout << "Number of Columns: " <<matrix.GetNumberOfColumns() << std::endl;
    std::cout << "Matrix: Empty Initialized " << std::endl;
    matrix.Print();
    std::vector<float> row1(3,10);
    std::vector<float> row3(3,20);
    std::vector<float> row4(3,50);

    matrix.SetValue(1, row1);
    matrix.SetValue(3, row3);
    matrix.SetValue(4, row4);
    std::cout << "Matrix with Values: " << std::endl;
    matrix.Print();
}

