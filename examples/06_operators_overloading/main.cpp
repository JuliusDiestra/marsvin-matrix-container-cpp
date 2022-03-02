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
    // m3
    marsvin::Matrix<float> m3(2,2);
    std::vector<float> row6(2,100);
    std::vector<float> row7(2,100);
    m3.SetRow(1, row6);
    m3.SetRow(2, row7);
    std::cout << "m3: " << std::endl;
    m3.Print();
    // Addition
    marsvin::Matrix<float> matrixAddition;
    matrixAddition = m1 + m2;
    std::cout << "Addition m1 + m2: " << std::endl;
    matrixAddition.Print();
    // Addition of 3 matrices
    matrixAddition = m1 + m2 + m3;
    std::cout << "Addition m1 + m2 + m3: " << std::endl;
    matrixAddition.Print();
    // Addition with scalar
    matrixAddition = m1 + 2.0f;
    std::cout << "Addition m1 + 2.0: " << std::endl;
    matrixAddition.Print();
    // Addition with scalar
    matrixAddition = 2.0f + m1;
    std::cout << "Addition 2.0 + m1: " << std::endl;
    matrixAddition.Print();
    
}

