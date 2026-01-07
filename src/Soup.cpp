#include "Soup.hpp"
#include <iostream>
#include "ToString.hpp"

Soup::Soup(Ingredient ingredient) : Food(ingredient) {
    if (ingredient.meat.empty() || ingredient.veggie.empty() || ingredient.seasoning.empty()) {
        throw std::invalid_argument("Soup must have Meat, Veggie, and Seasoning.");
    }
    if (!ingredient.base.empty() || !ingredient.drinkBase.empty() || !ingredient.sweet.empty()) {
        throw std::invalid_argument("Soup cannot have Base, DrinkBase, or Sweet.");
    }
    foodType = FoodType::Soup;
    CountFoodPrice();
}

void Soup::Cook() {
    std::cout << "Prepared Soup" << std::endl;
    std::cout << "There is ingredient" << std::endl;
    std::cout << ToString(ingredient.meat) << std::endl;
    std::cout << ToString(ingredient.veggie) << std::endl;
    std::cout << ToString(ingredient.seasoning) << std::endl;
    std::cout << "Done Soup" << std::endl;
}
