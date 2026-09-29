#pragma once
#include <string>

// Abstract Logger class:
class Logger
{
public:
    virtual void log(std::string msg) = 0;

    virtual ~Logger() {};
};