#include "StorageManager.hpp"
#include <stdexcept>

StorageManager::StorageManager(){
    storages.push_back(Storage(StorageType::CANDY));
    storages.push_back(Storage(StorageType::COOKIES));
    storages.push_back(Storage(StorageType::CAKE));
    storages.push_back(Storage(StorageType::OTHER));
}

void StorageManager::AddAllStorageCapacity(int capacity){
        for(auto& storage : storages){
                storage.setCapacity(storage.getCapacity() + capacity);
        }
}
void StorageManager::moveCapacity(StorageType fromType, StorageType toType, int moveCapacity){
        Storage* fromStorage = nullptr;
        Storage* toStorage = nullptr;

        for(auto& storage : storages){
                if(storage.getType() == fromType){
                        fromStorage = &storage;
                }
                if(storage.getType() == toType){
                        toStorage = &storage;
                }
        }

        if(fromStorage == nullptr || toStorage == nullptr){
                throw std::invalid_argument("Invalid storage type");
        }


        if(fromStorage->getAmount() > moveCapacity){
                throw std::invalid_argument("Not enough capacity in fromStorage");
        }
        if(toStorage->getAmount() + moveCapacity > toStorage->getCapacity()){
                throw std::invalid_argument("Exceeds maximum capacity in toStorage");
        }

        fromStorage->setCapacity(fromStorage->getCapacity() - moveCapacity);
        toStorage->setCapacity(toStorage->getCapacity() + moveCapacity);
}

std::vector<Storage>& StorageManager::getStorages() {
    return storages;
}
