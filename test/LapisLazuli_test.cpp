#include <gtest/gtest.h>

#include "Armor.hpp"
#include "LapisLazuli.hpp"

TEST(LapisLazuli, GetMaterial) {
    LapisLazuli lapisLazuli = LapisLazuli();

    auto ll = lapisLazuli.GetMaterial();
    ASSERT_EQ(ll, Material::LapisLazuli);
}
