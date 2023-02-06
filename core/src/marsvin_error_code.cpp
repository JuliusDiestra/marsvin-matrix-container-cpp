
#include "marsvin_error_code.hpp"

namespace marsvin {

ErrorCode::ErrorCode() : error_type_{ErrorType::kOk} {}

ErrorCode::ErrorCode(ErrorType error_type) : error_type_{error_type} {}

void ErrorCode::set_error_type(ErrorType error_type) {
    error_type_ = error_type;
}

ErrorType ErrorCode::error_type() {
    return error_type_;
}

bool ErrorCode::ok() {
    bool bool_{false};
    if (error_type_ == ErrorType::kOk) {
        bool_ = true;
    }
    return bool_;
}

ErrorType ErrorCode::TypeOk() {
    return ErrorType::kOk;
}

ErrorType ErrorCode::TypeRow() {
    return ErrorType::kRow;
}

ErrorType ErrorCode::TypeColumn() {
    return ErrorType::kColumn;
}

ErrorType ErrorCode::TypeRowAndColumn() {
    return ErrorType::kRowAndColumn;
}

} // namespace marsvin