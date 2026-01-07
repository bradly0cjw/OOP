#include "Dessert.hpp"
#include <stdexcept>

Dessert::Dessert(std::vector<Ingredient> ingredient) {
    for (auto i : ingredient) {
        if (i != Ingredient::Chocolate && i != Ingredient::Pudding && 
            i != Ingredient::Apple) {
            throw std::invalid_argument("Invalid ingredient for Dessert");
        }
    }
    this->ingredients = ingredient;
}

std::vector<Ingredient> Dessert::GetIngredient() {
    return ingredients;
}

FoodType Dessert::GetFoodType() {
    return FoodType::Dessert;
}

bool Dessert::IsDone() {
    return isDone;
}

void Dessert::Cook() {
    if (isDone) {
        throw std::invalid_argument("Dessert is already cooked");
    }
    isDone = true;
}

void Dessert::AddOption(Option option) {
    if (isDone) {
        throw std::invalid_argument("Cannot add option to cooked Dessert");
    }
    if (option != Option::Large && option != Option::ExtraSugar && 
        option != Option::HalfSugar && option != Option::None) {
        throw std::invalid_argument("Invalid option for Dessert");
    }
    this->option = option;
}

Option Dessert::GetOption() {
    return option;
}
