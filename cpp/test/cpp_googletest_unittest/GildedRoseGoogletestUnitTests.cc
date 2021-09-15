#include <gtest/gtest.h>
#include "GildedRose.h"

TEST(GildedRoseTest, Foo) {
    vector<Item> items;
    items.emplace_back("Foo", 0, 0);
    GildedRose app(items);
    app.updateQuality();
    EXPECT_EQ("fixme", app.items[0].name);
}
