#include "monkey_watcher.hpp"

// Implement this:
void MonkeyWatcher::filter_op(std::vector<Monkey> &monkeys)
{
    this->monkeys_seen.insert(this->monkeys_seen.end(), monkeys.begin(), monkeys.end());
    // this implementation allows to call Monkeywatcher multiple times to accumulate monkeys
    // alternatively. this->monkeys_seen = monkeys; would just overwrite the monkeys seen so far
    // with the new monkeys this would be a different take if we want the watcher to forget
}

const std::vector<Monkey> &MonkeyWatcher::get_monkeys_seen() const
{
    return this->monkeys_seen;
}