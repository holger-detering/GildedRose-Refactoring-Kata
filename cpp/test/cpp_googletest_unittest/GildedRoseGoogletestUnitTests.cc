#include <gtest/gtest.h>

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

TEST(GildedRoseTest, sellIn_of_normal_item_is_decreased_by_one) { // NOLINT(cert-err58-cpp)
    vector<Item> items;
    constexpr auto sellIn = 10;
    constexpr auto quality = 20;
    items.emplace_back(normal_item, sellIn, quality);
    GildedRose app(items);

    app.updateQuality();

    EXPECT_EQ(app.items[0].sellIn, sellIn - 1);
}

TEST(GildedRoseTest, quality_of_normal_item_is_decreased_by_one) { // NOLINT(cert-err58-cpp)
    vector<Item> items;
    constexpr auto sellIn = 10;
    constexpr auto quality = 20;
    items.emplace_back(normal_item, sellIn, quality);
    GildedRose app(items);

    app.updateQuality();

    EXPECT_EQ(app.items[0].quality, quality - 1);
}

TEST(GildedRoseTest, quality_of_normal_item_is_decreased_by_two_when_sellIn_is_reached) { // NOLINT(cert-err58-cpp)
    vector<Item> items;
    constexpr auto sellIn = 0;
    constexpr auto quality = 20;
    items.emplace_back(normal_item, sellIn, quality);
    GildedRose app(items);

    app.updateQuality();

    EXPECT_EQ(app.items[0].quality, quality - 2);
}

TEST(GildedRoseTest, quality_will_never_be_negative) { // NOLINT(cert-err58-cpp)
    vector<Item> items;
    constexpr auto sellIn = 0;
    constexpr auto quality = 0;
    items.emplace_back(normal_item, sellIn, quality);
    GildedRose app(items);

    app.updateQuality();

    EXPECT_GE(app.items[0].quality, 0);
}

TEST(GildedRoseTest, aged_brie_increases_in_quality) { // NOLINT(cert-err58-cpp)
    vector<Item> items;
    constexpr auto sellIn = 10;
    constexpr auto quality = 20;
    items.emplace_back(aged_brie, sellIn, quality);
    GildedRose app(items);

    app.updateQuality();

    EXPECT_GT(app.items[0].quality, quality);
}

TEST(GildedRoseTest, max_quality_is_50) { // NOLINT(cert-err58-cpp)
    vector<Item> items;
    constexpr auto sellIn = 10;
    items.emplace_back(aged_brie, sellIn, max_quality);
    GildedRose app(items);

    app.updateQuality();

    EXPECT_LE(app.items[0].quality, max_quality);
}

TEST(GildedRoseTest, sulfuras_never_has_to_be_sold) { // NOLINT(cert-err58-cpp)
    vector<Item> items;
    constexpr auto sellIn = 10;
    constexpr auto quality = 20;
    items.emplace_back(sulfuras, sellIn, quality);
    GildedRose app(items);

    app.updateQuality();

    EXPECT_EQ(app.items[0].sellIn, sellIn);
}

TEST(GildedRoseTest, sulfuras_never_decreases_in_quality) { // NOLINT(cert-err58-cpp)
    vector<Item> items;
    constexpr auto sellIn = 10;
    constexpr auto quality = 20;
    items.emplace_back(sulfuras, sellIn, quality);
    GildedRose app(items);

    app.updateQuality();

    EXPECT_EQ(app.items[0].quality, quality);
}

// may fail
TEST(GildedRoseTest, DISABLED_sulfuras_quality_stays_at_80) { // NOLINT(cert-err58-cpp)
    vector<Item> items;
    constexpr auto sellIn = 10;
    constexpr auto quality = 20;
    items.emplace_back(sulfuras, sellIn, quality);
    GildedRose app(items);

    app.updateQuality();

    EXPECT_EQ(app.items[0].quality, 80);
}

TEST(GildedRoseTest, backstage_passes_increase_in_quality) { // NOLINT(cert-err58-cpp)
    vector<Item> items;
    constexpr auto sellIn = 15;
    constexpr auto quality = 20;
    items.emplace_back(backstage_pass, sellIn, quality);
    GildedRose app(items);

    app.updateQuality();

    EXPECT_GT(app.items[0].quality, quality);
}

TEST(GildedRoseTest, quality_of_backstage_pass_increases_by_2_on_day_10) { // NOLINT(cert-err58-cpp)
    vector<Item> items;
    constexpr auto sellIn = 10;
    constexpr auto quality = 20;
    items.emplace_back(backstage_pass, sellIn, quality);
    GildedRose app(items);

    app.updateQuality();

    EXPECT_EQ(app.items[0].quality, quality + 2);
}

TEST(GildedRoseTest, quality_of_backstage_pass_increases_by_3_on_day_5) { // NOLINT(cert-err58-cpp)
    vector<Item> items;
    constexpr auto sellIn = 5;
    constexpr auto quality = 20;
    items.emplace_back(backstage_pass, sellIn, quality);
    GildedRose app(items);

    app.updateQuality();

    EXPECT_EQ(app.items[0].quality, quality + 3);
}

TEST(GildedRoseTest, quality_of_backstage_pass_stays_zero_after_the_concert) { // NOLINT(cert-err58-cpp)
    vector<Item> items;
    constexpr auto sellIn = 0;
    constexpr auto quality = 20;
    items.emplace_back(backstage_pass, sellIn, quality);
    GildedRose app(items);

    app.updateQuality();

    EXPECT_EQ(app.items[0].quality, 0);
}

// failing test case for new feature
TEST(GildedRoseTest, quality_of_conjured_item_decreases_twice_as_fast) { // NOLINT(cert-err58-cpp)
    vector<Item> items;
    constexpr auto sellIn = 10;
    constexpr auto quality = 20;
    items.emplace_back(conjured_item, sellIn, quality);
    GildedRose app(items);

    app.updateQuality();

    EXPECT_EQ(app.items[0].quality, quality - 2);
}
