#include "Burger.hpp"
#include <stdexcept>
#include <algorithm>

Burger::Burger(std::vector<Ingredient> ingredient) {
    this->ingredients = ingredient;
}

std::vector<Ingredient> Burger::GetIngredient() {
    return ingredients;
}

FoodType Burger::GetFoodType() {
    return FoodType::Burger;
}

bool Burger::IsDone() {
    return isDone;
}

void Burger::Cook() {
    if (isDone) {
        return;
    }
    isDone = true;
}

void Burger::AddOption(Option option) {
    if (isDone) {
        throw std::invalid_argument("Cannot add option to cooked Burger");
    }
    this->option = option;
}

Option Burger::GetOption() {
    return option;
}