#include "Salad.hpp"
#include <iostream>
#include "ToString.hpp"

Salad::Salad(Ingredient ingredient) : Food(ingredient) {
    if (ingredient.veggie.empty() || ingredient.seasoning.empty()) {
        throw std::invalid_argument("Salad must have Veggie and Seasoning.");
    }
    if (!ingredient.base.empty() || !ingredient.meat.empty() || !ingredient.drinkBase.empty() || !ingredient.sweet.empty()) {
        throw std::invalid_argument("Salad cannot have Base, Meat, DrinkBase, or Sweet.");
    }
    foodType = FoodType::Salad;
    CountFoodPrice();
}

void Salad::Cook() {
    std::cout << "Prepared Salad" << std::endl;
    std::cout << "There is ingredient" << std::endl;
    std::cout << ToString(ingredient.veggie) << std::endl;
    std::cout << ToString(ingredient.seasoning) << std::endl;
    std::cout << "Done Salad" << std::endl;
}
