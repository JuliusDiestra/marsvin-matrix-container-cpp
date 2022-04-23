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
        Logger();
        template<typename T> static void operator<<(const marsvin::Matrix<T>& matrix);
        template<typename T> static void operator<<(const std::vector<T>& vector);
}

}

// Implementation

marsvin::Logger::Logger(){};

template<typename T> void operator<<(const marsvin::Matrix<T>& matrix) {
    data_ = matrix.GetVectorData();
    for (std::size_t j = 0; j < data_.size(); j++) {
        if ( (j+1) % matrix.GetNumberOfColumns() == 0) {
            std::cout << data_[j] << '\n';
        } else {
            std::cout << data_.[j] << '\t';
        }
    };
}

template<typename T> void operator<<(const std::vector<T>& vector) {
    // to be done
}


#endif // MARSVIN_CORE_MARSVIN_LOGGER_HPP_
