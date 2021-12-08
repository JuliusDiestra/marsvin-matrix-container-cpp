#ifndef MARSVIN_DIFFERENTIAL_HPP_
#define MARSVIN_DIFFERENTIAL_HPP_

#include <functional>

namespace marsvin {

class Differential {
    public:
        Differential();
        template<typename T> static T Derivative(std::function<T(T)> f,T x, T dx);
};

}


template<typename T> T marsvin::Differential::Derivative(std::function<T(T)> f,T x, T dx) {
    // f'(x) = 
    T df;
    T m1 = (f(x+dx) - f(x-dx))/(2*dx);
    T m2 = (f(x+2*dx) - f(x-2*dx))/(4*dx);
    T m3 = (f(x+3*dx) - f(x-3*dx))/(6*dx);
    df = (3/2)*m1 - (3/5)*m2 +(1/10)*m3;
    return df;
}

#endif // MARSVIN_DIFFERENTIAL_HPP_
