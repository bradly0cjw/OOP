#include <gtest/gtest.h>
#include "Pickaxe/DiamondPickaxe.hpp"
#include "Ore/CoalOre.hpp"
#include "Ore/IronOre.hpp"
#include "Ore/GoldOre.hpp"
#include "Ore/DiamondOre.hpp"
#include "Ore/ObsidianOre.hpp"

TEST(DIAMOND_PICKAXE_TEST, Constructor) {
    DiamondPickaxe p;
    ASSERT_EQ(p.GetPickaxeType(), PickaxeType::Diamond);
    ASSERT_EQ(p.GetDurability(), Durability::DiamondDurability);
}

TEST(DIAMOND_PICKAXE_TEST, Mining_Coal) {
    DiamondPickaxe p;
    ASSERT_EQ(p.GetDurability(), Durability::DiamondDurability);
    std::shared_ptr<Ore> o = std::make_shared<CoalOre>();
    Product product = p.Mining(o);
    ASSERT_EQ(product, Product::Coal);
    ASSERT_EQ(o, nullptr);
    ASSERT_EQ(p.GetDurability(), Durability::DiamondDurability - DurabilityCost::CoalDurabilityCost);
}

TEST(DIAMOND_PICKAXE_TEST, Mining_Many_Coal) {
    DiamondPickaxe p;
    ASSERT_EQ(p.GetDurability(), Durability::DiamondDurability);
    for (int i = 0; i < 1561; i++) {
        std::shared_ptr<Ore> o = std::make_shared<CoalOre>();
        p.Mining(o);
    }
    std::shared_ptr<Ore> o = std::make_shared<CoalOre>();
    ASSERT_THROW(p.Mining(o), std::invalid_argument);
}

TEST(DIAMOND_PICKAXE_TEST, Mining_Iron) {
    DiamondPickaxe p;
    ASSERT_EQ(p.GetDurability(), Durability::DiamondDurability);
    std::shared_ptr<Ore> o = std::make_shared<IronOre>();
    Product product = p.Mining(o);
    ASSERT_EQ(product, Product::Iron);
    ASSERT_EQ(o, nullptr);
    ASSERT_EQ(p.GetDurability(), Durability::DiamondDurability - DurabilityCost::IronDurabilityCost);
}

TEST(DIAMOND_PICKAXE_TEST, Mining_Many_Iron) {
    DiamondPickaxe p;
    ASSERT_EQ(p.GetDurability(), Durability::DiamondDurability);
    for (int i = 0; i < 520; i++) {
        std::shared_ptr<Ore> o = std::make_shared<IronOre>();
        p.Mining(o);
    }
    std::shared_ptr<Ore> o = std::make_shared<IronOre>();
    ASSERT_THROW(p.Mining(o), std::invalid_argument);
}

TEST(DIAMOND_PICKAXE_TEST, Mining_Diamond) {
    DiamondPickaxe p;
    ASSERT_EQ(p.GetDurability(), Durability::DiamondDurability);
    std::shared_ptr<Ore> o = std::make_shared<DiamondOre>();
    Product product = p.Mining(o);
    ASSERT_EQ(product, Product::Diamond);
    ASSERT_EQ(o, nullptr);
    ASSERT_EQ(p.GetDurability(), Durability::DiamondDurability - DurabilityCost::DiamondDurabilityCost);
}

TEST(DIAMOND_PICKAXE_TEST, Mining_Many_Diamond) {
    DiamondPickaxe p;
    ASSERT_EQ(p.GetDurability(), Durability::DiamondDurability);
    for (int i = 0; i < 156; i++) {
        std::shared_ptr<Ore> o = std::make_shared<DiamondOre>();
        p.Mining(o);
    }
    std::shared_ptr<Ore> o = std::make_shared<DiamondOre>();
    ASSERT_THROW(p.Mining(o), std::invalid_argument);
}

TEST(DIAMOND_PICKAXE_TEST, Mining_Obsidian) {
    DiamondPickaxe p;
    ASSERT_EQ(p.GetDurability(), Durability::DiamondDurability);
    std::shared_ptr<Ore> o = std::make_shared<ObsidianOre>();
    Product product = p.Mining(o);
    ASSERT_EQ(product, Product::Obsidian);
    ASSERT_EQ(o, nullptr);
    ASSERT_EQ(p.GetDurability(), Durability::DiamondDurability - DurabilityCost::ObsidianDurabilityCost);
}

TEST(DIAMOND_PICKAXE_TEST, Mining_Many_Obsidian) {
    DiamondPickaxe p;
    ASSERT_EQ(p.GetDurability(), Durability::DiamondDurability);
    for (int i = 0; i < 39; i++) {
        std::shared_ptr<Ore> o = std::make_shared<ObsidianOre>();
        p.Mining(o);
    }
    std::shared_ptr<Ore> o = std::make_shared<ObsidianOre>();
    ASSERT_THROW(p.Mining(o), std::invalid_argument);
}
