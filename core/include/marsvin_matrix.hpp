/**
 * @file marsvin_matrix.hpp
 *
 */

#ifndef MARSVIN_CORE_MARSVIN_MATRIX_HPP_
#define MARSVIN_CORE_MARSVIN_MATRIX_HPP_

#include <cstddef>
#include <iostream>
#include <stdexcept>
#include <vector>

namespace marsvin {

/**
 * @class Matrix
 * @brief Matrix class base on std::vector use to declare matrices, row and
 * column vectors.
 *
 */

template<typename T>
class Matrix {
  private:
    /**
     * @brief Proxy class for operator().
     *
     * Proxy class use as middle layer for the two ways of usage of operator().
     * First case is to read an entry/element value.
     * Sencond case to set an entry/elemetn value.
     */
    class EntryProxy;

  public:
    /**
     * @brief Default constructor.
     *
     * Creates an empty matrix. Size of the matrix is 0x0.
     *
     */
    Matrix();
    /**
     * @brief Constructor for any matrix.
     *
     * Creates matrix of any size. Number of rows and columns are input
     * parameters of constructor. All matrix entries are zero.
     *
     * @param row Number of rows.
     * @param column Number of columns.
     *
     */
    Matrix(std::size_t row, std::size_t column);
    /**
     * @brief Constructor for square matrix.
     *
     * Creates an square matrix of size n. All matrix entries are zero.
     *
     * @param n Number of rows and colums for square matrix.
     *
     */
    Matrix(std::size_t n);
    /**
     * @brief Constructor for square diagonal matrix.
     *
     * Creates an square matrix with diagonal set by the std::vector input.
     * The number of rows and columns is equal to the length of the std::vector
     * input.
     *
     * @param diagonal Diagonal of the square matrix.
     *
     */
    Matrix(const std::vector<T>& diagonal);
    /**
     * @brief Constructor using another matrix instance.
     *
     * Creates a matrix using information from another matrix instance.
     * All the properties of the matrix instances are copied to the new
     * instance.
     *
     * @param matrix Matrix instance use to create a new matrix with same
     * properties.
     *
     */
    Matrix(const marsvin::Matrix<T>& matrix);
    /**
     * @brief Constructor using a submatrix from another matrix instance.
     *
     * Creates a matrix using a submatrix from another matrix instances.
     * Matrix size and information depends on the submatrix selected from
     * the original matrix.
     *
     * @param matrix Matrix instance use to create a new matrix.
     * @param row_i Row initial index.
     * @param column_i Column initial index.
     * @param row_j Row final index.
     * @param column_j Column final index.
     *
     */
    Matrix(const marsvin::Matrix<T>& matrix,
           std::size_t row_i,
           std::size_t column_i,
           std::size_t row_j,
           std::size_t column_j);

    /**
     * @brief Method to set matrix entry/element value.
     *
     * @param row Row index.
     * @param colum Column index.
     * @param entry Entry value.
     *
     */
    void SetEntry(std::size_t row, std::size_t column, T entry);
    /**
     * @brief Method to set values in a selected matrix row.
     *
     * @param row Row index.
     * @param data Data to store in the selected row.
     *
     */
    void SetRow(std::size_t row, const std::vector<T>& data);
    /**
     * @brief Method to set values in a selected matrix column.
     *
     * @param column Column index.
     * @param data Data to store in the selected column.
     *
     */
    void SetColumn(std::size_t column, const std::vector<T>& data);
    /**
     * @brief Method to set values in the matrix diagnoal.
     *
     * @param data Data to store in the matrix diagonal.
     *
     */
    void SetDiagonal(const std::vector<T>& data);
    /**
     * @brief Method to set matrix data using a vector.
     *
     * Marsvin matrix data is stored in a 1d vector.
     * You can set the values of matrix using this method
     *
     * @param data Data to store in the matrix.
     *
     */
    void SetVectorData(const std::vector<T>& data);
    /**
     * @brief Method to swap two matrix rows.
     *
     * @param column_i First row number.
     * @param column_j Second row number.
     *
     */
    void SwapRows(std::size_t i, std::size_t j);

