#include <iostream>
#include "marsvin.hpp"
#include <cmath>

int main() {
    // Function setting
    // F(X) = x^2 + y^2; where X = (x,y);
    // dF(X)/dX = [dF(x,y_val)/dx at ; dF(x_val)/dy] at (x_val,y_val)
    // dF(X)/dX = [2*x; 2*y] at (1,1) = [2;2]
    std::function<float(std::vector<float>)> F = [](std::vector<float> X){
        return X.at(0)*X.at(0) + X.at(1)*X.at(1);
    };
    std::vector<float> Xv{1,1};
    float dx = 0.01;
    std::vector<float> gradF = marsvin::Differential::Gradient(F,Xv,dx);
    std::cout << "Gradient of F at (1,1)" << std::endl;
    std::cout << "Gradient of F at (1,1) : gradF(0) = " << gradF.at(0) << std::endl;
    std::cout << "Gradient of F at (1,1) : gradF(1) = " << gradF.at(1) << std::endl;
}

