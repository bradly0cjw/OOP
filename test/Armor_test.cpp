#include "Armor.hpp"
#include <gtest/gtest.h>

TEST(Armor, ArmorTest) {
    Armor armor = Armor(ArmorType::Diamond);

    auto pT = armor.GetArmorType();
    ASSERT_EQ(pT, ArmorType::Diamond);
    ASSERT_EQ(armor.GetEnchantment(),Enchantment::NaN);
}

TEST(Armor, ArmorTest2) {
    Armor armor = Armor(ArmorType::Gold);

    auto pT = armor.GetArmorType();
    ASSERT_EQ(pT, ArmorType::Gold);
    ASSERT_EQ(armor.GetEnchantment(),Enchantment::NaN);
}

TEST(Armor, ArmorTest3) {
    Armor armor = Armor(ArmorType::Iron);

    auto pT = armor.GetArmorType();
    ASSERT_EQ(pT, ArmorType::Iron);
    ASSERT_EQ(armor.GetEnchantment(),Enchantment::NaN);
}

TEST(Armor, ArmorTestWithEnchantment) {
    Armor armor = Armor(ArmorType::Diamond);

    ASSERT_EQ(armor.GetEnchantment(),Enchantment::NaN);

    armor.ApplyEnchantment(Enchantment::Efficiency_I);

    ASSERT_EQ(armor.GetEnchantment(),Enchantment::Efficiency_I);
}
