
#ifndef MARSVIN_CORE_MARSVIN_TOOLS_HPP_
#define MARSVIN_CORE_MARSVIN_TOOLS_HPP_

#include "marsvin_base_matrix.hpp"

namespace marsvin {
namespace tools {

template<typename T>
bool CompareMatrix(const ::marsvin::BaseMatrix<T>& m_lhs,
                   const ::marsvin::BaseMatrix<T>& m_rhs,
                   T tolerance = 0.01) {
    bool result = true;
    if ((m_lhs.rows() == m_rhs.rows()) &&
        (m_lhs.columns() == m_rhs.columns())) {
        for (std::size_t r = 0; r < m_rhs.rows(); ++r) {
            for (std::size_t c = 0; c < m_rhs.columns(); ++c) {
                T diff = m_lhs.at(r, c) - m_rhs.at(r, c);
                bool compare_one = diff < tolerance;
                bool compare_two = -1 * tolerance < diff;
                if (!compare_one || !compare_two) {
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

}  // namespace tools
}  // namespace marsvin

#endif  // MARSVIN_CORE_MARSVIN_TOOLS_HPP_
