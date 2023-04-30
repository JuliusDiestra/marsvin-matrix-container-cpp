
#include "marsvin_exception.hpp"

namespace marsvin {

Exception::Exception(const ErrorCode& error_code) :
  std::out_of_range(ErrorCodeToString(error_code)),
  error_code_{error_code} {
    if (error_code_.NoError()) {
        throw std::invalid_argument(
            "marsvin::Exception constructor argument should be an ErrorCode "
            "class storing a failure.");
    }
}

ErrorCode Exception::error_code() const {
    return error_code_;
}

std::string Exception::ErrorCodeToString(const ErrorCode& error_code) {
    std::string string_{};
    switch (error_code.error_type()) {
        case marsvin::ErrorType::kRow:
            string_ = "Row index out of limits";
            break;
        case marsvin::ErrorType::kColumn:
            string_ = "Column index out of limits";
            break;
        case marsvin::ErrorType::kRowAndColumn:
            string_ = "Row and Column indexes out of limits";
            break;
        case marsvin::ErrorType::kAddition:
            string_ = "Addition error. Size mismatch.";
            break;
        case marsvin::ErrorType::kSubtraction:
            string_ = "Addition error. Size mismatch.";
            break;
        case marsvin::ErrorType::kMultiplication:
            string_ =
                "Multiplication error. Number of columns of lhs matrix must be "
                "equal to number of rows of rhs matrix.";
            break;
        case marsvin::ErrorType::kInitializerList:
            string_ =
                "Initializer list should match the matrix size "
                "(multiplication of number of rows and columns)";
            break;
        case marsvin::ErrorType::kDoubleInitializerList:
            string_ =
                "Double initializer is "
                "std::initializer_list<std::initializer_list<T>> cut_."
                "The matrix number of rows is equal to cut_.size(). "
                "Each internal std::initializer_list<T> should have the same "
                "size and this "
                "value is the matrix column size.";
            break;
        default:
            break;
    }
    return string_;
}

}  // namespace marsvin
