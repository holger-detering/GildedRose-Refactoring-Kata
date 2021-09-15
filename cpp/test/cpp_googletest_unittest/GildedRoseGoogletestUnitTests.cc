#include <gtest/gtest.h>
#include "GildedRose.h"

TEST(GildedRoseTest, Foo) { // NOLINT(cert-err58-cpp)
    vector<Item> items;
    items.emplace_back("Foo", 0, 0);
    GildedRose app(items);
    app.updateQuality();
    EXPECT_EQ("Foo", app.items[0].name);
}
