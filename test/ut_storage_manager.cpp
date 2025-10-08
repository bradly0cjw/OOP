#include <gtest/gtest.h>
#include "StorageManager.hpp"

TEST(StorageManagerTest, test_construct) {
    StorageManager manager;
    auto& storages = manager.getStorages();

    ASSERT_EQ(4, storages.size());

    ASSERT_EQ(StorageType::CANDY, storages[0].getType());
    ASSERT_EQ(StorageType::COOKIES, storages[1].getType());
    ASSERT_EQ(StorageType::CAKE, storages[2].getType());
    ASSERT_EQ(StorageType::OTHER, storages[3].getType());

    for (const auto& storage : storages) {
        ASSERT_EQ(10, storage.getCapacity());
        ASSERT_EQ(0, storage.getAmount());
    }
}

TEST(StorageManagerTest, test_add_all_storage_capacity) {
    StorageManager manager;
    manager.AddAllStorageCapacity(50);

    auto &storages = manager.getStorages();
    for (const auto &storage : storages) {
        ASSERT_EQ(60, storage.getCapacity());
    }
}

TEST(StorageManagerTest, test_move_capacity_success) {
    StorageManager manager;

    manager.moveCapacity(StorageType::CANDY, StorageType::COOKIES, 5);

    auto &storages = manager.getStorages();
    ASSERT_EQ(5, storages[0].getCapacity());
    ASSERT_EQ(15, storages[1].getCapacity());
}

TEST(StorageManagerTest, test_move_capacity_throws) {
    StorageManager manager;

    auto &storages = manager.getStorages();
    storages[0].add("Lollipop", 8);  // 先塞點心

    ASSERT_THROW(
        manager.moveCapacity(StorageType::CANDY, StorageType::COOKIES, 5),
        std::invalid_argument);
}

TEST(StorageManagerTest, test_move_capacity_zero) {
    StorageManager manager;

    manager.moveCapacity(StorageType::CANDY, StorageType::COOKIES, 0);

    auto &storages = manager.getStorages();
    ASSERT_EQ(10, storages[0].getCapacity());
    ASSERT_EQ(10, storages[1].getCapacity());
}

TEST(StorageManagerTest, test_move_capacity_all) {
    StorageManager manager;

    manager.moveCapacity(StorageType::CAKE, StorageType::OTHER, 10);

    auto &storages = manager.getStorages();
    ASSERT_EQ(0, storages[2].getCapacity());
    ASSERT_EQ(20, storages[3].getCapacity());
}

TEST(StorageManagerTest, test_move_capacity_multiple_times) {
    StorageManager manager;

    manager.moveCapacity(StorageType::CANDY, StorageType::COOKIES, 3);
    manager.moveCapacity(StorageType::COOKIES, StorageType::CAKE, 2);
    manager.moveCapacity(StorageType::CAKE, StorageType::OTHER, 1);

    auto &storages = manager.getStorages();
    ASSERT_EQ(7, storages[0].getCapacity());  // Candy
    ASSERT_EQ(11, storages[1].getCapacity()); // Cookies
    ASSERT_EQ(11, storages[2].getCapacity());  // Cake
    ASSERT_EQ(11, storages[3].getCapacity()); // Other
}

TEST(StorageManagerTest, test_move_capacity_same_type) {
    StorageManager manager;

    manager.moveCapacity(StorageType::CANDY, StorageType::CANDY, 5);

    auto &storages = manager.getStorages();
    ASSERT_EQ(10, storages[0].getCapacity());
}
