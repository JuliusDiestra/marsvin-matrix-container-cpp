

#include "marsvin_error_code.hpp"

namespace masrvin {

ErrorCode::ErrorCode() : error_type_{ErrorCode::Ok()} {};

Errorcode::ErrorCode(ErrorType error_type) : error_type_{error_type} {};

void ErrorCode::set_error_type(ErrorType error_type) {
    error_type_ = error_type;
};

ErrorType ErrorCode::error_type() {
    return error_type_;
};

bool ErrorCode::ok() {
    bool bool_{false};
    if (error_type_ == ErrorCode::Ok()) {
        bool_ = true;
    }
    return bool_;
};

} // namespace marsvin
