
#include "gtest/gtest.h"
#include "marsvin/containers/base_matrix.hpp"
#include "marsvin/tools/logger.hpp"
#include "marsvin/tools/compare.hpp"

TEST(BaseMatrix, Constructor_empty_matrix) {
    marsvin::BaseMatrix<int> cut_;
    EXPECT_TRUE(cut_.empty());
    EXPECT_EQ(0,cut_.rows());
    EXPECT_EQ(0,cut_.columns());
    EXPECT_EQ(0,cut_.size());
}

TEST(BaseMatrix, Constructor_with_row_and_columns) {
    constexpr std::size_t ROWS_ = 3;
    constexpr std::size_t COLUMNS_ = 4;
    marsvin::BaseMatrix<int> cut_(ROWS_, COLUMNS_);
    EXPECT_FALSE(cut_.empty());
    EXPECT_EQ(ROWS_,cut_.rows());
    EXPECT_EQ(COLUMNS_,cut_.columns());
    EXPECT_EQ(ROWS_*COLUMNS_,cut_.size());
}

TEST(BaseMatrix, Constructor_Initializer_List) {
    constexpr std::size_t ROWS_ = 2;
    constexpr std::size_t COLUMNS_ = 3;
    marsvin::BaseMatrix<int> cut_(ROWS_, COLUMNS_, {1,2,3,4,5,6});
    EXPECT_EQ(cut_.size(),ROWS_*COLUMNS_);
    EXPECT_EQ(cut_.at(0,0), 1);
    EXPECT_EQ(cut_.at(0,1), 2);
    EXPECT_EQ(cut_.at(0,2), 3);
    EXPECT_EQ(cut_.at(1,0), 4);
    EXPECT_EQ(cut_.at(1,1), 5);
    EXPECT_EQ(cut_.at(1,2), 6);
}

TEST(BaseMatrix, Constructor_Copy) {
    constexpr std::size_t ROWS_ = 2;
    constexpr std::size_t COLUMNS_ = 3;
    marsvin::BaseMatrix<int> base_matrix_one(ROWS_, COLUMNS_, {1,2,3,4,5,6});
    marsvin::BaseMatrix<int> base_matrix_two = base_matrix_one;
    EXPECT_EQ(base_matrix_two.size(),ROWS_*COLUMNS_);
    EXPECT_EQ(base_matrix_two.at(0,0), 1);
    EXPECT_EQ(base_matrix_two.at(0,1), 2);
    EXPECT_EQ(base_matrix_two.at(0,2), 3);
    EXPECT_EQ(base_matrix_two.at(1,0), 4);
    EXPECT_EQ(base_matrix_two.at(1,1), 5);
    EXPECT_EQ(base_matrix_two.at(1,2), 6);
}

TEST(BaseMatrix, Constructor_Move) {
    constexpr std::size_t ROWS_ = 2;
    constexpr std::size_t COLUMNS_ = 3;
    marsvin::BaseMatrix<int> base_matrix_one(ROWS_, COLUMNS_, {1,2,3,4,5,6});
    marsvin::BaseMatrix<int> base_matrix_two = std::move(base_matrix_one);
    EXPECT_TRUE(base_matrix_one.empty());
    EXPECT_EQ(base_matrix_two.size(),ROWS_*COLUMNS_);
    EXPECT_EQ(base_matrix_two.at(0,0), 1);
    EXPECT_EQ(base_matrix_two.at(0,1), 2);
    EXPECT_EQ(base_matrix_two.at(0,2), 3);
    EXPECT_EQ(base_matrix_two.at(1,0), 4);
    EXPECT_EQ(base_matrix_two.at(1,1), 5);
    EXPECT_EQ(base_matrix_two.at(1,2), 6);
}

TEST(BaseMatrix, method_empty_01) {
    marsvin::BaseMatrix<int> cut_;
    EXPECT_TRUE(cut_.empty());
}

