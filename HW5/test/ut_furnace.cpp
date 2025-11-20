#include <gtest/gtest.h>

#include "Furnace.hpp"
#include "Ore/CoalOre.hpp"
#include "Ore/IronOre.hpp"
#include "Ore/GoldOre.hpp"
#include "Ore/DiamondOre.hpp"
#include "Ore/ObsidianOre.hpp"

TEST(FURNACE_TEST, PickupProduct) {
    auto furnace = Furnace();
    auto product = furnace.PickupProduct();
    ASSERT_EQ(product.size(), 0);
}

TEST(FURNACE_TEST, AddOre_Iron) {
    auto furnace = Furnace();
    auto ironore = std::make_shared<IronOre>();

    furnace.AddOre(ironore);

    auto product = furnace.PickupProduct();
    ASSERT_EQ(product.front()->GetProduct(), Product::Iron);
}

TEST(FURNACE_TEST, AddOre_Many_Iron) {
    auto furnace = Furnace();

    for(int i = 0 ;i<64; i++) {
        furnace.AddOre(std::make_shared<IronOre>());
    }
    ASSERT_THROW(furnace.AddOre(std::make_shared<IronOre>()), std::invalid_argument);

    auto product = furnace.PickupProduct();
    ASSERT_EQ(product.front()->GetProduct(), Product::Iron);
}

TEST(FURNACE_TEST, AddOre_Gold) {
    auto furnace = Furnace();
    auto goldore = std::make_shared<GoldOre>();

    furnace.AddOre(goldore);

    auto product = furnace.PickupProduct();
    ASSERT_EQ(product.front()->GetProduct(), Product::Gold);
}

TEST(FURNACE_TEST, AddOre_Many_Gold) {
    auto furnace = Furnace();

    for(int i = 0 ;i<64; i++) {
        furnace.AddOre(std::make_shared<GoldOre>());
    }
    ASSERT_THROW(furnace.AddOre(std::make_shared<GoldOre>()), std::invalid_argument);

    auto product = furnace.PickupProduct();
    ASSERT_EQ(product.front()->GetProduct(), Product::Gold);
}

TEST(FURNACE_TEST, AddOre_First_Iron_Second_Gold) {
    auto furnace = Furnace();
    auto goldore = std::make_shared<GoldOre>();
    auto ironore = std::make_shared<IronOre>();

    furnace.AddOre(ironore);
    ASSERT_THROW(furnace.AddOre(goldore), std::invalid_argument);
}

TEST(FURNACE_TEST, AddOre_First_Gold_Second_Iron) {
    auto furnace = Furnace();
    auto goldore = std::make_shared<GoldOre>();
    auto ironore = std::make_shared<IronOre>();

    furnace.AddOre(goldore);
    ASSERT_THROW(furnace.AddOre(ironore), std::invalid_argument);
}

TEST(FURNACE_TEST, AddOre_First_Many_Iron_Second_Many_Gold) {
    auto furnace = Furnace();

    for(int i = 0 ;i<64; i++) {
        furnace.AddOre(std::make_shared<IronOre>());
    }
    ASSERT_THROW(furnace.AddOre(std::make_shared<IronOre>()), std::invalid_argument);
    auto product = furnace.PickupProduct();
    for (const auto &elem: product) {
        ASSERT_EQ(elem->GetProduct(), Product::Iron);
    }

    for(int i = 0 ;i<64; i++) {
        furnace.AddOre(std::make_shared<GoldOre>());
    }
    ASSERT_THROW(furnace.AddOre(std::make_shared<GoldOre>()), std::invalid_argument);

    auto product_gold = furnace.PickupProduct();
    for (const auto &elem: product_gold) {
        ASSERT_EQ(elem->GetProduct(), Product::Gold);
    }
}

