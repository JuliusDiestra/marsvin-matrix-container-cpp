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
}

#endif // MARSVIN_MATRIX_HPP_

