#ifndef STORAGE_HPP
#define STORAGE_HPP

#include "Snack.hpp"
#include <string>
#include <vector>

enum class StorageType {
    CANDY,
    COOKIES,
    CAKE,
    OTHER
};

class Storage {
public:
    Storage(StorageType storageType);
    Storage(StorageType storageType, int storageCapacity);

    void add(std::string snackName);
    void add(std::string snackName, int snackAmount);
    void eat(std::string snackName, int snackAmount);
    void eatFirst(int snackAmount);
    void eatLast(int snackAmount);
    void sortByAmount();
    void sortBySnackName();
    void clear();

    [[nodiscard]] int getAmount() const;
    [[nodiscard]] int getCapacity() const;
    [[nodiscard]] StorageType getType() const;
    [[nodiscard]] const std::vector<Snack> &getSnacks() const;

    void setCapacity(int storageCapacity);

private:
    std::vector<Snack> snacks;
    StorageType type;
    int amount;
    int capacity;
};
#endif
