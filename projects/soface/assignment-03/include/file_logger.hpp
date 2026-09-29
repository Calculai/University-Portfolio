#pragma once
#include <string>

#include "logger.hpp"
#include "fstream"

// Concrete FileLogger class:
class FileLogger : public Logger
{
public:
    FileLogger(std::string filename);

    virtual void log(std::string msg) override;

    ~FileLogger();

private:
    std::ofstream logfile;
};