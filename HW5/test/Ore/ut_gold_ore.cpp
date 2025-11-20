#include <gtest/gtest.h>
#include "Ore/GoldOre.hpp"

TEST(GOLD_ORE_TEST, Constructor) {
    GoldOre o;
    ASSERT_EQ(o.GetProduct(), Product::Gold);
    ASSERT_EQ(o.GetDurabilityCost(), DurabilityCost::GoldDurabilityCost);
}

TEST(GOLD_ORE_TEST, GetBreakExp) {
    GoldOre o;
    ASSERT_EQ(o.GetBreakExp(), BreakExp::GoldBreakExp);
}

TEST(GOLD_ORE_TEST, GetSmeltExp) {
    GoldOre o;
    ASSERT_EQ(o.GetSmeltExp(), SmeltExp::GoldSmeltExp);
}
