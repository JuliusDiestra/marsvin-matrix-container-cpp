/**
 * @file lower_inverse.hpp
 *
 */

#ifndef MARSVIN_TRIANGULAR_SYSTEMS_LOWER_INVERSE_HPP_
#define MARSVIN_TRIANGULAR_SYSTEMS_LOWER_INVERSE_HPP_

#include "marsvin/containers/matrix.hpp"

namespace marsvin {
namespace triangular_matrix {

template<typename T>
void lower_inverse(const ::marsvin::Matrix<T>& L, ::marsvin::Matrix<T>& X) {
    // Check L is square
    if (!L.is_square()) {
        throw marsvin::Exception(marsvin::StatusCode::TypeErrorSquareMatrix());
    }
    // Check if X is empty. It is not not empty, check its size.
    if (X.empty()) {
        X.resize(L.rows(), L.columns());
    } else {
        if ((L.rows() != X.rows()) || (L.columns() != X.columns())) {
            throw marsvin::Exception(marsvin::StatusCode::TypeErrorEqualSize());
        }
    }
    std::size_t n{L.rows()};
    T sum;
    for (std::size_t k = 0; k <= (n - 1); ++k) {
        X.at(k, k) = 1 / L.at(k, k);
        for (std::size_t i = k + 1; i <= (n - 1); ++i) {
            sum = 0;
            for (std::size_t j = k; j <= (i - 1); ++j) {
                sum = sum + L.at(i, j) * X.at(j, k);
            }
            X.at(i, k) = -sum / L.at(i, i);
        }
    }
};

template<typename T>
marsvin::Matrix<T> lower_inverse(const ::marsvin::Matrix<T>& L) {
    marsvin::Matrix<T> X(L.rows(), L.columns());
    lower_inverse(L, X);
    return X;
};

template<typename T>
void lower_inverse_memory(::marsvin::Matrix<T>& L) {
    lower_inverse(L, L);
};

}  // namespace triangular_matrix
}  // namespace marsvin

#endif  // MARSVIN_TRIANGULAR_SYSTEMS_LOWER_INVERSE_HPP_
