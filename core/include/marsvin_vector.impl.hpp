#ifndef MARSVIN_CORE_MARSVIN_VECTOR_IMPL_HPP_
#define MARSVIN_CORE_MARSVIN_VECTOR_IMPL_HPP_

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
  BaseMatrix<T>::BaseMatrix(std::move(other)) {}

template<typename T>
std::size_t Vector<T>::GetId() const {
    return instance_counter.id();
}

template<typename T>
std::size_t Vector<T>::GetInstanceCounter() {
    return InstanceCounter<Vector>::counter();
}

}  // namespace marsvin

#endif  // MARSVIN_CORE_MARSVIN_VECTOR_IMPL_HPP_
