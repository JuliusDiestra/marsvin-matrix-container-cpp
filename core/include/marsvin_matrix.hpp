/**
 * @file marsvin_matrix.hpp
 *
 */

#ifndef MARSVIN_CORE_MARSVIN_MATRIX_HPP_
#define MARSVIN_CORE_MARSVIN_MATRIX_HPP_

#include "marsvin_base_matrix.hpp"

namespace marsvin {

/**
 * @class Matrix
 * @brief Abstraction of a 2D container.
 */
template<typename T>
class Matrix : public BaseMatrix<T> {
    /**
     * @brief Constructor using initializer list of initializer list
     *
     * @param initializer_list Initializer list of initializer list.
     *
     */
  public:
    Matrix();
    Matrix(std::size_t rows, std::size_t columns);
    Matrix(std::size_t rows,
           std::size_t columns,
           std::initializer_list<T> initializer_list);
    Matrix(std::initializer_list<std::initializer_list<T>>
               double_initializer_list);
    Matrix(const Matrix& other);
    Matrix(Matrix&& other);
};
}  // namespace marsvin

#include "marsvin_matrix.impl.hpp"

#endif  // MARSVIN_CORE_MARSVIN_MATRIX_HPP_
