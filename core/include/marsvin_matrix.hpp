/**
 * @file marsvin_matrix.hpp
 *
 */

#ifndef MARSVIN_CORE_MARSVIN_MATRIX_HPP_
#define MARSVIN_CORE_MARSVIN_MATRIX_HPP_

#include <cstddef>
#include <vector>
#include <iostream>
#include <stdexcept>

namespace marsvin {

/**
 * @class Matrix
 * @brief Matrix class base on std::vector use to declare matrices, row and column vectors.
 *
 */

template <typename T>
class Matrix {
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
         * Creates matrix of any size. Number of rows and columns are input parameters of constructor.
         * All matrix entries are zero.
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
         * The number of rows and columns is equal to the length of the std::vector input.
         *
         * @param diagonal Diagonal of the square matrix.
         *
         */
        Matrix(std::vector<T> diagonal);
        /**
         * @brief Constructor using another matrix instance.
         *
         * Creates a matrix using information from another matrix instance.
         * All the properties of the matrix instances are copied to the new instance.
         *
         * @param matrix Matrix instance use to create a new matrix with same properties.
         *
         */
        Matrix(marsvin::Matrix<T>& matrix);
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
        Matrix(marsvin::Matrix<T>& matrix,std::size_t row_i,std::size_t column_i,std::size_t row_j,std::size_t column_j);


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
        void SetRow(std::size_t row,std::vector<T> data);
        /**
         * @brief Method to set values in a selected matrix column.
         *
         * @param column Column index.
         * @param data Data to store in the selected column.
         *
         */
        void SetColumn(std::size_t column,std::vector<T> data);
        /**
         * @brief Method to set values in the matrix diagnoal.
         *
         * @param data Data to store in the matrix diagonal.
         *
         */
        void SetDiagonal(std::vector<T> data);
        void SetVectorData(std::vector<T> data);
        void SwapRows(std::size_t i, std::size_t j);                        // Swap two rows in matrix.
        // Methods: Read matrix values
        T GetEntry(std::size_t row, std::size_t column) const;
        std::vector<T> GetRow(std::size_t row) const;
        std::vector<T> GetColumn(std::size_t column) const;
        std::vector<T> GetDiagonal() const;
        std::vector<T> GetVectorData() const;                                   // Get Matrix information as a 1D vector
        std::size_t GetNumberOfRows() const;                                    // Get matrix number of rows
        std::size_t GetNumberOfColumns() const;                                 // Get matrix number of columns
        // Others
        void Print() const;                                                     // Print Matrix values
        bool IsSquare() const;                                                  // Return 1 if Matrix is square
        void ScalarMultiplication(T scalar);                                    // Matrix element multiply by constant
        // Matrix operations
        Matrix<T> Transpose() const;
        // Operators
        template<typename U> friend Matrix<U> operator+(const Matrix<U>& m_lhs, const Matrix<U>& m_rhs);
        template<typename U> friend Matrix<U> operator+(const Matrix<U>& m_lhs, const U& scalar);
        template<typename U> friend Matrix<U> operator+(const U& scalar, const Matrix<U>& m_rhs);

        template<typename U> friend Matrix<U> operator-(const Matrix<U>& m_lhs, const Matrix<U>& m_rhs);
        template<typename U> friend Matrix<U> operator-(const Matrix<U>& m_lhs, const U& scalar);
        template<typename U> friend Matrix<U> operator-(const U& scalar, const Matrix<U>& m_rhs);

