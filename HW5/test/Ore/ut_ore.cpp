#include <gtest/gtest.h>
#include "Ore/Ore.hpp"

class TestOre : public Ore {
public:
    TestOre(Product product, int durabilityCost)
        : Ore(product, durabilityCost) {}

    float GetBreakExp() override {
        return 0;
    }
};

TEST(ORE_TEST, Constructor) {
    ASSERT_THROW(TestOre o(Product::None, 3), std::invalid_argument);
    ASSERT_NO_THROW(TestOre o(Product::Coal, 3));
    ASSERT_NO_THROW(TestOre o(Product::Iron, 3));
    ASSERT_NO_THROW(TestOre o(Product::Gold, 3));
    ASSERT_NO_THROW(TestOre o(Product::Diamond, 3));
    ASSERT_NO_THROW(TestOre o(Product::Obsidian, 3));
}

TEST(ORE_TEST, GetProduct) {
    TestOre o1(Product::Coal, 3);
    ASSERT_EQ(o1.GetProduct(), Product::Coal);

    TestOre o2(Product::Iron, 3);
    ASSERT_EQ(o2.GetProduct(), Product::Iron);

    TestOre o3(Product::Gold, 3);
    ASSERT_EQ(o3.GetProduct(), Product::Gold);

    TestOre o4(Product::Diamond, 3);
    ASSERT_EQ(o4.GetProduct(), Product::Diamond);

    TestOre o5(Product::Obsidian, 3);
    ASSERT_EQ(o5.GetProduct(), Product::Obsidian);
}

TEST(ORE_TEST, GetDurabilityCost) {
    TestOre o1(Product::Coal, 3);
    ASSERT_EQ(o1.GetDurabilityCost(), 3);

    TestOre o2(Product::Coal, 5);
    ASSERT_EQ(o2.GetDurabilityCost(), 5);

    TestOre o3(Product::Coal, 10);
    ASSERT_EQ(o3.GetDurabilityCost(), 10);
}