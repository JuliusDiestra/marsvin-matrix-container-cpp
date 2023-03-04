/**
 * @file marsvin_base_matrix.hpp
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
        using value_type = T;
        using size_type = std::size_t;
        using reference = value_type&;
        using const_reference = const value_type&;
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
        BaseMatrix(std::size_t rows, std::size_t columns);
        /**
         * Base matrix destructor
         */
        ~BaseMatrix();
        /**
         * @brief Method to check if matrix is empty.
         */
        bool empty() const;
        /**
         * @brief Method to get the number of rows of the matrix.
         *
         */
        std::size_t rows() const;
        /**
         * @brief Method to get the number of columns of the matrix.
         *
         */
        std::size_t columns() const;
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
         *  @brief Method to get matrix entry/element.
         *
         *  @param row Row index.
         *  @param column Column index.
         *
         */
        T GetEntry(std::size_t row, std::size_t column) const;
    protected:
        /**
         * Matrix number of rows.
         */
        std::size_t rows_;
        /**
         * Matrix number of columns.
         */
        std::size_t columns_;
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
        /**
         * @brief Method to transform a 2D matrix index to the equivalent 1D index of the vector.
         * where data is stored.
         *
         * @param row Row index.
         * @param column Column index.
         */
        std::size_t Transform2dTo1d(std::size_t row, std::size_t column) const;
        /**
         * @brief Method to check index boundaries to access entry/element.
         *
         * Check if the index is out of the limits of the number of row and columns.
         * In case is out of boundaries, the method throw and exception.
         *
         *  @param row Row index.
         *  @param column Column index.
         */
        void CheckIndex(std::size_t row, std::size_t column) const;
};

template<typename T>
BaseMatrix<T>::BaseMatrix(std::size_t rows, std::size_t columns) :
  rows_{rows},
  columns_{columns},
  size_{rows_*columns_} {
    if (size_ > 0) {
        data_ = allocator_.allocate(size_);
    } else {
        data_ = nullptr;
    }
}

template<typename T>
BaseMatrix<T>::BaseMatrix() : BaseMatrix(0, 0) {}

template<typename T>
BaseMatrix<T>::~BaseMatrix() {
    if (!empty()) {
        allocator_.deallocate(data_, size_);
    }
}

template<typename T>
bool BaseMatrix<T>::empty() const {
    bool empty_ = false;
    if (data_ == nullptr) {
        empty_ = true;
    }
    return empty_;
}

template<typename T>
std::size_t BaseMatrix<T>::rows() const {
    return rows_;
}

template<typename T>
std::size_t BaseMatrix<T>::columns() const {
    return columns_;
}

template<typename T>
void marsvin::BaseMatrix<T>::SetEntry(std::size_t row,std::size_t column, T entry) {
    CheckIndex(row,column);
    std::size_t k = Transform2dTo1d(row,column);
    data_[k] = entry;
}

// Protected
template<typename T>
std::size_t marsvin::BaseMatrix<T>::Transform2dTo1d(std::size_t row,std::size_t column) const {
    std::size_t k = column + columns_*(row);
    return k;
}

template<typename T>
void marsvin::BaseMatrix<T>::CheckIndex(std::size_t row, std::size_t column) const {
    if (row >= rows_ ) {
        if (column >= columns_) {
            throw std::invalid_argument("Index out of bounderies for ROW and COLUMN");
        }
        throw std::invalid_argument("Index out of bounderies for ROW");
    } else {
        if (column >= columns_ ) {
            throw std::invalid_argument("Index out of bounderies for COLUMN");
        }
    }
}

} // namespace marsvin

#endif // MARSVIN_CORE_MARSVIN_BASE_MATRIX_HPP_
