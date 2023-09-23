# Marsvin library contains matrix and vector containers and linear algebra operations

[TOC]

Marsvin library contains matrix and vector containers and linear algebra operations.

## Containers

Three containers are provided in this library:

* BaseMatrix
* Matrix
* Vector

In this library, a **vector** is considered a **matrix** with 1 column.
By default, every **vector** is a column vector.

**BaseMatrix** contains methods that can be used for **Matrix** and **Vector**.

**Vector** class includes extra methods useful for vector operation,
and the **Matrix** class includes extra methods useful for matrix linear algebra.

### BaseMatrix

Header file :

    include "base_matrix.hpp"

A **BaseMatrix** object can be created as,

    marsvin::BaseMatrix<T> base_matrix;

**BaseMatrix** is the base class for **Matrix** and **Vector** classes.

In order to read/write a **BaseMatrix** element, a row and column index should
be provided and you can use the **at(row,column)** method.
The row or column index starts at 0.

    // Create 2x2 base matrix
    marsvin::BaseMatrix<int> base_matrix(2,2);
    // Write values into base matrix.
    base_matrix.at(0,0) = 1;
    base_matrix.at(0,1) = 2;
    base_matrix.at(1,0) = 3;
    base_matrix.at(1,1) = 4;
    // Read values from base matrix.
    int var_ = base_matrix.at(1,0);

The elements of **BaseMatrix** are allocated in contiguous memory.
The 2D index is converted into a 1D index and the memory block is accessed.

Basic operations are provided using overload operators :

* Addition          : +
* Subtraction       : -
* Multiplication    : *

### Matrix

**Matrix** class inherits from **BaseMatrix**.

Header file :

    include "matrix.hpp"

A **Matrix** object can be created as,

    marsvin::Matrix<T> matrix;

### Vector

A vector is considered as Nx1 matrix in this library.

**Vector** class inherits from **BaseMatrix**.

Header file :

    include "vector.hpp"

A **Vector** object can be created as,

    marsvin::Vector<T> vector;

## Linear Algebra

### Forward Substitution

TBD

### Backward Substitution

TBD

### Gauss Elimination

TBD

#### Partial Pivoting

TBD

