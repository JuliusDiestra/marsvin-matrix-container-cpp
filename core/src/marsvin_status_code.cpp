
#include "marsvin_status_code.hpp"

namespace marsvin {

StatusCode::StatusCode() :
  status_type_{StatusType::kSuccess} {}

StatusCode::StatusCode(StatusType status_type) :
  status_type_{status_type} {}

void StatusCode::set_status_type(StatusType status_type) {
    status_type_ = status_type;
}

StatusType StatusCode::status_type() const {
    return status_type_;
}

bool StatusCode::success() const {
    bool bool_;
    if (status_type_ == StatusType::kSuccess) {
        bool_ = true;
    } else {
        bool_ = false;
    }
    return bool_;
}

bool StatusCode::failure() const {
    return !success();
}
StatusType StatusCode::TypeSuccess() {
    return StatusType::kSuccess;
}

StatusType StatusCode::TypeErrorRowIndex() {
    return StatusType::kErrorRowIndex;
}

StatusType StatusCode::TypeErrorColumnIndex() {
    return StatusType::kErrorColumnIndex;
}

StatusType StatusCode::TypeErrorRowAndColumnIndex() {
    return StatusType::kErrorRowAndColumnIndex;
}

StatusType StatusCode::TypeErrorAdditionDimension() {
    return StatusType::kErrorAdditionDimension;
}

StatusType StatusCode::TypeErrorSubtractionDimension() {
    return StatusType::kErrorSubtractionDimension;
}

StatusType StatusCode::TypeErrorMultiplicationDimension() {
    return StatusType::kErrorMultiplicationDimension;
}

StatusType StatusCode::TypeErrorInitializerList() {
    return StatusType::kErrorInitializerList;
}

StatusType StatusCode::TypeErrorDoubleInitializerList() {
    return StatusType::kErrorDoubleInitializerList;
}

StatusType StatusCode::TypeErrorSquareMatrix() {
    return StatusType::kErrorSquareMatrix;
}

}  // namespace marsvin
