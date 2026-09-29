#ifndef VISITOR_HPP
#define VISITOR_HPP

class Monkey;
class Tiger;
class Fish;

class Visitor
{
public:
    virtual void visit(Monkey &monkey) = 0;
    virtual void visit(Tiger &tiger) = 0;
    virtual void visit(Fish &fish) = 0;

    virtual ~Visitor(){};
};

#endif // VISITOR_HPP