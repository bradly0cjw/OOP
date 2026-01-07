#include "../include/Manager.hpp"
#include "../include/Burger.hpp"
#include "../include/Drink.hpp"
#include "../include/Noodle.hpp"
#include "../include/Salad.hpp"
#include "../include/Soup.hpp"
#include "../include/Dessert.hpp"
#include "../include/ToString.hpp"
#include "../include/RandomFood.hpp"
#include "Validator.hpp"

int main() {
    std::vector<std::shared_ptr<Food>> foods;

    // 1. Burger: Base, Meat, Veggie, Seasoning
    Ingredient burgerIng;
    burgerIng.base.push_back(Base::Bread);
    burgerIng.meat.push_back(Meat::Beef);
    burgerIng.veggie.push_back(Veggie::Lettuce);
    burgerIng.seasoning.push_back(Seasoning::Salt);
    foods.push_back(std::make_shared<Burger>(burgerIng));

    // 2. Drink: DrinkBase
    Ingredient drinkIng;
    drinkIng.drinkBase.push_back(DrinkBase::Cola);
    foods.push_back(std::make_shared<Drink>(drinkIng));

    // 3. Noodle: Base, Meat, Veggie, Seasoning
    Ingredient noodleIng;
    noodleIng.base.push_back(Base::Noodle);
    noodleIng.meat.push_back(Meat::Pork);
    noodleIng.veggie.push_back(Veggie::Onion);
    noodleIng.seasoning.push_back(Seasoning::SoySauce);
    foods.push_back(std::make_shared<Noodle>(noodleIng));

    // 4. Salad: Veggie, Seasoning
    Ingredient saladIng;
    saladIng.veggie.push_back(Veggie::Tomato);
    saladIng.seasoning.push_back(Seasoning::Cheese);
    foods.push_back(std::make_shared<Salad>(saladIng));

    // 5. Soup: Meat, Veggie, Seasoning
    Ingredient soupIng;
    soupIng.meat.push_back(Meat::Chicken);
    soupIng.veggie.push_back(Veggie::Corn);
    soupIng.seasoning.push_back(Seasoning::Pepper);
    foods.push_back(std::make_shared<Soup>(soupIng));

    // 6. Dessert: Sweet
    Ingredient dessertIng;
    dessertIng.sweet.push_back(Sweet::Chocolate);
    foods.push_back(std::make_shared<Dessert>(dessertIng));

    Manager manager(foods);
    manager.CookAllFood();
    manager.CountAllFoodPrice();
    
    std::cout << std::flush;
    Validate(manager.GetFood());
}