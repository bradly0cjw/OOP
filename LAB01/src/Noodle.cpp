#include "Noodle.hpp"
#include <iostream>
#include "ToString.hpp"

Noodle::Noodle(Ingredient ingredient) : Food(ingredient) {
    if (ingredient.base.empty() || ingredient.meat.empty() || ingredient.veggie.empty() || ingredient.seasoning.empty()) {
        throw std::invalid_argument("Noodle must have Base, Meat, Veggie, and Seasoning.");
    }
    if (!ingredient.drinkBase.empty() || !ingredient.sweet.empty()) {
        throw std::invalid_argument("Noodle cannot have DrinkBase or Sweet.");
    }
    foodType = FoodType::Noodle;
    CountFoodPrice();
}

Noodle::~Noodle() {
}

void Noodle::Cook() {
    std::cout << "Prepared Noodle" << std::endl;
    std::cout << "There is ingredient" << std::endl;
    std::cout << ToString(ingredient.base) << std::endl;
    std::cout << ToString(ingredient.meat) << std::endl;
    std::cout << ToString(ingredient.veggie) << std::endl;
    std::cout << ToString(ingredient.seasoning) << std::endl;
    std::cout << "Done Noodle" << std::endl;
}