/**
 * @file marsvin_error_type.hpp
 *
 */

#ifndef MARSVIN_CORE_MARSVIN_TYPE_CODE_HPP_
#define MARSVIN_CORE_MARSVIN_TYPE_CODE_HPP_

namespace marsvin {

/**
 * @enum ErrorType
 * @brief Enum to clasify different runtime errors during operations with
 * matrices.
 *
 */
enum class ErrorType {
    kNoError,      // No error.
    kRow,          // Row index out of limits.
    kColumn,       // Column index out of limits.
    kRowAndColumn  // Row and column indexes out of limits.
    kAddition,     // Error adding two matrices.
    kSubstraction, // Error subtracting two matrices.
    kMultiplication // Error multiplying two matrices.
};

}  // namespace marsvin

#endif  // MARSVIN_CORE_MARSVIN_ERROR_TYPE_HPP_