TEST(BaseMatrix, method_empty_02) {
    marsvin::BaseMatrix<int> cut_(2,5);
    EXPECT_FALSE(cut_.empty());
}
TEST(BaseMatrix, method_at_ReadAndSet) {
    constexpr std::size_t ROWS_ = 2;
    constexpr std::size_t COLUMNS_ = 2;
    marsvin::BaseMatrix<int> cut_(ROWS_, COLUMNS_);
    cut_.at(0,0) = 1;
    cut_.at(0,1) = 2;
    cut_.at(1,0) = 3;
    cut_.at(1,1) = 4;
    EXPECT_EQ(cut_.at(0,0),1);
    EXPECT_EQ(cut_.at(0,1),2);
    EXPECT_EQ(cut_.at(1,0),3);
    EXPECT_EQ(cut_.at(1,1),4);
}

TEST(BaseMatrix, method_at_Exception_ErrorRowType) {
    constexpr std::size_t ROWS_ = 2;
    constexpr std::size_t COLUMNS_ = 2;
    marsvin::BaseMatrix<int> cut_(ROWS_, COLUMNS_);
    try {
        cut_.at(2,1) = 10;
    } catch (const marsvin::Exception& exception_) {
        EXPECT_EQ(exception_.status_code().status_type(), marsvin::StatusCode::TypeErrorRowIndex());
    }
}

TEST(BaseMatrix, method_at_Exception_ErrorColumnType) {
    constexpr std::size_t ROWS_ = 2;
    constexpr std::size_t COLUMNS_ = 2;
    marsvin::BaseMatrix<int> cut_(ROWS_, COLUMNS_);
    try {
        cut_.at(1,2) = 10;
    } catch (const marsvin::Exception& exception_) {
        EXPECT_EQ(exception_.status_code().status_type(), marsvin::StatusCode::TypeErrorColumnIndex());
    }
}

TEST(BaseMatrix, method_at_Exception_ErrorRowAndColumnType) {
    constexpr std::size_t ROWS_ = 2;
    constexpr std::size_t COLUMNS_ = 2;
    marsvin::BaseMatrix<int> cut_(ROWS_, COLUMNS_);
    try {
        cut_.at(2,2) = 10;
    } catch (const marsvin::Exception& exception_) {
        EXPECT_EQ(exception_.status_code().status_type(), marsvin::StatusCode::TypeErrorRowAndColumnIndex());
    }
}

TEST(BaseMatrix, method_resize_BiggerMatrix) {
    marsvin::Logger logger_;
    // Original Size
    constexpr std::size_t kRows = 4;
    constexpr std::size_t kColumns = 5;
    // New Size
    constexpr std::size_t kRowsResize = 6;
    constexpr std::size_t kColumnsResize = 8;
    // Create matrix
    marsvin::BaseMatrix<int> cut_(kRows, kColumns);
    // Fill matrix elements with values
    for (std::size_t r = 0; r < kRows ; ++r) {
        for (std::size_t c = 0; c < kColumns; ++c) {
            cut_.at(r,c) = c + r*kColumns + 1;
        }
    }
    logger_ << cut_;
    cut_.resize(kRowsResize, kColumnsResize);
    std::cout << "Resized matrix :" << std::endl;
    logger_ << cut_;
    EXPECT_EQ(cut_.rows(),kRowsResize);
    EXPECT_EQ(cut_.columns(),kColumnsResize);
    for (std::size_t r = 0; r < kRows ; ++r) {
        for (std::size_t c = 0; c < kColumns; ++c) {
            EXPECT_EQ(cut_.at(r,c), c + r*kColumns + 1);
        }
    }
    // Check the addional entries are ZERO
    for (std::size_t r = 0; r < kRows; ++r) {
        for (std::size_t c = kColumns; c < kColumnsResize; ++c) {
            EXPECT_EQ(cut_.at(r,c),0);
        }
    }
    for (std::size_t r = kRows; r < kRowsResize; ++r) {
        for (std::size_t c = 0; c < kColumns; ++c) {
            EXPECT_EQ(cut_.at(r,c),0);
        }
    }
}

