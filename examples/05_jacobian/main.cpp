#include <iostream>
#include "marsvin.hpp"
#include <cmath>

int main() {
    // Function setting
    // F(X) = [x^4 + 3*x*y^2; 5*y^2 - 2*x*y + 1]
    // X = (x,y)
    // Jacobian:
    // jacF = [4*x^3 + 3*y^2,6*x*y; -2*y,10*y-2*x]
    // jacF at X = (1,2)
    // jacF = [16,12;-4,18]
    std::function<float(std::vector<float>)> F_1 = [](std::vector<float> X){ 
        float x = X.at(0);
        float y = X.at(1);
        return std::pow(x,4) + 3*x*std::pow(y,2);
    };
    std::function<float(std::vector<float>)> F_2 = [](std::vector<float> X){ 
        float x = X.at(0);
        float y = X.at(1);
        return 5*std::pow(y,2) - 2*x*y + 1;
    };
    std::vector<std::function<float(std::vector<float>)>> F{F_1,F_2};
    std::vector<float> Xv{1,2};
    float dx = 0.01;
    marsvin::Matrix<float> jacobF = marsvin::Differential::Jacobian(F,Xv,dx);
    jacobF.Print();
}

