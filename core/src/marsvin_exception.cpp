

#include "marsvin_exception.hpp"

namespace marsvin {

Exception::Exception(const ErrorCode& error_code) :
  std::out_of_range(ErrorCodeToString(error_code)),
  error_code_{error_code} {
    if (error_code_.Ok()) {
        throw std::invalid_argument("marsvin::Exception constructor argument should be an ErrorCode class storing a failure.");
    }
  }

void Exception::set_error_code(ErrorCode error_code) {
    error_code_ = error_code;
}

ErrorCode Exception::error_code() const {
    return error_code_;
}

std::string Exception::ErrorCodeToString(const ErrorCode& error_code) {
    std::string string_{};
    switch (error_code.error_type()) {
        case marsvin::ErrorCode::TypeRow():
            string_ = "Row index out of limits";
            break;
        case marsvin::ErrorCode::TypeColumn():
            string_ = "Column index out of limits";
            break;
        case marsvin::ErrorCode::TypeRowAndColumn():
            string_ = "Row and Column indexes out of limits";
            break;
        default:
            break;
    }
    return string_;
}

} // namespace marsvin
