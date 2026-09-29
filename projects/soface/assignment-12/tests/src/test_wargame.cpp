#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include <string>

#include "soldier.hpp"
#include "unit_selection.hpp"
#include "battle_monitor.hpp"
#include "revolver.hpp"

using Catch::Matchers::Contains;
using Catch::Matchers::Equals;
using Catch::Matchers::UnorderedEquals;

TEST_CASE("Test wargame")
{
    Revolver r;

    Soldier giJoe("giJoe", &r);
    Soldier zero("zero", &r);
    Soldier boris("boris", &r);
    Soldier rasputin("rasputin", &r);

    std::vector<GameUnit *> units = {
        &giJoe,
        &zero,
        &boris,
        &rasputin,
    };

    // attach observer to all units
    BattleMonitor m;
    for (auto u : units)
    {
        u->attach(m);
    }

    SECTION("Single Target")
    {
        REQUIRE(m.messages.size() == 0);

        giJoe.shootAt(boris);

        REQUIRE_THAT(m.messages, Equals(std::vector<std::string>{"boris got hit for 1 damage"}));

        boris.shootAt(giJoe);

        REQUIRE_THAT(m.messages, Equals(std::vector<std::string>{"boris got hit for 1 damage", "giJoe got hit for 1 damage"}));
    }

    SECTION("Selection")
    {
        UnitSelection s1;
        s1.addToSelection(giJoe);
        s1.addToSelection(zero);

        UnitSelection s2;
        s2.addToSelection(boris);
        s2.addToSelection(rasputin);

        s1.shootAt(s2);

        REQUIRE_THAT(m.messages, UnorderedEquals(std::vector<std::string>{
                                     "boris got hit for 1 damage",
                                     "rasputin got hit for 1 damage",
                                     "boris got hit for 1 damage",
                                     "rasputin got hit for 1 damage"}));

        m.messages = {}; // clear messages
        s2.shootAt(s1);
        REQUIRE_THAT(m.messages,
                     UnorderedEquals(std::vector<std::string>{
                         "giJoe got hit for 1 damage",
                         "giJoe got hit for 1 damage",
                         "zero got hit for 1 damage",
                         "zero got hit for 1 damage"}));
    }
}
