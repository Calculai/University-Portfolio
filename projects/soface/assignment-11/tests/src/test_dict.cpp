#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "dict.hpp"
#include <string>

/*
The tests verify all required Dict functionality from the assignment
Running with `ctest --verbose` shows branch-specific print output for all normal/reachable paths
My failure condition branches are not realistically reachable in normal execution but also unlikely
to ever occur so I will take this as good enough branch coverage
*/

using Catch::Matchers::UnorderedEquals;

TEST_CASE("Test Dict")
{
    // I copied in specification so that I can base test off it to insure software meets requirements (***** denotes requirements)

    // Associates the key with the specified value. *****
    Dict<std::string, int> database;

    std::string s = "Ch852";
    int i = 2026;
    database.set(s, i);

    // make sure that the key is associated with the value in the dictionary
    REQUIRE(database.get(s).value() == i);

    // If the key is already in the dictionary its value is overwritten. *****
    int new_i = 2027;
    database.set(s, new_i);
    REQUIRE(database.get(s).value() == new_i);


    // Determines if the key is defined in the dictionary. *****
    // Return true if the key is defined in the dictionary. *****
    // Return false otherwise. *****

    // Needs to be true since we know the key is in the dictionary
    REQUIRE(database.has(s));

    // Return false since we know this key is not in the dictionary
    REQUIRE_FALSE(database.has("random key"));

    // Add another to the list just to make it longer
    std::string d = "AL964";
    int g = 293026;
    database.set(d, g);

    // Returns the number of items in the dictionary. *****

    // We added two items so far so the length should be 2
    REQUIRE(database.len() == 2);

    // Get the value associated with the specified key. *****

    // s has the value new_i so we require that association
    REQUIRE(database.get(s).value() == new_i);

    // If no value is found std::nullopt is returned. *****

    // If we try to get something from a nonexistent key we should get nullopt
    REQUIRE(database.get("nonexistent key") == std::nullopt);

    // Delete the specified key and its associated value from the dictionary. *****

    // Require that key s is in the dictionary before deletion
    REQUIRE(database.has(s));
    // Delete it
    database.del(s);        
    // Require that key s is not in the dictionary after deletion and then try to get the value from key s which should give nullopt
    REQUIRE_FALSE(database.has(s));
    REQUIRE(database.get(s) == std::nullopt);

    // If the key is not present in the dictionary, nothing happens. *****
    database.del("imaginary key");  
    // My cout will inform us what happens cant require this test

    std::string t = "Ch6572";
    int h = 9999;
    database.set(t, h);

    // List all keys of the dictionary. *****

    // Use the fuction and then require that the list of keys are the two surviving keys in the dictionary
    auto keylist = database.keys();
    REQUIRE_THAT(keylist, UnorderedEquals(std::vector<std::string>{"AL964", "Ch6572"}));


    // List all values of the dictionary. *****

    // same thing as above
    auto vallist = database.values();
    REQUIRE_THAT(vallist, UnorderedEquals(std::vector<int>{293026, 9999}));


    

}
