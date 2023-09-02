/**
 * @file marsvin_instance_counter.hpp
 *
 */

#ifndef MARSVIN_CORE_INSTANCE_COUNTER_H_
#define MARSVIN_CORE_INSTANCE_COUNTER_H_

#include <cstddef>

namespace marsvin {

template<typename T>
class InstanceCounter {
  public:
    InstanceCounter();
    InstanceCounter(const InstanceCounter& other);
    InstanceCounter(InstanceCounter&& other);
    ~InstanceCounter();
    static std::size_t counter();
    std::size_t id() const;

  private:
    static std::size_t counter_;
    std::size_t id_;
};

template<typename T>
InstanceCounter<T>::InstanceCounter() {
    id_ = ++counter_;
}

template<typename T>
InstanceCounter<T>::InstanceCounter(const InstanceCounter& other) {
    id_ = ++counter_;
}

template<typename T>
InstanceCounter<T>::InstanceCounter(InstanceCounter&& other) {
    id_ = other.id_;
}

template<typename T>
InstanceCounter<T>::~InstanceCounter() {
    if (counter_ <= 0) {
        counter_ = 0;
    } else {
        --counter_;
    }
}

template<typename T>
std::size_t InstanceCounter<T>::counter() {
    return counter_;
}

template<typename T>
std::size_t InstanceCounter<T>::id() const {
    return id_;
}

template<typename T>
std::size_t InstanceCounter<T>::counter_ = 0;

}  // namespace marsvin

#endif  // MARSVIN_CORE_INSTANCE_COUNTER_H_
