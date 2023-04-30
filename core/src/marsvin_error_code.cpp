
#include "marsvin_error_code.hpp"

namespace marsvin {

ErrorCode::ErrorCode() :
  error_type_{ErrorType::kNoError} {}

ErrorCode::ErrorCode(ErrorType error_type) :
  error_type_{error_type} {}

void ErrorCode::set_error_type(ErrorType error_type) {
    error_type_ = error_type;
}

ErrorType ErrorCode::error_type() const {
    return error_type_;
}

bool ErrorCode::NoError() const {
    bool bool_;
    if (error_type_ == ErrorType::kNoError) {
        bool_ = true;
    } else {
        bool_ = false;
    }
    return bool_;
}

ErrorType ErrorCode::TypeNoError() {
    return ErrorType::kNoError;
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

ErrorType ErrorCode::TypeAddition() {
    return ErrorType::kAddition;
}

ErrorType ErrorCode::TypeSubtraction() {
    return ErrorType::kSubtraction;
}

ErrorType ErrorCode::TypeMultiplication() {
    return ErrorType::kMultiplication;
}

ErrorType ErrorCode::TypeInitializerList() {
    return ErrorType::kInitializerList;
}

ErrorType ErrorCode::TypeDoubleInitializerList() {
    return ErrorType::kDoubleInitializerList;
}

}  // namespace marsvin
