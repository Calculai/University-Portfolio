#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "matrix.hpp"
using namespace Catch::Matchers;

TEST_CASE("Test Matrix")
{
    size_t n_rows = 3;
    size_t n_cols = 3;
    Mat2D<float> mat1(n_rows, n_cols);
    Mat2D<float> mat2(n_rows, n_cols);
    float constant = 10.0f;
    size_t n_threads = 3;

    // sets matrix to 0,2,3
    for (size_t row = 0; row < n_rows; row++)
    {
        for (size_t col = 0; col < n_cols; col++)
        {
            float value = static_cast<float>(row * n_cols + (col));
            mat1.set(row, col, value);
            mat2.set(row, col, value * constant);
        }
    }

    SECTION("multiply_single_threaded")
    {

        REQUIRE(!mat1.array_equal(mat2));
        mat1.multiply_single_threaded(constant);
        REQUIRE(mat1.array_equal(mat2));
    }

    SECTION("multiply_partitioned")
    {

        REQUIRE(!mat1.array_equal(mat2));
        mat1.multiply_partitioned(constant, n_threads);
        REQUIRE(mat1.array_equal(mat2));
    }
}
