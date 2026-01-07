#include "Pickaxe.hpp"
#include "Enchantment.hpp"
#include <gtest/gtest.h>

TEST(Pickaxe, PickaxeTest) {
    Pickaxe pickaxe = Pickaxe(PickaxeType::Wood);

    auto pT = pickaxe.GetPickaxeType();
    ASSERT_EQ(pT, PickaxeType::Wood);
    ASSERT_EQ(pickaxe.GetEnchantment(),Enchantment::NaN);
}

TEST(Pickaxe, PickaxeTest2) {
    Pickaxe pickaxe = Pickaxe(PickaxeType::Diamond);

    auto pT = pickaxe.GetPickaxeType();
    ASSERT_EQ(pT, PickaxeType::Diamond);
    ASSERT_EQ(pickaxe.GetEnchantment(),Enchantment::NaN);
}

TEST(Pickaxe, PickaxeTest3) {
    Pickaxe pickaxe = Pickaxe(PickaxeType::Gold);

    auto pT = pickaxe.GetPickaxeType();
    ASSERT_EQ(pT, PickaxeType::Gold);
    ASSERT_EQ(pickaxe.GetEnchantment(),Enchantment::NaN);
}

TEST(Pickaxe, PickaxeTest4) {
    Pickaxe pickaxe = Pickaxe(PickaxeType::Iron);

    auto pT = pickaxe.GetPickaxeType();
    ASSERT_EQ(pT, PickaxeType::Iron);
    ASSERT_EQ(pickaxe.GetEnchantment(),Enchantment::NaN);
}

TEST(Pickaxe, PickaxeTest5) {
    Pickaxe pickaxe = Pickaxe(PickaxeType::Stone);

    auto pT = pickaxe.GetPickaxeType();
    ASSERT_EQ(pT, PickaxeType::Stone);
    ASSERT_EQ(pickaxe.GetEnchantment(),Enchantment::NaN);
}

TEST(Pickaxe, PickaxeTestWithEnchantment) {
    Pickaxe pickaxe = Pickaxe(PickaxeType::Diamond);

    ASSERT_EQ(pickaxe.GetEnchantment(),Enchantment::NaN);

    pickaxe.ApplyEnchantment(Enchantment::Unbreaking_I);

    ASSERT_EQ(pickaxe.GetEnchantment(),Enchantment::Unbreaking_I);
}

TEST(Pickaxe, PickaxeTestWithEnchantment2) {
    Pickaxe pickaxe = Pickaxe(PickaxeType::Diamond);

    ASSERT_EQ(pickaxe.GetEnchantment(),Enchantment::NaN);

    pickaxe.ApplyEnchantment(Enchantment::Unbreaking_II);

    ASSERT_EQ(pickaxe.GetEnchantment(),Enchantment::Unbreaking_II);
}