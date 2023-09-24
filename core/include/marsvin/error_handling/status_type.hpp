/**
 * @file status_type.hpp
 *
 */

#ifndef MARSVIN_ERROR_HANDLING_STATUS_TYPE_HPP_
#define MARSVIN_ERROR_HANDLING_STATUS_TYPE_HPP_

namespace marsvin {

/**
 * @enum StatusType
 * @brief Enum to clasify different status. Including success status or runtime
 * errors during operations with matrices and vectors.
 *
 */
enum class StatusType {
    kSuccess,                    // Success status.
    kErrorRowIndex,              // Row index out of limits.
    kErrorColumnIndex,           // Column index out of limits.
    kErrorRowAndColumnIndex,     // Row and column indexes out of limits.
    kErrorAdditionDimension,     // Error adding two matrices/vectors. Operation
                                 // needs similar dimensions.
    kErrorSubtractionDimension,  // Error subtraction two matrices/vectors.
                                 // Operation needs similar dimensions.
    kErrorMultiplicationDimension,  // Error multiplying two matrices.
                                    // Dimensions error.
    kErrorInitializerList,  // Initializer list does not match matrix size.
    kErrorDoubleInitializerList,  // Initializer list does not match matrix
                                  // size.
    kErrorSquareMatrix,  // Error while a function is not applied to an square
                         // matrix.
    kErrorEqualSize,     // Error while same size of matrix/vector is needed.
    kErrorSolveLinearEquantionDimensions  // Error while A*x=b, A.columns() or
                                          // A.rows() != b.size()
};

}  // namespace marsvin

#endif  // MARSVIN_CORE_MARSVIN_STATUS_TYPE_HPP_
