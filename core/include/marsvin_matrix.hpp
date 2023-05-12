/**
 * @file marsvin_matrix.hpp
 *
 */

#ifndef MARSVIN_CORE_MARSVIN_MATRIX_HPP_
#define MARSVIN_CORE_MARSVIN_MATRIX_HPP_

#include "marsvin_base_matrix.hpp"
#include "marsvin_instance_counter.hpp"

namespace marsvin {

/**
 * @class Matrix
 * @brief Abstraction of a 2D container.
 */
template<typename T>
class Matrix : public BaseMatrix<T> {

  public:
    /**
     * @brief Default constructor.
     *
     * Creates an empty matrix. Size of the matrix is 0x0.
     *
     */
    Matrix();

    /**
     * @brief Constructor for matrix with initial size.
     *
     * Creates matrix of any size. Number of rows and columns are input
     * parameters of constructor. All matrix entries are zero.
     *
     * @param rows Number of rows.
     * @param columns Number of columns.
     *
     */
    Matrix(std::size_t rows, std::size_t columns);

    /**
     * @brief Constructor using initializer list
     *
     * The size of matrix should be specify.
     * The element/entries values are specified by the initializer list.
     *
     * @param rows Number of rows.
     * @param columns Number of columns.
     * @param initializer_list Initializer list.
     *
     */
    Matrix(std::size_t rows,
           std::size_t columns,
           std::initializer_list<T> initializer_list);
    /**
     * @brief Constructor using initializer list of initializer list
     *
     * @param initializer_list Initializer list of initializer list.
     *
     */
    Matrix(std::initializer_list<std::initializer_list<T>>
               double_initializer_list);

    /**
     * @brief Copy constructor
     *
     * Copy data allocated from input matrix instance to the new matrix
     * instance.
     */
    Matrix(const Matrix& other);

    /**
     * @brief Move constructor
     *
     * Move data allocated from input matrix instance to the new matrix
     * instance.
     */
    Matrix(Matrix&& other);

    std::size_t GetId() const;
    static std::size_t GetInstanceCounter();

  private:
    InstanceCounter<Matrix> instance_counter;
};
}  // namespace marsvin

#include "marsvin_matrix.impl.hpp"

#endif  // MARSVIN_CORE_MARSVIN_MATRIX_HPP_
