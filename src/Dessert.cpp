#include "Dessert.hpp"
#include <iostream>
#include "ToString.hpp"

Dessert::Dessert(Ingredient ingredient) : Food(ingredient) {
    if (ingredient.sweet.empty()) {
        throw std::invalid_argument("Dessert must have Sweet.");
    }
    if (!ingredient.meat.empty() || !ingredient.veggie.empty() || !ingredient.seasoning.empty() || !ingredient.drinkBase.empty()) {
        throw std::invalid_argument("Dessert cannot have Meat, Veggie, Seasoning, or DrinkBase.");
    }
    foodType = FoodType::Dessert;
    CountFoodPrice();
}

void Dessert::Cook() {
    std::cout << "Prepared Dessert" << std::endl;
    std::cout << "There is ingredient" << std::endl;
    std::cout << ToString(ingredient.base) << std::endl;
    std::cout << ToString(ingredient.sweet) << std::endl;
    std::cout << "Done Dessert" << std::endl;
}
