#define CATCH_CONFIG_MAIN // tell Catch to provide a main() - only do this in one cpp file
#include "catch2/catch.hpp"

// code under test
#include "GildedRose.h"

namespace {
constexpr auto normal_item = "+5 Dexterity Vest";
constexpr auto aged_brie = "Aged Brie";
constexpr auto sulfuras = "Sulfuras, Hand of Ragnaros";
constexpr auto backstage_pass = "Backstage passes to a TAFKAL80ETC concert";
constexpr auto conjured_item = "Conjured Mana Cake";
constexpr auto max_quality = 50;
} // namespace

TEST_CASE("sellIn of normal item is decreased by one") {
    vector<Item> items;
    constexpr auto sellIn = 10;
    constexpr auto quality = 20;
    items.emplace_back(normal_item, sellIn, quality);
    GildedRose app(items);

    app.updateQuality();

    CHECK(app.items[0].sellIn == sellIn - 1);
}

TEST_CASE("quality of normal item is decreased by one") {
    vector<Item> items;
    constexpr auto sellIn = 10;
    constexpr auto quality = 20;
    items.emplace_back(normal_item, sellIn, quality);
    GildedRose app(items);

    app.updateQuality();

    CHECK(app.items[0].quality == quality - 1);
}

TEST_CASE("quality of normal item is decreased by two when sellIn is reached") {
    vector<Item> items;
    constexpr auto sellIn = 0;
    constexpr auto quality = 20;
    items.emplace_back(normal_item, sellIn, quality);
    GildedRose app(items);

    app.updateQuality();

    CHECK(app.items[0].quality == quality - 2);
}

TEST_CASE("quality will never be negative") {
    vector<Item> items;
    constexpr auto sellIn = 0;
    constexpr auto quality = 0;
    items.emplace_back(normal_item, sellIn, quality);
    GildedRose app(items);

    app.updateQuality();

    CHECK(app.items[0].quality >= 0);
}

TEST_CASE("aged brie increases in quality") {
    vector<Item> items;
    constexpr auto sellIn = 10;
    constexpr auto quality = 20;
    items.emplace_back(aged_brie, sellIn, quality);
    GildedRose app(items);

    app.updateQuality();

    CHECK(app.items[0].quality > quality);
}

TEST_CASE("max. quality is 50") {
    vector<Item> items;
    constexpr auto sellIn = 10;
    items.emplace_back(aged_brie, sellIn, max_quality);
    GildedRose app(items);

    app.updateQuality();

    CHECK(app.items[0].quality <= max_quality);
}

TEST_CASE("sulfuras never has to be sold") {
    vector<Item> items;
    constexpr auto sellIn = 10;
    constexpr auto quality = 20;
    items.emplace_back(sulfuras, sellIn, quality);
    GildedRose app(items);

    app.updateQuality();

    CHECK(app.items[0].sellIn == sellIn);
}

TEST_CASE("sulfuras never decreases in quality") {
    vector<Item> items;
    constexpr auto sellIn = 10;
    constexpr auto quality = 20;
    items.emplace_back(sulfuras, sellIn, quality);
    GildedRose app(items);

    app.updateQuality();

    CHECK(app.items[0].quality == quality);
}

// skipped
TEST_CASE("sulfuras quality stays at 80", "[!mayfail]") {
    vector<Item> items;
    constexpr auto sellIn = 10;
    constexpr auto quality = 20;
    items.emplace_back(sulfuras, sellIn, quality);
    GildedRose app(items);

    app.updateQuality();

    CHECK(app.items[0].quality == 80);
}

TEST_CASE("backstage passes increase in quality") {
    vector<Item> items;
    constexpr auto sellIn = 15;
    constexpr auto quality = 20;
    items.emplace_back(backstage_pass, sellIn, quality);
    GildedRose app(items);

    app.updateQuality();

    CHECK(app.items[0].quality > quality);
}

TEST_CASE("quality of backstage pass increases by 2 on day 10") {
    vector<Item> items;
    constexpr auto sellIn = 10;
    constexpr auto quality = 20;
    items.emplace_back(backstage_pass, sellIn, quality);
    GildedRose app(items);

    app.updateQuality();

    CHECK(app.items[0].quality == quality + 2);
}

TEST_CASE("quality of backstage pass increases by 3 on day 5") {
    vector<Item> items;
    constexpr auto sellIn = 5;
    constexpr auto quality = 20;
    items.emplace_back(backstage_pass, sellIn, quality);
    GildedRose app(items);

    app.updateQuality();

    CHECK(app.items[0].quality == quality + 3);
}

TEST_CASE("quality of backstage pass stays zero after the concert") {
    vector<Item> items;
    constexpr auto sellIn = 0;
    constexpr auto quality = 20;
    items.emplace_back(backstage_pass, sellIn, quality);
    GildedRose app(items);

    app.updateQuality();

    CHECK(app.items[0].quality == 0);
}

// failing test case for new feature
TEST_CASE("quality of conjured item decreases twice as fast", "[!mayfail]") {
    vector<Item> items;
    constexpr auto sellIn = 10;
    constexpr auto quality = 20;
    items.emplace_back(conjured_item, sellIn, quality);
    GildedRose app(items);

    app.updateQuality();

    CHECK(app.items[0].quality == quality - 2);
}
