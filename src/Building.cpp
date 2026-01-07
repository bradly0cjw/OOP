#include "Building.hpp"

Building::Building(int totalFloors) {
    this->totalFloors=totalFloors;
    for (int i = 1; i <= totalFloors; ++i) {
        this->companies.push_back(std::make_shared<Company>("company" + std::to_string(i), i));
    }
}

int Building::getTotalFloors() {
    return this->totalFloors;
}

std::vector<std::shared_ptr<Company>> Building::getCompanies() {
    return this->companies;
}

int Building::CountWorkingCompanies() {
    int count = 0;
    for (auto& c : this->companies) {
        if (c->isWork()) {
            count++;
        }
    }
    return count;
}
