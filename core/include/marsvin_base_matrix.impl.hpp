
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
T& marsvin::BaseMatrix<T>::at(std::size_t row,std::size_t column) {
    CheckIndex(row,column);
    return data_[Transform2dTo1d(row,column)];
}

/*
 * Protected
 */
template<typename T>
std::size_t marsvin::BaseMatrix<T>::Transform2dTo1d(std::size_t row,std::size_t column) const {
    std::size_t k = column + columns_*(row);
    return k;
}

template<typename T>
void marsvin::BaseMatrix<T>::CheckIndex(std::size_t row, std::size_t column) const {
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

} // namespace marsvin

#endif // MARSVIN_CORE_MARSVIN_BASE_MATRIX_IMPL_HPP_
