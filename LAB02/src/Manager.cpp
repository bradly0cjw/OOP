#include "Manager.hpp"
#include "ICookable.hpp"
#include "IPreparable.hpp"
#include <iostream>

Manager::Manager() {}

void Manager::SetFood(std::vector<std::shared_ptr<IFood>> food) {
    this->foods = food;
}

void Manager::MakeFood() {
    for (auto food : foods) {
        if (auto cookable = std::dynamic_pointer_cast<ICookable>(food)) {
            cookable->Cook();
        } else if (auto preparable = std::dynamic_pointer_cast<IPreparable>(food)) {
            preparable->Prepare();
        }
    }
}

std::vector<std::shared_ptr<IFood>> Manager::GetFood() {
    return foods;
}