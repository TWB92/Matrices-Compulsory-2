#include <iostream>

#include "Matrix.h"


int main(int argc, char* argv[])
{
    Matrix matrix2(3, 3);
    matrix2.read();
    matrix2.print();
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            std::cout << "Submatrix on index [" << i << ", " << j << "]\n";
            matrix2.subMatrix(i,j).print();
        }
    }
    std::cout << matrix2.determinant();
}
