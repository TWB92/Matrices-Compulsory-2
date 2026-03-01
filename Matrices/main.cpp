#include <iostream>

#include "Matrix.h"


int main(int argc, char* argv[])
{
    //
    //          -- Results copied from wolfram alpha --
    //
    //      Test matrix : {{1,0,2},{-3,4,6},{-1,-2,3}}
    //      Determinant : 44
    //      inverse     : (0.545455 | -0.0909091 | -0.181818   0.0681818 | 0.113636 | -0.272727   0.227273 | 0.0454545 | 0.0909091)
    //
    //      Test matrix : {{1,2,3},{2,3,4},{3,4,2}}
    //      Determinant : 3
    //      Inverse     : (-3.33333 | 2.66667 | -0.333333   2.66667 | -2.33333 | 0.666667   -0.333333 | 0.666667 | -0.333333)

    Matrix matrix1(3, 3);
    matrix1.read();
    matrix1.print();
    
    Matrix matrix2(3, 3);
    matrix2.read();
    matrix2.print();

    std::cout << "\nInverse of matrix.\n";
    matrix1.inverse().print();
    matrix2.inverse().print();
    
    // Vector3D functionality.
    Vector3D newVector(3,5,-2);
    newVector.print();
    matrix1.multiply(newVector).print();
    matrix2.multiply(newVector).print();
    
    Vector3D anotherVector(-4,-2,8);
    newVector += anotherVector;
    newVector.print();
}
