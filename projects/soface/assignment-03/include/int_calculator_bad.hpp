#pragma once
#include "logger.hpp"

class IntCalculatorBad
{
public:
    // Dependency injection through constructor
    IntCalculatorBad();

    virtual int sum(int a, int b);

    virtual int multiply(int a, int b);

private:
    Logger *logger;
};