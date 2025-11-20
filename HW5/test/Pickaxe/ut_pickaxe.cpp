#include <gtest/gtest.h>
#include "Pickaxe/Pickaxe.hpp"

class TestPickaxe : public Pickaxe {
public:
    TestPickaxe(PickaxeType pickaxeType, int durability)
        : Pickaxe(pickaxeType, durability) {}
    
    Product Mining(std::shared_ptr<Ore> &ore) override {
        return Product::None;
    }
};

TEST(PICKAXE_TEST, Constructor) {
    ASSERT_NO_THROW(TestPickaxe p(PickaxeType::Wooden, 3));
    ASSERT_NO_THROW(TestPickaxe p(PickaxeType::Stone, 3));
    ASSERT_NO_THROW(TestPickaxe p(PickaxeType::Iron, 3));
    ASSERT_NO_THROW(TestPickaxe p(PickaxeType::Gold, 3));
    ASSERT_NO_THROW(TestPickaxe p(PickaxeType::Diamond, 3));
}

TEST(PICKAXE_TEST, GetPickaxeType) {
    TestPickaxe p1(PickaxeType::Wooden, 3);
    ASSERT_EQ(p1.GetPickaxeType(), PickaxeType::Wooden);

    TestPickaxe p2(PickaxeType::Stone, 3);
    ASSERT_EQ(p2.GetPickaxeType(), PickaxeType::Stone);

    TestPickaxe p3(PickaxeType::Iron, 3);
    ASSERT_EQ(p3.GetPickaxeType(), PickaxeType::Iron);

    TestPickaxe p4(PickaxeType::Gold, 3);
    ASSERT_EQ(p4.GetPickaxeType(), PickaxeType::Gold);

    TestPickaxe p5(PickaxeType::Diamond, 3);
    ASSERT_EQ(p5.GetPickaxeType(), PickaxeType::Diamond);
}

TEST(PICKAXE_TEST, GetDurability) {
    TestPickaxe p1(PickaxeType::Wooden, 3);
    ASSERT_EQ(p1.GetDurability(), 3);

    TestPickaxe p2(PickaxeType::Wooden, 5);
    ASSERT_EQ(p2.GetDurability(), 5);

    TestPickaxe p3(PickaxeType::Wooden, 10);
    ASSERT_EQ(p3.GetDurability(), 10);
}