    /**
     *  @brief Method to get matrix entry/element.
     *
     *  @param row Row index.
     *  @param column Column index.
     *
     */
    T GetEntry(std::size_t row, std::size_t column) const;
    /**
     *  @brief Method to get a matrix row.
     *
     *  @param row Row index.
     *
     */
    std::vector<T> GetRow(std::size_t row) const;
    /**
     *  @brief Method to get a matrix column.
     *
     *  @param row Column index.
     *
     */
    std::vector<T> GetColumn(std::size_t column) const;
    /**
     * @brief Method to get the matrix diagonal.
     *
     */
    std::vector<T> GetDiagonal() const;
    /**
     * @brief Method to get matrix data as a 1d vector.
     *
     */
    std::vector<T> GetVectorData() const;
    /**
     * @brief Method to get the number of rows of the matrix.
     *
     */
    std::size_t GetNumberOfRows() const;
    /**
     * @brief Method to get the number of columns of the matrix.
     *
     */
    std::size_t GetNumberOfColumns() const;

    /**
     * @brief Method to know if the matrix instance is an square matrix or not.
     *
     */
    bool IsSquareMatrix() const;

    /**
     * @brief Method to obtain the transpose of the matrix instance.
     *
     */
    Matrix<T> Transpose() const;

    /**
     * @brief Method to perform the addition of two matrix instances.
     *
     * @param m_lhs Matrix left hand side.
     * @param m_rhs Matrix right hand side.
     *
     */
    template<typename U>
    friend Matrix<U> operator+(const Matrix<U>& m_lhs, const Matrix<U>& m_rhs);
    /**
     * @brief Method to perform the addition of one matrix instance and one
     * scalar. The scalar is added to each matrix element.
     *
     * @param m_lhs Matrix left hand side.
     * @param scalar Scalar value.
     *
     */
    template<typename U>
    friend Matrix<U> operator+(const Matrix<U>& m_lhs, const U& scalar);
    /**
     * @brief Method to perform the addition of one scalar and one matrix
     * instance. The scalar is added to each matrix element.
     *
     * @param scalar Scalar value.
     * @param m_rhs Matrix right hand side.
     *
     */
    template<typename U>
    friend Matrix<U> operator+(const U& scalar, const Matrix<U>& m_rhs);

    /**
     * @brief Method to perform substraction of two matrix instances.
     *
     * @param m_lhs Matrix left hand side.
     * @param m_rhs Matrix right hand side.
     *
     */
    template<typename U>
    friend Matrix<U> operator-(const Matrix<U>& m_lhs, const Matrix<U>& m_rhs);
    /**
     * @brief Method to perform substraction of one matrix instance and one
     * scalar. The scalar is substracted to each matrix element.
     *
     * @param m_lhs Matrix left hand side.
     * @param scalar Scalar value.
     *
     */
    template<typename U>
    friend Matrix<U> operator-(const Matrix<U>& m_lhs, const U& scalar);
    /**
     * @brief Method to perform substraction of one scalar and one matrix
     * instance. The scalar is substracted to each matrix element.
     *
     * @param scalar Scalar value.
     * @param m_rhs Matrix right hand side.
     *
     */
    template<typename U>
    friend Matrix<U> operator-(const U& scalar, const Matrix<U>& m_rhs);

    /**
     * @brief Method to perform the multiplication of two matrix instances.
     *
     * @param m_lhs Matrix left hand side.
     * @param m_rhs Matrix right hand side.
     *
     */
    template<typename U>
    friend Matrix<U> operator*(const Matrix<U>& m_lhs, const Matrix<U>& m_rhs);
    /**
     * @brief Method to perform the multiplication of one matrix instance and
     * one scalar. The scalar is multiplied to each matrix element.
     *
     * @param m_lhs Matrix left hand side.
     * @param scalar Scalar value.
     *
     */
    template<typename U>
    friend Matrix<U> operator*(const Matrix<U>& m_lhs, const U& scalar);
    /**
     * @brief Method to perform the multiplication of one scalar and one matrix
     * instance. The scalar is multiplied to each matrix element.
     *
     * @param scalar Scalar value.
     * @param m_rhs Matrix right hand side.
     *
     */
    template<typename U>
    friend Matrix<U> operator*(const U& scalar, const Matrix<U>& m_rhs);
    /**
     *  @brief Method to get matrix entry/element using () operator.
     *
     *  @param row Row index.
     *  @param column Column index.
     *
     */
    EntryProxy operator()(std::size_t row, std::size_t column);