TEST(BaseMatrix, method_resize_HigherRowsLowerColums) {
    marsvin::Logger logger_;
    // Original Size
    constexpr std::size_t kRows = 4;
    constexpr std::size_t kColumns = 5;
    // New Size
    constexpr std::size_t kRowsResize = 6;
    constexpr std::size_t kColumnsResize = 3;
    // Create matrix
    marsvin::BaseMatrix<int> cut_(kRows, kColumns);
    // Fill matrix elements with values
    for (std::size_t r = 0; r < kRows ; ++r) {
        for (std::size_t c = 0; c < kColumns; ++c) {
            cut_.at(r,c) = c + r*kColumns + 1;
        }
    }
    logger_ << cut_;
    cut_.resize(kRowsResize, kColumnsResize);
    std::cout << "Resized matrix :" << std::endl;
    logger_ << cut_;
    EXPECT_EQ(cut_.rows(),kRowsResize);
    EXPECT_EQ(cut_.columns(),kColumnsResize);
    for (std::size_t r = 0; r < kRows ; ++r) {
        for (std::size_t c = 0; c < kColumnsResize; ++c) {
            EXPECT_EQ(cut_.at(r,c), c + r*kColumns + 1);
        }
    }
    // Check the addional entries are ZERO
    for (std::size_t r = kRows; r < kRowsResize; ++r) {
        for (std::size_t c = 0; c < kColumnsResize; ++c) {
            EXPECT_EQ(cut_.at(r,c),0);
        }
    }
}

TEST(BaseMatrix, method_resize_SameRowsLowerColums) {
    marsvin::Logger logger_;
    // Original Size
    constexpr std::size_t kRows = 4;
    constexpr std::size_t kColumns = 5;
    // New Size
    constexpr std::size_t kRowsResize = 4;
    constexpr std::size_t kColumnsResize = 3;
    // Create matrix
    marsvin::BaseMatrix<int> cut_(kRows, kColumns);
    // Fill matrix elements with values
    for (std::size_t r = 0; r < kRows ; ++r) {
        for (std::size_t c = 0; c < kColumns; ++c) {
            cut_.at(r,c) = c + r*kColumns + 1;
        }
    }
    logger_ << cut_;
    cut_.resize(kRowsResize, kColumnsResize);
    std::cout << "Resized matrix :" << std::endl;
    logger_ << cut_;
    EXPECT_EQ(cut_.rows(),kRowsResize);
    EXPECT_EQ(cut_.columns(),kColumnsResize);
    for (std::size_t r = 0; r < kRows ; ++r) {
        for (std::size_t c = 0; c < kColumnsResize; ++c) {
            EXPECT_EQ(cut_.at(r,c), c + r*kColumns + 1);
        }
    }
}

TEST(BaseMatrix, method_resize_LowerRowsHigherColums) {
    marsvin::Logger logger_;
    // Original Size
    constexpr std::size_t kRows = 4;
    constexpr std::size_t kColumns = 5;
    // New Size
    constexpr std::size_t kRowsResize = 2;
    constexpr std::size_t kColumnsResize = 6;
    // Create matrix
    marsvin::BaseMatrix<int> cut_(kRows, kColumns);
    // Fill matrix elements with values
    for (std::size_t r = 0; r < kRows ; ++r) {
        for (std::size_t c = 0; c < kColumns; ++c) {
            cut_.at(r,c) = c + r*kColumns + 1;
        }
    }
    logger_ << cut_;
    cut_.resize(kRowsResize, kColumnsResize);
    std::cout << "Resized matrix :" << std::endl;
    logger_ << cut_;
    EXPECT_EQ(cut_.rows(),kRowsResize);
    EXPECT_EQ(cut_.columns(),kColumnsResize);
    for (std::size_t r = 0; r < kRowsResize ; ++r) {
        for (std::size_t c = 0; c < kColumns; ++c) {
            EXPECT_EQ(cut_.at(r,c), c + r*kColumns + 1);
        }
    }
    // Check the addional entries are ZERO
    for (std::size_t r = 0; r < kRowsResize; ++r) {
        for (std::size_t c = kColumns; c < kColumnsResize; ++c) {
            EXPECT_EQ(cut_.at(r,c),0);
        }
    }
}

