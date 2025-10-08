#include "Storage.hpp"
#include "bits/stdc++.h"

Storage::Storage(StorageType storageType) {
    type = storageType;
    capacity = 10;
    amount = 0;
}

Storage::Storage(StorageType storageType, int storageCapacity) {
    type = storageType;
    capacity = storageCapacity;
    amount = 0;
}

void Storage::add(std::string snackName) {
    if (getAmount() + 1 > capacity) {
        throw std::invalid_argument("Storage is full");
    }
    for (auto it = snacks.begin(); it != snacks.end(); ++it) {
        if (it->getName() == snackName) {
                it->setAmount(it->getAmount() + 1);
                amount += 1;
                return;
        }
    }
        snacks.emplace_back(snackName, 1);
        amount += 1;
}

void Storage::add(std::string snackName, int snackAmount) {
    if (snackAmount <= 0) {
        throw std::invalid_argument("Snack amount must be positive");
    }
    if (getAmount() + snackAmount > capacity) {
        throw std::invalid_argument("Storage is full");
    }
    for (auto it = snacks.begin(); it != snacks.end(); ++it) {
        if (it->getName() == snackName) {
            it->setAmount(it->getAmount() + snackAmount);
            amount += snackAmount;
            return;
        }
    }
    snacks.emplace_back(snackName, snackAmount);
    amount += snackAmount;
}

void Storage::eat(std::string snackName, int snackAmount) {
    for (auto it = snacks.begin(); it != snacks.end(); ++it) {
        if (it->getName() == snackName) {
            if (it->getAmount() < snackAmount) {
                throw std::invalid_argument("Not enough snacks");
            } else if (it->getAmount() == snackAmount) {
                snacks.erase(it);
            } else {
                it->setAmount(it->getAmount() - snackAmount);
            }
            return;
        }
    }
    throw std::invalid_argument("Snack not found");
}

void Storage::eatFirst(int snackAmount) {
    if (snacks.empty()) {
        throw std::invalid_argument("Storage is empty");
    }
    if (snacks.front().getAmount() < snackAmount) {
        throw std::invalid_argument("Not enough snacks");
    } else if (snacks.front().getAmount() == snackAmount) {
        snacks.erase(snacks.begin());
    } else {
        snacks.front().setAmount(snacks.front().getAmount() - snackAmount);
    }
}

void Storage::eatLast(int snackAmount) {
    if (snacks.empty()) {
        throw std::invalid_argument("Storage is empty");
    }
    if (snacks.back().getAmount() < snackAmount) {
        throw std::invalid_argument("Not enough snacks");
    } else if (snacks.back().getAmount() == snackAmount) {
        snacks.pop_back();
    } else {
        snacks.back().setAmount(snacks.back().getAmount() - snackAmount);
    }
}

void Storage::sortByAmount() {
    std::sort(snacks.begin(), snacks.end(), [](const Snack &a, const Snack &b) {
        return a.getAmount() < b.getAmount();
    });
}

void Storage::sortBySnackName() {
    std::sort(snacks.begin(), snacks.end(), [](const Snack &a, const Snack &b) {
        return a.getName() < b.getName();
    });
}

void Storage::clear() {
    snacks.clear();
}

int Storage::getAmount() const {
    return amount;
}

int Storage::getCapacity() const {
    return capacity;
}

StorageType Storage::getType() const {
    return type;
}

const std::vector<Snack> &Storage::getSnacks() const {
    return snacks;
}

void Storage::setCapacity(int storageCapacity) {
    capacity = storageCapacity;
}