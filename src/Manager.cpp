#include "Manager.hpp"
#include <iostream>
#include <string>

Manager::Manager(std::vector<std::shared_ptr<Food>> food) {
    this->foods = food;
}

void Manager::CookAllFood() {
    for (auto& food : foods) {
        food->Cook();
    }
}

void Manager::CountAllFoodPrice() {
    for (auto& food : foods) {
        food->CountFoodPrice();
    }
}

std::vector<std::shared_ptr<Food>> Manager::GetFood() {
    return foods;
}