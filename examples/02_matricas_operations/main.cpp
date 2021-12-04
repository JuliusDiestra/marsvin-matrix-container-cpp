#include <iostream>
#include "marsvin.hpp"

int main() {
    // m1
    marsvin::Matrix<float> m1(2,2);
    std::vector<float> row1(2,10);
    std::vector<float> row2(2,20);
    m1.SetRow(1, row1);
    m1.SetRow(2, row2);
    std::cout << "m1: " << std::endl;
    m1.Print();
    // m2
    marsvin::Matrix<float> m2(2,2);
    std::vector<float> row4(2,30);
    std::vector<float> row5(2,40);
    m2.SetRow(1, row4);
    m2.SetRow(2, row5);
    std::cout << "m2: " << std::endl;
    m2.Print();
    // Adding
    marsvin::Matrix<float> m3 = marsvin::matrix::BasicOperations::Addition(m1,m2);
    std::cout << "m3: " << std::endl;
    m3.Print(); 
}

