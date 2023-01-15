/**
 * @file marsvin_matrix.hpp
 *
 */

#ifndef MARSVIN_CORE_MARSVIN_BASE_MATRIX_HPP_
#define MARSVIN_CORE_MARSVIN_BASE_MATRIX_HPP_


namespace marsvin {

/**
 * @class BaseMatrix
 * @brief Base natrix class with minimum features.
 *
 */
template <typename T>
class BaseMatrix {
    public:
        /**
         * @brief Default constructor.
         *
         * Creates an empty matrix. Size of the matrix is 0x0.
         *
         */
        BaseMatrix();
        /**
         * @brief Constructor for any matrix.
         *
         * Creates matrix of any size. Number of rows and columns are input parameters of constructor.
         * All matrix entries are zero.
         *
         * @param n_rows Number of rows.
         * @param n_columns Number of columns.
         *
         */
        BaseMatrix(std::size_t n_rows, std::size_t n_columns);
        /*
         * Base matrix destructor
         */
        ~BaseMatrix();
    protected:
        /**
         * Matrix number of rows.
         */
        std::size_t n_rows_;
        /**
         * Matrix number of columns.
         */
        std::size_t n_columns_;
        /*
         * Matrix size
         */
        std::size_t size_;
        /*
         * Data allocator
         */
        std::allocator<T> allocator_;
        /**
         * Matrix data stored in a one dimension array.
         */
        T* data_;
};

template<typename T> BaseMatrix<T>::BaseMatrix(std::size_t n_rows, std::size_t n_columns) :
  n_rows_{n_rows},
  n_columns_{n_columns},
  size_{n_rows_*n_columns_} {
    if (size_ > 0) {
        data_ = allocator_.allocate(size_);
    }
}

} // namespace marsvin

#endif // MARSVIN_CORE_MARSVIN_BASE_MATRIX_HPP_
