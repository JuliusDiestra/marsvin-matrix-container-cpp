
Marsvin library contains matrix and vector containers and linear algebra operations.

[TOC]

# Containers

Three containers are provided in this library:

* BaseMatrix
* Matrix
* Vector

In this library, a **vector** is considered a **matrix** with 1 column.
By default, every **vector** is a column vector.

**BaseMatrix** contains methods that can be used for **Matrix** and **Vector**.

**Vector** class includes extra methods useful for vector operation,
and the **Matrix** class includes extra methods useful for matrix linear algebra.

## BaseMatrix

Header file :

    #include "marsvin/containers/base_matrix.hpp"

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

## Matrix

**Matrix** class inherits from **BaseMatrix**.

Header file :

    #include "marsvin/containers/matrix.hpp"

A **Matrix** object can be created as,

    marsvin::Matrix<T> matrix;

## Vector

A vector is considered as Nx1 matrix in this library.

**Vector** class inherits from **BaseMatrix**.

Header file :

    #include "marsvin/containers/vector.hpp"

A **Vector** object can be created as,

    marsvin::Vector<T> vector;

# Linear Algebra

## Triangular Systems

### Lower Triangular Matrix

#### Forward Substitution

Header file :

    #include "marsvin/triangular_systems/forward_substitution.hpp"

The algorithm provides a solution for the following equation,

\f$ Lx = b \f$

where,

\f$ L \f$ : Nonsingular lower triangular matrix of order \f$ n \f$.

\f$ b \f$ : Vector or \f$ n \f$ order.

Then \f$ x \f$ can be calculated by,

    for k = 0 to n-1
        x[k] = b[k]
        for j = 0 to k-1
            x[k] = x[k] - L[k,j]x[j]
        end for j
        x[k] = x[k]/L[k,k]
    end for k

This algorihm is implemented by the function,

    marsvin::Vector<T> forward_substitution(const ::marsvin::Matrix<T>& L, const ::marsvin::Vector<T>& b)

For example,

    // L : Nonsingular lower triangular matrix of nxn size.
    // b : Vector of n size.
    marsvin::Vector<T> x;
    x = marsvin::forward_substitution(L, b);

or,

    // L : Nonsingular lower triangular matrix of nxn size.
    // b : Vector of n size.
    marsvin::Vector<T> x;
    marsvin::forward_substitution(L, b, x);

In order to avoid using memory to allocate \f$ x \f$,
we can overwrite the solution in vector \f$ b \f$,

    for k = 0 to n-1
        for j = 0 to k-1
            b[k] = b[k] - L[k,j]b[j]
        end for j
        b[k] = b[k]/L[k,k]
    end for k

This algorihm is implemented by the function,

    marsvin::Vector<T> forward_substitution_memory(const ::marsvin::Matrix<T>& L, ::marsvin::Vector<T>& b)

For example,

    // L : Nonsingular lower triangular matrix of nxn size.
    // b : Vector of n size.
    marsvin::forward_substitution_memory(L, b);

#### Inverse

Header file :

    #include "marsvin/triangular_system/lower_inverse.hpp"

### Upper Triangular Matrix
#### Backward Substitution

Solution of an upper  triangular system

For the following equation,

\f$ Ux = b \f$

where,

\f$ U \f$ : Nonsingular upper triangular matrix of order \f$ n \f$.

\f$ b \f$ : Vector or \f$ n \f$ order.

Then \f$ x \f$ can be calculated by,

    for k = n-1 to 0
        x[k] = b[k]
        for j = k+1 to n-1
            x[k] = x[k] - U[k,j]x[j]
        end for j
        x[k] = x[k]/U[k,k]
    end for k

This algorihm is implemented by the function,

    marsvin::Vector<T> backward_substitution(const ::marsvin::Matrix<T>& L, const ::marsvin::Vector<T>& b)

For example,

    // U : Nonsingular upper triangular matrix of nxn size.
    // b : Vector of n size.
    marsvin::Vector<T> x;
    x = marsvin::backward_substitution(L, b);

or,

    // U : Nonsingular upper triangular matrix of nxn size.
    // b : Vector of n size.
    marsvin::Vector<T> x;
    marsvin::backward_substitution(L, b, x);

In order to avoid using memory to allocate \f$ x \f$,
we can overwrite the solution in vector \f$ b \f$,

    for k = n-1 to 0
        for j = k+1 to n-1
            b[k] = b[k] - U[k,j]b[j]
        end for j
        b[k] = b[k]/U[k,k]
    end for k

This algorihm is implemented by the function,

    marsvin::Vector<T> backward_substitution_memory(const ::marsvin::Matrix<T>& U, ::marsvin::Vector<T>& b)

For example,

    // U : Nonsingular upper triangular matrix of nxn size.
    // b : Vector of n size.
    marsvin::backward_substitution_memory(L, b);

#### Inverse

Header file :

    #include "marsvin/triangular_system/upper_inverse.hpp"

Giving the following equation,

\f[

XU = I

\f]

where,

