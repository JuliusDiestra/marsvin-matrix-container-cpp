/**
 * @file marsvin_error_code.hpp
 *
 */

#ifndef MARSVIN_CORE_MARSVIN_ERROR_CODE_HPP_
#define MARSVIN_CORE_MARSVIN_ERROR_CODE_HPP_

namespace marsvin {

enum class ErrorType {
    kOk,
    kRow,
    kColumn,
    kRowAndColumn
};

/**
 * @class ErrorCode
 * @brief Error code class
 */

class ErrorCode {
  public:
    ErrorCode();
    ErrorCode(ErrorType error_type);
    void set_error_type(ErrorType error_type);
    ErrorType error_type();
    bool ok();
    static ErrorType TypeOk();
    static ErrorType TypeRow();
    static ErrorType TypeColumn();
    static ErrorType TypeRowAndColumn();
  private:
    ErrorType error_type_;
};

} // namespace marsvin

#endif // MARSVIN_CORE_MARSVIN_ERROR_CODE_HPP_
