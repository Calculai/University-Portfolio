#pragma once
#include <string>

#include "logger.hpp"

// Concrete DummyLogger class:
class DummyLogger : public Logger
{
public:
    virtual void log(std::string msg) override;
};