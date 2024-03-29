/**
 * @file status_code.hpp
 *
 */

#ifndef MARSVIN_ERROR_HANDLING_STATUS_CODE_HPP_
#define MARSVIN_ERROR_HANDLING_STATUS_CODE_HPP_

#include "marsvin/error_handling/status_type.hpp"

namespace marsvin {

/**
 * @class StatusCode
 * @brief Status code class. This class contains information of operations
 * status. While error, this class should be used to throw exceptions.
 */

class StatusCode {
  public:
    StatusCode();
    StatusCode(StatusType status_type);
    void set_status_type(StatusType status_type);
    StatusType status_type() const;
    bool success() const;
    bool failure() const;
    static StatusType TypeSuccess();
    static StatusType TypeErrorRowIndex();
    static StatusType TypeErrorColumnIndex();
    static StatusType TypeErrorRowAndColumnIndex();
    static StatusType TypeErrorAdditionDimension();
    static StatusType TypeErrorSubtractionDimension();
    static StatusType TypeErrorMultiplicationDimension();
    static StatusType TypeErrorInitializerList();
    static StatusType TypeErrorDoubleInitializerList();
    static StatusType TypeErrorSquareMatrix();
    static StatusType TypeErrorEqualSize();
    static StatusType TypeErrorSolveLinearEquantionDimensions();
    static StatusType TypeErrorMatrixDiagonalHasZero();

  private:
    StatusType status_type_;
};

}  // namespace marsvin

#endif  // MARSVIN_ERROR_HANDLING_STATUS_CODE_HPP_
