#include "Drink.hpp"
#include <stdexcept>

Drink::Drink(std::vector<Ingredient> ingredient) {
    this->ingredients = ingredient;
}

std::vector<Ingredient> Drink::GetIngredient() {
    return ingredients;
}

FoodType Drink::GetFoodType() {
    return FoodType::Drink;
}

bool Drink::IsDone() {
    return isDone;
}

void Drink::Prepare() {
    if (isDone) {
        return;
    }
    isDone = true;
}

void Drink::AddOption(Option option) {
    if (isDone) {
        throw std::invalid_argument("Cannot add option to prepared Drink");
    }
    this->option = option;
}

Option Drink::GetOption() {
    return option;
}