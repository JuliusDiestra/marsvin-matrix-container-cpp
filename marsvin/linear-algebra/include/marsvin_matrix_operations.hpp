#ifndef MARSVIN_MATRIX_OPERATIONS_HPP_
#define MARSVIN_MATRIX_OPERATIONS_HPP_

#include "marsvin_matrix.hpp"
#include <algorithm>

namespace marsvin {

namespace matrix {

class Operations {
    public:
        Operations();
        template<typename T> static marsvin::Matrix<T> Addition(const marsvin::Matrix<T>& m1, const marsvin::Matrix<T>& m2);
        template<typename T> static marsvin::Matrix<T> Substraction(const marsvin::Matrix<T>& m1, const marsvin::Matrix<T>& m2);
        template<typename T> static marsvin::Matrix<T> Multiplication(const marsvin::Matrix<T>& m1, const marsvin::Matrix<T>& m2);
    private:
        template<typename T> static bool CheckSameDimentions(const marsvin::Matrix<T>& m1, const marsvin::Matrix<T>& m2);
        template<typename T> static bool CheckMultiplication(const marsvin::Matrix<T>& m1, const marsvin::Matrix<T>& m2);
};

}
}

template<typename T> marsvin::Matrix<T> marsvin::matrix::Operations::Addition(const marsvin::Matrix<T>& m1, const marsvin::Matrix<T>& m2) {
    if (!CheckSameDimentions(m1,m2)) {
        throw std::invalid_argument("Mismatch in matrices dimensions :(");
    }
    // Initialize result matrix
    marsvin::Matrix<T> m_result(m1.GetNumberOfRows(),m1.GetNumberOfColumns());
    T sum;
    for (std::size_t i=1;i<=m1.GetNumberOfRows();i++) {
        for (std::size_t j=1; j<= m1.GetNumberOfColumns();j++) {
            sum = m1.GetEntry(i,j) + m2.GetEntry(i,j);
            m_result.SetEntry(i,j,sum);
        }
    }
    return m_result;
}

template<typename T> marsvin::Matrix<T> marsvin::matrix::Operations::Substraction(const marsvin::Matrix<T>& m1, const marsvin::Matrix<T>& m2) {
    if (!CheckSameDimentions(m1,m2)) {
        throw std::invalid_argument("Mismatch in matrices dimensions :(");
    }
    // Initialize result matrix
    marsvin::Matrix<T> m_result(m1.GetNumberOfRows(),m1.GetNumberOfColumns());
    T diff;
    for (std::size_t i=1;i<=m1.GetNumberOfRows();i++) {
        for (std::size_t j=1; j<= m1.GetNumberOfColumns();j++) {
            diff = m1.GetEntry(i,j) - m2.GetEntry(i,j);
            m_result.SetEntry(i,j,diff);
        }
    }
    return m_result;
}

template<typename T> marsvin::Matrix<T> marsvin::matrix::Operations::Multiplication(const marsvin::Matrix<T>& m1, const marsvin::Matrix<T>& m2) {
    if (!CheckMultiplication(m1,m2)) {
        throw std::invalid_argument("Mismatch in matrices dimensions for multiplication");
    }
    // Initialize result matrix
    marsvin::Matrix<T> m_result(m1.GetNumberOfRows(),m2.GetNumberOfColumns());
    std::size_t n = m1.GetNumberOfColumns();
    T sum;
    for (std::size_t i=1;i<=m1.GetNumberOfRows();i++) {
        for (std::size_t j=1; j<= m2.GetNumberOfColumns();j++) {
            sum = 0;
            for (std::size_t k=1; k <=n; k++) {
                sum += m1.GetEntry(i,k)*m2.GetEntry(k,j);
            }
            m_result.SetEntry(i,j,sum);
        }
    }
    return m_result;
}


template<typename T> bool marsvin::matrix::Operations::CheckSameDimentions(const marsvin::Matrix<T>& m1, const marsvin::Matrix<T>& m2) {
    bool check = false;
    if ( (m1.GetNumberOfRows() == m2.GetNumberOfRows()) && (m1.GetNumberOfColumns() == m2.GetNumberOfColumns())) {
        check = true;
    }
    return check;
}

template<typename T> bool marsvin::matrix::Operations::CheckMultiplication(const marsvin::Matrix<T>& m1, const marsvin::Matrix<T>& m2) {
    bool check = false;
    if (m1.GetNumberOfColumns() == m2.GetNumberOfRows()) {
        check = true;
    }
    return check;
}

#endif // MARSVIN_MATRIX_OPERATIONS_SHPP_
