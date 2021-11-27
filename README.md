# marsvin-library-cpp
------------------------------------------------------------------------------

Repository that contains the **MARSVIN** library that contains useful functions for modelling and linear solvers.

The **MARSVIN** library depends only on standard libraries and a lot of coffee.

## How to use it

1. Clone repository
2. In CMakeListst.txt : Add marsvin subdirectory.
```
add_subdirectory(${PATH_TO_MARSVIN_DIRECTORY}/marsvin)
```
3. In CMakeListst.txt : Link marsvin library to your target
```
target_link_libraries(${YOUR_TARGET_NAME} marsvin)
```
4. Include header file in your code:
```
#include "marsvin.hpp"
```

## Classes

Current implemented classes:

- **marsvin::Matrix :** Matrix class.
    -  **marsvin::Matrix::Matrix :** Matrix constructor. Helps to initiate the matrix. The matrix is initiated as a matrix with zeros.
            1. **marsvin::Matrix::Matrix(std::size_t n) :** Initiates an Square Matrix with zeros. 
            2. **marsvin::Matrix::Matrix(std::size_t n_rows,std::size_t n_columns) :** Initiates a Matrix with n_rows number of rows and n_columns number of columns.
    -  **marsvin::Matrix::SetEntry(std::size_t row, std::size_t column, T entry):** Set an entry in the (row,column) matrix position.
    -  **marsvin::Matrix::SetRow(std::size_t row, T row_vector):** Set a row vector in a define row.
    -  **marsvin::Matrix::SetColumn(std::size_t column, T row_column):** Set a column vector in a define row.
    -  **marsvin::Matrix::GetNumberofRows():** Get the number of rows of the matrix object.
    -  **marsvin::Matrix::GetNumberofColumns():** Get the number of columns of the matrix object.
    -  **marsvin::Matrix::Print():** Print matrix class instance.
    -  **marsvin::Matrix::IsSquare():** Set boolean. True if the matrix object is square. False if not.

