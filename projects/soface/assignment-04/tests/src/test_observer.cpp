#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "monkey.hpp"
#include "keeper.hpp"
#include "tiger.hpp"
#include "fish.hpp"
#include "animal_rights_group.hpp"
// See Catch2's documentation: https://github.com/catchorg/Catch2/blob/devel/docs/tutorial.md#scaling-up

TEST_CASE("Observers")
{
    Keeper keeper;

    Monkey m;
    Tiger t;
    Fish f;
    std::vector<Animal *> animals{&m, &t, &f};

    AnimalRightsGroup peta(1, 1, 1);
    Observer *obs = &peta;

    for (auto animal : animals)
    {
        animal->attach(&peta);
    }

    REQUIRE(!peta.animals_ok());

    for (auto animal : animals)
    {
        animal->accept(keeper);
    }

    REQUIRE(peta.animals_ok());
}
