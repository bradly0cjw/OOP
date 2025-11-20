#include <gtest/gtest.h>
#include "Pickaxe/IronPickaxe.hpp"
#include "Ore/CoalOre.hpp"
#include "Ore/IronOre.hpp"
#include "Ore/GoldOre.hpp"
#include "Ore/DiamondOre.hpp"
#include "Ore/ObsidianOre.hpp"

TEST(IRON_PICKAXE_TEST, Constructor) {
    IronPickaxe p;
    ASSERT_EQ(p.GetPickaxeType(), PickaxeType::Iron);
    ASSERT_EQ(p.GetDurability(), Durability::IronDurability);
}

TEST(IRON_PICKAXE_TEST, Mining_Coal) {
    IronPickaxe p;
    ASSERT_EQ(p.GetDurability(), Durability::IronDurability);
    std::shared_ptr<Ore> o = std::make_shared<CoalOre>();
    Product product = p.Mining(o);
    ASSERT_EQ(product, Product::Coal);
    ASSERT_EQ(o, nullptr);
    ASSERT_EQ(p.GetDurability(), Durability::IronDurability - DurabilityCost::CoalDurabilityCost);
}

TEST(IRON_PICKAXE_TEST, Mining_Many_Coal) {
    IronPickaxe p;
    ASSERT_EQ(p.GetDurability(), Durability::IronDurability);
    for (int i = 0; i < 250; i++) {
        std::shared_ptr<Ore> o = std::make_shared<CoalOre>();
        p.Mining(o);
    }
    std::shared_ptr<Ore> o = std::make_shared<CoalOre>();
    ASSERT_THROW(p.Mining(o), std::invalid_argument);
}

TEST(IRON_PICKAXE_TEST, Mining_Iron) {
    IronPickaxe p;
    ASSERT_EQ(p.GetDurability(), Durability::IronDurability);
    std::shared_ptr<Ore> o = std::make_shared<IronOre>();
    Product product = p.Mining(o);
    ASSERT_EQ(product, Product::Iron);
    ASSERT_EQ(o, nullptr);
    ASSERT_EQ(p.GetDurability(), Durability::IronDurability - DurabilityCost::IronDurabilityCost);
}

TEST(IRON_PICKAXE_TEST, Mining_Many_Iron) {
    IronPickaxe p;
    ASSERT_EQ(p.GetDurability(), Durability::IronDurability);
    for (int i = 0; i < 83; i++) {
        std::shared_ptr<Ore> o = std::make_shared<IronOre>();
        p.Mining(o);
    }
    std::shared_ptr<Ore> o = std::make_shared<IronOre>();
    ASSERT_THROW(p.Mining(o), std::invalid_argument);
}

TEST(IRON_PICKAXE_TEST, Mining_Gold) {
    IronPickaxe p;
    ASSERT_EQ(p.GetDurability(), Durability::IronDurability);
    std::shared_ptr<Ore> o = std::make_shared<GoldOre>();
    Product product = p.Mining(o);
    ASSERT_EQ(product, Product::Gold);
    ASSERT_EQ(o, nullptr);
    ASSERT_EQ(p.GetDurability(), Durability::IronDurability - DurabilityCost::GoldDurabilityCost);
}

TEST(IRON_PICKAXE_TEST, Mining_Many_Gold) {
    IronPickaxe p;
    ASSERT_EQ(p.GetDurability(), Durability::IronDurability);
    for (int i = 0; i < 50; i++) {
        std::shared_ptr<Ore> o = std::make_shared<GoldOre>();
        p.Mining(o);
    }
    std::shared_ptr<Ore> o = std::make_shared<GoldOre>();
    ASSERT_THROW(p.Mining(o), std::invalid_argument);
}

TEST(IRON_PICKAXE_TEST, Mining_Diamond) {
    IronPickaxe p;
    ASSERT_EQ(p.GetDurability(), Durability::IronDurability);
    std::shared_ptr<Ore> o = std::make_shared<DiamondOre>();
    Product product = p.Mining(o);
    ASSERT_EQ(product, Product::Diamond);
    ASSERT_EQ(o, nullptr);
    ASSERT_EQ(p.GetDurability(), Durability::IronDurability - DurabilityCost::DiamondDurabilityCost);
}

TEST(IRON_PICKAXE_TEST, Mining_Many_Diamond) {
    IronPickaxe p;
    ASSERT_EQ(p.GetDurability(), Durability::IronDurability);
    for (int i = 0; i < 25; i++) {
        std::shared_ptr<Ore> o = std::make_shared<DiamondOre>();
        p.Mining(o);
    }
    std::shared_ptr<Ore> o = std::make_shared<DiamondOre>();
    ASSERT_THROW(p.Mining(o), std::invalid_argument);
}
TEST(IRON_PICKAXE_TEST, Mining_Obsidian) {
    IronPickaxe p;
    ASSERT_EQ(p.GetDurability(), Durability::IronDurability);
    std::shared_ptr<Ore> o = std::make_shared<ObsidianOre>();
    Product product = p.Mining(o);
    ASSERT_EQ(product, Product::None);
    ASSERT_EQ(o, nullptr);
    ASSERT_EQ(p.GetDurability(), Durability::IronDurability - DurabilityCost::ObsidianDurabilityCost);
}

TEST(IRON_PICKAXE_TEST, Mining_Many_Obsidian) {
    IronPickaxe p;
    ASSERT_EQ(p.GetDurability(), Durability::IronDurability);
    for (int i = 0; i < 6; i++) {
        std::shared_ptr<Ore> o = std::make_shared<ObsidianOre>();
        p.Mining(o);
    }
    std::shared_ptr<Ore> o = std::make_shared<ObsidianOre>();
    ASSERT_THROW(p.Mining(o), std::invalid_argument);
}
