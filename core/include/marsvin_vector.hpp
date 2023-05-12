/**
 * @file marsvin_vector.hpp
 *
 */

#ifndef MARSVIN_CORE_MARSVIN_VECTOR_HPP_
#define MARSVIN_CORE_MARSVIN_VECTOR_HPP_

#include "marsvin_base_matrix.hpp"

namespace marsvin {

/**
 * @class Matrix
 * @brief Abstraction of a 2D container.
 */
template<typename T>
class Vector : public BaseMatrix<T> {
  public:
    Vector();
    Vector(std::size_t size);
    Vector(std::initializer_list<T> initializer_list);
    Vector(const Vector& other);
    Vector(Vector&& other);
  private:
    InstanceCounter<Vector> instance_counter;

};
}  // namespace marsvin

#include "marsvin_vector.impl.hpp"

#endif  // MARSVIN_CORE_MARSVIN_VECTOR_HPP_
