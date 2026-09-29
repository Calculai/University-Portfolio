#include <iostream>

#include "int_calculator_bad.hpp"

IntCalculatorBad::IntCalculatorBad() {}

int IntCalculatorBad::sum(int a, int b)
{

    int res = a + b;

    std::cout << "taking the sum of: " << a << " and " << b << " which is " << res << std::endl;

    return res;
}

int IntCalculatorBad::multiply(int a, int b)
{
    int res = a * b;

    std::cout << "taking the product of: " << a << " and " << b << " which is " << res << std::endl;

    return res;
}