\f$ X \f$ : Inverse of upper triangular matrix \f$ U \f$ of order \f$ n \f$.

\f$ U \f$ : Nonsingular upper triangular matrix of order \f$ n \f$.

\f$ I \f$ : Identity matrix of order \f$ n \f$.

\f[
\begin{bmatrix}
x_{0,0} & x_{0,1}   & x_{0,2}   & \dots     & x_{0,n-2}     & x_{0,n-1} \\
0       & x_{1,1}   & x_{1,2}   & \dots     & x_{1,n-2}     & x_{1,n-1} \\
0       & 0         & x_{2,2}   & \dots     & x_{2,n-2}     & x_{2,n-1} \\
\vdots  & \vdots    & \vdots    & \ddots    & \vdots        & \vdots \\
0       & 0         & 0         & \dots     & x_{n-2,n-2}   & x_{n-2,n-1} \\
0       & 0         & 0         & \dots     & 0             & x_{n-1,n-1} \\
\end{bmatrix}
\begin{bmatrix}
u_{0,0} & u_{0,1}   & u_{0,2}   & \dots     & u_{0,n-2}     & u_{0,n-1} \\
0       & u_{1,1}   & u_{1,2}   & \dots     & u_{1,n-2}     & u_{1,n-1} \\
0       & 0         & u_{2,2}   & \dots     & u_{2,n-2}     & u_{2,n-1} \\
\vdots  & \vdots    & \vdots    & \ddots    & \vdots        & \vdots \\
0       & 0         & 0         & \dots     & u_{n-2,n-2}   & u_{n-2,n-1} \\
0       & 0         & 0         & \dots     & 0             & u_{n-1,n-1} \\
\end{bmatrix} =
\begin{bmatrix}
1       & 0     & 0     & \dots     & 0     & 0 \\
0       & 1     & 0     & \dots     & 0     & 0 \\
0       & 0         & 1   & \dots     & 0     & 0 \\
\vdots  & \vdots    & \vdots    & \ddots    & \vdots        & \vdots \\
0       & 0         & 0         & \dots     & 1   & 0 \\
0       & 0         & 0         & \dots     & 0             & 1 \\
\end{bmatrix}
\f]

After multiplying and solving for \f$ x_{i,j} \f$,

\f[
x_{0,0} = \frac{1}{u_{0,0}}
\f]
\f[
x_{0,1} = - \frac{1}{u_{1,1}} u_{0,1} x_{0,0}
\f]
\f[
x_{0,2} = - \frac{1}{u_{2,2}}  \left[ u_{0,2}x_{0,0} + u_{1,2} x_{0,1} \right]
\f]
\f[
\vdots
\f]
\f[
x_{0,n-1} = - \frac{1}{u_{n-1,n-1}}  \left[ u_{0,n-1}x_{0,0} + u_{1,n-1}x_{0,1} + \dots  + u_{n-2,n-1} x_{0,n-2} \right]
\f]

\f[
x_{1,1} = \frac{1}{u_{1,1}}
\f]
\f[
x_{1,2} = - \frac{1}{u_{2,2}} u_{1,2} x_{1,1}
\f]
\f[
x_{1,3} = - \frac{1}{u_{3,3}}  \left[ u_{1,3}x_{1,1} + u_{2,3} x_{1,2} \right]
\f]
\f[
\vdots
\f]
\f[
x_{1,n-1} = - \frac{1}{u_{n-1,n-1}}  \left[ u_{1,n-1}x_{1,1} + u_{2,n-1}x_{1,2} + \dots  + u_{n-2,n-1} x_{1,n-2} \right]
\f]

A general expression can be written as,
\f[
x_{k,j} =
\begin{cases}
\frac{1}{u_{i,j}} & i = j \\
- \frac{1}{u_{j,j}}  \sum_{i = k}^{j-1}  u_{i,j}x_{k,i}  & k < j \\
0 & k > j
\end{cases}  \\

\f]

Then, the Following algorithm can be formulated,

    for k = 0 to n-1
        for j = 0 to n-1
            if k==j
                X[k,j] = 1/U[k,j]
            else if k < j
                sum = 0
                for i = k to j -1
                    sum = sum + U[i,j]X[k,i]
                end for i
                X[k,j] = 1/U[j,j] * sum
            else
                X[k,j] = 0
            end if
        end for j
    end for k




## LU Decomposition

Given a \f$ n \times n \f$ matrix defined as \f$A\f$.
A general expression for factorization can be written as,

\f[
PAQ = LU
\f]

where,

\f$A\f$ : Matrix to be factorized. Dimension : \f$ n \times n \f$.

\f$P\f$ : Permutation matrix to re-order rows of A. Dimension : \f$ n \times n \f$.

\f$Q\f$ : Permutation matrix to re-order columns of A. Dimension : \f$ n \times n \f$.

\f$L\f$ : Lower triangular matrix. Dimension : \f$ n \times n \f$.

\f$U\f$ : Upper triangular matrix. Dimension : \f$ n \times n \f$.

### Partial Pivoting

TBD : Addingle pseudo code for algorithm.


