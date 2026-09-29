#include <sstream> // Hint to how you should build the message.

#include "int_calculator.hpp"

// Constructor Injection
IntCalculator::IntCalculator(Logger *log) : logger(log) {}
// construct the class and assign the logger variable to be the passed logger pointer
// changed to logger(log) to make it clearer for me as I am new to C++ and logger(logger) is confusing

// Implement this:
int IntCalculator::sum(int a, int b)
{
    // we calculate the sum
    int r = a + b;
    /*
    We need to log this sum, the log requires a string,
    so we need to build a string. For this I found 
    stringstream.
    */
    std::stringstream ss;
    ss << "taking the sum of: " << a << " and " << b << " which is " << r;
    
    // then we log the message using the logger
    logger->log(ss.str());
    // call logger variable and use its log function and pass the string we built using stringstream

    // finally we return the result
    return r;
}

// Implement this:
int IntCalculator::multiply(int a, int b)
{
    // other implementation has more deeper thought this just outlines funcitonality

    // get the product
    int r = a * b;

    // make the stringstream and print to it
    std::stringstream ss;
    ss << "taking the product of: " << a << " and " << b << " which is " << r;

    // log it
    logger->log(ss.str());

    // return r
    return r;
}