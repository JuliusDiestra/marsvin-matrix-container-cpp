/**
 * @file marsvin_logger.hpp
 *
 */

#ifndef MARSVIN_CORE_MARSVIN_LOGGER_HPP_
#define MARSVIN_CORE_MARSVIN_LOGGER_HPP_

#include "marsvin_matrix.hpp"
#include <iostream>
#include <vector>

namespace marsvin {

/**
 * @class Logger
 * @brief Class to print marsvin::Matrix and std::vectors instances using << operator.
 *
 */
class Logger {
    public:
        /*
         * @brief Default constructor.
         *
         * Creates Logger instance use to stream marsvin::Matrix and std::vector elements.
         *
         */
        Logger();
        /*
         * @brief Method to print marsvin::Matrix elements.
         *
         * @param matrix Matrix instance to stream elements.
         *
         */
        template<typename T> void operator<<(const marsvin::Matrix<T>& matrix);
        /*
         * @brief Method to print std::vector elements.
         *
         * @param vector Vector instance to stream elements.
         *
         */
        template<typename T> void operator<<(const std::vector<T>& vector);
};

}

// Implementation

marsvin::Logger::Logger(){};

template<typename T> void marsvin::Logger::operator<<(const marsvin::Matrix<T>& matrix) {
    std::vector<T> data_;
    data_ = matrix.GetVectorData();
    for (std::size_t j = 0; j < data_.size(); j++) {
        if ( (j+1) % matrix.GetNumberOfColumns() == 0) {
            std::cout << data_[j] << '\n';
        } else {
            std::cout << data_[j] << '\t';
        }
    };
}

template<typename T> void marsvin::Logger::operator<<(const std::vector<T>& vector) {
    for (std::size_t j = 0; j < vector.size(); j++) {
        if (j != vector.size() -1 ) {
            std::cout << vector.at(j) << '\t';
        } else {
            std::cout << vector.at(j) << '\n';
        }
    }
}
#endif // MARSVIN_CORE_MARSVIN_LOGGER_HPP_
