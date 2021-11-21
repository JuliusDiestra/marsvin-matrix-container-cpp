#include "marsvin_matrix.hpp"

template class marsvin::Matrix<int>;
template class marsvin::Matrix<float>;
template class marsvin::Matrix<double>;

/*
// Constructors
template<typename T> marsvin::Matrix<T>::Matrix(std::size_t row, std::size_t column): row_{ row }, column_{ column }, data_{ std::vector<T>(row*column,0) } {};
template<typename T> marsvin::Matrix<T>::Matrix(): Matrix(0,0) {};
template<typename T> marsvin::Matrix<T>::Matrix(std::size_t n):Matrix(n,n){};

template<typename T> void marsvin::Matrix<T>::SetValue(std::size_t row, std::vector<T> data) {
    data_.insert(data_.begin()+row,data.begin(),data.end());
};

std::size_t marsvin::Matrix::GetNumberOfRows() {
    return row_;
};

std::size_t marsvin::Matrix::GetNumberOfColumns() {
    return column_;
};
*/
