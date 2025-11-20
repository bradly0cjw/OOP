#include <gtest/gtest.h>
#include "Pickaxe/WoodenPickaxe.hpp"
#include "Ore/CoalOre.hpp"
#include "Ore/IronOre.hpp"
#include "Ore/GoldOre.hpp"
#include "Ore/DiamondOre.hpp"
#include "Ore/ObsidianOre.hpp"

TEST(WOODEN_PICKAXE_TEST, Constructor) {
    WoodenPickaxe p;
    ASSERT_EQ(p.GetPickaxeType(), PickaxeType::Wooden);
    ASSERT_EQ(p.GetDurability(), Durability::WoodenDurability);
}

TEST(WOODEN_PICKAXE_TEST, Mining_Coal) {
    WoodenPickaxe p;
    ASSERT_EQ(p.GetDurability(), Durability::WoodenDurability);
    std::shared_ptr<Ore> o = std::make_shared<CoalOre>();
    Product product = p.Mining(o);
    ASSERT_EQ(product, Product::Coal);
    ASSERT_EQ(o, nullptr);
    ASSERT_EQ(p.GetDurability(), Durability::WoodenDurability - DurabilityCost::CoalDurabilityCost);
}

TEST(WOODEN_PICKAXE_TEST, Mining_Many_Coal) {
    WoodenPickaxe p;
    ASSERT_EQ(p.GetDurability(), Durability::WoodenDurability);
    for (int i = 0; i < 59; i++) {
        std::shared_ptr<Ore> o = std::make_shared<CoalOre>();
        p.Mining(o);
    }
    std::shared_ptr<Ore> o = std::make_shared<CoalOre>();
    ASSERT_THROW(p.Mining(o), std::invalid_argument);
}

TEST(WOODEN_PICKAXE_TEST, Mining_Iron) {
    WoodenPickaxe p;
    ASSERT_EQ(p.GetDurability(), Durability::WoodenDurability);
    std::shared_ptr<Ore> o = std::make_shared<IronOre>();
    Product product = p.Mining(o);
    ASSERT_EQ(product, Product::None);
    ASSERT_EQ(o, nullptr);
    ASSERT_EQ(p.GetDurability(), Durability::WoodenDurability - DurabilityCost::IronDurabilityCost);
}

TEST(WOODEN_PICKAXE_TEST, Mining_Many_Iron) {
    WoodenPickaxe p;
    ASSERT_EQ(p.GetDurability(), Durability::WoodenDurability);
    for (int i = 0; i < 19; i++) {
        std::shared_ptr<Ore> o = std::make_shared<IronOre>();
        p.Mining(o);
    }
    std::shared_ptr<Ore> o = std::make_shared<IronOre>();
    ASSERT_THROW(p.Mining(o), std::invalid_argument);
}

TEST(WOODEN_PICKAXE_TEST, Mining_Gold) {
    WoodenPickaxe p;
    ASSERT_EQ(p.GetDurability(), Durability::WoodenDurability);
    std::shared_ptr<Ore> o = std::make_shared<GoldOre>();
    Product product = p.Mining(o);
    ASSERT_EQ(product, Product::None);
    ASSERT_EQ(o, nullptr);
    ASSERT_EQ(p.GetDurability(), Durability::WoodenDurability - DurabilityCost::GoldDurabilityCost);
}

TEST(WOODEN_PICKAXE_TEST, Mining_Many_Gold) {
    WoodenPickaxe p;
    ASSERT_EQ(p.GetDurability(), Durability::WoodenDurability);
    for (int i = 0; i < 11; i++) {
        std::shared_ptr<Ore> o = std::make_shared<GoldOre>();
        p.Mining(o);
    }
    std::shared_ptr<Ore> o = std::make_shared<GoldOre>();
    ASSERT_THROW(p.Mining(o), std::invalid_argument);
}

TEST(WOODEN_PICKAXE_TEST, Mining_Diamond) {
    WoodenPickaxe p;
    ASSERT_EQ(p.GetDurability(), Durability::WoodenDurability);
    std::shared_ptr<Ore> o = std::make_shared<DiamondOre>();
    Product product = p.Mining(o);
    ASSERT_EQ(product, Product::None);
    ASSERT_EQ(o, nullptr);
    ASSERT_EQ(p.GetDurability(), Durability::WoodenDurability - DurabilityCost::DiamondDurabilityCost);
}

TEST(WOODEN_PICKAXE_TEST, Mining_Many_Diamond) {
    WoodenPickaxe p;
    ASSERT_EQ(p.GetDurability(), Durability::WoodenDurability);
    for (int i = 0; i < 5; i++) {
        std::shared_ptr<Ore> o = std::make_shared<DiamondOre>();
        p.Mining(o);
    }
    std::shared_ptr<Ore> o = std::make_shared<DiamondOre>();
    ASSERT_THROW(p.Mining(o), std::invalid_argument);
}

TEST(WOODEN_PICKAXE_TEST, Mining_Obsidian) {
    WoodenPickaxe p;
    ASSERT_EQ(p.GetDurability(), Durability::WoodenDurability);
    std::shared_ptr<Ore> o = std::make_shared<ObsidianOre>();
    ASSERT_THROW(p.Mining(o), std::invalid_argument);
}

