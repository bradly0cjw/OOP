#include <gtest/gtest.h>
#include "Ore/SmeltableOre.hpp"

class TestSmeltableOre : public SmeltableOre {
public:
    TestSmeltableOre(Product product, int durabilityCost)
        : SmeltableOre(product, durabilityCost) {}

    float GetBreakExp() override {
        return 0;
    }
    float GetSmeltExp() override {
        return 0;
    }
};

TEST(SMELTABLE_ORE_TEST, Constructor) {
    ASSERT_THROW(TestSmeltableOre o(Product::None, 3), std::invalid_argument);
    ASSERT_NO_THROW(TestSmeltableOre o(Product::Coal, 3));
    ASSERT_NO_THROW(TestSmeltableOre o(Product::Iron, 3));
    ASSERT_NO_THROW(TestSmeltableOre o(Product::Gold, 3));
    ASSERT_NO_THROW(TestSmeltableOre o(Product::Diamond, 3));
    ASSERT_NO_THROW(TestSmeltableOre o(Product::Obsidian, 3));
}

TEST(SMELTABLE_ORE_TEST, GetProduct) {
    TestSmeltableOre o1(Product::Coal, 3);
    ASSERT_EQ(o1.GetProduct(), Product::Coal);

    TestSmeltableOre o2(Product::Iron, 3);
    ASSERT_EQ(o2.GetProduct(), Product::Iron);

    TestSmeltableOre o3(Product::Gold, 3);
    ASSERT_EQ(o3.GetProduct(), Product::Gold);

    TestSmeltableOre o4(Product::Diamond, 3);
    ASSERT_EQ(o4.GetProduct(), Product::Diamond);

    TestSmeltableOre o5(Product::Obsidian, 3);
    ASSERT_EQ(o5.GetProduct(), Product::Obsidian);
}

TEST(SMELTABLE_ORE_TEST, GetDurabilityCost) {
    TestSmeltableOre o1(Product::Coal, 3);
    ASSERT_EQ(o1.GetDurabilityCost(), 3);

    TestSmeltableOre o2(Product::Coal, 5);
    ASSERT_EQ(o2.GetDurabilityCost(), 5);

    TestSmeltableOre o3(Product::Coal, 10);
    ASSERT_EQ(o3.GetDurabilityCost(), 10);
}