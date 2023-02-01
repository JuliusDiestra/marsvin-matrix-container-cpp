/**
 * @file marsvin_error_code.hpp
 *
 */

#ifndef MARSVIN_CORE_MARSVIN_ERROR_CODE_HPP_
#define MARSVIN_CORE_MARSVIN_ERROR_CODE_HPP_

namespace marsvin {

enum class ErrorType {
    kOk,
    kColumnOutOfBoundaries,
    kRowOutOfBoundaries,
    kRowAndColumnOutOfBoundaries
};

class ErrorCode {
  public:
    ErrorCode(){};
    ErrorCode(ErrorType error_type);
    void set_error_type(ErrorType error_type);
    ErrorType error_type();
    bool ok();
    static ErrorType Ok();
    static ErrorType ColumnOutOfBoundaries();
    static ErrorType RowOutOfBoundaries();
    static ErrorType RowAndColumnOutOfBoundaries();
  private:
    ErrorType error_type_;
};

} // namespace marsvin

#endif // MARSVIN_CORE_MARSVIN_ERROR_CODE_HPP_
