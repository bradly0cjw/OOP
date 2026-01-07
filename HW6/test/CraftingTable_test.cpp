#include "Armor.hpp"
#include "CraftingTable.hpp"
#include "LapisLazuli.hpp"
#include "Ingot.hpp"
#include "Stick.hpp"
#include "Diamond.hpp"
#include <gtest/gtest.h>
#include <memory>

class CraftingTableTest : public testing::Test {
protected:
    CraftingTable craftingTable;
};

TEST_F(CraftingTableTest, NormalCraftArmor) {
    std::shared_ptr<Ingot> ingot = std::make_shared<Ingot>(Material::Gold);

    craftingTable.SetCraftInput(ingot);

    craftingTable.Craft();

    auto armor = craftingTable.GetOutput();
    auto ar = std::dynamic_pointer_cast<Armor>(armor);

    ASSERT_EQ(ar->GetArmorType(), ArmorType::Gold);
}

TEST_F(CraftingTableTest, NormalCraftPickaxe) {
    std::shared_ptr<Ingot> ingot = std::make_shared<Ingot>(Material::Diamond);
    std::shared_ptr<Stick> stick = std::make_shared<Stick>();

    craftingTable.SetCraftInput(ingot);
    craftingTable.SetMaterialInput(stick);

    craftingTable.Craft();

    auto pickaxe = craftingTable.GetOutput();
    auto pa = std::dynamic_pointer_cast<Pickaxe>(pickaxe);

    ASSERT_EQ(pa->GetPickaxeType(), PickaxeType::Diamond);
}

TEST_F(CraftingTableTest, CraftWithoutInput) {
    ASSERT_THROW(craftingTable.Craft(), std::invalid_argument);
}
TEST_F(CraftingTableTest, CraftWithoutIngot) {
    std::shared_ptr<Stick> stick = std::make_shared<Stick>();
    craftingTable.SetMaterialInput(stick);
    ASSERT_THROW(craftingTable.Craft(), std::invalid_argument);
}

TEST_F(CraftingTableTest, CraftWithFullOutput) {
    std::shared_ptr<Ingot> goldIngot = std::make_shared<Ingot>(Material::Gold);
    std::shared_ptr<Ingot> ironIngot = std::make_shared<Ingot>(Material::Iron);

    craftingTable.SetCraftInput(goldIngot);

    craftingTable.Craft();

    craftingTable.SetCraftInput(ironIngot);

    ASSERT_THROW(craftingTable.Craft(), std::invalid_argument);
}

TEST_F(CraftingTableTest, ThrowErrorWithCraftItem) {
    std::shared_ptr<LapisLazuli> lapisLazuli = std::make_shared<LapisLazuli>();
    std::shared_ptr<Ingot> copperIngot = std::make_shared<Ingot>(Material::Copper);

    ASSERT_THROW(craftingTable.SetCraftInput(copperIngot), std::invalid_argument);
    ASSERT_THROW(craftingTable.SetCraftInput(lapisLazuli), std::invalid_argument);
}

TEST_F(CraftingTableTest, ThrowErrorWithCraftItemTwo) {
    std::shared_ptr<Stick> stick = std::make_shared<Stick>();

    ASSERT_THROW(craftingTable.SetCraftInput(stick);, std::invalid_argument);
}

TEST_F(CraftingTableTest, ThrowErrorWithMaterial) {
    std::shared_ptr<Ingot> goldIngot = std::make_shared<Ingot>(Material::Gold);
    std::shared_ptr<Ingot> ironIngot = std::make_shared<Ingot>(Material::Iron);
    std::shared_ptr<LapisLazuli> lapisLazuli = std::make_shared<LapisLazuli>();
    std::shared_ptr<Ingot> copperIngot = std::make_shared<Ingot>(Material::Copper);
    std::shared_ptr<Diamond> diamond = std::make_shared<Diamond>();

    ASSERT_THROW(craftingTable.SetMaterialInput(goldIngot), std::invalid_argument);
    ASSERT_THROW(craftingTable.SetMaterialInput(ironIngot), std::invalid_argument);
    ASSERT_THROW(craftingTable.SetMaterialInput(lapisLazuli), std::invalid_argument);
    ASSERT_THROW(craftingTable.SetMaterialInput(copperIngot), std::invalid_argument);
    ASSERT_THROW(craftingTable.SetMaterialInput(diamond), std::invalid_argument);
}

TEST_F(CraftingTableTest, GetEmptyOutput) {
    ASSERT_THROW(craftingTable.GetOutput(), std::invalid_argument);
}
