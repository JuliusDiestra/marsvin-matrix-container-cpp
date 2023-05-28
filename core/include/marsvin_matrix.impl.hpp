#ifndef MARSVIN_CORE_MARSVIN_MATRIX_IMPL_HPP_
#define MARSVIN_CORE_MARSVIN_MATRIX_IMPL_HPP_

namespace marsvin {

template<typename T>
Matrix<T>::Matrix() :
  BaseMatrix<T>::BaseMatrix() {}

template<typename T>
Matrix<T>::Matrix(std::size_t rows, std::size_t columns) :
  BaseMatrix<T>::BaseMatrix(rows, columns) {}

template<typename T>
Matrix<T>::Matrix(std::size_t size) :
  BaseMatrix<T>::BaseMatrix(size, size) {}

template<typename T>
Matrix<T>::Matrix(std::size_t rows,
                  std::size_t columns,
                  std::initializer_list<T> initializer_list) :
  BaseMatrix<T>::BaseMatrix(rows, columns, initializer_list) {}

template<typename T>
Matrix<T>::Matrix(
    std::initializer_list<std::initializer_list<T>> double_initializer_list) {
    std::size_t rows = double_initializer_list.size();
    std::size_t columns{0};
    for (auto it = double_initializer_list.begin();
         it != double_initializer_list.end();
         ++it) {
        if (it == double_initializer_list.begin()) {
            columns = (*it).size();
        } else {
            if (columns != (*it).size()) {
                throw marsvin::Exception(
                    marsvin::StatusCode::TypeErrorDoubleInitializerList());
            }
        }
    }
    this->rows_ = rows;
    this->columns_ = columns;
    this->data_ = this->allocator_.allocate(this->size());
    int counter{0};
    for (auto it = double_initializer_list.begin();
         it != double_initializer_list.end();
         ++it) {
        std::copy(
            (*it).begin(), (*it).end(), this->data_ + this->columns_ * counter);
        ++counter;
    }
}

template<typename T>
Matrix<T>::Matrix(const Matrix& other) :
  BaseMatrix<T>::BaseMatrix(other) {}

template<typename T>
Matrix<T>::Matrix(Matrix&& other) :
  BaseMatrix<T>::BaseMatrix(std::move(other)),
  instance_counter{std::move(other.instance_counter)} {}

template<typename T>
std::size_t Matrix<T>::GetId() const {
    return instance_counter.id();
}

template<typename T>
std::size_t Matrix<T>::GetInstanceCounter() {
    return InstanceCounter<Matrix>::counter();
}

template<typename T>
bool Matrix<T>::is_square() const {
    bool is_square;
    if (this->rows() == this->columns()) {
        is_square = true;
    } else {
        is_square = false;
    }
    return is_square;
}

template<typename T>
void Matrix<T>::set_diagonal(T value) {
    if (is_square()) {
        for (std::size_t j; j < this->rows(); ++j) {
            this->at(j, j) = value;
        }
    }
}

}  // namespace marsvin

#endif  // MARSVIN_CORE_MARSVIN_MATRIX_IMPL_HPP_
