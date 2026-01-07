#include "Burger.hpp"
#include <iostream>
#include "ToString.hpp"

Burger::Burger(Ingredient ingredient) : Food(ingredient) {
    if (ingredient.base.empty() || ingredient.meat.empty() || ingredient.veggie.empty() || ingredient.seasoning.empty()) {
        throw std::invalid_argument("Burger must have Base, Meat, Veggie, and Seasoning.");
    }
    if (!ingredient.drinkBase.empty() || !ingredient.sweet.empty()) {
        throw std::invalid_argument("Burger cannot have DrinkBase or Sweet.");
    }
    foodType = FoodType::Burger;
    CountFoodPrice();
}

void Burger::Cook() {
    std::cout << "Prepared Burger" << std::endl;
    std::cout << "There is ingredient" << std::endl;
    std::cout << ToString(ingredient.base) << std::endl;
    std::cout << ToString(ingredient.meat) << std::endl;
    std::cout << ToString(ingredient.veggie) << std::endl;
    std::cout << ToString(ingredient.seasoning) << std::endl;
    std::cout << "Done Burger" << std::endl;
}