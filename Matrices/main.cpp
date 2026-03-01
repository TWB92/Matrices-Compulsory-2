#include <iostream>

#include "Matrix.h"


int main(int argc, char* argv[])
{
    //
    //          -- Copied from wolfram alpha --
    //
    //      Test matrix  : {{3,2,1},{1,6,3},{2,-4,0}}
    //      Determinant  : 32
    //      inverse      : (0.375 | -0.125 | 0   0.1875 | -0.0625 | -0.25   -0.5 | 0.5 | 0.5)
    //
    //
    
    Matrix matrix2(3, 3);
    matrix2.read();
    matrix2.print();

    std::cout << "\nInverse of matrix.\n";
    matrix2.inverse().print();
}