  private:
    /**
     * Matrix number of rows.
     */
    std::size_t n_rows_;
    /**
     * Matrix number of columns.
     */
    std::size_t n_columns_;
    /**
     * Matrix data stored in a one dimension vector.
     */
    std::vector<T> data_;
    /**
     * @brief Method to transform a 2D matrix index to the equivalent 1D index
     * of the vector. where data is stored.
     *
     * @param row Row index.
     * @param column Column index.
     */
    std::size_t Transform2dTo1d(std::size_t row, std::size_t column) const;
    /**
     * @brief Method to transform data 1D vector index to the equivalent 2D
     * Matrix index.
     *
     * @param index Vector data index.
     */
    std::vector<std::size_t> Transform1dTo2d(std::size_t index) const;
    /**
     * @brief Method to check if 2 Matrices has the same dimensions.
     *
     * Check if the two matrices has the same dimensions.
     *
     * @param m_lhs Matrix left hand side.
     * @param m_rhs Matrix right hand side.
     */
    static bool CheckSameDimentions(const marsvin::Matrix<T>& m_lhs,
                                    const marsvin::Matrix<T>& m_rhs);
    /**
     * @brief Method to check if 2 matrices can be multiplied.
     *
     * Check if the left hand side matrix number of columns is equal to the
     * right hand side matrix number of rows.
     *
     * @param m_lhs Matrix left hand side.
     * @param m_rhs Matrix right hand side.
     */
    static bool CheckMultiplication(const marsvin::Matrix<T>& m_lhs,
                                    const marsvin::Matrix<T>& m_rhs);
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

template<typename T>
class Matrix<T>::EntryProxy {
  public:
    EntryProxy(marsvin::Matrix<T>& matrix, std::size_t row, std::size_t column);
    operator T();
    void operator=(T entry_input);

