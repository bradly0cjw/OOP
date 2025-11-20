#include <gtest/gtest.h>
#include "Ore/CoalOre.hpp"

TEST(COAL_ORE_TEST, Constructor) {
    CoalOre o;
    ASSERT_EQ(o.GetProduct(), Product::Coal);
    ASSERT_EQ(o.GetDurabilityCost(), DurabilityCost::CoalDurabilityCost);
}

TEST(COAL_ORE_TEST, GetBreakExp) {
    CoalOre o;
    ASSERT_EQ(o.GetBreakExp(), BreakExp::CoalBreakExp);
}
