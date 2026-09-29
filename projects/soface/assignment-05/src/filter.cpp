#include "filter.hpp"

Filter::Filter() : next_filter(nullptr)
{
}

Filter &Filter::set_next(Filter &filter)
{
    this->next_filter = &filter;
    return filter;
}

void Filter::filter(std::vector<Monkey> &monkeys)
{
    this->filter_op(monkeys);

    if (this->next_filter != nullptr)
    {
        this->next_filter->filter(monkeys);
    }
}