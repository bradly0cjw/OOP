#ifndef STORAGEMANAGER_HPP
#define STORAGEMANAGER_HPP

#include "Storage.hpp"

class StorageManager {
public:
    StorageManager();

    void AddAllStorageCapacity(int capacity);
    void moveCapacity(StorageType fromType, StorageType toType, int moveCapacity);

    [[nodiscard]] std::vector<Storage>& getStorages();

private:
    std::vector<Storage> storages;
};

#endif
