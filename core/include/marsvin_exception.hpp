/**
 * @file marsvin_exception.hpp
 *
 */

#ifndef MARSVIN_CORE_MARSVIN_EXCEPTION_HPP_
#define MARSVIN_CORE_MARSVIN_EXCEPTION_HPP_

#include <stdexcept>
#include <string>

#include "marsvin_error_code.hpp"

namespace marsvin {

class Exception : public std::out_of_range {
  public:
    Exception() = delete;
    explicit Exception(const ErrorCode& error_code);
    ErrorCode error_code() const;
  private:
    ErrorCode error_code_;
    std::string ErrorCodeToString(const ErrorCode& error_code);
};

} // namespace marsvin

#endif // MARSVIN_CORE_MARSVIN_EXCEPTION_HPP_
