#pragma once

#include <sstream>
#include "logger.hpp"

template <typename T>
class TemplateCalculator
{
public:
    explicit TemplateCalculator(Logger *logger) : logger(logger)
    {
    }

    // Implement this:
    T sum(T a, T b)
    {
        // we calculate the sum
        T r = a + b;
        
        // we make a stringstream and then print to it
        std::stringstream ss;
        ss << "taking the sum of: " << a << " and " << b << " which is " << r;
    
        // then we log the message using the logger
        logger->log(ss.str());

        // we return our result
        return r;
    }

    // Implement this:
    T multiply(T a, T b)
    {
        // get the product
        T r = a * b;

        // make the stringstream and print to it
        std::stringstream ss;
        ss << "taking the product of: " << a << " and " << b << " which is " << r;

        // log it
        logger->log(ss.str());

        // return r
        return r;
    }

private:
    Logger *logger;
};