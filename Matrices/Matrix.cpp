#include "Matrix.h"
#include <iostream>

Matrix::Matrix()
{
    // Default constructor, creates a 10x10 matrix
    m = M;
    n = N;
    // Make all entries of matrix 0
    for (int i = 0; i < M; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            A[i][j] = 0;
        }
    }
}

Matrix::Matrix(int _m, int _n) : m(_m), n(_n) // Shorthand for setting variables based on the parameters.
{
    for (int i = 0; i < _m; ++i)
    {
        for (int j = 0; j < _n; ++j)
        {
            A[i][j] = 0;
        }
    }
}

void Matrix::read()
{
    // User input of a matrix's entries.
    std::cout << "Fill your matrix\n";
    
    for (int i = 0; i < m; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            std::cin >> A[i][j];
        }
    }
    std::cout << std::endl;
}

void Matrix::print()
{
    // Self-explanatory, prints the indices of the matrix in the console in an ordered matter.
    std::cout << "--- Printing matrix of size [" << m << " x " << n << "] ---\n";
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            std::cout << A[i][j] << " ";
        }
        std::cout << "\n";
    }
}

Matrix Matrix::multiply(Matrix otherMatrix)
{
    // Multiplication between two matrices where n is equal to the other matrix's m
    if ((n!=otherMatrix.m))
    {
        std::cout << "Cannot multiply, different sizes\n";
        return Matrix();
    }
    
    Matrix dynamicResult(m, otherMatrix.n);

    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < otherMatrix.n; ++j)
        {
            for (int k = 0; k < n; ++k)
            {
                double resultValue = dynamicResult.A[i][j] + (A[i][k] * otherMatrix.A[k][j]);
                dynamicResult.A[i][j] = resultValue;
            }
        }
    }
    return dynamicResult;
}

Matrix Matrix::multiply(double factor)
{
    // Function which multiplies all entries of a matrix with a scalar
    
    Matrix newMatrix(m,n);
    
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            newMatrix.A[i][j] = A[i][j] * factor;
        }
    }
    return newMatrix;
}

Matrix Matrix::subMatrix(int _i, int _j) // Does not look pretty, but it works, and I cannot see any other way this is done.
{
    // Finds the submatrix or "Minor" of a matrix of any given entry. Does not allow creating submatrices outside the matrix's size.
    
    if (_i >= m || _j >= n || _i < 0 || _j < 0)
    {
        std::cout << "Arguments outside of range";
        return Matrix(m, n);
    }
    // A submatrix with one row and one column remove
    Matrix sub(m-1,n-1);
    
    // Loop through all rows before the one which is removed.
    for (int i = 0; i < _i; ++i)
    {
        // Same here, goes through all columns before the one removed.
        for (int j = 0; j < _j; ++j)
        {
            sub.A[i][j] = A[i][j];
        }
        
        for (int j = _j; j < n-1; ++j)
        {
            sub.A[i][j] = A[i][j+1];
        }
    }
    
    for (int i = _i; i < m-1; ++i)
    {
        for (int j = 0; j < _j; ++j)
        {
            sub.A[i][j] = A[i+1][j];
        }
        
        for (int j = _j; j < n-1; ++j)
        {
            sub.A[i][j] = A[i+1][j+1];
        }
    }
    
    return sub;
}

Matrix Matrix::adjoint()
{
    // If matrix is not square, go out of function.
    if (m!=n)
    {
        std::cout << "Matrix must be square to find adjoint";
        return Matrix();
    }
    
    // Create a matrix which will be the adjoint matrix by the end.
    Matrix adjointMatrix(m,n);
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            // The factor deciding whether the cofactor is the negative of the determinant of the submatrix or not.
            double adjFactor = pow(-1, i+j);
            
            // Switching out "i" and "j" means we don't need to call the transpose function on the result.
            adjointMatrix.A[i][j] = subMatrix(i,j).determinant() * adjFactor; 
        }
    }
    
    return adjointMatrix.transpose();
}

Matrix Matrix::transpose()
{
    // Create new matrix which will become the transpose (n and m are switched).
    Matrix newMatrix(n, m);

    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            // put the entries in the matrix on the other side of the diagonal.
            newMatrix.A[j][i] = A[i][j];
        }
    }
    return newMatrix;
}

double Matrix::determinant()
{
    // Works only for square matrices up to 3x3, but can be easily scaled.
    
    if (n!=m)
    {
        std::cout << "Matrix is not square, determinant cannot be calculated";
        return 0;
    }
    
    // The determinant of a 1x1 matrix is its only entry
    if (m==1)
    {   
        return A[0][0];
    }
    
    // The determinant of a 2x2 matrix is simple
    if (m==2)
    {
        return A[0][0] * A[1][1] - A[0][1] * A[1][0]; // ad - bc
    }
    
    // The determinant of a 3x3 function (and above) is found by adding every entry in the first row multiplied with its cofactor
    if (m==3)
    {
        return A[0][0]*subMatrix(0,0).determinant() - A[0][1]*subMatrix(0,1).determinant() + A[0][2]*subMatrix(0,2).determinant();
    }
    
    // As I have so humbly searched on the internet, the cofactor for larger sizes of square matrices can be done recursively.
    // I will probably implement it, just writing here to remind myself.

    std::cout << "Matrix too big! Function finds determinants for matrices up to 3x3.\n";
    return 0;
}

Matrix Matrix::inverse()
{
    // Based on the definition of an inverse matrix, it cannot be inverted if it is not square, or if the determinant is = 0.
    // Technically checking if m!=n is redundant, but it adds another level of readability, and it makes sure the determinant function is not called pointlessly.
    if (m!=n || determinant()==0)
    {
        std::cout << "Matrix cannot be inverted\n";
        return Matrix();
    }
    // 1/det(A) * adj(A)
    // Based on what we learned from week 6 on slide 8
    return adjoint().multiply(1/determinant());
}
