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
    // Get row for m1
    std::cout << "### Reading rows for m1 ##" << std::endl;
    std::cout << "m1 (1,1) : " << m1.GetEntry(1,1) << std::endl;
    std::vector<float> vec = m1.GetRow(1);
    std::cout << "row 1 size: " << vec.size() << std::endl;
    std::cout << "m1 (1,1) : " << vec.at(0) << std::endl;
    std::cout << "m1 (1,2) : " << vec.at(1) << std::endl;
    std::cout << "row 2 size: " << vec.size() << std::endl;
    vec = m1.GetRow(2);
    std::cout << "m2 (1,1) : " << vec.at(0) << std::endl;
    std::cout << "m2 (1,2) : " << vec.at(1) << std::endl;   
    // Adding
    marsvin::Matrix<float> m3 = marsvin::matrix::Operations::Addition(m1,m2);
    std::cout << "m3: m1 + m2 " << std::endl;
    m3.Print();
    // Multiplication
    marsvin::Matrix<float> m4 = marsvin::matrix::Operations::Multiplication(m1,m2);
    std::cout << "m4: m1*m2 " << std::endl;
    m4.Print();
    // Scalar Multiplication
    marsvin::Matrix<float> m44 = marsvin::matrix::Operations::ScalarMultiplication(m4,2.0f);
    std::cout << "2*m4 :" << std::endl;
    m44.Print();
    // Get Transpose
    marsvin::Matrix<float> m5 = marsvin::matrix::Operations::Transpose(m1);
    std::cout << "m1 :" << std::endl;
    m1.Print();
    std::cout << "m1 transpose: " << std::endl;
    m5.Print();
}

