/**
 * @file marsvin_exception.hpp
 *
 */

#ifndef MARSVIN_CORE_MARSVIN_EXCEPTION_HPP_
#define MARSVIN_CORE_MARSVIN_EXCEPTION_HPP_

#include <stdexcept>
#include <string>

#include "marsvin/error_handling/status_code.hpp"

namespace marsvin {

class Exception : public std::out_of_range {
  public:
    Exception() = delete;
    explicit Exception(const StatusCode& status_code);
    StatusCode status_code() const;

  private:
    StatusCode status_code_;
    std::string StatusCodeToString(const StatusCode& status_code);
};

}  // namespace marsvin

#endif  // MARSVIN_CORE_MARSVIN_EXCEPTION_HPP_
