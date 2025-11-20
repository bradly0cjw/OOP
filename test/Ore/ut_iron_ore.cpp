#include <gtest/gtest.h>
#include "Ore/IronOre.hpp"

TEST(IRON_ORE_TEST, Constructor) {
    IronOre o;
    ASSERT_EQ(o.GetProduct(), Product::Iron);
    ASSERT_EQ(o.GetDurabilityCost(), DurabilityCost::IronDurabilityCost);
}

TEST(IRON_ORE_TEST, GetBreakExp) {
    IronOre o;
    ASSERT_EQ(o.GetBreakExp(), BreakExp::IronBreakExp);
}

TEST(IRON_ORE_TEST, GetSmeltExp) {
    IronOre o;
    ASSERT_EQ(o.GetSmeltExp(), SmeltExp::IronSmeltExp);
}
