#include "Drink.hpp"
#include <iostream>
#include "ToString.hpp"

Drink::Drink(Ingredient ingredient) : Food(ingredient) {
    if (ingredient.drinkBase.empty()) {
        throw std::invalid_argument("Drink must have DrinkBase.");
    }
    if (!ingredient.base.empty() || !ingredient.meat.empty() || !ingredient.veggie.empty() || !ingredient.seasoning.empty() || !ingredient.sweet.empty()) {
        throw std::invalid_argument("Drink cannot have Base, Meat, Veggie, Seasoning, or Sweet.");
    }
    foodType = FoodType::Drink;
    CountFoodPrice();
}

void Drink::Cook() {
    std::cout << "Prepared Drink" << std::endl;
    std::cout << "There is ingredient" << std::endl;
    std::cout << ToString(ingredient.drinkBase) << std::endl;
    std::cout << "Done Drink" << std::endl;
}
