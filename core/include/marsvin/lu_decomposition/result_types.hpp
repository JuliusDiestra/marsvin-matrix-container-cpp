/**
 * @file result_types.hpp
 *
 */

#ifndef MARSVIN_LU_DECOMPOSITION_RESULT_TYPES_HPP_
#define MARSVIN_LU_DECOMPOSITION_RESULT_TYPES_HPP_

namespace marsvin {
namespace lud {

template <typename T>
class result {
  public:
    result(::marsvin::Matrix<T> L,
           ::marsvin::Matrix<T> U,
           ::marsvin::Matrix<T> P,
           ::marsvin::Matrix<T> Q) {
        result_.reserve(4);
        result_.push_back(std::move(L));
        result_.push_back(std::move(U));
        result_.push_back(std::move(P));
        result_.push_back(std::move(Q));
    }
    const ::marsvin::Matrix<T>& L() {
        return result_.at(0);
    };
    ::marsvin::Matrix<T> U() {
        return result_.at(1);
    }
    ::marsvin::Matrix<T> P() {
        return result_.at(2);
    }
    ::marsvin::Matrix<T> Q() {
        return result_.at(3);
    }
  private:
    std::vector<::marsvin::Matrix<T>> result_;
};

}  // namespace lud
}  // namespace marsvin

#endif  // MARSVIN_LU_DECOMPOSITION_RESULT_TYPES_HPP_

