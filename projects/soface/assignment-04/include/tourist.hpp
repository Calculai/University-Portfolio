#ifndef TOURIST_HPP
#define TOURIST_HPP

#include <vector>
#include <string>
#include "visitor.hpp"

class Tourist : public Visitor
{
public:
    std::vector<std::string> list_visited();
    virtual void visit(Monkey &monkey) override;
    virtual void visit(Tiger &tiger) override;
    virtual void visit(Fish &fish) override;
    virtual ~Tourist(){};

    // changed the name &monkey to &tiger for the visit tiger and
    // the same for fish because I don't like mixing the terms, 
    // it is unneeded but also not harmful so I did it for clarity.

private:
    std::vector<std::string> visited;
};

#endif // TOURIST_HPP