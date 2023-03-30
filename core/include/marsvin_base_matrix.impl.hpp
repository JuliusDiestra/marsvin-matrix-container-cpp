
#ifndef MARSVIN_CORE_MARSVIN_BASE_MATRIX_IMPL_HPP_
#define MARSVIN_CORE_MARSVIN_BASE_MATRIX_IMPL_HPP_

namespace marsvin {
/*
 * Public
 */
template<typename T>
BaseMatrix<T>::BaseMatrix(std::size_t rows, std::size_t columns) :
  rows_{rows},
  columns_{columns},
  size_{rows_ * columns_} {
    if (size_ > 0) {
        data_ = allocator_.allocate(size_);
    } else {
        data_ = nullptr;
    }
}

template<typename T>
BaseMatrix<T>::BaseMatrix() :
  BaseMatrix(0, 0) {}

template<typename T>
BaseMatrix<T>::~BaseMatrix() {
    if (!empty()) {
        allocator_.deallocate(data_, size_);
    }
}

template<typename T>
bool BaseMatrix<T>::empty() const {
    bool empty_;
    if (data_ == nullptr) {
        empty_ = true;
    } else {
        empty_ = false;
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
const T& BaseMatrix<T>::at(std::size_t row, std::size_t column) const {
    CheckIndex(row, column);
    return data_[Transform2dTo1d(row, column)];
}

template<typename T>
T& BaseMatrix<T>::at(std::size_t row, std::size_t column) {
    return const_cast<T&>(const_cast<const BaseMatrix*>(this)->at(row, column));
}

template<typename T>
void BaseMatrix<T>::resize(std::size_t resize_rows, std::size_t resize_columns) {
    if ((resize_rows == rows_) && (resize_columns == columns_)) {
        return;
    } else {
        std::size_t new_size_ = resize_rows * resize_columns;
        T* data_resize_ = allocator_.allocate(resize_rows * resize_columns);
        std::fill(data_resize_,data_resize_ + new_size_, 0);
        if (resize_rows >= rows_) {
            if (resize_columns >= columns_) {
                // CASE 1 : New matrix bigger.
                for (std::size_t j = 0; j < rows_; ++j) {
                    std::copy(data_ + j*columns_, data_ + j*columns_ + columns_, data_resize_ + j*resize_columns);
                }
            } else {
                // CASE 2 : Resized matrix cut down by column
                for (std::size_t j = 0; j < rows_; ++j) {
                    std::copy(data_ + j*columns_, data_ + j*columns_ + resize_columns, data_resize_ + j*resize_columns);
                }
            }
        } else {
            if (resize_columns >= columns_) {
                // CASE 3 : Resized matrix cut down by row
                for (std::size_t j = 0; j < resize_rows; ++j) {
                    std::copy(data_ + j*columns_, data_ + j*columns_ + columns_, data_resize_ + j*resize_columns);
                }
            } else {
                // CASE 4 : Resized matrix cut down column and row
                for (std::size_t j = 0; j < resize_rows; ++j) {
                    std::copy(data_ + j*columns_, data_ + j*columns_ + resize_columns, data_resize_ + j*resize_columns);
                }
            }
        }
        // Allocate ande deallocate
        allocator_.deallocate(data_, size_);
        data_ = allocator_.allocate(new_size_);
        std::copy(data_resize_, data_resize_ + new_size_, data_);
        allocator_.deallocate(data_resize_, new_size_);
        // Set new rows and columns
        size_ = new_size_;
        rows_ = resize_rows;
        columns_ = resize_columns;
    }
}

template<typename T>
void BaseMatrix<T>::clear() {
}
/*
 * Protected
 */
template<typename T>
std::size_t marsvin::BaseMatrix<T>::Transform2dTo1d(std::size_t row,
                                                    std::size_t column) const {
    std::size_t k = column + columns_ * (row);
    return k;
}

template<typename T>
void marsvin::BaseMatrix<T>::CheckIndex(std::size_t row,
                                        std::size_t column) const {
    if ((row >= rows_) && (column >= columns_)) {
        throw marsvin::Exception(marsvin::ErrorCode::TypeRowAndColumn());
    }
    if (row >= rows_) {
        throw marsvin::Exception(marsvin::ErrorCode::TypeRow());
    }
    if (column >= columns_) {
        throw marsvin::Exception(marsvin::ErrorCode::TypeColumn());
    }
}

}  // namespace marsvin

#endif  // MARSVIN_CORE_MARSVIN_BASE_MATRIX_IMPL_HPP_
