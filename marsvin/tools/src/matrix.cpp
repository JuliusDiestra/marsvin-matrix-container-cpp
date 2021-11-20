#include "marsvin_matrix.hpp"

// Constructors
marsvin::Matrix::Matrix(std::size_t row, std::size_t column): row_{ row }, colum_{ column }, data_{ std::vector<T>(row*column,0) } {};
marsvin::Matrix::Matrix():Matrix(0,0) {};
marsvin::Matrix::Matrix(std::size_t n):Matrix(n,n){};

void marsvin::Matrix::SetValue(std::size_t row, std::vector<T> data) {
    data_.insert(data_.begin()+row,data.begin(),data.end());
};

std::size_t marsvin::Matrix::GetNumberOfRows() {
    return row_;
};

std::size_t marsvin::Matrix::GetNumberOfColumns() {
    return column_;
};


