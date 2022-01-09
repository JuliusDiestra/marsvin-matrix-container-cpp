# marsvin-library-cpp
------------------------------------------------------------------------------

Repository that contains the **MARSVIN** library that contains useful functions for modelling and linear solvers.

Current implementations:

* Matrix Class
* Basic matrices operations: Addition, Substraction and Multiplication.
* Numerical differentiation: First, Second derivative, Gradient and Jacobian.

.... More coming soon ... I guess ...

The **MARSVIN** library depends only on standard libraries and a lot of coffee.
## How to build library

1. Clone repository
2. Run bash script
```
bash build-code.sh
```

## How to use it as a submodule

1. Add repository as submodule

```
git submodule add git@github.com:MarsvinTech/marsvin-library-cpp.git
```

2. Initiate submodule
```
git submodule update --init --recursive
```

3. In CMakeListst.txt : Add marsvin subdirectory.
```
add_subdirectory(${PATH_TO_MARSVIN_DIRECTORY}/marsvin-library-cpp)
```

4. In CMakeListst.txt : Link marsvin library to your target
```
target_link_libraries(${YOUR_TARGET_NAME} marsvin)
```

5. Include header file in your code:
```
#include "marsvin.hpp"
```

## Classes

Current implemented classes:

- **marsvin::Matrix :** Matrix class.
    -  **marsvin::Matrix::Matrix :** Matrix constructor. Helps to initiate the matrix. The matrix is initiated as a matrix with zeros.

             marsvin::Matrix::Matrix(std::size_t n) : Initiates an Square Matrix with zeros. 

             marsvin::Matrix::Matrix(std::size_t n_rows,std::size_t n_columns) : Initiates a Matrix with n_rows number of rows and n_columns number of columns.

    -  **marsvin::Matrix::SetEntry(std::size_t row, std::size_t column, T entry):** Set an entry in the (row,column) matrix position.
    -  **marsvin::Matrix::SetRow(std::size_t row, std::vector<T> row_vector):** Set a row vector in a define row.
    -  **marsvin::Matrix::SetColumn(std::size_t column, std::vector<T> row_column):** Set a column vector in a define row.
    -  **marsvin::Matrix::GetNumberofRows():** Get the number of rows of the matrix object.
    -  **marsvin::Matrix::GetNumberofColumns():** Get the number of columns of the matrix object.
    -  **marsvin::Matrix::Print():** Print matrix class instance.
    -  **marsvin::Matrix::IsSquare():** Set boolean. True if the matrix object is square. False if not.

- **marsvin::Matrix::Operations :** Class with matrices operations.
    -  **marsvin::Matrix::Operations::Operations() :** Class constructor of matrices operations.
    -  **marsvin::Matrix::Operations::Addition(marsvin::Matrix m1,marsvin::Matrix m2) :** Method to add two matrices.
    -  **marsvin::Matrix::Operations::Substraction(marsvin::Matrix m1,marsvin::Matrix m2) :** Method to substract two matrices.
    -  **marsvin::Matrix::Operations::Multiplication(marsvin::Matrix m1,marsvin::Matrix m2) :** Method to multiply two matrices.
    -  **marsvin::Matrix::Operations::Transpose(marsvin::Matrix m1) :** Method to multiply two matrices.

- **marsvin::Differential :** Class with differential calculus methods.
    -  **marsvin::Differential::Differential() :** Class constructor of differential calculus.
    -  **marsvin::Differential::FirstDerivative(std::function<T(T)> f, T x, T dx) :** Numerical first derivative.
    -  **marsvin::Differential::SecondDerivative(std::function<T(T)> f, T x, T dx) :** Numerical second derivative.
    -  **marsvin::Differential::Gradient(std::function<T(std::vector<T>)> f, std::vector<T> Xv, T dx) :** Numerical gradient.
    -  **marsvin::Differential::Jacobian(std::vector<std::function<T(std::vector<T>)>> f, std::vector<T> Xv, T dx) :** Numerical jacobian.

