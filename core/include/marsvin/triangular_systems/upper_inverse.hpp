/**
 * @file upper_inverse.hpp
 *
 */

#ifndef MARSVIN_TRIANGULAR_SYSTEMS_UPPER_INVERSE_HPP_
#define MARSVIN_TRIANGULAR_SYSTEMS_UPPER_INVERSE_HPP_

#include "marsvin/containers/matrix.hpp"

namespace marsvin {
namespace triangular_matrix {

template<typename T>
void upper_inverse(const ::marsvin::Matrix<T>& U, ::marsvin::Matrix<T>& X) {
    // Check L is square
    if (!U.is_square()) {
        throw marsvin::Exception(marsvin::StatusCode::TypeErrorSquareMatrix());
    }
    // Check if X is empty. It is not not empty, check its size.
    if (X.empty()) {
        X.resize(U.rows(), U.columns());
    } else {
        if ( (U.rows() != X.rows()) || (U.columns() != U.columns()) ) {
            throw marsvin::Exception(marsvin::StatusCode::TypeErrorEqualSize());
        }
    }
    std::size_t n{U.rows()};
    T sum;
    for (std::size_t k = 0; k <= (n-1); ++k) {
        for (std::size_t j = 0; j <= (n-1); ++j) {
            if (k==j) {
                X.at(k,j) = 1/U.at(k,j);
            } else if (k < j) {
                sum = 0;
                for (std::size_t i = k; i <= j-1; ++i) {
                    sum = sum + U.at(i,j)*X.at(k,i);
                }
                X.at(k,j) = -sum/U.at(j,j);
            } else {
                X.at(k,j) = 0;
            }
        }
    }
};

template<typename T>
marsvin::Matrix<T> upper_inverse(const ::marsvin::Matrix<T>& U) {
    marsvin::Matrix<T> X(U.rows(), U.columns());
    upper_inverse(U, X);
    return X;
};

template<typename T>
void upper_inverse_memory(::marsvin::Matrix<T>& U) {
    upper_inverse(U, U);
};

}  // namespace triangular_matrix
}  // namespace marsvin

#endif  // MARSVIN_TRIANGULAR_SYSTEMS_LOWER_INVERSE_HPP_
