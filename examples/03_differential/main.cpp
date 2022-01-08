#include <iostream>
#include "marsvin.hpp"
#include <cmath>

int main() {
    std::function<float(float)> fun1 = [](float x){return x*x;};
    float x_value = 2.0;
    float dx = 0.01;
    float result = marsvin::Differential::FirstDerivative(fun1,x_value,dx);
    float result2 = marsvin::Differential::SecondDerivative(fun1,x_value,dx);
    std::cout << "First Derivative of x^2 at x = 2 : " << result << std::endl;
    std::cout << "Second Derivative of x^2 at x = 2 : " << result2 << std::endl;
    std::function<float(float)> fun2 = [](float x){return std::sin(x);};
    float pi = std::atan(1)*4;
    result = marsvin::Differential::FirstDerivative(fun2,pi/3,0.01F);
    std::cout << "First Derivative of sin(x) at x = pi/3 : " << result << std::endl;
}

