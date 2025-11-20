#include <gtest/gtest.h>
#include "Ore/DiamondOre.hpp"

TEST(DIAMOND_ORE_TEST, Constructor) {
    DiamondOre o;
    ASSERT_EQ(o.GetProduct(), Product::Diamond);
    ASSERT_EQ(o.GetDurabilityCost(), DurabilityCost::DiamondDurabilityCost);
}

TEST(DIAMOND_ORE_TEST, GetBreakExp) {
    DiamondOre o;
    ASSERT_EQ(o.GetBreakExp(), BreakExp::DiamondBreakExp);
}