        template<typename U> friend Matrix<U> operator*(const Matrix<U>& m_lhs, const Matrix<U>& m_rhs);
        template<typename U> friend Matrix<U> operator*(const Matrix<U>& m_lhs, const U& scalar);
        template<typename U> friend Matrix<U> operator*(const U& scalar, const Matrix<U>& m_rhs);
    private:
        std::size_t n_rows_;
        std::size_t n_columns_;
        std::vector<T> data_;
        std::size_t Transform2dTo1d(std::size_t,std::size_t) const;
        std::vector<std::size_t> Transform1dTo2d(std::size_t) const;
        static bool CheckSameDimentions(const marsvin::Matrix<T>& m_lhs, const marsvin::Matrix<T>& m_rhs);
        static bool CheckMultiplication(const marsvin::Matrix<T>& m_lhs, const marsvin::Matrix<T>& m_rhs);
};

// Implementation

// Constructor
template<typename T> marsvin::Matrix<T>::Matrix(std::size_t n_rows, std::size_t n_columns): n_rows_{ n_rows }, n_columns_{ n_columns }, data_{ std::vector<T>(n_rows*n_columns,0) } {}
template<typename T> marsvin::Matrix<T>::Matrix():Matrix(0,0) {}
template<typename T> marsvin::Matrix<T>::Matrix(std::size_t n):Matrix(n,n){}
template<typename T> marsvin::Matrix<T>::Matrix(std::vector<T> diagonal):Matrix(diagonal.size()){SetDiagonal(diagonal);}
template<typename T> marsvin::Matrix<T>::Matrix(marsvin::Matrix<T>& matrix): n_rows_{ matrix.GetNumberOfRows() }, n_columns_{ matrix.GetNumberOfColumns() }, data_{ matrix.GetVectorData() } {}
template<typename T> marsvin::Matrix<T>::Matrix(marsvin::Matrix<T>& matrix,std::size_t row_i,std::size_t column_i,std::size_t row_j,std::size_t column_j) {
    if ( row_i > row_j) {
        throw std::invalid_argument("Second row index should be greater than first row index");
    }
    if ( column_i > column_j) {
        throw std::invalid_argument("Second column index should be greater than first column index");
    }
    n_rows_ = row_j - row_i + 1;
    n_columns_ = column_j - column_i + 1;
    data_ = std::vector<T>(n_rows_*n_columns_,0);
    std::vector<T> vec_temp;
    for (std::size_t j = 1; j <= n_rows_ ;j++) {
        vec_temp = matrix.GetRow(j + row_i - 1);
        SetRow(j,std::vector<T>(vec_temp.begin()+column_i-1,vec_temp.begin()+column_j));
    }
}

// Methods
template<typename T> void marsvin::Matrix<T>::SetEntry(std::size_t row,std::size_t column, T entry) {
    std::size_t k = Transform2dTo1d(row,column);
    data_.at(k) = entry; // Change to operator []
}

template<typename T> void marsvin::Matrix<T>::SetRow(std::size_t row, std::vector<T> data) {
    if (n_columns_ != data.size() ) {
        std::cerr << "Wrong Row Matrix size. It must be:" << n_columns_  << std::endl;
        throw std::invalid_argument("Wrong length of row vector :(");
    }
    std::size_t k = Transform2dTo1d(row,1);
    data_.insert(data_.begin()+k,data.begin(),data.end());
    k = Transform2dTo1d(row+1,1);
    data_.erase(data_.begin() + k,data_.begin() + k + n_columns_);
}

template<typename T> void marsvin::Matrix<T>::SetColumn(std::size_t column, std::vector<T> data) {
    if (n_rows_ != data.size() ) {
        std::cerr << "Wrong Column Matrix size. It must be:" << n_rows_  << std::endl;
        throw std::invalid_argument("Wrong length of column vector :(");
    }
    for (int j = 0;j<n_rows_;j++) {
        SetEntry(j+1,column,data.at(j));
    }
}

template<typename T> void marsvin::Matrix<T>::SetDiagonal(std::vector<T> data) {
    if ( !IsSquare() ) {
        std::cerr << "Matrix should be square nxn. Where n = " << n_rows_  << std::endl;
        throw std::invalid_argument("Matrix should be square");
    }
    if (data.size() != n_rows_) {
        std::cerr << "Wrong diagonal length. Length must be: " << n_rows_  << std::endl;
        throw std::invalid_argument("Wrong diagonal length");
    }
    for (int j = 0;j<n_rows_;j++) {
        SetEntry(j+1,j+1,data.at(j));
    }
}


template<typename T> void marsvin::Matrix<T>::SetVectorData(std::vector<T> data) {
    if (data.size() != data_.size()) {
        std::cerr << "Wrong data length. Length must be: " << n_rows_*n_columns_  << std::endl;
        throw std::invalid_argument("Wrong data length");
    }
    data_ = data;
}

template<typename T> void marsvin::Matrix<T>::SwapRows(std::size_t i, std::size_t j) {
    if ( i > n_rows_ || j > n_rows_  ) {
        std::cerr << "The number of rows is: " << n_rows_ << std::endl;
        throw std::invalid_argument("Row numbers out of limits");
    }
    if (i != j) {
        std::vector<T> temp_row_i = GetRow(i);
        std::vector<T> temp_row_j = GetRow(j);
        SetRow(j,temp_row_i);
        SetRow(i,temp_row_j);
    }
}

template<typename T> T marsvin::Matrix<T>::GetEntry(std::size_t row, std::size_t column) const {
    return data_.at(Transform2dTo1d(row,column));
}

template<typename T> std::vector<T> marsvin::Matrix<T>::GetRow(std::size_t row) const {
    std::size_t k = Transform2dTo1d(row,1);
    return std::vector<T>(data_.begin() + k,data_.begin()+ k + n_columns_);
}

template<typename T> std::vector<T> marsvin::Matrix<T>::GetColumn(std::size_t column) const {
    std::vector<T> vec = std::vector<T>(n_rows_,0);
    for (int j = 0;j<n_rows_;j++) {
        vec.at(j) = GetEntry(j+1,column);
    }
    return vec;
}

template<typename T> std::vector<T> marsvin::Matrix<T>::GetDiagonal() const {
    std::vector<T> vec;
    if (IsSquare()) {
        for (int j = 0;j<n_rows_;j++) {
            vec.push_back(GetEntry(j+1,j+1));
        }
    }
    return vec;
}


template<typename T> std::vector<T> marsvin::Matrix<T>::GetVectorData() const {
    return data_;
}

template<typename T> std::size_t marsvin::Matrix<T>::GetNumberOfRows() const {
    return n_rows_;
}

template<typename T> std::size_t marsvin::Matrix<T>::GetNumberOfColumns() const {
    return n_columns_;
}

template<typename T> void marsvin::Matrix<T>::Print() const {
    for (std::size_t j = 0; j < data_.size(); j++) {
        if ( (j+1) % n_columns_ == 0) {
            std::cout << data_.at(j) << '\n';
        } else {
            std::cout << data_.at(j) << '\t';
        }
    };
}

template<typename T> bool marsvin::Matrix<T>::IsSquare() const {
    bool is_square_ = false;
    if (n_rows_ == n_columns_) {
        is_square_ = true;
    }
    return is_square_;
}

template<typename T> void marsvin::Matrix<T>::ScalarMultiplication(T scalar) {
    for (std::size_t j = 0; j < data_.size(); j++) {
        data_.at(j) = data_.at(j)*scalar;
    }
}

// Matrix operations
template<typename T> marsvin::Matrix<T> marsvin::Matrix<T>::Transpose() const {
    marsvin::Matrix<T> m_result(GetNumberOfColumns(),GetNumberOfRows());
    for (std::size_t i=1; i<= GetNumberOfRows();i++) {
        m_result.SetColumn(i,GetRow(i));
    }
    return m_result;
}

// Operators
template<typename T> marsvin::Matrix<T> operator+(const marsvin::Matrix<T>& m_lhs,const marsvin::Matrix<T>& m_rhs) {
    if (!marsvin::Matrix<T>::CheckSameDimentions(m_lhs,m_rhs)) {
        throw std::invalid_argument("Mismatch in matrices dimensions :(");
    }
    // Initialize result matrix
    marsvin::Matrix<T> m_result(m_lhs.GetNumberOfRows(),m_lhs.GetNumberOfColumns());
    T sum;
    for (std::size_t i=1;i<=m_lhs.GetNumberOfRows();i++) {
        for (std::size_t j=1; j<= m_lhs.GetNumberOfColumns();j++) {
            sum = m_lhs.GetEntry(i,j) + m_rhs.GetEntry(i,j);
            m_result.SetEntry(i,j,sum);
        }
    }
    return m_result;
}

template<typename T> marsvin::Matrix<T> operator+(const marsvin::Matrix<T>& m_lhs, const T& scalar) {
    marsvin::Matrix<T> m_result(m_lhs.GetNumberOfRows(),m_lhs.GetNumberOfColumns());
    T sum;
    for (std::size_t i=1;i<=m_lhs.GetNumberOfRows();i++) {
        for (std::size_t j=1; j<= m_lhs.GetNumberOfColumns();j++) {
            sum = m_lhs.GetEntry(i,j) + scalar;
            m_result.SetEntry(i,j,sum);
        }
    }
    return m_result;
}

template<typename T> marsvin::Matrix<T> operator+(const T& scalar, const marsvin::Matrix<T>& m_rhs) {
    marsvin::Matrix<T> m_result(m_rhs.GetNumberOfRows(),m_rhs.GetNumberOfColumns());
    T sum;
    for (std::size_t i=1;i<=m_rhs.GetNumberOfRows();i++) {
        for (std::size_t j=1; j<= m_rhs.GetNumberOfColumns();j++) {
            sum = m_rhs.GetEntry(i,j) + scalar;
            m_result.SetEntry(i,j,sum);
        }
    }
    return m_result;
}

template<typename T> marsvin::Matrix<T> operator-(const marsvin::Matrix<T>& m_lhs,const marsvin::Matrix<T>& m_rhs) {
    if (!marsvin::Matrix<T>::CheckSameDimentions(m_lhs,m_rhs)) {
        throw std::invalid_argument("Mismatch in matrices dimensions :(");
    }
    // Initialize result matrix
    marsvin::Matrix<T> m_result(m_lhs.GetNumberOfRows(),m_lhs.GetNumberOfColumns());
    T sum;
    for (std::size_t i=1;i<=m_lhs.GetNumberOfRows();i++) {
        for (std::size_t j=1; j<= m_lhs.GetNumberOfColumns();j++) {
            sum = m_lhs.GetEntry(i,j) - m_rhs.GetEntry(i,j);
            m_result.SetEntry(i,j,sum);
        }
    }
    return m_result;
}

template<typename T> marsvin::Matrix<T> operator-(const marsvin::Matrix<T>& m_lhs, const T& scalar) {
    marsvin::Matrix<T> m_result(m_lhs.GetNumberOfRows(),m_lhs.GetNumberOfColumns());
    T sum;
    for (std::size_t i=1;i<=m_lhs.GetNumberOfRows();i++) {
        for (std::size_t j=1; j<= m_lhs.GetNumberOfColumns();j++) {
            sum = m_lhs.GetEntry(i,j) - scalar;
            m_result.SetEntry(i,j,sum);
        }
    }
    return m_result;
}

template<typename T> marsvin::Matrix<T> operator-(const T& scalar, const marsvin::Matrix<T>& m_rhs) {
    marsvin::Matrix<T> m_result(m_rhs.GetNumberOfRows(),m_rhs.GetNumberOfColumns());
    T sum;
    for (std::size_t i=1;i<=m_rhs.GetNumberOfRows();i++) {
        for (std::size_t j=1; j<= m_rhs.GetNumberOfColumns();j++) {
            sum = m_rhs.GetEntry(i,j) - scalar;
            m_result.SetEntry(i,j,sum);
        }
    }
    return m_result;
}

template<typename T> marsvin::Matrix<T> operator*(const marsvin::Matrix<T>& m_lhs, const marsvin::Matrix<T>& m_rhs) {
    if (!marsvin::Matrix<T>::CheckMultiplication(m_lhs,m_rhs)) {
        throw std::invalid_argument("Mismatch in matrices dimensions for multiplication");
    }
    marsvin::Matrix<T> m_result(m_lhs.GetNumberOfRows(),m_rhs.GetNumberOfColumns());
    std::size_t n = m_lhs.GetNumberOfColumns();
    T sum;
    for (std::size_t i=1;i<=m_lhs.GetNumberOfRows();i++) {
        for (std::size_t j=1; j<= m_rhs.GetNumberOfColumns();j++) {
            sum = 0;
            for (std::size_t k=1; k <=n; k++) {
                sum += m_lhs.GetEntry(i,k)*m_rhs.GetEntry(k,j);
            }
            m_result.SetEntry(i,j,sum);
        }
    }
    return m_result;
}


template<typename T> marsvin::Matrix<T> operator*(const T& scalar, const marsvin::Matrix<T>& m_rhs) {
    marsvin::Matrix<T> m_result(m_rhs.GetNumberOfRows(),m_rhs.GetNumberOfColumns());
    std::vector<T> matrix_data_ = m_rhs.GetVectorData();
    for (std::size_t j = 0; j < matrix_data_.size(); j++) {
        matrix_data_.at(j) = matrix_data_.at(j)*scalar;
    }
    m_result.SetVectorData(matrix_data_);
    return m_result;
}

template<typename T> marsvin::Matrix<T> operator*(const marsvin::Matrix<T>& m_lhs, const T& scalar) {
    marsvin::Matrix<T> m_result(m_lhs.GetNumberOfRows(),m_lhs.GetNumberOfColumns());
    std::vector<T> matrix_data_ = m_lhs.GetVectorData();
    for (std::size_t j = 0; j < matrix_data_.size(); j++) {
        matrix_data_.at(j) = matrix_data_.at(j)*scalar;
    }
    m_result.SetVectorData(matrix_data_);
    return m_result;
}
// Private methods
// (row-1,column-1)     :   Matrix coordinate for C++. The users set (row,column) like in books
//  k                   :   1d index
template<typename T> std::size_t marsvin::Matrix<T>::Transform2dTo1d(std::size_t row,std::size_t column) const {
    std::size_t k = column-1 + n_columns_*(row-1);
    return k;
}

template<typename T> std::vector<std::size_t> marsvin::Matrix<T>::Transform1dTo2d(std::size_t k) const {
    return std::vector<std::size_t>(2,0);
}

template<typename T> bool marsvin::Matrix<T>::CheckSameDimentions(const marsvin::Matrix<T>& m_lhs, const marsvin::Matrix<T>& m_rhs) {
    bool check = false;
    if ( (m_lhs.GetNumberOfRows() == m_rhs.GetNumberOfRows()) && (m_lhs.GetNumberOfColumns() == m_rhs.GetNumberOfColumns())) {
        check = true;
    }
    return check;
}

template<typename T> bool marsvin::Matrix<T>::CheckMultiplication(const marsvin::Matrix<T>& m_lhs, const marsvin::Matrix<T>& m_rhs) {
    bool check = false;
    if (m_lhs.GetNumberOfColumns() == m_rhs.GetNumberOfRows()) {
        check = true;
    }
    return check;
}

}
#endif // MARSVIN_CORE_MARSVIN_MATRIX_HPP_

