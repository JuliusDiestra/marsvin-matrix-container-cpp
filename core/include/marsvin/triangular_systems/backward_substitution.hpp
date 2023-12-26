/**
 * @file forward_substitution.hpp
 *
 */

#ifndef MARSVIN_TRIANGULAR_SYSTEMS_BACKWARD_SUBSTITUTION_HPP_
#define MARSVIN_TRIANGULAR_SYSTEMS_BACKWARD_SUBSTITUTION_HPP_

#include "marsvin/containers/matrix.hpp"
#include "marsvin/containers/vector.hpp"

namespace marsvin {

template<typename T>
void backward_substitution(const ::marsvin::Matrix<T>& U,
                          const ::marsvin::Vector<T>& b,
                          ::marsvin::Vector<T>& x) {
    // Check U is square
    if (!U.is_square()) {
        throw marsvin::Exception(marsvin::StatusCode::TypeErrorSquareMatrix());
    }
    // Check if U rows or columns are equal to size of b
    if (U.rows() != b.size()) {
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
    for (int k = U.rows() - 1; k >= 0; --k) {
        // TBD : Add check if U.at(k,k) is close to Zero.
        x.at(k) = b.at(k);
        if (k >= 0) {
            for (std::size_t j = k + 1; j <= U.rows() -1 ; ++j) {
                x.at(k) = x.at(k) - U.at(k, j) * x.at(j);
            }
        }
        x.at(k) = x.at(k) / U.at(k, k);
    }
};

}  // namespace marsvin

#endif  // MARSVIN_TRIANGULAR_SYSTEMS_BACKWARD_SUBSTITUTION_HPP_
