/**
 * @file marsvin_logger.hpp
 *
 */

#ifndef MARSVIN_CORE_MARSVIN_LOGGER_HPP_
#define MARSVIN_CORE_MARSVIN_LOGGER_HPP_

#include <iostream>
#include <vector>

#include "marsvin_base_matrix.hpp"

namespace marsvin {

/**
 * @class Logger
 * @brief Class to print marsvin::Matrix and std::vectors instances using <<
 * operator.
 *
 */
class Logger {
  public:
    /**
     * @brief Default constructor.
     *
     * Creates Logger instance use to stream marsvin::Matrix and std::vector
     * elements.
     *
     */
    Logger();
    /**
     * @brief Method to print marsvin::Matrix elements.
     *
     * @param matrix Matrix instance to stream elements.
     *
     */
    template<typename T>
    void operator<<(const marsvin::BaseMatrix<T>& matrix);
    /**
     * @brief Method to print std::vector elements.
     *
     * @param vector Vector instance to stream elements.
     *
     */
    template<typename T>
    void operator<<(const std::vector<T>& vector);
};

}  // namespace marsvin

// Implementation

marsvin::Logger::Logger(){};

template<typename T>
void marsvin::Logger::operator<<(const marsvin::BaseMatrix<T>& matrix) {
    for (std::size_t r = 0; r < matrix.rows(); ++r) {
        for (std::size_t c = 0; c < matrix.columns(); ++c) {
            if (c == (matrix.columns() - 1)) {
                std::cout << matrix.at(r,c) << '\n';
            } else {
                std::cout << matrix.at(r,c) << '\t';
            }
        }
    };
}

template<typename T>
void marsvin::Logger::operator<<(const std::vector<T>& vector) {
    for (std::size_t j = 0; j < vector.size(); j++) {
        if (j != vector.size() - 1) {
            std::cout << vector.at(j) << '\t';
        } else {
            std::cout << vector.at(j) << '\n';
        }
    }
}
#endif  // MARSVIN_CORE_MARSVIN_LOGGER_HPP_
