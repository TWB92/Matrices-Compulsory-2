#include <iostream>

#include "Matrix.h"


int main(int argc, char* argv[])
{
    //
    //          -- Copied from wolfram alpha --
    //
    //      Test matrix  : {{3,5,7},{2,3,6},{7,1,2}}
    //      Determinant  : 57
    //      inverse      : (0 | -0.0526316 | 0.157895 0.666667 | -0.754386 | -0.0701754 -0.333333 | 0.561404 | -0.0175439)
    //
    //
    
    Matrix matrix2(3, 3);
    matrix2.read();
    matrix2.print();

    std::cout << "\nInverse of matrix.\n";
    matrix2.inverse().print();
}
