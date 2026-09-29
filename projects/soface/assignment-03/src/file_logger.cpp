#include "file_logger.hpp"
#include <fstream>
#include <iostream>

// Implement this:
FileLogger::FileLogger(std::string filename)
{
    // logfile is an ofstream object, which has an open function
    logfile.open(filename, std::ios::app);
    // called like this it opens a file with filename of the string then it
    // appends to the file. This creates a persistent log file that keeps
    // all the logs between runs of the program.

    // alternatively we could open the file in trunc mode to overwrite it each time:
    // logfile.open(filename, std::ios::trunc);
    // this is just a design choice, it might be important if we use it a lot 
    // to avoid massive log files, but for this assignment I think appending is fine.


    // check if the file was opened successfully
    if (!logfile.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
        // print the error to terminal and return
    }
}

// Implement this:
void FileLogger::log(std::string msg)
{
    // we need to write the message to the file, we can use the ofstream object for this
    if (logfile.is_open()) {
        logfile << msg << std::endl;
    } else {
        std::cerr << "Error: log file could not open.";
        return;
        // print the error to terminal and return
    }
}

// Implement this:
FileLogger::~FileLogger() {}
// since I am going with a persistant log file
// I don't close the file so the desturctor is default

/*
if i wanted to close the file each time i would do it like this:
FileLogger::~FileLogger() {
    if (logfile.is_open()) {
        logfile.close();
    }
}
this uses the close function to delete the txtfile

after reading the test file this implementation would
not pass since it requires the file to stay between
runs
*/