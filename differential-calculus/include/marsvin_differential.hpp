#ifndef MARSVIN_DIFFERENTIAL_HPP_
#define MARSVIN_DIFFERENTIAL_HPP_

#include "marsvin_matrix.hpp"
#include <functional>
#include <vector>

namespace marsvin {

class Differential {
    public:
        Differential();
        template<typename T> static T FirstDerivative(std::function<T(T)> f,T x, T dx);
        template<typename T> static T SecondDerivative(std::function<T(T)> f,T x, T dx);
        template<typename T> static std::vector<T> Gradient(std::function<T(std::vector<T>)> f,std::vector<T> Xv, T dx);
        template<typename T> static marsvin::Matrix<T> Jacobian(std::vector<std::function<T(std::vector<T>)>> F, std::vector<T> X, T dx);
};
}

// Implementation

template<typename T> T marsvin::Differential::FirstDerivative(std::function<T(T)> f,T x, T dx) {
    // f'(x) = 
    T df;
    T m1 = (f(x+dx) - f(x-dx))/(2*dx);
    T m2 = (f(x+2*dx) - f(x-2*dx))/(4*dx);
    T m3 = (f(x+3*dx) - f(x-3*dx))/(6*dx);
    df = (3/2)*m1 - (3/5)*m2 +(1/10)*m3;
    return df;
}

template<typename T> T marsvin::Differential::SecondDerivative(std::function<T(T)> f,T x, T dx) {
    // f''(x) = [ f(x+dx) - 2*f(x) + f(x-dx) ]/dx^2  
    T ddf = (f(x+dx) - 2*f(x) + f(x-dx))/(dx*dx);
    return ddf;
}

template<typename T> std::vector<T> marsvin::Differential::Gradient(std::function<T(std::vector<T>)> f,std::vector<T> Xv, T dx) {
    std::vector<T> X_vj;
    std::function<T(T)> g;
    std::vector<T> grad_f;
    for (int j = 0; j < Xv.size(); j++) {
        X_vj.clear();
        X_vj = Xv;
        // Set g(xj) = f(X_vj)
        g = [f,Xv,j](T x_j){
            std::vector<T> X_vj;
            X_vj = Xv;
            X_vj.at(j) = x_j;
            return f(X_vj);
        };
        // Store grad_f
        grad_f.push_back(FirstDerivative(g,Xv.at(j),dx));
    }
    return grad_f;
}

template<typename T> marsvin::Matrix<T> marsvin::Differential::Jacobian(std::vector<std::function<T(std::vector<T>)>> F, std::vector<T> Xv, T dx) {
    std::size_t n = Xv.size();
    std::size_t m = F.size();
    marsvin::Matrix<T> jacobian(m,n);
    std::function<T(std::vector<T>)> f_j;
    for (int j = 0; j < m; j++) {
        f_j = F.at(j);
        jacobian.SetRow(j+1,Gradient(f_j,Xv,dx));
    }
    return jacobian;
}

#endif // MARSVIN_DIFFERENTIAL_HPP_
