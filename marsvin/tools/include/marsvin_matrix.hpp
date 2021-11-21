#ifndef MARSVIN_MATRIX_HPP_
#define MARSVIN_MATRIX_HPP_

#include <cstddef>
#include <vector>

namespace marsvin {

template <typename T>
class Matrix {
    public:
        // Constructors
        Matrix(std::size_t row, std::size_t column);    // Any matrix
        Matrix();                                       // Default empty matrix.
        Matrix(std::size_t n);                          // Square matrix
        // Methods
        void SetValue(std::size_t row,std::vector<T> data);      // Matrix is filled by rows.
        std::size_t GetNumberOfRows();
        std::size_t GetNumberOfColumns();
    private:
        std::size_t row_;
        std::size_t column_;
        std::vector<T> data_;
};

// Implementation
template<typename T> marsvin::Matrix<T>::Matrix(std::size_t row, std::size_t column): row_{ row }, column_{ column }, data_{ std::vector<T>(row*column,0) } {}
template<typename T> marsvin::Matrix<T>::Matrix():Matrix(0,0) {}
template<typename T> marsvin::Matrix<T>::Matrix(std::size_t n):Matrix(n,n){}
template<typename T> void marsvin::Matrix<T>::SetValue(std::size_t row, std::vector<T> data) {
    data_.insert(data_.begin()+row,data.begin(),data.end());
}
template<typename T> std::size_t marsvin::Matrix<T>::GetNumberOfRows() {
    return row_;
}

template<typename T> std::size_t marsvin::Matrix<T>::GetNumberOfColumns() {
    return column_;
};

}


#endif // MARSVIN_MATRIX_HPP_

