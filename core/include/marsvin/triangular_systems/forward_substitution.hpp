/**
 * @file forward_substitution.hpp
 *
 */

#ifndef MARSVIN_TRIANGULAR_SYSTEMS_FORWARD_SUBSTITUTION_HPP_
#define MARSVIN_TRIANGULAR_SYSTEMS_FORWARD_SUBSTITUTION_HPP_

#include "marsvin/containers/matrix.hpp"
#include "marsvin/containers/vector.hpp"

namespace marsvin {

template<typename T>
void forward_substitution(const ::marsvin::Matrix<T>& L,
                          const ::marsvin::Vector<T>& b,
                          ::marsvin::Vector<T>& x) {

    // Check L is square
    if (!L.is_square()) {
        throw marsvin::Exception(marsvin::StatusCode::TypeErrorSquareMatrix());
    }
    // Check if L rows or columns are equal to size of b
    if (L.rows() != b.size()) {
        throw marsvin::Exception(
            marsvin::StatusCode::TypeErrorSolveLinearEquantionDimensions());
    }
    // Check x and b sizes
    if (x.empty()) {
        x.resize(b.size());
    } else {
        if (x.size() != b.size()) {
            throw marsvin::Exception(marsvin::StatusCode::TypeErrorEqualSize());
        }
    }
    for (std::size_t k = 0; k < L.rows(); ++k) {
        x.at(k) = b.at(k);
        if (k > 0) {
            for (std::size_t j = 0; j <= (k - 1); ++j) {
                x.at(k) = x.at(k) - L.at(k, j) * x.at(j);
            }
        }
        x.at(k) = x.at(k) / L.at(k, k);
    }
};

template<typename T>
marsvin::Vector<T> forward_substitution(const ::marsvin::Matrix<T>& L,
                                        const ::marsvin::Vector<T>& b) {
    marsvin::Vector<T> x(b.size());
    forward_substitution(L, b, x);
    return x;
};

template<typename T>
void forward_substitution_memory(const ::marsvin::Matrix<T>& L,
                                 ::marsvin::Vector<T>& b) {
    forward_substitution(L, b, b);
};

}  // namespace marsvin

#endif  // MARSVIN_TRIANGULAR_SYSTEMS_FORWARD_SUBSTITUTION_HPP_
