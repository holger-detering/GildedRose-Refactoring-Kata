// Include header files for test frameworks
#include <ApprovalTests.hpp>
#include <gtest/gtest.h>

#include <sstream>
#include <utility>

// Include code under test
#include "GildedRose.h"

std::ostream &operator<<(std::ostream &os, const Item &obj) {
    return os << "name: " << obj.name << ", sellIn: " << obj.sellIn << ", quality: " << obj.quality;
}

namespace {
std::vector<Item> Items() {
    return std::vector<Item>{{"+5 Dexterity Vest", 10, 20},
                             {"Aged Brie", 2, 0},
                             {"Elixir of the Mongoose", 5, 7},
                             {"Sulfuras, Hand of Ragnaros", 0, 80},
                             {"Sulfuras, Hand of Ragnaros", -1, 80},
                             {"Backstage passes to a TAFKAL80ETC concert", 15, 20},
                             {"Backstage passes to a TAFKAL80ETC concert", 10, 49},
                             {"Backstage passes to a TAFKAL80ETC concert", 5, 49},
                             {"Conjured Mana Cake", 3, 6}};
}
} // namespace

TEST(GildedRoseApprovalTests, Approvingtext) { // NOLINT(cert-err58-cpp)
    auto items = Items();
    GildedRose app(items);

    std::stringstream out_stream;
    for (int day = 0; day <= 30; ++day) {
        out_stream << "----- day " << day << " -----\n";
        out_stream << "name, sellIn, quality\n";
        for (const auto &item : items) {
            out_stream << item << "\n";
        }
        out_stream << '\n';
        app.updateQuality();
    }

    ApprovalTests::Approvals::verify(out_stream.str());
}

TEST(GildedRoseApprovalTests, VerifyCombinations) { // NOLINT(cert-err58-cpp)
    std::vector<string> names{"Foo"};
    std::vector<int> sellIns{1};
    std::vector<int> qualities{1};

    auto f = [](string name, int sellIn, int quality) {
        vector<Item> items = {Item(std::move(name), sellIn, quality)};
        GildedRose app(items);
        app.updateQuality();
        return items[0];
    };

    ApprovalTests::CombinationApprovals::verifyAllCombinations(f, names, sellIns, qualities);
}
