#include "SideDish.hpp"
#include <stdexcept>

SideDish::SideDish(std::vector<Ingredient> ingredient) {
    this->ingredients = ingredient;
}

std::vector<Ingredient> SideDish::GetIngredient() {
    return ingredients;
}

FoodType SideDish::GetFoodType() {
    return FoodType::SideDish;
}

bool SideDish::IsDone() {
    return isDone;
}

void SideDish::Cook() {
    if (isDone) {
        return;
    }
    isDone = true;
}

void SideDish::AddOption(Option option) {
    if (isDone) {
        throw std::invalid_argument("Cannot add option to cooked SideDish");
    }
    this->option = option;
}

Option SideDish::GetOption() {
    return option;
}