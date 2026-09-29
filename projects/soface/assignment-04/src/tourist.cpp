#include "tourist.hpp"

// Implement this (visitor pattern)
void Tourist::visit(Monkey &monkey)
{
    visited.push_back("monkey");
    // pushback is used to add the string to the end of the vector of strings visited
    // since it is initialized empty
    // this way tourist stores the string 
    // can be used even if we visit again just adds another string
}

// Implement this (visitor pattern)
void Tourist::visit(Tiger &tiger)
{
    visited.push_back("tiger");
    // see monkey
}

// Implement this (visitor pattern)
void Tourist::visit(Fish &fish)
{
    visited.push_back("fish");
    // see monkey
}

std::vector<std::string> Tourist::list_visited()
{
    return visited;
}