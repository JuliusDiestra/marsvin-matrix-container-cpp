#ifndef MARSVIN_LUDECOMPOSITION_HPP_
#define MARSVIN_LUDECOMPOSITION_HPP_

#include <vector>
#include <algorithm>

namespace marsvin {

class LUDecomposition {
    public:
        LUDecomposition();
        template<typename T> static std::vector<marsvin::Matrix<T>> PartialPivoting(const marsvin::Matrix<T>& m1);
};

} // namespace marsvin


template<typename T> std::vector<marsvin::Matrix<T>> marsvin::LUDecomposition::PartialPivoting(const marsvin::Matrix<T>& A) {
    // Reference:
    // [1] Page 237 -> Numerical Linear Algebra: Theory and Applications - Larisa Beilina, Evgenii Karchevskii and Mikhail Karchevskii
    std::vector<marsvin::Matrix<T>> result_;
    if (m1.IsSquare()) {
        // Initial condition
        std::vector<T> diagonal_(A.GetNumberOfRows(),1);
        marsvin::Matrix<T> P(diagonal_);
        marsvin::Matrix<T> L(diagonal_);
        // Loop
        for (int j = 1 ;j < A.GetNumberOfRows();j++) {
            m = std::max_element(A.GetColumn(j).begin()+j-1,A.GetColumn(j).end()) - A.GetColumn(j).begin() + 1;
            if (m != j) {
                P.SwapRows(m,j);
                U.SwapRows(m,j);
                if (j >= 2) {
                    std::vector<T> new_row_j {A.GetRow(m).begin(), A.GetRow(m).begin()+j-2};
                    new_row_j.insert(new_row_j.end(),A.GetRow(m).begin() + j - 1,A.GetRow(m).end());
                    std::vector<T> new_row_m {A.GetRow(j).begin(), A.GetRow(j).begin()+j-2};
                    new_row_m.insert(new_row_m.end(),A.GetRow(j).begin() + j - 1,A.GetRow(j).end());
                    A.SetRow(j,new_row_j); 
                    A.SetRow(m,new_row_m); 
                }
            }
            // Update L
            std::vector<T> new_L_column_j { L.GetColumn(j).begin(),L.GetColumn(j.begin()+j-1) };
            std::vector<T> L_sub_column = std::transform(U.GetColumn(j).begin(),U.GetColumn(j).end(),[U,j](T &c){return c/U.GetEntry(j,j)});
            new_L_column_j.insert(new_L.column_j.end(),L_sub_column.begin()+j,L_sub_column.end());
            L.SetColumn(j,new_L_column_j);
            // Ref: https://slaystudy.com/c-divide-vector-by-scalar/
            // Update U
            
        }
    }
}

#endif // MARSVIN_LUDECOMPOSITION_HPP_
