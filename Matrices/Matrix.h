#pragma once

#include "Vector3D.h"

class Matrix
{
public:
    // -- Constructors --
    Matrix();
    Matrix(int _m, int _n);
    
    // -- Functions --
    void read();
    void print();
    Matrix multiply(Matrix otherMatrix);
    Matrix multiply(double factor);
    Matrix subMatrix(int _i,int _j);
    Matrix adjoint();
    Matrix transpose();
    double determinant();
    Matrix inverse();
    Vector3D multiply(Vector3D v);
private:
    // -- Constants --
    static const int M = 10;
    static const int N = 10;
    
    // -- Variables --
    double A[M][N];
    int m; // actual number of rows
    int n; // actual number of columns
};
