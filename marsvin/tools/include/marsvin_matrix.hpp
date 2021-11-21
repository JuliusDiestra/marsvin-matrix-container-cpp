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
        void SetRow(std::size_t row,std::vector<T> data);     // Matrix is filled by rows.
        std::size_t GetNumberOfRows();                          // Get matrix number of rows
        std::size_t GetNumberOfColumns();                       // Get matrix number of columns
        void Print();                                           // Print Matrix values
    private:
        std::size_t row_;
        std::size_t column_;
        std::vector<T> data_;
};

// Implementation

// Constructor
template<typename T> marsvin::Matrix<T>::Matrix(std::size_t row, std::size_t column): row_{ row }, column_{ column }, data_{ std::vector<T>(row*column,0) } {}
template<typename T> marsvin::Matrix<T>::Matrix():Matrix(0,0) {}
template<typename T> marsvin::Matrix<T>::Matrix(std::size_t n):Matrix(n,n){}

// Methods
template<typename T> void marsvin::Matrix<T>::SetRow(std::size_t row, std::vector<T> data) {
    if (column_ != data.size() ) {
        std::cerr << "Wrong Row Matrix size. It must be:" << column_  << std::endl;
        throw std::invalid_argument("Wrong length of row vector.");
    } 
    data_.insert(data_.begin()+row*column_-column_,data.begin(),data.end());
    data_.erase(data_.begin()+(row+1)*column_-column_,data_.begin()+(row+1)*column_);
}

template<typename T> std::size_t marsvin::Matrix<T>::GetNumberOfRows() {
    return row_;
}

template<typename T> std::size_t marsvin::Matrix<T>::GetNumberOfColumns() {
    return column_;
}

template<typename T> void marsvin::Matrix<T>::Print() { 
    for (std::size_t j = 0; j < data_.size(); j++) {
        if ( (j+1) % column_ == 0) { 
            std::cout << data_.at(j) << '\n';
        } else {
            std::cout << data_.at(j) << '\t';
        }
    };
}

}

#endif // MARSVIN_MATRIX_HPP_

