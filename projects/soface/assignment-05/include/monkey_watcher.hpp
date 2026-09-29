#ifndef MONKEY_WATCHER_HPP
#define MONKEY_WATCHER_HPP

#include "filter.hpp"

class MonkeyWatcher : public Filter
{
public:
    const std::vector<Monkey> &get_monkeys_seen() const;

protected:
    virtual void filter_op(std::vector<Monkey> &monkeys) override;

private:
    std::vector<Monkey> monkeys_seen;
};

#endif // MONKEY_WATCHER_HPP