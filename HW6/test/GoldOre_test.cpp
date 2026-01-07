#include <gtest/gtest.h>

#include <memory>

#include "Ingot.hpp"
#include "GoldOre.hpp"
#include "Tool.hpp"

TEST(GoldOre, IsBreakable) {
    GoldOre ore = GoldOre();

    ASSERT_EQ(ore.BreakableBy(w), false);
    ASSERT_EQ(ore.BreakableBy(s), false);
    ASSERT_EQ(ore.BreakableBy(i), true);
    ASSERT_EQ(ore.BreakableBy(d), true);
    ASSERT_EQ(ore.BreakableBy(g), false);
}

TEST(GoldOre, IsSmeltable) {
    GoldOre ore = GoldOre();

    auto ingot = ore.Smelt();
    ASSERT_EQ(ingot->GetMaterial(), Material::Gold);
}
