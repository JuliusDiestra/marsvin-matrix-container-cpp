/**
 * @file vector_impl.hpp
 *
 */

#ifndef MARSVIN_CONTAINERS_VECTOR_IMPL_HPP_
#define MARSVIN_CONTAINERS_VECTOR_IMPL_HPP_

namespace marsvin {

template<typename T>
Vector<T>::Vector() :
  BaseMatrix<T>::BaseMatrix() {}

template<typename T>
Vector<T>::Vector(std::size_t size) :
  BaseMatrix<T>::BaseMatrix(size, 1) {}

template<typename T>
Vector<T>::Vector(std::initializer_list<T> initializer_list) :
  BaseMatrix<T>::BaseMatrix(initializer_list.size(), 1, initializer_list) {}

template<typename T>
Vector<T>::Vector(const Vector& other) :
  BaseMatrix<T>::BaseMatrix(other) {}

template<typename T>
Vector<T>::Vector(Vector&& other) :
  BaseMatrix<T>::BaseMatrix(std::move(other)),
  instance_counter{std::move(other.instance_counter)} {}

template<typename T>
Vector<T>& Vector<T>::operator=(const Vector& other) {
    return this->operator=(other);
}

template<typename T>
Vector<T>& Vector<T>::operator=(Vector&& other) {
    return this->operator=(other);
}

template<typename T>
void Vector<T>::resize(std::size_t size) {
    BaseMatrix<T>::resize(size, 1);
}

template<typename T>
T& Vector<T>::at(std::size_t index) {
    return BaseMatrix<T>::at(index, 0);
}

template<typename T>
const T& Vector<T>::at(std::size_t index) const {
    return BaseMatrix<T>::at(index, 0);
}

template<typename T>
std::size_t Vector<T>::GetId() const {
    return instance_counter.id();
}

template<typename T>
std::size_t Vector<T>::GetInstanceCounter() {
    return InstanceCounter<Vector>::counter();
}

}  // namespace marsvin

#endif  // MARSVIN_CONTAINERS_VECTOR_IMPL_HPP_
