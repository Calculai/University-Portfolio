#ifndef FILTER_HPP
#define FILTER_HPP

#include <vector>

#include "monkey.hpp"

class Filter
{
public:
    Filter();
    void filter(std::vector<Monkey> &monkeys);
    Filter &set_next(Filter &filter);

protected:
    virtual void filter_op(std::vector<Monkey> &monkeys) = 0;

private:
    Filter *next_filter;
};

#endif // FILTER_HPP