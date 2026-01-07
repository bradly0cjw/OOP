#include <gtest/gtest.h>

#include <memory>

#include "LapisLazuliOre.hpp"
#include "Tool.hpp"

TEST(LapisLazuliOre, IsBreakable) {
    LapisLazuliOre ore = LapisLazuliOre();

    ASSERT_EQ(ore.BreakableBy(w), false);
    ASSERT_EQ(ore.BreakableBy(s), true);
    ASSERT_EQ(ore.BreakableBy(i), true);
    ASSERT_EQ(ore.BreakableBy(d), true);
    ASSERT_EQ(ore.BreakableBy(g), false);
}