TEST(FURNACE_TEST, AddOre_First_Many_Gold_Second_Many_Iron) {
    auto furnace = Furnace();

    for(int i = 0 ;i<64; i++) {
        furnace.AddOre(std::make_shared<GoldOre>());
    }
    ASSERT_THROW(furnace.AddOre(std::make_shared<GoldOre>()), std::invalid_argument);

    auto product_gold = furnace.PickupProduct();
    for (const auto &elem: product_gold) {
        ASSERT_EQ(elem->GetProduct(), Product::Gold);
    }

    for(int i = 0 ;i<64; i++) {
        furnace.AddOre(std::make_shared<IronOre>());
    }
    ASSERT_THROW(furnace.AddOre(std::make_shared<IronOre>()), std::invalid_argument);
    auto product_iron = furnace.PickupProduct();
    for (const auto &elem: product_iron) {
        ASSERT_EQ(elem->GetProduct(), Product::Iron);
    }
}

TEST(FURNACE_TEST, AddAnyOre) {
    auto furnace = Furnace();

    ASSERT_THROW(furnace.AddAnyOre(std::make_shared<CoalOre>()), std::invalid_argument);
    ASSERT_THROW(furnace.AddAnyOre(std::make_shared<DiamondOre>()), std::invalid_argument);
    ASSERT_THROW(furnace.AddAnyOre(std::make_shared<ObsidianOre>()), std::invalid_argument);

    furnace.AddAnyOre(std::make_shared<IronOre>());
    ASSERT_THROW(furnace.AddAnyOre(std::make_shared<GoldOre>()), std::invalid_argument);
    ASSERT_THROW(furnace.AddAnyOre(std::make_shared<CoalOre>()), std::invalid_argument);
    ASSERT_THROW(furnace.AddAnyOre(std::make_shared<DiamondOre>()), std::invalid_argument);
    ASSERT_THROW(furnace.AddAnyOre(std::make_shared<ObsidianOre>()), std::invalid_argument);
    furnace.AddAnyOre(std::make_shared<IronOre>());

    auto product_iron = furnace.PickupProduct();
    ASSERT_EQ(product_iron.front()->GetProduct(), Product::Iron);

    furnace.AddAnyOre(std::make_shared<GoldOre>());
    ASSERT_THROW(furnace.AddAnyOre(std::make_shared<IronOre>()), std::invalid_argument);
    ASSERT_THROW(furnace.AddAnyOre(std::make_shared<CoalOre>()), std::invalid_argument);
    ASSERT_THROW(furnace.AddAnyOre(std::make_shared<DiamondOre>()), std::invalid_argument);
    ASSERT_THROW(furnace.AddAnyOre(std::make_shared<ObsidianOre>()), std::invalid_argument);
    furnace.AddAnyOre(std::make_shared<GoldOre>());

    auto product_gold = furnace.PickupProduct();
    ASSERT_EQ(product_gold.front()->GetProduct(), Product::Gold);
}
TEST(FURNACE_TEST, AddAnyOre_Many_Gold) {
    auto furnace = Furnace();
    for(int i = 0 ;i<64; i++) {
        furnace.AddAnyOre(std::make_shared<GoldOre>());
    }
    ASSERT_THROW(furnace.AddAnyOre(std::make_shared<GoldOre>()), std::invalid_argument);

    auto product_gold = furnace.PickupProduct();
    for (const auto &elem: product_gold) {
        ASSERT_EQ(elem->GetProduct(), Product::Gold);
    }
}

TEST(FURNACE_TEST, AddAnyOre_Many_Iron) {
    auto furnace = Furnace();
    for(int i = 0 ;i<64; i++) {
        furnace.AddAnyOre(std::make_shared<IronOre>());
    }
    ASSERT_THROW(furnace.AddAnyOre(std::make_shared<IronOre>()), std::invalid_argument);

    auto product_gold = furnace.PickupProduct();
    for (const auto &elem: product_gold) {
        ASSERT_EQ(elem->GetProduct(), Product::Iron);
    }
}
