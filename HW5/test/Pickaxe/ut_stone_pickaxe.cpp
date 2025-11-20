#include <gtest/gtest.h>
#include "Pickaxe/StonePickaxe.hpp"
#include "Ore/CoalOre.hpp"
#include "Ore/IronOre.hpp"
#include "Ore/GoldOre.hpp"
#include "Ore/DiamondOre.hpp"
#include "Ore/ObsidianOre.hpp"

TEST(STONE_PICKAXE_TEST, Constructor) {
    StonePickaxe p;
    ASSERT_EQ(p.GetPickaxeType(), PickaxeType::Stone);
    ASSERT_EQ(p.GetDurability(), Durability::StoneDurability);
}

TEST(STONE_PICKAXE_TEST, Mining_Coal) {
    StonePickaxe p;
    ASSERT_EQ(p.GetDurability(), Durability::StoneDurability);
    std::shared_ptr<Ore> o = std::make_shared<CoalOre>();
    Product product = p.Mining(o);
    ASSERT_EQ(product, Product::Coal);
    ASSERT_EQ(o, nullptr);
    ASSERT_EQ(p.GetDurability(), Durability::StoneDurability - DurabilityCost::CoalDurabilityCost);
}

TEST(STONE_PICKAXE_TEST, Mining_Many_Coal) {
    StonePickaxe p;
    ASSERT_EQ(p.GetDurability(), Durability::StoneDurability);
    for (int i = 0; i < 131; i++) {
        std::shared_ptr<Ore> o = std::make_shared<CoalOre>();
        p.Mining(o);
    }
    std::shared_ptr<Ore> o = std::make_shared<CoalOre>();
    ASSERT_THROW(p.Mining(o), std::invalid_argument);
}

TEST(STONE_PICKAXE_TEST, Mining_Iron) {
    StonePickaxe p;
    ASSERT_EQ(p.GetDurability(), Durability::StoneDurability);
    std::shared_ptr<Ore> o = std::make_shared<IronOre>();
    Product product = p.Mining(o);
    ASSERT_EQ(product, Product::Iron);
    ASSERT_EQ(o, nullptr);
    ASSERT_EQ(p.GetDurability(), Durability::StoneDurability - DurabilityCost::IronDurabilityCost);
}

TEST(STONE_PICKAXE_TEST, Mining_Many_Iron) {
    StonePickaxe p;
    ASSERT_EQ(p.GetDurability(), Durability::StoneDurability);
    for (int i = 0; i < 43; i++) {
        std::shared_ptr<Ore> o = std::make_shared<IronOre>();
        p.Mining(o);
    }
    std::shared_ptr<Ore> o = std::make_shared<IronOre>();
    ASSERT_THROW(p.Mining(o), std::invalid_argument);
}

TEST(STONE_PICKAXE_TEST, Mining_Gold) {
    StonePickaxe p;
    ASSERT_EQ(p.GetDurability(), Durability::StoneDurability);
    std::shared_ptr<Ore> o = std::make_shared<GoldOre>();
    Product product = p.Mining(o);
    ASSERT_EQ(product, Product::None);
    ASSERT_EQ(o, nullptr);
    ASSERT_EQ(p.GetDurability(), Durability::StoneDurability - DurabilityCost::GoldDurabilityCost);
}

TEST(STONE_PICKAXE_TEST, Mining_Many_Gold) {
    StonePickaxe p;
    ASSERT_EQ(p.GetDurability(), Durability::StoneDurability);
    for (int i = 0; i < 26; i++) {
        std::shared_ptr<Ore> o = std::make_shared<GoldOre>();
        p.Mining(o);
    }
    std::shared_ptr<Ore> o = std::make_shared<GoldOre>();
    ASSERT_THROW(p.Mining(o), std::invalid_argument);
}

TEST(STONE_PICKAXE_TEST, Mining_Diamond) {
    StonePickaxe p;
    ASSERT_EQ(p.GetDurability(), Durability::StoneDurability);
    std::shared_ptr<Ore> o = std::make_shared<DiamondOre>();
    Product product = p.Mining(o);
    ASSERT_EQ(product, Product::None);
    ASSERT_EQ(o, nullptr);
    ASSERT_EQ(p.GetDurability(), Durability::StoneDurability - DurabilityCost::DiamondDurabilityCost);
}

TEST(STONE_PICKAXE_TEST, Mining_Many_Diamond) {
    StonePickaxe p;
    ASSERT_EQ(p.GetDurability(), Durability::StoneDurability);
    for (int i = 0; i < 13; i++) {
        std::shared_ptr<Ore> o = std::make_shared<DiamondOre>();
        p.Mining(o);
    }
    std::shared_ptr<Ore> o = std::make_shared<DiamondOre>();
    ASSERT_THROW(p.Mining(o), std::invalid_argument);
}

TEST(STONE_PICKAXE_TEST, Mining_Obsidian) {
    StonePickaxe p;
    ASSERT_EQ(p.GetDurability(), Durability::StoneDurability);
    std::shared_ptr<Ore> o = std::make_shared<ObsidianOre>();
    ASSERT_THROW(p.Mining(o), std::invalid_argument);
}
