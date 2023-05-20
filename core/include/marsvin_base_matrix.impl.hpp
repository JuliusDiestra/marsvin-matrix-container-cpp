
#ifndef MARSVIN_CORE_MARSVIN_BASE_MATRIX_IMPL_HPP_
#define MARSVIN_CORE_MARSVIN_BASE_MATRIX_IMPL_HPP_

namespace marsvin {
/*
 * Public
 */
template<typename T>
BaseMatrix<T>::BaseMatrix(std::size_t rows, std::size_t columns) :
  rows_{rows},
  columns_{columns} {
    if (size() > 0) {
        data_ = allocator_.allocate(size());
        std::fill(begin(), end(), static_cast<T>(0));
    } else {
        data_ = nullptr;
    }
}

template<typename T>
BaseMatrix<T>::BaseMatrix() :
  BaseMatrix(0, 0) {}

template<typename T>
BaseMatrix<T>::BaseMatrix(std::size_t rows,
                          std::size_t columns,
                          std::initializer_list<T> initializer_list) {
    if (initializer_list.size() != (rows * columns)) {
        throw marsvin::Exception(
            marsvin::StatusCode::TypeErrorInitializerList());
    }
    rows_ = rows;
    columns_ = columns;
    data_ = allocator_.allocate(size());
    std::copy(initializer_list.begin(), initializer_list.end(), data_);
}

template<typename T>
BaseMatrix<T>::BaseMatrix(const BaseMatrix& other) {
    data_ = allocator_.allocate(other.rows() * other.columns());
    std::copy(other.data_, other.data_ + other.size(), data_);
    rows_ = other.rows_;
    columns_ = other.columns_;
}

template<typename T>
BaseMatrix<T>::BaseMatrix(BaseMatrix&& other) :
  data_{std::exchange(other.data_, nullptr)} {
    rows_ = other.rows();
    columns_ = other.columns();
    other.rows_ = 0;
    other.columns_ = 0;
}

template<typename T>
BaseMatrix<T>::~BaseMatrix() {
    if (!empty()) {
        allocator_.deallocate(data_, size());
    }
}

template<typename T>
BaseMatrix<T>& BaseMatrix<T>::operator=(const BaseMatrix& other) {
    if (!empty()) {
        allocator_.deallocate(data_, size());
    }
    data_ = allocator_.allocate(other.size());
    columns_ = other.columns_;
    rows_ = other.rows_;
    return *this;
}

template<typename T>
BaseMatrix<T>& BaseMatrix<T>::operator=(BaseMatrix&& other) {
    data_ = std::exchange(other.data_, nullptr);
    other.rows_ = 0;
    other.columns_ = 0;
    return *this;
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
std::size_t BaseMatrix<T>::size() const {
    return rows_ * columns_;
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
void BaseMatrix<T>::resize(std::size_t resize_rows,
                           std::size_t resize_columns) {
    if ((resize_rows == rows_) && (resize_columns == columns_)) {
        return;
    } else {
        std::size_t new_size_ = resize_rows * resize_columns;
        T* data_resize_ = allocator_.allocate(resize_rows * resize_columns);
        std::fill(data_resize_, data_resize_ + new_size_, 0);
        if (resize_rows >= rows_) {
            if (resize_columns >= columns_) {
                // CASE 1 : New matrix bigger.
                for (std::size_t j = 0; j < rows_; ++j) {
                    std::copy(data_ + j * columns_,
                              data_ + j * columns_ + columns_,
                              data_resize_ + j * resize_columns);
                }
            } else {
                // CASE 2 : Resized matrix cut down by column
                for (std::size_t j = 0; j < rows_; ++j) {
                    std::copy(data_ + j * columns_,
                              data_ + j * columns_ + resize_columns,
                              data_resize_ + j * resize_columns);
                }
            }
        } else {
            if (resize_columns >= columns_) {
                // CASE 3 : Resized matrix cut down by row
                for (std::size_t j = 0; j < resize_rows; ++j) {
                    std::copy(data_ + j * columns_,
                              data_ + j * columns_ + columns_,
                              data_resize_ + j * resize_columns);
                }
            } else {
                // CASE 4 : Resized matrix cut down column and row
                for (std::size_t j = 0; j < resize_rows; ++j) {
                    std::copy(data_ + j * columns_,
                              data_ + j * columns_ + resize_columns,
                              data_resize_ + j * resize_columns);
                }
            }
        }
        // Allocate ande deallocate
        allocator_.deallocate(data_, size());
        data_ = allocator_.allocate(new_size_);
        std::copy(data_resize_, data_resize_ + new_size_, data_);
        allocator_.deallocate(data_resize_, new_size_);
        // Set new rows and columns
        rows_ = resize_rows;
        columns_ = resize_columns;
    }
}

template<typename T>
void BaseMatrix<T>::clear() {
    if (empty()) {
        return;
    } else {
        allocator_.deallocate(data_, size());
        data_ = nullptr;
        columns_ = 0;
        rows_ = 0;
    }
}

template<typename T>
typename BaseMatrix<T>::iterator BaseMatrix<T>::begin() {
    return &data_[0];
}

template<typename T>
typename BaseMatrix<T>::iterator BaseMatrix<T>::end() {
    return &data_[size() - 1];
}

template<typename T>
marsvin::BaseMatrix<T> operator+(const marsvin::BaseMatrix<T>& m_lhs,
                                 const marsvin::BaseMatrix<T>& m_rhs) {
    if ((m_lhs.rows() == m_rhs.rows()) &&
        (m_lhs.columns() == m_rhs.columns())) {
        marsvin::BaseMatrix<T> m_result(m_rhs.rows(), m_rhs.columns());
        for (std::size_t r = 0; r < m_rhs.rows(); ++r) {
            for (std::size_t c = 0; c < m_rhs.columns(); ++c) {
                m_result.at(r, c) = m_lhs.at(r, c) + m_rhs.at(r, c);
            }
        }
        return marsvin::BaseMatrix<T>(m_result);
    } else {
        throw marsvin::Exception(
            marsvin::StatusCode::TypeErrorAdditionDimension());
    }
}

template<typename T>
marsvin::BaseMatrix<T> operator+(const marsvin::BaseMatrix<T>& m_lhs,
                                 const T& scalar) {
    marsvin::BaseMatrix<T> m_result(m_lhs.rows(), m_lhs.columns());
    for (std::size_t r = 0; r < m_lhs.rows(); ++r) {
        for (std::size_t c = 0; c < m_lhs.columns(); ++c) {
            m_result.at(r, c) = m_lhs.at(r, c) + scalar;
        }
    }
    return m_result;
}

template<typename T>
marsvin::BaseMatrix<T> operator+(const T& scalar,
                                 const marsvin::BaseMatrix<T>& m_rhs) {
    marsvin::BaseMatrix<T> m_result(m_rhs.rows(), m_rhs.columns());
    for (std::size_t r = 0; r < m_rhs.rows(); ++r) {
        for (std::size_t c = 0; c < m_rhs.columns(); ++c) {
            m_result.at(r, c) = m_rhs.at(r, c) + scalar;
        }
    }
    return m_result;
}

template<typename T>
marsvin::BaseMatrix<T> operator-(const marsvin::BaseMatrix<T>& m_lhs,
                                 const marsvin::BaseMatrix<T>& m_rhs) {
    if ((m_lhs.rows() == m_rhs.rows()) &&
        (m_lhs.columns() == m_rhs.columns())) {
        marsvin::BaseMatrix<T> m_result(m_rhs.rows(), m_rhs.columns());
        for (std::size_t r = 0; r < m_rhs.rows(); ++r) {
            for (std::size_t c = 0; c < m_rhs.columns(); ++c) {
                m_result.at(r, c) = m_lhs.at(r, c) - m_rhs.at(r, c);
            }
        }
        return marsvin::BaseMatrix<T>(m_result);
    } else {
        throw marsvin::Exception(
            marsvin::StatusCode::TypeErrorAdditionDimension());
    }
}

template<typename T>
marsvin::BaseMatrix<T> operator-(const marsvin::BaseMatrix<T>& m_lhs,
                                 const T& scalar) {
    marsvin::BaseMatrix<T> m_result(m_lhs.rows(), m_lhs.columns());
    for (std::size_t r = 0; r < m_lhs.rows(); ++r) {
        for (std::size_t c = 0; c < m_lhs.columns(); ++c) {
            m_result.at(r, c) = m_lhs.at(r, c) - scalar;
        }
    }
    return m_result;
}

template<typename T>
marsvin::BaseMatrix<T> operator-(const T& scalar,
                                 const marsvin::BaseMatrix<T>& m_rhs) {
    marsvin::BaseMatrix<T> m_result(m_rhs.rows(), m_rhs.columns());
    for (std::size_t r = 0; r < m_rhs.rows(); ++r) {
        for (std::size_t c = 0; c < m_rhs.columns(); ++c) {
            m_result.at(r, c) = m_rhs.at(r, c) - scalar;
        }
    }
    return m_result;
}

template<typename T>
marsvin::BaseMatrix<T> operator*(const marsvin::BaseMatrix<T>& m_lhs,
                                 const marsvin::BaseMatrix<T>& m_rhs) {
    T sum;
    marsvin::BaseMatrix<T> m_result(m_lhs.rows(), m_rhs.columns());
    if (m_lhs.columns() == m_rhs.rows()) {
        for (std::size_t i = 0; i < m_lhs.rows(); ++i) {
            for (std::size_t j = 0; j < m_rhs.columns(); ++j) {
                sum = 0;
                for (std::size_t k=0; k < m_lhs.columns(); ++k) {
                    sum += m_lhs.at(i,k)*m_rhs.at(k,j);
                }
                m_result.at(i,j) = sum;
            }
        }
    } else {
        throw marsvin::Exception(
            marsvin::StatusCode::TypeErrorMultiplicationDimension());
    }
    return m_result;
}

template<typename T>
bool operator==(const marsvin::BaseMatrix<T>& m_lhs,
                const marsvin::BaseMatrix<T>& m_rhs) {
    bool result = true;
    if ((m_lhs.rows() == m_rhs.rows()) &&
        (m_lhs.columns() == m_rhs.columns())) {
        for (std::size_t r = 0; r < m_rhs.rows(); ++r) {
            for (std::size_t c = 0; c < m_rhs.columns(); ++c) {
                if (m_lhs.at(r, c) != m_rhs.at(r, c)) {
                    result = false;
                    return result;
                }
            }
        }
    } else {
        result = false;
    }
    return result;
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
        throw marsvin::Exception(
            marsvin::StatusCode::TypeErrorRowAndColumnIndex());
    }
    if (row >= rows_) {
        throw marsvin::Exception(marsvin::StatusCode::TypeErrorRowIndex());
    }
    if (column >= columns_) {
        throw marsvin::Exception(marsvin::StatusCode::TypeErrorColumnIndex());
    }
}

}  // namespace marsvin

#endif  // MARSVIN_CORE_MARSVIN_BASE_MATRIX_IMPL_HPP_
