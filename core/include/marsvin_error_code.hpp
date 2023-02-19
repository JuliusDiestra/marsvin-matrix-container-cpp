/**
 * @file marsvin_error_code.hpp
 *
 */

#ifndef MARSVIN_CORE_MARSVIN_ERROR_CODE_HPP_
#define MARSVIN_CORE_MARSVIN_ERROR_CODE_HPP_

#include "marsvin_error_type.hpp"

namespace marsvin {

/**
 * @class ErrorCode
 * @brief Error code class use to throw exception. This class contains information of the error.
 */

class ErrorCode {
  public:
    ErrorCode();
    ErrorCode(ErrorType error_type);
    void set_error_type(ErrorType error_type);
    ErrorType error_type() const;
    bool Ok() const;
    static constexpr ErrorType TypeOk();
    static constexpr ErrorType TypeRow();
    static constexpr ErrorType TypeColumn();
    static constexpr ErrorType TypeRowAndColumn();
  private:
    ErrorType error_type_;
};

} // namespace marsvin

#endif // MARSVIN_CORE_MARSVIN_ERROR_CODE_HPP_
