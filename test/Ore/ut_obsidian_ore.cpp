#include <gtest/gtest.h>
#include "Ore/ObsidianOre.hpp"

TEST(OBSIDIAN_ORE_TEST, Constructor) {
    ObsidianOre o;
    ASSERT_EQ(o.GetProduct(), Product::Obsidian);
    ASSERT_EQ(o.GetDurabilityCost(), DurabilityCost::ObsidianDurabilityCost);
}

TEST(OBSIDIAN_ORE_TEST, GetBreakExp) {
    ObsidianOre o;
    ASSERT_EQ(o.GetBreakExp(), BreakExp::ObsidianBreakExp);
}
