#include <gtest/gtest.h>

#include "Armor.hpp"
#include "Diamond.hpp"

TEST(Diamond, IsCraftable) {
    Diamond diamond = Diamond();

    auto dd = diamond.GetMaterial();
    ASSERT_EQ(dd, Material::Diamond);
}
