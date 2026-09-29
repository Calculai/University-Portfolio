#ifndef FEEDER_HPP
#define FEEDER_HPP

#include "filter.hpp"

class Feeder : public Filter
{

protected:
    virtual void filter_op(std::vector<Monkey> &monkeys) override;
};

#endif // FEEDER_HPP