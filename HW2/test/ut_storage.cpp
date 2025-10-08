#include "gtest/gtest.h"
#include "Storage.hpp"

TEST(StorageTest, test_construct_with_type) {
    Storage storage = Storage(StorageType::CAKE);

    ASSERT_EQ(StorageType::CAKE, storage.getType());
    ASSERT_EQ(0, storage.getAmount());
    ASSERT_EQ(10, storage.getCapacity());
}

TEST(StorageTest, test_construct_with_type_and_capacity) {
    Storage storage = Storage(StorageType::CAKE, 15);

    ASSERT_EQ(StorageType::CAKE, storage.getType());
    ASSERT_EQ(0, storage.getAmount());
    ASSERT_EQ(15, storage.getCapacity());
}

TEST(StorageTest, test_add_snack_with_name) {
    Storage storage = Storage(StorageType::CANDY, 5);
    storage.add("KitKat");

    ASSERT_EQ(1, storage.getSnacks().size());
    ASSERT_EQ(1, storage.getAmount());
    ASSERT_EQ(1, storage.getSnacks()[0].getAmount());
    ASSERT_EQ("KitKat", storage.getSnacks()[0].getName());
}

TEST(StorageTest, test_add_snack_with_name_twice) {
    Storage storage = Storage(StorageType::CANDY, 5);
    storage.add("KitKat");
    storage.add("KitKat");

    ASSERT_EQ(1, storage.getSnacks().size());
    ASSERT_EQ(2, storage.getAmount());
    ASSERT_EQ(2, storage.getSnacks()[0].getAmount());
    ASSERT_EQ("KitKat", storage.getSnacks()[0].getName());
}

TEST(StorageTest, test_add_snack_overflow_with_name) {
    Storage storage = Storage(StorageType::CAKE, 2);
    storage.add("CheeseCake", 2);

    ASSERT_THROW(storage.add("Brownie"), std::invalid_argument);
}

TEST(StorageTest, test_add_snack_with_name_and_amount) {
    Storage storage = Storage(StorageType::CANDY, 5);
    storage.add("Oreo", 2);

    ASSERT_EQ(1, storage.getSnacks().size());
    ASSERT_EQ(2, storage.getAmount());
    ASSERT_EQ(2, storage.getSnacks()[0].getAmount());
    ASSERT_EQ("Oreo", storage.getSnacks()[0].getName());
}

TEST(StorageTest, test_add_snack_with_name_and_amount_twice) {
    Storage storage = Storage(StorageType::CANDY, 5);
    storage.add("Oreo", 2);
    storage.add("Oreo", 2);

    ASSERT_EQ(1, storage.getSnacks().size());
    ASSERT_EQ(4, storage.getAmount());
    ASSERT_EQ(4, storage.getSnacks()[0].getAmount());
    ASSERT_EQ("Oreo", storage.getSnacks()[0].getName());
}

TEST(StorageTest, test_add_snack_overflow_with_name_and_amount) {
    Storage storage = Storage(StorageType::CAKE, 2);

    ASSERT_THROW(storage.add("Brownie", 3), std::invalid_argument);
}

TEST(StorageTest, test_eat_snack_with_name_and_amount) {
    Storage storage = Storage(StorageType::COOKIES, 5);
    storage.add("Oreo", 3);

    storage.eat("Oreo", 2);
    ASSERT_EQ(1, storage.getSnacks()[0].getAmount());
}

TEST(StorageTest, test_eat_all_snack_with_name_and_amount) {
    Storage storage = Storage(StorageType::COOKIES, 5);
    storage.add("Oreo", 3);

    storage.eat("Oreo", 3);
    ASSERT_TRUE(storage.getSnacks().empty());
}

TEST(StorageTest, test_eat_snack_overflow_with_name_and_amount) {
    Storage storage = Storage(StorageType::COOKIES, 5);
    storage.add("Oreo", 3);

    ASSERT_THROW(storage.eat("Oreo", 6), std::invalid_argument);
}

TEST(StorageTest, test_eat_snack_not_exist_with_name_and_amount) {
    Storage storage = Storage(StorageType::COOKIES, 5);

    ASSERT_THROW(storage.eat("Oreo", 6), std::invalid_argument);
}

TEST(StorageTest, test_eat_first_with_amount) {
    Storage storage = Storage(StorageType::OTHER, 10);
    storage.add("Mars", 3);
    storage.add("Twix", 4);

    storage.eatFirst(2);
    ASSERT_EQ(1, storage.getSnacks().front().getAmount());
    ASSERT_EQ(4, storage.getSnacks().back().getAmount());
}

TEST(StorageTest, test_eat_all_first_with_amount) {
    Storage storage = Storage(StorageType::OTHER, 10);
    storage.add("Mars", 3);
    storage.add("Twix", 4);

    storage.eatFirst(3);
    ASSERT_EQ(1, storage.getSnacks().size());
    ASSERT_EQ("Twix", storage.getSnacks().front().getName());
    ASSERT_EQ(4, storage.getSnacks().front().getAmount());
}

TEST(StorageTest, test_eat_last_with_amount) {
    Storage storage = Storage(StorageType::OTHER, 10);
    storage.add("Mars", 3);
    storage.add("Twix", 4);

    storage.eatLast(3);
    ASSERT_EQ(3, storage.getSnacks().front().getAmount());
    ASSERT_EQ(1, storage.getSnacks().back().getAmount());
}

TEST(StorageTest, test_eat_all_last_with_amount) {
    Storage storage = Storage(StorageType::OTHER, 10);
    storage.add("Mars", 3);
    storage.add("Twix", 4);

    storage.eatLast(4);
    ASSERT_EQ(1, storage.getSnacks().size());
    ASSERT_EQ("Mars", storage.getSnacks().back().getName());
    ASSERT_EQ(3, storage.getSnacks().back().getAmount());
}

TEST(StorageTest, test_sort_snacks_by_amount) {
    Storage storage = Storage(StorageType::CANDY, 15);
    storage.add("Zebra", 5);
    storage.add("Apple", 2);
    storage.add("Mango", 7);

    storage.sortBySnackName();
    ASSERT_EQ("Apple", storage.getSnacks()[0].getName());
    ASSERT_EQ("Mango", storage.getSnacks()[1].getName());
    ASSERT_EQ("Zebra", storage.getSnacks()[2].getName());

}

TEST(StorageTest, test_sort_snacks_by_Name) {
    Storage storage = Storage(StorageType::CANDY, 15);
    storage.add("Zebra", 5);
    storage.add("Apple", 2);
    storage.add("Mango", 7);


    storage.sortByAmount();
    ASSERT_EQ(2, storage.getSnacks()[0].getAmount());
    ASSERT_EQ(5, storage.getSnacks()[1].getAmount());
    ASSERT_EQ(7, storage.getSnacks()[2].getAmount());
}

TEST(StorageTest, test_clear_snacks) {
    Storage storage = Storage(StorageType::CANDY, 10);
    storage.add("Candy", 3);
    storage.add("Cookie", 2);

    storage.clear();
    ASSERT_TRUE(storage.getSnacks().empty());
}
