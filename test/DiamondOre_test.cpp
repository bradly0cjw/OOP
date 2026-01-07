#include <gtest/gtest.h>

#include "DiamondOre.hpp"
#include "Tool.hpp"

TEST(DiamondOre, IsBreakable) {
    DiamondOre ore = DiamondOre();

    ASSERT_EQ(ore.BreakableBy(w), false);
    ASSERT_EQ(ore.BreakableBy(s), false);
    ASSERT_EQ(ore.BreakableBy(i), true);
    ASSERT_EQ(ore.BreakableBy(d), true);
    ASSERT_EQ(ore.BreakableBy(g), false);
}
