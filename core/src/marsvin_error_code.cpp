
#include "marsvin_error_code.hpp"

namespace marsvin {

ErrorCode::ErrorCode() :
    error_type_{ErrorType::kOk} {}

ErrorCode::ErrorCode(ErrorType error_type) :
    error_type_{error_type} {}

void ErrorCode::set_error_type(ErrorType error_type) {
    error_type_ = error_type;
}

ErrorType ErrorCode::error_type() const {
    return error_type_;
}

bool ErrorCode::Ok() const {
    bool bool_{false};
    if (error_type_ == ErrorType::kOk) {
        bool_ = true;
    }
    return bool_;
}

constexpr ErrorType ErrorCode::TypeOk() {
    return ErrorType::kOk;
}

constexpr ErrorType ErrorCode::TypeRow() {
    return ErrorType::kRow;
}

constexpr ErrorType ErrorCode::TypeColumn() {
    return ErrorType::kColumn;
}

constexpr ErrorType ErrorCode::TypeRowAndColumn() {
    return ErrorType::kRowAndColumn;
}

} // namespace marsvin
