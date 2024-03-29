/**
 * @file vector.hpp
 *
 */

#ifndef MARSVIN_CONTAINERS_VECTOR_HPP_
#define MARSVIN_CONTAINERS_VECTOR_HPP_

#include "marsvin/containers/base_matrix.hpp"
#include "marsvin/tools/instance_counter.hpp"

namespace marsvin {

/**
 * @class Vector
 * @brief Vector container. A vector consider as a matrix Nx1.
 */
template<typename T>
class Vector : public BaseMatrix<T> {
  public:
    /**
     * @brief Default constructor.
     *
     * Creates an empty vector. Size of the vector is 0.
     *
     */
    Vector();
    /**
     * @brief Constructor to initialize vector with a defined size.
     *
     * Create a vector with a defined size.
     * All vector entries are zero.
     *
     * @param size Number of vector elements/entries.
     *
     */
    Vector(std::size_t size);

    /**
     * @brief Constructor using initializer list
     *
     * The size of vector is the size of the initializer list.
     *
     * @param initializer_list Initializer list.
     */
    Vector(std::initializer_list<T> initializer_list);

    /**
     * @brief Copy constructor
     *
     * Copy data allocated from input vector instance to the new vector
     * instance.
     */
    Vector(const Vector& other);

    /**
     * @brief Move constructor
     *
     * Move data allocated from input vector instance to the new vector
     * instance.
     */
    Vector(Vector&& other);

    /**
     * @brief Copy assignment
     *
     */
    Vector<T>& operator=(const Vector& other);

    /**
     * @brief Move assignment
     *
     */
    Vector<T>& operator=(Vector&& other);

    /**
     * @brief Method to resize vector container.
     *
     * @param size Number of elements.
     *
     */
    void resize(std::size_t size);

    /**
     * @brief Method to set vector entry/element.
     *
     * @param index Element index.
     *
     */
    T& at(std::size_t index);

    /**
     * @brief Method to set vector entry/element.
     *
     * @param index Element index.
     *
     */
    const T& at(std::size_t index) const;

    /**
     * @brief Method to get vector instance ID.
     *
     * Each vector instance created has a unique ID.
     */
    std::size_t GetId() const;

    /**
     * @brief Method to get total number of marsvin::Vector<T> created.
     *
     * This static method get the count of all the marsvin::Vector<T> created.
     * While a vector is destroyed or moved, the counter goes down one.
     */
    static std::size_t GetInstanceCounter();

  private:
    InstanceCounter<Vector> instance_counter;
};
}  // namespace marsvin

#include "marsvin/containers/vector_impl.hpp"

#endif  // MARSVIN_CONTAINERS_VECTOR_HPP_