TEST(BaseMatrix, method_resize_LowerRowsSameColums) {
    marsvin::Logger logger_;
    // Original Size
    constexpr std::size_t kRows = 4;
    constexpr std::size_t kColumns = 5;
    // New Size
    constexpr std::size_t kRowsResize = 2;
    constexpr std::size_t kColumnsResize = 5;
    // Create matrix
    marsvin::BaseMatrix<int> cut_(kRows, kColumns);
    // Fill matrix elements with values
    for (std::size_t r = 0; r < kRows ; ++r) {
        for (std::size_t c = 0; c < kColumns; ++c) {
            cut_.at(r,c) = c + r*kColumns + 1;
        }
    }
    logger_ << cut_;
    cut_.resize(kRowsResize, kColumnsResize);
    std::cout << "Resized matrix :" << std::endl;
    logger_ << cut_;
    EXPECT_EQ(cut_.rows(),kRowsResize);
    EXPECT_EQ(cut_.columns(),kColumnsResize);
    for (std::size_t r = 0; r < kRowsResize ; ++r) {
        for (std::size_t c = 0; c < kColumns; ++c) {
            EXPECT_EQ(cut_.at(r,c), c + r*kColumns + 1);
        }
    }
}

TEST(BaseMatrix, method_resize_LowerRowsLowerColums) {
    marsvin::Logger logger_;
    // Original Size
    constexpr std::size_t kRows = 4;
    constexpr std::size_t kColumns = 5;
    // New Size
    constexpr std::size_t kRowsResize = 2;
    constexpr std::size_t kColumnsResize = 3;
    // Create matrix
    marsvin::BaseMatrix<int> cut_(kRows, kColumns);
    // Fill matrix elements with values
    for (std::size_t r = 0; r < kRows ; ++r) {
        for (std::size_t c = 0; c < kColumns; ++c) {
            cut_.at(r,c) = c + r*kColumns + 1;
        }
    }
    logger_ << cut_;
    cut_.resize(kRowsResize, kColumnsResize);
    std::cout << "Resized matrix :" << std::endl;
    logger_ << cut_;
    EXPECT_EQ(cut_.rows(),kRowsResize);
    EXPECT_EQ(cut_.columns(),kColumnsResize);
    for (std::size_t r = 0; r < kRowsResize ; ++r) {
        for (std::size_t c = 0; c < kColumnsResize; ++c) {
            EXPECT_EQ(cut_.at(r,c), c + r*kColumns + 1);
        }
    }
}

TEST(BaseMatrix, method_resize_SameRowsSameColums) {
    marsvin::Logger logger_;
    // Original Size
    constexpr std::size_t kRows = 4;
    constexpr std::size_t kColumns = 5;
    // New Size
    constexpr std::size_t kRowsResize = 4;
    constexpr std::size_t kColumnsResize = 5;
    // Create matrix
    marsvin::BaseMatrix<int> cut_(kRows, kColumns);
    // Fill matrix elements with values
    for (std::size_t r = 0; r < kRows ; ++r) {
        for (std::size_t c = 0; c < kColumns; ++c) {
            cut_.at(r,c) = c + r*kColumns + 1;
        }
    }
    logger_ << cut_;
    cut_.resize(kRowsResize, kColumnsResize);
    std::cout << "Resized matrix :" << std::endl;
    logger_ << cut_;
    EXPECT_EQ(cut_.rows(),kRows);
    EXPECT_EQ(cut_.columns(),kColumns);
    for (std::size_t r = 0; r < kRows; ++r) {
        for (std::size_t c = 0; c < kColumns; ++c) {
            EXPECT_EQ(cut_.at(r,c), c + r*kColumns + 1);
        }
    }
}

