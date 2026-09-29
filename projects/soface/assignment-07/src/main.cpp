// File for sandboxing and trying out code

#include "matrix.hpp"
#include <ostream>
#include <iostream>

int main(int argc, char **argv)
{
    size_t n_rows = 3;
    size_t n_cols = 3;
    Mat2D<float> mat(n_rows, n_cols);

    for (size_t row = 0; row < n_rows; row++)
    {
        for (size_t col = 0; col < n_cols; col++)
        {
            float value = static_cast<float>(row * n_cols + (col));
            mat.set(row, col, value);
        }
    }

    // mat.multiply_single_threaded(10);

    mat.multiply_partitioned(10, 3);

    std::cout << std::endl
              << mat;

    return 0;
}