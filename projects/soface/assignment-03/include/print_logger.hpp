#pragma once
#include <string>

#include "logger.hpp"

// Concrete PrintLogger class:
class PrintLogger : public Logger
{
public:
    virtual void log(std::string msg) override;
};