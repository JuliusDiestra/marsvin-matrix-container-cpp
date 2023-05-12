
#include "gtest/gtest.h"
#include "marsvin_base_matrix.hpp"
#include "marsvin_logger.hpp"

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
    /*
     * TBD
     */
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
        EXPECT_EQ(exception_.error_code().error_type(), marsvin::ErrorCode::TypeRow());
    }
}

TEST(BaseMatrix, method_at_Exception_ErrorColumnType) {
    constexpr std::size_t ROWS_ = 2;
    constexpr std::size_t COLUMNS_ = 2;
    marsvin::BaseMatrix<int> cut_(ROWS_, COLUMNS_);
    try {
        cut_.at(1,2) = 10;
    } catch (const marsvin::Exception& exception_) {
        EXPECT_EQ(exception_.error_code().error_type(), marsvin::ErrorCode::TypeColumn());
    }
}

TEST(BaseMatrix, method_at_Exception_ErrorRowAndColumnType) {
    constexpr std::size_t ROWS_ = 2;
    constexpr std::size_t COLUMNS_ = 2;
    marsvin::BaseMatrix<int> cut_(ROWS_, COLUMNS_);
    try {
        cut_.at(2,2) = 10;
    } catch (const marsvin::Exception& exception_) {
        EXPECT_EQ(exception_.error_code().error_type(), marsvin::ErrorCode::TypeRowAndColumn());
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
        EXPECT_EQ(exception_.error_code().error_type(), marsvin::ErrorCode::TypeAddition());
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
