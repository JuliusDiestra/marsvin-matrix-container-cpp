/**
 * @file marsvin_lud_algorithms.hpp
 *
 */

#ifndef MARSVIN_CORE_LUD_ALGORITHMS_HPP_
#define MARSVIN_CORE_LUD_ALGORITHMS_HPP_

#include <cstdlib>

#include "marsvin_logger.hpp"
#include "marsvin_matrix.hpp"

namespace marsvin {
namespace lud {

template<typename T>
std::vector<::marsvin::Matrix<T>> partial_pivoting(::marsvin::Matrix<T>& A) {
    marsvin::Logger logger_;
    // Initial conditions
    std::size_t n = A.rows();
    ::marsvin::Matrix<T> L(n);
    L.set_diagonal(1);
    ::marsvin::Matrix<T> U{A};
    ::marsvin::Matrix<T> P(n);
    P.set_diagonal(1);

    std::size_t i;
    for (std::size_t k = 0; k <= (n - 2); ++k) {
        // Find i >= k to maximize |U(i,k)|
        i = k;
        for (std::size_t idx = k; idx <= (n - 2); ++idx) {
            if (std::abs(U.at(idx, k)) < std::abs(U.at(idx + 1, k))) {
                i = idx + 1;
            }
        }
        // Swap U(k,k:n) <-> U(i,k:n)
        for (std::size_t idx = k; idx <= (n - 1); ++idx) {
            std::swap(U.at(k, idx), U.at(i, idx));
        }
        // Swap L(k,1:k-1) <-> L(i,1:k-1)
        if (k >= 1) {
            for (std::size_t idx = 0; idx <= (k - 1); ++idx) {
                std::swap(L.at(k, idx), L.at(i, idx));
            }
        }
        // Swap P(k,:) <-> P(i,:)
        P.swap_rows(k, i);
        // for j = k+1:m
        //      L(j,k) = U(j,k)/U(k,k)
        //      U(j,k:m) = U(j,k:m) − L(j, k)*U(k,k:m)
        for (std::size_t j = k + 1; j <= (n - 1); ++j) {
            L.at(j, k) = U.at(j, k) / U.at(k, k);
            for (std::size_t idx = k; idx <= (n - 1); ++idx) {
                U.at(j, idx) = U.at(j, idx) - L.at(j, k) * U.at(k, idx);
            }
        }
    }
    // Results
    std::vector<::marsvin::Matrix<T>> result_matrices;
    result_matrices.reserve(3);
    result_matrices.push_back(std::move(L));
    result_matrices.push_back(std::move(U));
    result_matrices.push_back(std::move(P));
    return result_matrices;
}

}  // namespace lud
}  // namespace marsvin

#endif  // MARSVIN_CORE_LUD_ALGORITHMS_HPP_
