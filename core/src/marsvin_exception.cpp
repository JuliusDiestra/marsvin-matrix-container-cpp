
#include "marsvin/error_handling/exception.hpp"

namespace marsvin {

Exception::Exception(const StatusCode& status_code) :
  std::out_of_range(StatusCodeToString(status_code)),
  status_code_{status_code} {
    if (status_code_.success()) {
        throw std::invalid_argument(
            "marsvin::Exception constructor argument should be an StatusCode "
            "class storing a failure.");
    }
}

StatusCode Exception::status_code() const {
    return status_code_;
}

std::string Exception::StatusCodeToString(const StatusCode& status_code) {
    std::string string_{};
    switch (status_code.status_type()) {
        case marsvin::StatusType::kErrorRowIndex:
            string_ = "Row index out of limits";
            break;
        case marsvin::StatusType::kErrorColumnIndex:
            string_ = "Column index out of limits";
            break;
        case marsvin::StatusType::kErrorRowAndColumnIndex:
            string_ = "Row and Column indexes out of limits";
            break;
        case marsvin::StatusType::kErrorAdditionDimension:
            string_ = "Addition error. Size mismatch.";
            break;
        case marsvin::StatusType::kErrorSubtractionDimension:
            string_ = "Addition error. Size mismatch.";
            break;
        case marsvin::StatusType::kErrorMultiplicationDimension:
            string_ =
                "Multiplication error. Number of columns of lhs matrix must be "
                "equal to number of rows of rhs matrix.";
            break;
        case marsvin::StatusType::kErrorInitializerList:
            string_ =
                "Initializer list should match the matrix size "
                "(multiplication of number of rows and columns)";
            break;
        case marsvin::StatusType::kErrorDoubleInitializerList:
            string_ =
                "Double initializer is "
                "std::initializer_list<std::initializer_list<T>> cut_."
                "The matrix number of rows is equal to cut_.size(). "
                "Each internal std::initializer_list<T> should have the same "
                "size and this "
                "value is the matrix column size.";
            break;
        case marsvin::StatusType::kErrorSquareMatrix:
            string_ = "Operation should be applied in an square matrix.";
            break;
        case marsvin::StatusType::kErrorEqualSize:
            string_ =
                "Equal size of matrix or vector is required in operation.";
            break;
        case marsvin::StatusType::kErrorSolveLinearEquantionDimensions:
            string_ =
                "Error solving linear equation A*x=b. "
                "Matrix number of rows or columns  must be equal to vector size.";
            break;
        default:
            string_ = "Unknown error.";
            break;
    }
    return string_;
}

}  // namespace marsvin
