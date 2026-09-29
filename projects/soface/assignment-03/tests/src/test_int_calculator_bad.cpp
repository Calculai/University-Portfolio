#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "int_calculator_bad.hpp"

// See Catch2's documentation: https://github.com/catchorg/Catch2/blob/devel/docs/tutorial.md#scaling-up

TEST_CASE("IntCalculatorBad")
{
    IntCalculatorBad calc;

    SECTION("sum")
    {
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                REQUIRE(calc.sum(i, j) == i + j);
            }
        }
    }

    SECTION("multiply")
    {

        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                REQUIRE(calc.multiply(i, j) == i * j);
            }
        }
    }
}
