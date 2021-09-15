#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch2/catch.hpp"
#include "GildedRose.h"

TEST_CASE("test Foo")
{
    vector<Item> items;
    items.emplace_back("Foo", 0, 0);
    GildedRose app(items);
    app.updateQuality();
    REQUIRE("Foo" == app.items[0].name);
}
