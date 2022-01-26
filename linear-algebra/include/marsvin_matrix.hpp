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
        // Methods
        void SetEntry(std::size_t row, std::size_t column, T entry);        // Set (row,column) matrix entry.
        void SetRow(std::size_t row,std::vector<T> data);                   // Matrix is filled by a row
        void SetColumn(std::size_t column,std::vector<T> data);             // Matrix is filled by a column
        void SetDiagonal(std::vector<T> data);                              // Matrix is filled by a diagonal
        T GetEntry(std::size_t row, std::size_t column) const;
        std::vector<T> GetRow(std::size_t row) const;
        std::vector<T> GetColumn(std::size_t column) const;
        std::vector<T> GetDiagonal() const;
        std::size_t GetNumberOfRows() const;                                      // Get matrix number of rows
        std::size_t GetNumberOfColumns() const;                                   // Get matrix number of columns
        void Print() const;                                                       // Print Matrix values
        bool IsSquare() const;                                                    // Return 1 if Matrix is square
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

}
#endif // MARSVIN_MATRIX_HPP_

