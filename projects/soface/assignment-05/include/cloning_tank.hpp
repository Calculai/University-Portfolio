#ifndef CLONING_TANK
#define CLONING_TANK

#include "filter.hpp"

class CloningTank : public Filter
{

protected:
    virtual void filter_op(std::vector<Monkey> &monkeys) override;
};

#endif // CLONING_TANK