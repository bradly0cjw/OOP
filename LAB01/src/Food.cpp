#include "Food.hpp"

FoodType Food::GetFoodType() {
    return foodType;
}

int Food::GetPrice() {
    return price;
}
void Food::CountFoodPrice() {
    price = 0;
    price += ingredient.base.size() * 20;
    price += ingredient.meat.size() * 15;
    price += ingredient.veggie.size() * 10;
    price += ingredient.seasoning.size() * 0;
    price += ingredient.sweet.size() * 15;
    price += ingredient.drinkBase.size() * 10;
}
Ingredient Food::GetIngredient() {
    return ingredient;
}
Food::Food(Ingredient ingredient) {
    this->ingredient=ingredient;
}
