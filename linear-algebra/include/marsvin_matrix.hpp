#ifndef MARSVIN_MATRIX_HPP_
#define MARSVIN_MATRIX_HPP_

#include <cstddef>
#include <vector>
#include <iostream>
#include <stdexcept>

namespace marsvin {

template <typename T>
class Matrix {
    public:
        // Constructors
        Matrix(std::size_t row, std::size_t column);            // Any matrix
        Matrix();                                               // Default empty matrix.
        Matrix(std::size_t n);                                  // Square matrix
        Matrix(std::vector<T> diagonal);                        // Diagonal Matrix
        Matrix(marsvin::Matrix<T>& matrix);                                                                                 // Initalize using information from another matrix.
        Matrix(marsvin::Matrix<T>& matrix,std::size_t row_i,std::size_t column_i,std::size_t row_j,std::size_t column_j);   // Initalize using a submatrix from another matrix.
        // Methods
        void SetEntry(std::size_t row, std::size_t column, T entry);        // Set (row,column) matrix entry.
        void SetRow(std::size_t row,std::vector<T> data);                   // Matrix is filled by a row
        void SetColumn(std::size_t column,std::vector<T> data);             // Matrix is filled by a column
        void SetDiagonal(std::vector<T> data);                              // Matrix is filled by a diagonal
        void SwapRows(std::size_t i, std::size_t j);                        // Swap two rows in matrix.
        T GetEntry(std::size_t row, std::size_t column) const;
        std::vector<T> GetRow(std::size_t row) const;
        std::vector<T> GetColumn(std::size_t column) const;
        std::vector<T> GetDiagonal() const;
        std::vector<T> GetVectorData() const;                                   // Get Matrix information as a 1D vector
        std::size_t GetNumberOfRows() const;                                    // Get matrix number of rows
        std::size_t GetNumberOfColumns() const;                                 // Get matrix number of columns
        void Print() const;                                                     // Print Matrix values
        bool IsSquare() const;                                                  // Return 1 if Matrix is square
        void ScalarMultiplication(T scalar);                                    // Matrix element multiply by constant
    private:
        std::size_t n_rows_;
        std::size_t n_columns_;
        std::vector<T> data_;
        std::size_t Transform2dTo1d(std::size_t,std::size_t) const;
        std::vector<std::size_t> Transform1dTo2d(std::size_t) const;
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
    data_.at(k) = entry;
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

// (row-1,column-1)     :   Matrix coordinate for C++. The users set (row,column) like in books
//  k                   :   1d index
template<typename T> std::size_t marsvin::Matrix<T>::Transform2dTo1d(std::size_t row,std::size_t column) const {
    std::size_t k = column-1 + n_columns_*(row-1);
    return k;
}

template<typename T> std::vector<std::size_t> marsvin::Matrix<T>::Transform1dTo2d(std::size_t k) const {
    return std::vector<std::size_t>(2,0); 
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
}
#endif // MARSVIN_MATRIX_HPP_

