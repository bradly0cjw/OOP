#include <gtest/gtest.h>

#include <memory>

#include "Ingot.hpp"
#include "IronOre.hpp"
#include "Tool.hpp"

TEST(IronOre, IsBreakable) {
    IronOre ore = IronOre();

    ASSERT_EQ(ore.BreakableBy(w), false);
    ASSERT_EQ(ore.BreakableBy(s), true);
    ASSERT_EQ(ore.BreakableBy(i), true);
    ASSERT_EQ(ore.BreakableBy(d), true);
    ASSERT_EQ(ore.BreakableBy(g), false);
}

TEST(IronOre, IsSmeltable) {
    IronOre ore = IronOre();

    auto ingot = ore.Smelt();
    ASSERT_EQ(ingot->GetMaterial(), Material::Iron);
}
