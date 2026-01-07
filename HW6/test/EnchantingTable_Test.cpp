#include "EnchantingTable.hpp"
#include "Armor.hpp"
#include "LapisLazuli.hpp"
#include "Pickaxe.hpp"
#include <gtest/gtest.h>
#include <memory>

class EnchantingTableTest : public testing::Test {
protected:
    EnchantingTable enchantingTable;
};

TEST_F(EnchantingTableTest, NormalEnchantArmor) {
    std::shared_ptr<Armor> armor = std::make_shared<Armor>(ArmorType::Iron);
    std::shared_ptr<LapisLazuli> ll = std::make_shared<LapisLazuli>();

    enchantingTable.SetEnchantItem(armor);
    enchantingTable.SetConsumeItem(ll);

    enchantingTable.Enchant(Enchantment::Efficiency_II);

    auto ar = enchantingTable.GetOutput();
    auto ans = std::dynamic_pointer_cast<Armor>(ar);

    ASSERT_EQ(ans->GetEnchantment(), Enchantment::Efficiency_II);
}

TEST_F(EnchantingTableTest, EnchantWithoutAnything) {
    ASSERT_THROW(enchantingTable.Enchant(Enchantment::Efficiency_II);, std::invalid_argument);
}

TEST_F(EnchantingTableTest, EnchantWithoutLapisLazuli) {
    std::shared_ptr<Armor> armor = std::make_shared<Armor>(ArmorType::Iron);

    enchantingTable.SetEnchantItem(armor);

    ASSERT_THROW(enchantingTable.Enchant(Enchantment::Efficiency_III), std::invalid_argument);
}

TEST_F(EnchantingTableTest, CraftWithFullOutput) {
    std::shared_ptr<Armor> armor = std::make_shared<Armor>(ArmorType::Diamond);
    std::shared_ptr<Armor> armor2 = std::make_shared<Armor>(ArmorType::Gold);
    std::shared_ptr<LapisLazuli> ll = std::make_shared<LapisLazuli>();
    std::shared_ptr<LapisLazuli> ll2 = std::make_shared<LapisLazuli>();

    enchantingTable.SetEnchantItem(armor);
    enchantingTable.SetConsumeItem(ll);

    enchantingTable.Enchant(Enchantment::Mending);

    enchantingTable.SetEnchantItem(armor2);
    enchantingTable.SetConsumeItem(ll2);

    ASSERT_THROW(enchantingTable.Enchant(Enchantment::Unbreaking_III), std::invalid_argument);
}

TEST_F(EnchantingTableTest, GetEmptyOutput) {
    ASSERT_THROW(enchantingTable.GetOutput(), std::invalid_argument);
}
