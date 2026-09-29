#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "monkey.hpp"
#include "fish.hpp"
#include "tiger.hpp"

#include "visitor.hpp"
#include "tourist.hpp"

class VisitorSpy : public Visitor
{
public:
    VisitorSpy() : monkeys_visited(0), tigers_visited(0), fish_visited(0)
    {
    }

    void visit(Monkey &monkey) override
    {
        monkeys_visited += 1;
    }
    void visit(Tiger &tiger) override
    {
        tigers_visited += 1;
    }
    void visit(Fish &fish) override
    {
        fish_visited += 1;
    }

    int monkeys_visited;
    int tigers_visited;
    int fish_visited;
};

TEST_CASE("Animals")
{

    Monkey m;
    Tiger t;
    Fish f;

    VisitorSpy spy;
    Tourist tourist;

    std::vector<Animal *>
        animals;
    animals.push_back(&m);
    animals.push_back(&t);
    animals.push_back(&f);

    for (auto const animal : animals)
    {
        animal->accept(spy);
        animal->accept(tourist);
    }

    SECTION("Animals calls visit")
    {

        REQUIRE(spy.monkeys_visited == 1);
        REQUIRE(spy.tigers_visited == 1);
        REQUIRE(spy.fish_visited == 1);
    }

    SECTION("Tourist Records Visits")
    {
        std::vector<std::string> expected{"monkey", "tiger", "fish"};
        auto visited = tourist.list_visited();

        REQUIRE(visited == expected);
    }
}
