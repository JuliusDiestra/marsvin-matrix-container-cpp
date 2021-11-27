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
        void SetEntry(T entry, std::size_t row, std::size_t column);        // Set (row,column) matrix entry.
        void SetRow(std::size_t row,std::vector<T> data);                   // Matrix is filled by rows.
        std::size_t GetNumberOfRows();                                      // Get matrix number of rows
        std::size_t GetNumberOfColumns();                                   // Get matrix number of columns
        void Print();                                                       // Print Matrix values
        bool IsSquare();                                                    // Return 1 if Matrix is square
    private:
        std::size_t n_rows_;
        std::size_t n_columns_;
        std::vector<T> data_;
        std::size_t Transform2dTo1d(std::size_t,std::size_t);
        std::vector<std::size_t> Transform1dTo2d(std::size_t);
};

// Implementation

// Constructor
template<typename T> marsvin::Matrix<T>::Matrix(std::size_t n_rows, std::size_t n_columns): n_rows_{ n_rows }, n_columns_{ n_columns }, data_{ std::vector<T>(n_rows*n_columns,0) } {}
template<typename T> marsvin::Matrix<T>::Matrix():Matrix(0,0) {}
template<typename T> marsvin::Matrix<T>::Matrix(std::size_t n):Matrix(n,n){}

// Methods

template<typename T> void marsvin::Matrix<T>::SetEntry(T entry, std::size_t row,std::size_t column) {
    std::size_t k = Transform2dTo1d(row,column);
    data_.insert(data_.begin()+k,entry);
    data_.erase(data_.begin()+k+1);
}



template<typename T> void marsvin::Matrix<T>::SetRow(std::size_t row, std::vector<T> data) {
    if (n_columns_ != data.size() ) {
        std::cerr << "Wrong Row Matrix size. It must be:" << n_columns_  << std::endl;
        throw std::invalid_argument("Wrong length of row vector :(");
    } 
    data_.insert(data_.begin()+row*n_columns_-n_columns_,data.begin(),data.end());
    data_.erase(data_.begin()+(row+1)*n_columns_-n_columns_,data_.begin()+(row+1)*n_columns_);
}

template<typename T> std::size_t marsvin::Matrix<T>::GetNumberOfRows() {
    return n_rows_;
}

template<typename T> std::size_t marsvin::Matrix<T>::GetNumberOfColumns() {
    return n_columns_;
}

template<typename T> void marsvin::Matrix<T>::Print() {
    for (std::size_t j = 0; j < data_.size(); j++) {
        if ( (j+1) % n_columns_ == 0) { 
            std::cout << data_.at(j) << '\n';
        } else {
            std::cout << data_.at(j) << '\t';
        }
    };
}

// (r-1,c-1)    :   Matrix coordinate for C++. The users set r,c like in books
//  k           :   1d index
template<typename T> std::size_t marsvin::Matrix<T>::Transform2dTo1d(std::size_t r,std::size_t c) {
    std::size_t k = c-1 + n_columns_*(r-1);
    return k;
}

template<typename T> std::vector<std::size_t> marsvin::Matrix<T>::Transform1dTo2d(std::size_t k) {
    return std::vector<std::size_t>(2,0); 
}

template<typename T> bool marsvin::Matrix<T>::IsSquare() {
    bool is_square_ = false;
    if (n_rows_ == n_columns_) {
        is_square_ = true;
    }
    return is_square_; 
}

}
#endif // MARSVIN_MATRIX_HPP_

