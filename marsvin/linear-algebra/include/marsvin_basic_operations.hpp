#ifndef MARSVIN_MATRIX_BASIC_OPERATIONS_HPP_
#define MARSVIN_MATRIX_BASIC_OPERATIONS_HPP_

#include "marsvin_matrix.hpp"
#include <algorithm>

namespace marsvin {

namespace matrix {

class BasicOperations {
    public:
        BasicOperations();
        template<typename T> static marsvin::Matrix<T> Addition(const marsvin::Matrix<T>& m1, const marsvin::Matrix<T>& m2);
//    static Substracction();
//    static Multiplication();
        template<typename T> static bool CheckSameDimentions(const marsvin::Matrix<T>& m1, const marsvin::Matrix<T>& m2);
        template<typename T> static bool CheckMultiplication(const marsvin::Matrix<T>& m1, const marsvin::Matrix<T>& m2);
};

}
}

template<typename T> marsvin::Matrix<T> marsvin::matrix::BasicOperations::Addition(const marsvin::Matrix<T>& m1, const marsvin::Matrix<T>& m2) {
    if (!CheckSameDimentions(m1,m2)) {
        throw std::invalid_argument("Mismatch in matrices dimensions :(");
    }
    // Initialize result matrix
    marsvin::Matrix<T> m_result(m1.GetNumberOfRows(),m1.GetNumberOfColumns());
    return m_result;
}


template<typename T> bool marsvin::matrix::BasicOperations::CheckSameDimentions(const marsvin::Matrix<T>& m1, const marsvin::Matrix<T>& m2) {
    bool check = false;
    if ( (m1.GetNumberOfRows() == m2.GetNumberOfRows()) && (m1.GetNumberOfColumns() == m2.GetNumberOfColumns())) {
        check = true;
    }
    return check;
}

template<typename T> bool marsvin::matrix::BasicOperations::CheckMultiplication(const marsvin::Matrix<T>& m1, const marsvin::Matrix<T>& m2) {
    bool check = false;
    if (m1.GetNumberofColumns() == m2.GetNumberOfRows()) {
        check = true;
    }
    return check;
}

#endif // MARSVIN_MATRIX_BASIC_OPERATIONS_SHPP_
