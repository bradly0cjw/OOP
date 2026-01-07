#include <gtest/gtest.h>

#include <memory>

#include "CopperOre.hpp"
#include "Ingot.hpp"
#include "Tool.hpp"

TEST(CopperOre, IsBreakable) {
    CopperOre ore = CopperOre();

    ASSERT_EQ(ore.BreakableBy(w), false);
    ASSERT_EQ(ore.BreakableBy(s), true);
    ASSERT_EQ(ore.BreakableBy(i), true);
    ASSERT_EQ(ore.BreakableBy(d), true);
    ASSERT_EQ(ore.BreakableBy(g), false);
}

TEST(CopperOre, IsSmeltable) {
    CopperOre ore = CopperOre();

    auto ingot = ore.Smelt();
    ASSERT_EQ(ingot->GetMaterial(), Material::Copper);
}
