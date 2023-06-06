/**
 * @file marsvin_base_matrix.hpp
 *
 */

#ifndef MARSVIN_CORE_MARSVIN_BASE_MATRIX_HPP_
#define MARSVIN_CORE_MARSVIN_BASE_MATRIX_HPP_

#include <utility>

#include "marsvin_exception.hpp"

namespace marsvin {

/**
 * @class BaseMatrix
 * @brief Base matrix class with minimum features.
 *
 */
template<typename T>
class BaseMatrix {
  public:
    using value_type = T;
    using size_type = std::size_t;
    using reference = value_type&;
    using const_reference = const value_type&;
    using iterator = T*;
    /**
     * @brief Default constructor.
     *
     * Creates an empty matrix. Size of the matrix is 0x0.
     *
     */
    BaseMatrix();
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
    BaseMatrix(std::size_t rows, std::size_t columns);

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
    BaseMatrix(std::size_t rows,
               std::size_t columns,
               std::initializer_list<T> initializer_list);

    /**
     * @brief Copy constructor
     *
     * Copy data allocated from input matrix instance to the new matrix
     * instance.
     */
    BaseMatrix(const BaseMatrix& other);

    /**
     * @brief Move constructor
     *
     * Move data allocated from input matrix instance to the new matrix
     * instance.
     */
    BaseMatrix(BaseMatrix&& other);

    /**
     * Base matrix destructor
     */
    ~BaseMatrix();

    /**
     * @brief Copy Assignment
     */
    BaseMatrix& operator=(const BaseMatrix& other);

    /**
     * @brief Move Assignment
     */
    BaseMatrix& operator=(BaseMatrix&& other);

    /**
     * @brief Method to check if matrix is empty.
     */
    bool empty() const;

    /**
     * @brief Method to get the number of rows of the matrix.
     *
     */
    std::size_t rows() const;

    /**
     * @brief Method to get the number of columns of the matrix.
     *
     */
    std::size_t columns() const;

    /**
     * @brief Method to get matrix size. Total number of elements/entries.
     *
     */
    std::size_t size() const;

    /**
     *  @brief Method to set matrix entry/element.
     *
     *  @param row Row index.
     *  @param column Column index.
     *
     */
    T& at(std::size_t row, std::size_t column);

    /**
     *  @brief Method to get matrix entry/element.
     *
     *  @param row Row index.
     *  @param column Column index.
     *
     */
    const T& at(std::size_t row, std::size_t column) const;

    /**
     * @brief Method to resize matrix container.
     *
     * @param rows Number of rows
     * @param columns Number of columns
     *
     */
    void resize(std::size_t rows, std::size_t columns);

    /**
     * @brief Method to clear matrix container.
     * Data is deallocated. Rows and columns are set to zero.
     *
     */
    void clear();

    /**
     * @brief Pointer to the first data member of matrix.
     *
     */
    iterator begin();

    /**
     * @brief Pointer to the last data member of matrix.
     *
     */
    iterator end();

    /**
     * @brief Method to perform the addition of two matrix instances.
     *
     * @param m_lhs Matrix left hand side.
     * @param m_rhs Matrix right hand side.
     *
     */
    template<typename U>
    friend BaseMatrix<U> operator+(const BaseMatrix<U>& m_lhs,
                                   const BaseMatrix<U>& m_rhs);
    /**
     * @brief Method to perform the addition of one matrix instance and one
     * scalar. The scalar is added to each matrix element.
     *
     * @param m_lhs Matrix left hand side.
     * @param scalar Scalar value.
     *
     */
    template<typename U>
    friend BaseMatrix<U> operator+(const BaseMatrix<U>& m_lhs, const U& scalar);
    /**
     * @brief Method to perform the addition of one scalar and one matrix
     * instance. The scalar is added to each matrix element.
     *
     * @param scalar Scalar value.
     * @param m_rhs Matrix right hand side.
     *
     */
    template<typename U>
    friend BaseMatrix<U> operator+(const U& scalar, const BaseMatrix<U>& m_rhs);

    /**
     * @brief Method to perform substraction of two matrix instances.
     *
     * @param m_lhs Matrix left hand side.
     * @param m_rhs Matrix right hand side.
     *
     */
    template<typename U>
    friend BaseMatrix<U> operator-(const BaseMatrix<U>& m_lhs,
                                   const BaseMatrix<U>& m_rhs);
    /**
     * @brief Method to perform substraction of one matrix instance and one
     * scalar. The scalar is substracted to each matrix element.
     *
     * @param m_lhs Matrix left hand side.
     * @param scalar Scalar value.
     *
     */
    template<typename U>
    friend BaseMatrix<U> operator-(const BaseMatrix<U>& m_lhs, const U& scalar);
    /**
     * @brief Method to perform substraction of one scalar and one matrix
     * instance. The scalar is substracted to each matrix element.
     *
     * @param scalar Scalar value.
     * @param m_rhs Matrix right hand side.
     *
     */
    template<typename U>
    friend BaseMatrix<U> operator-(const U& scalar, const BaseMatrix<U>& m_rhs);

    /**
     * @brief Method to perform the multiplication of two matrix instances.
     *
     * @param m_lhs Matrix left hand side.
     * @param m_rhs Matrix right hand side.
     *
     */
    template<typename U>
    friend BaseMatrix<U> operator*(const BaseMatrix<U>& m_lhs,
                                   const BaseMatrix<U>& m_rhs);
    /**
     * @brief Method to perform the multiplication of one matrix instance and
     * one scalar. The scalar is multiplied to each matrix element.
     *
     * @param m_lhs Matrix left hand side.
     * @param scalar Scalar value.
     *
     */
    template<typename U>
    friend BaseMatrix<U> operator*(const BaseMatrix<U>& m_lhs, const U& scalar);
    /**
     * @brief Method to perform the multiplication of one scalar and one matrix
     * instance. The scalar is multiplied to each matrix element.
     *
     * @param scalar Scalar value.
     * @param m_rhs Matrix right hand side.
     *
     */
    template<typename U>
    friend BaseMatrix<U> operator*(const U& scalar, const BaseMatrix<U>& m_rhs);

    /**
     * @brief Method to check if two matrices are equal.
     *
     * @param m_lhs Matrix left hand side.
     * @param m_rhs Matrix right hand side.
     */
    template<typename U>
    friend BaseMatrix<U> operator==(const U& scalar,
                                    const BaseMatrix<U>& m_rhs);

  protected:
    /**
     * Matrix number of rows.
     */
    std::size_t rows_;
    /**
     * Matrix number of columns.
     */
    std::size_t columns_;
    /*
     * Data allocator
     */
    std::allocator<T> allocator_;
    /**
     * Matrix data stored in a one dimension array.
     */
    T* data_;
    /**
     * @brief Method to transform a 2D matrix index to the equivalent 1D index
     * of the vector. where data is stored.
     *
     * @param row Row index.
     * @param column Column index.
     */
    std::size_t Transform2dTo1d(std::size_t row, std::size_t column) const;
    /**
     * @brief Method to check index boundaries to access entry/element.
     *
     * Check if the index is out of the limits of the number of row and columns.
     * In case is out of boundaries, the method throw and exception.
     *
     *  @param row Row index.
     *  @param column Column index.
     */
    void CheckIndex(std::size_t row, std::size_t column) const;
};

}  // namespace marsvin

#include "marsvin_base_matrix.impl.hpp"

#endif  // MARSVIN_CORE_MARSVIN_BASE_MATRIX_HPP_
