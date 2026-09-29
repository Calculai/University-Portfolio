#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "monkey.hpp"
#include "monkey_watcher.hpp"
#include "feeder.hpp"
#include "cloning_tank.hpp"
using namespace Catch::Matchers;

TEST_CASE("Test Filtering")
{
    std::vector<Monkey> monkeys{
        {"Harambe", 10}, {"Rafiki", 1}, {"Abu", 3}};

    MonkeyWatcher watcher;
    Feeder feeder;

    SECTION("MonkeyWatcher")
    {
        REQUIRE(watcher.get_monkeys_seen().empty() == true);
        watcher.filter(monkeys);
        REQUIRE_THAT(
            watcher.get_monkeys_seen(),
            UnorderedEquals(std::vector<Monkey>{{"Harambe", 10}, {"Rafiki", 1}, {"Abu", 3}}));
    }

    SECTION("Feeder")
    {
        feeder.set_next(watcher);
        feeder.filter(monkeys);

        REQUIRE_THAT(
            watcher.get_monkeys_seen(),
            UnorderedEquals(std::vector<Monkey>{{"Harambe", 9}, {"Rafiki", 0}, {"Abu", 2}}));
    }

    SECTION("CloningTank")
    {
        CloningTank tank;

        tank.set_next(feeder).set_next(watcher);
        tank.filter(monkeys);
        REQUIRE_THAT(
            watcher.get_monkeys_seen(),
            UnorderedEquals(std::vector<Monkey>{{"Harambe", 9}, {"Rafiki", 0}, {"Abu", 2}, {"Harambe", 9}, {"Rafiki", 0}, {"Abu", 2}}));
    }
}