TEST(BaseMatrix, method_clear) {
    // Original Size
    constexpr std::size_t kRows = 4;
    constexpr std::size_t kColumns = 5;
    // Create matrix
    marsvin::BaseMatrix<int> cut_(kRows, kColumns);
    cut_.clear();
    EXPECT_TRUE(cut_.empty());
}

TEST(BaseMatrix, method_addition_two_matrices_error) {
    marsvin::BaseMatrix<int> m_lhs(2,3);
    marsvin::BaseMatrix<int> m_rhs(5,6);
    try {
        marsvin::BaseMatrix<int> m_result = m_lhs + m_rhs;
    } catch (const marsvin::Exception& exception_) {
        EXPECT_EQ(exception_.status_code().status_type(), marsvin::StatusCode::TypeErrorAdditionDimension());
    }
}

TEST(BaseMatrix, method_addition_two_matrices) {
    constexpr std::size_t kRows = 3;
    constexpr std::size_t kColumns = 2;
    marsvin::BaseMatrix<int> m_lhs(kRows,kColumns);
    marsvin::BaseMatrix<int> m_rhs(kRows,kColumns);
    for (std::size_t r = 0; r < kRows ; ++r) {
        for (std::size_t c = 0; c < kColumns; ++c) {
            m_lhs.at(r,c) = c + r*kColumns + 1;
            m_rhs.at(r,c) = 2*(c + r*kColumns + 1);
        }
    }
    marsvin::BaseMatrix<int> m_result = m_lhs + m_rhs;
    for (std::size_t r = 0; r < m_result.rows() ; ++r) {
        for (std::size_t c = 0; c < m_result.columns(); ++c) {
            EXPECT_EQ(m_result.at(r,c), 3*(c + r*m_result.columns() + 1));
        }
    }
}

TEST(BaseMatrix, method_base_matrix_multiplication) {
    constexpr std::size_t lhs_kRows = 3;
    constexpr std::size_t lhs_kColumns = 2;
    constexpr std::size_t rhs_kRows = 2;
    constexpr std::size_t rhs_kColumns = 4;
    marsvin::BaseMatrix<int> m_lhs(lhs_kRows, lhs_kColumns, {1,2,3,4,5,6});
    marsvin::BaseMatrix<int> m_rhs(rhs_kRows, rhs_kColumns, {1,2,3,4,5,6,7,8});
    marsvin::BaseMatrix<int> m_result_expected(lhs_kRows, rhs_kColumns, {11,14,17,20,23,30,37,44,35,46,57,68});
    auto m_result = m_lhs*m_rhs;
    EXPECT_EQ(m_result.rows(), lhs_kRows);
    EXPECT_EQ(m_result.columns(), rhs_kColumns);
    int tolerance = 0;
    EXPECT_TRUE(marsvin::tools::compare(m_result,m_result_expected,tolerance));
}

TEST(BaseMatrix, multiplication_matrix_vector) {
    constexpr std::size_t lhs_kRows = 5;
    constexpr std::size_t lhs_kColumns = 5;
    constexpr std::size_t rhs_kRows = 5;
    constexpr std::size_t rhs_kColumns = 1;
    marsvin::BaseMatrix<int> m_lhs(lhs_kRows, lhs_kColumns, {1,2,3,4,5,0,6,7,8,9,0,0,10,11,12,0,0,0,13,14,0,0,0,0,15});
    marsvin::BaseMatrix<int> m_rhs(rhs_kRows, rhs_kColumns, {1,2,3,4,5});
    marsvin::BaseMatrix<int> m_result_expected(lhs_kRows, rhs_kColumns, {55,110,134,122,75});
    auto m_result = m_lhs*m_rhs;
    EXPECT_EQ(m_result.rows(), lhs_kRows);
    EXPECT_EQ(m_result.columns(), rhs_kColumns);
    int tolerance = 0;
    EXPECT_TRUE(marsvin::tools::compare(m_result, m_result_expected,tolerance));
}