  private:
    Matrix& matrix_;
    std::size_t row_;
    std::size_t column_;
};

}  // namespace marsvin

// ---------------------------
// Implementation
// --------------------------

// Constructors
template<typename T>
marsvin::Matrix<T>::Matrix(std::size_t n_rows, std::size_t n_columns) :
  n_rows_{n_rows},
  n_columns_{n_columns},
  data_{std::vector<T>(n_rows * n_columns, 0)} {}
template<typename T>
marsvin::Matrix<T>::Matrix() :
  Matrix(0, 0) {}
template<typename T>
marsvin::Matrix<T>::Matrix(std::size_t n) :
  Matrix(n, n) {}
template<typename T>
marsvin::Matrix<T>::Matrix(const std::vector<T>& diagonal) :
  Matrix(diagonal.size()) {
    SetDiagonal(diagonal);
}
template<typename T>
marsvin::Matrix<T>::Matrix(const marsvin::Matrix<T>& matrix) :
  n_rows_{matrix.GetNumberOfRows()},
  n_columns_{matrix.GetNumberOfColumns()},
  data_{matrix.GetVectorData()} {}
template<typename T>
marsvin::Matrix<T>::Matrix(const marsvin::Matrix<T>& matrix,
                           std::size_t row_i,
                           std::size_t column_i,
                           std::size_t row_j,
                           std::size_t column_j) {
    if (row_i > row_j) {
        throw std::invalid_argument(
            "Second row index should be greater than first row index");
    }
    if (column_i > column_j) {
        throw std::invalid_argument(
            "Second column index should be greater than first column index");
    }
    n_rows_ = row_j - row_i + 1;
    n_columns_ = column_j - column_i + 1;
    data_ = std::vector<T>(n_rows_ * n_columns_, 0);
    std::vector<T> vec_temp;
    for (std::size_t j = 1; j <= n_rows_; j++) {
        vec_temp = matrix.GetRow(j + row_i - 1);
        SetRow(j,
               std::vector<T>(vec_temp.begin() + column_i - 1,
                              vec_temp.begin() + column_j));
    }
}

// Methods
template<typename T>
void marsvin::Matrix<T>::SetEntry(std::size_t row,
                                  std::size_t column,
                                  T entry) {
    CheckIndex(row, column);
    std::size_t k = Transform2dTo1d(row, column);
    data_[k] = entry;
}

template<typename T>
void marsvin::Matrix<T>::SetRow(std::size_t row, const std::vector<T>& data) {
    if (row > n_rows_) {
        throw std::invalid_argument("Index out of bounderies for ROW");
    }
    if (n_columns_ != data.size()) {
        throw std::invalid_argument("Wrong length of row vector.");
    }
    for (std::size_t j = 1; j <= n_columns_; j++) {
        SetEntry(row, j, data[j - 1]);
    }
}

template<typename T>
void marsvin::Matrix<T>::SetColumn(std::size_t column,
                                   const std::vector<T>& data) {
    if (column > n_columns_) {
        throw std::invalid_argument("Index out of bounderies for COLUMN");
    }
    if (n_rows_ != data.size()) {
        throw std::invalid_argument("Wrong length of column vector.");
    }
    for (int j = 0; j < n_rows_; j++) {
        SetEntry(j + 1, column, data[j]);
    }
}

template<typename T>
void marsvin::Matrix<T>::SetDiagonal(const std::vector<T>& data) {
    if (!IsSquareMatrix()) {
        throw std::invalid_argument("Matrix should be square");
    }
    if (data.size() != n_rows_) {
        throw std::invalid_argument("Wrong diagonal length");
    }
    for (int j = 0; j < n_rows_; j++) {
        SetEntry(j + 1, j + 1, data[j]);
    }
}

template<typename T>
void marsvin::Matrix<T>::SetVectorData(const std::vector<T>& data) {
    if (data.size() != data_.size()) {
        throw std::invalid_argument("Wrong data length");
    }
    data_ = data;
}

template<typename T>
void marsvin::Matrix<T>::SwapRows(std::size_t i, std::size_t j) {
    if (i > n_rows_ || j > n_rows_) {
        throw std::invalid_argument("Row numbers out of limits");
    }
    if (i != j) {
        std::vector<T> temp_row_i = GetRow(i);
        std::vector<T> temp_row_j = GetRow(j);
        SetRow(j, temp_row_i);
        SetRow(i, temp_row_j);
    }
}

template<typename T>
T marsvin::Matrix<T>::GetEntry(std::size_t row, std::size_t column) const {
    CheckIndex(row, column);
    return data_[Transform2dTo1d(row, column)];
}

template<typename T>
std::vector<T> marsvin::Matrix<T>::GetRow(std::size_t row) const {
    std::size_t k = Transform2dTo1d(row, 1);
    return std::vector<T>(data_.begin() + k, data_.begin() + k + n_columns_);
}

template<typename T>
std::vector<T> marsvin::Matrix<T>::GetColumn(std::size_t column) const {
    std::vector<T> vec = std::vector<T>(n_rows_, 0);
    for (int j = 0; j < n_rows_; j++) {
        vec.at(j) = GetEntry(j + 1, column);
    }
    return vec;
}

template<typename T>
std::vector<T> marsvin::Matrix<T>::GetDiagonal() const {
    std::vector<T> vec;
    if (IsSquareMatrix()) {
        vec.reserve(n_rows_);
        for (int j = 0; j < n_rows_; j++) {
            vec.push_back(GetEntry(j + 1, j + 1));
        }
    }
    return vec;
}

template<typename T>
std::vector<T> marsvin::Matrix<T>::GetVectorData() const {
    return data_;
}

template<typename T>
std::size_t marsvin::Matrix<T>::GetNumberOfRows() const {
    return n_rows_;
}

template<typename T>
std::size_t marsvin::Matrix<T>::GetNumberOfColumns() const {
    return n_columns_;
}

template<typename T>
bool marsvin::Matrix<T>::IsSquareMatrix() const {
    bool is_square_ = false;
    if (n_rows_ == n_columns_) {
        is_square_ = true;
    }
    return is_square_;
}

// Matrix operations
template<typename T>
marsvin::Matrix<T> marsvin::Matrix<T>::Transpose() const {
    marsvin::Matrix<T> m_result(GetNumberOfColumns(), GetNumberOfRows());
    for (std::size_t i = 1; i <= GetNumberOfRows(); i++) {
        m_result.SetColumn(i, GetRow(i));
    }
    return m_result;
}

// Operators
template<typename T>
marsvin::Matrix<T> operator+(const marsvin::Matrix<T>& m_lhs,
                             const marsvin::Matrix<T>& m_rhs) {
    if (!marsvin::Matrix<T>::CheckSameDimentions(m_lhs, m_rhs)) {
        throw std::invalid_argument("Mismatch in matrices dimensions :(");
    }
    // Initialize result matrix
    marsvin::Matrix<T> m_result(m_lhs.GetNumberOfRows(),
                                m_lhs.GetNumberOfColumns());
    T sum;
    for (std::size_t i = 1; i <= m_lhs.GetNumberOfRows(); i++) {
        for (std::size_t j = 1; j <= m_lhs.GetNumberOfColumns(); j++) {
            sum = m_lhs.GetEntry(i, j) + m_rhs.GetEntry(i, j);
            m_result.SetEntry(i, j, sum);
        }
    }
    return m_result;
}

template<typename T>
marsvin::Matrix<T> operator+(const marsvin::Matrix<T>& m_lhs, const T& scalar) {
    marsvin::Matrix<T> m_result(m_lhs.GetNumberOfRows(),
                                m_lhs.GetNumberOfColumns());
    T sum;
    for (std::size_t i = 1; i <= m_lhs.GetNumberOfRows(); i++) {
        for (std::size_t j = 1; j <= m_lhs.GetNumberOfColumns(); j++) {
            sum = m_lhs.GetEntry(i, j) + scalar;
            m_result.SetEntry(i, j, sum);
        }
    }
    return m_result;
}

template<typename T>
marsvin::Matrix<T> operator+(const T& scalar, const marsvin::Matrix<T>& m_rhs) {
    marsvin::Matrix<T> m_result(m_rhs.GetNumberOfRows(),
                                m_rhs.GetNumberOfColumns());
    T sum;
    for (std::size_t i = 1; i <= m_rhs.GetNumberOfRows(); i++) {
        for (std::size_t j = 1; j <= m_rhs.GetNumberOfColumns(); j++) {
            sum = m_rhs.GetEntry(i, j) + scalar;
            m_result.SetEntry(i, j, sum);
        }
    }
    return m_result;
}

template<typename T>
marsvin::Matrix<T> operator-(const marsvin::Matrix<T>& m_lhs,
                             const marsvin::Matrix<T>& m_rhs) {
    if (!marsvin::Matrix<T>::CheckSameDimentions(m_lhs, m_rhs)) {
        throw std::invalid_argument("Mismatch in matrices dimensions :(");
    }
    // Initialize result matrix
    marsvin::Matrix<T> m_result(m_lhs.GetNumberOfRows(),
                                m_lhs.GetNumberOfColumns());
    T sum;
    for (std::size_t i = 1; i <= m_lhs.GetNumberOfRows(); i++) {
        for (std::size_t j = 1; j <= m_lhs.GetNumberOfColumns(); j++) {
            sum = m_lhs.GetEntry(i, j) - m_rhs.GetEntry(i, j);
            m_result.SetEntry(i, j, sum);
        }
    }
    return m_result;
}

template<typename T>
marsvin::Matrix<T> operator-(const marsvin::Matrix<T>& m_lhs, const T& scalar) {
    marsvin::Matrix<T> m_result(m_lhs.GetNumberOfRows(),
                                m_lhs.GetNumberOfColumns());
    T sum;
    for (std::size_t i = 1; i <= m_lhs.GetNumberOfRows(); i++) {
        for (std::size_t j = 1; j <= m_lhs.GetNumberOfColumns(); j++) {
            sum = m_lhs.GetEntry(i, j) - scalar;
            m_result.SetEntry(i, j, sum);
        }
    }
    return m_result;
}

template<typename T>
marsvin::Matrix<T> operator-(const T& scalar, const marsvin::Matrix<T>& m_rhs) {
    marsvin::Matrix<T> m_result(m_rhs.GetNumberOfRows(),
                                m_rhs.GetNumberOfColumns());
    T sum;
    for (std::size_t i = 1; i <= m_rhs.GetNumberOfRows(); i++) {
        for (std::size_t j = 1; j <= m_rhs.GetNumberOfColumns(); j++) {
            sum = m_rhs.GetEntry(i, j) - scalar;
            m_result.SetEntry(i, j, sum);
        }
    }
    return m_result;
}

template<typename T>
marsvin::Matrix<T> operator*(const marsvin::Matrix<T>& m_lhs,
                             const marsvin::Matrix<T>& m_rhs) {
    if (!marsvin::Matrix<T>::CheckMultiplication(m_lhs, m_rhs)) {
        throw std::invalid_argument(
            "Mismatch in matrices dimensions for multiplication");
    }
    marsvin::Matrix<T> m_result(m_lhs.GetNumberOfRows(),
                                m_rhs.GetNumberOfColumns());
    std::size_t n = m_lhs.GetNumberOfColumns();
    T sum;
    for (std::size_t i = 1; i <= m_lhs.GetNumberOfRows(); i++) {
        for (std::size_t j = 1; j <= m_rhs.GetNumberOfColumns(); j++) {
            sum = 0;
            for (std::size_t k = 1; k <= n; k++) {
                sum += m_lhs.GetEntry(i, k) * m_rhs.GetEntry(k, j);
            }
            m_result.SetEntry(i, j, sum);
        }
    }
    return m_result;
}

template<typename T>
marsvin::Matrix<T> operator*(const T& scalar, const marsvin::Matrix<T>& m_rhs) {
    marsvin::Matrix<T> m_result(m_rhs.GetNumberOfRows(),
                                m_rhs.GetNumberOfColumns());
    std::vector<T> matrix_data_ = m_rhs.GetVectorData();
    for (std::size_t j = 0; j < matrix_data_.size(); j++) {
        matrix_data_.at(j) = matrix_data_.at(j) * scalar;
    }
    m_result.SetVectorData(matrix_data_);
    return m_result;
}

template<typename T>
marsvin::Matrix<T> operator*(const marsvin::Matrix<T>& m_lhs, const T& scalar) {
    marsvin::Matrix<T> m_result(m_lhs.GetNumberOfRows(),
                                m_lhs.GetNumberOfColumns());
    std::vector<T> matrix_data_ = m_lhs.GetVectorData();
    for (std::size_t j = 0; j < matrix_data_.size(); j++) {
        matrix_data_.at(j) = matrix_data_.at(j) * scalar;
    }
    m_result.SetVectorData(matrix_data_);
    return m_result;
}
// Private methods
// (row-1,column-1)     :   Matrix coordinate for C++. The users set
// (row,column) like in books
//  k                   :   1d index
template<typename T>
std::size_t marsvin::Matrix<T>::Transform2dTo1d(std::size_t row,
                                                std::size_t column) const {
    std::size_t k = column - 1 + n_columns_ * (row - 1);
    return k;
}

template<typename T>
std::vector<std::size_t> marsvin::Matrix<T>::Transform1dTo2d(
    std::size_t k) const {
    return std::vector<std::size_t>(2, 0);
}

template<typename T>
bool marsvin::Matrix<T>::CheckSameDimentions(const marsvin::Matrix<T>& m_lhs,
                                             const marsvin::Matrix<T>& m_rhs) {
    bool check = false;
    if ((m_lhs.GetNumberOfRows() == m_rhs.GetNumberOfRows()) &&
        (m_lhs.GetNumberOfColumns() == m_rhs.GetNumberOfColumns())) {
        check = true;
    }
    return check;
}

template<typename T>
bool marsvin::Matrix<T>::CheckMultiplication(const marsvin::Matrix<T>& m_lhs,
                                             const marsvin::Matrix<T>& m_rhs) {
    bool check = false;
    if (m_lhs.GetNumberOfColumns() == m_rhs.GetNumberOfRows()) {
        check = true;
    }
    return check;
}

template<typename T>
void marsvin::Matrix<T>::CheckIndex(std::size_t row, std::size_t column) const {
    if (row > n_rows_) {
        if (column > n_columns_) {
            throw std::invalid_argument(
                "Index out of bounderies for ROW and COLUMN");
        }
        throw std::invalid_argument("Index out of bounderies for ROW");
    } else {
        if (column > n_columns_) {
            throw std::invalid_argument("Index out of bounderies for COLUMN");
        }
    }
}

//---------------
// EntryProxy
//---------------
template<typename T>
typename marsvin::Matrix<T>::EntryProxy marsvin::Matrix<T>::operator()(
    std::size_t row,
    std::size_t column) {
    return EntryProxy(*this, row, column);
}

template<typename T>
marsvin::Matrix<T>::EntryProxy::EntryProxy(marsvin::Matrix<T>& matrix,
                                           std::size_t row,
                                           std::size_t column) :
  matrix_{matrix},
  row_{row},
  column_{column} {}

template<typename T>
marsvin::Matrix<T>::EntryProxy::operator T() {
    return matrix_.GetEntry(row_, column_);
}

template<typename T>
void marsvin::Matrix<T>::EntryProxy::operator=(T entry_input) {
    matrix_.SetEntry(row_, column_, entry_input);
}

#endif  // MARSVIN_CORE_MARSVIN_MATRIX_HPP_
