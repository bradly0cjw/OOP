#include <gtest/gtest.h>
#include "Pickaxe/GoldPickaxe.hpp"
#include "Ore/CoalOre.hpp"
#include "Ore/IronOre.hpp"
#include "Ore/GoldOre.hpp"
#include "Ore/DiamondOre.hpp"
#include "Ore/ObsidianOre.hpp"

TEST(GOLD_PICKAXE_TEST, Constructor) {
    GoldPickaxe p;
    ASSERT_EQ(p.GetPickaxeType(), PickaxeType::Gold);
    ASSERT_EQ(p.GetDurability(), Durability::GoldDurability);
}

TEST(GOLD_PICKAXE_TEST, Mining_Coal) {
    GoldPickaxe p;
    ASSERT_EQ(p.GetDurability(), Durability::GoldDurability);
    std::shared_ptr<Ore> o = std::make_shared<CoalOre>();
    Product product = p.Mining(o);
    ASSERT_EQ(product, Product::Coal);
    ASSERT_EQ(o, nullptr);
    ASSERT_EQ(p.GetDurability(), Durability::GoldDurability - DurabilityCost::CoalDurabilityCost);
}

TEST(GOLD_PICKAXE_TEST, Mining_Many_Coal) {
    GoldPickaxe p;
    ASSERT_EQ(p.GetDurability(), Durability::GoldDurability);
    for (int i = 0; i < 32; i++) {
        std::shared_ptr<Ore> o = std::make_shared<CoalOre>();
        p.Mining(o);
    }
    std::shared_ptr<Ore> o = std::make_shared<CoalOre>();
    ASSERT_THROW(p.Mining(o), std::invalid_argument);
}

TEST(GOLD_PICKAXE_TEST, Mining_Iron) {
    GoldPickaxe p;
    ASSERT_EQ(p.GetDurability(), Durability::GoldDurability);
    std::shared_ptr<Ore> o = std::make_shared<IronOre>();
    Product product = p.Mining(o);
    ASSERT_EQ(product, Product::None);
    ASSERT_EQ(o, nullptr);
    ASSERT_EQ(p.GetDurability(), Durability::GoldDurability - DurabilityCost::IronDurabilityCost);
}

TEST(GOLD_PICKAXE_TEST, Mining_Many_Iron) {
    GoldPickaxe p;
    ASSERT_EQ(p.GetDurability(), Durability::GoldDurability);
    for (int i = 0; i < 10; i++) {
        std::shared_ptr<Ore> o = std::make_shared<IronOre>();
        p.Mining(o);
    }
    std::shared_ptr<Ore> o = std::make_shared<IronOre>();
    ASSERT_THROW(p.Mining(o), std::invalid_argument);
}

TEST(GOLD_PICKAXE_TEST, Mining_Gold) {
    GoldPickaxe p;
    ASSERT_EQ(p.GetDurability(), Durability::GoldDurability);
    std::shared_ptr<Ore> o = std::make_shared<GoldOre>();
    Product product = p.Mining(o);
    ASSERT_EQ(product, Product::None);
    ASSERT_EQ(o, nullptr);
    ASSERT_EQ(p.GetDurability(), Durability::GoldDurability - DurabilityCost::GoldDurabilityCost);
}

TEST(GOLD_PICKAXE_TEST, Mining_Many_Gold) {
    GoldPickaxe p;
    ASSERT_EQ(p.GetDurability(), Durability::GoldDurability);
    for (int i = 0; i < 6; i++) {
        std::shared_ptr<Ore> o = std::make_shared<GoldOre>();
        p.Mining(o);
    }
    std::shared_ptr<Ore> o = std::make_shared<GoldOre>();
    ASSERT_THROW(p.Mining(o), std::invalid_argument);
}

TEST(GOLD_PICKAXE_TEST, Mining_Diamond) {
    GoldPickaxe p;
    ASSERT_EQ(p.GetDurability(), Durability::GoldDurability);
    std::shared_ptr<Ore> o = std::make_shared<DiamondOre>();
    Product product = p.Mining(o);
    ASSERT_EQ(product, Product::None);
    ASSERT_EQ(o, nullptr);
    ASSERT_EQ(p.GetDurability(), Durability::GoldDurability - DurabilityCost::DiamondDurabilityCost);
}

TEST(GOLD_PICKAXE_TEST, Mining_Many_Diamond) {
    GoldPickaxe p;
    ASSERT_EQ(p.GetDurability(), Durability::GoldDurability);
    for (int i = 0; i < 3; i++) {
        std::shared_ptr<Ore> o = std::make_shared<DiamondOre>();
        p.Mining(o);
    }
    std::shared_ptr<Ore> o = std::make_shared<DiamondOre>();
    ASSERT_THROW(p.Mining(o), std::invalid_argument);
}

TEST(GOLD_PICKAXE_TEST, Mining_Obsidian) {
    GoldPickaxe p;
    ASSERT_EQ(p.GetDurability(), Durability::GoldDurability);
    std::shared_ptr<Ore> o = std::make_shared<ObsidianOre>();
    ASSERT_THROW(p.Mining(o), std::invalid_argument);
}

