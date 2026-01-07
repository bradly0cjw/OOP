#include "Manager.hpp"
#include "Burger.hpp"
#include "Drink.hpp"
#include "Dessert.hpp"
#include "SideDish.hpp"
#include "ToString.hpp"
#include "Validator.hpp"

void TaskOne(){
    std::vector<Ingredient> ingredientBurger = {Ingredient::Bread, Ingredient::Cheese, Ingredient::Lettuce};
    std::vector<Ingredient> ingredientSideDish = {Ingredient::FrenchFries};
    std::vector<Ingredient> ingredientDrink = {Ingredient::CaramelMilkTea};

    std::shared_ptr<Burger> burger = std::make_shared<Burger>(ingredientBurger);
    std::shared_ptr<SideDish> sideDish = std::make_shared<SideDish>(ingredientSideDish);
    std::shared_ptr<Drink> drink = std::make_shared<Drink>(ingredientDrink);

    Manager manager;
    manager.SetFood({burger, sideDish, drink});
    manager.MakeFood();

    Validator valid;
    valid.Validate(manager.GetFood());
}

void TaskTwo(){
    std::vector<Ingredient> ingredientBurger = {Ingredient::Bread, Ingredient::CaramelMilkTea, Ingredient::FrenchFries};
    std::vector<Ingredient> ingredientSideDish = {Ingredient::Bread, Ingredient::Cheese, Ingredient::Lettuce, Ingredient::FrenchFries};
    std::vector<Ingredient> ingredientDrink = {Ingredient::Cheese};

    try {
        std::shared_ptr<Burger> burger = std::make_shared<Burger>(ingredientBurger);
    } catch (const std::exception& e){
        std::cerr << "Wrong Ingredient for hurger" << std::endl;
    }

    try {
        std::shared_ptr<SideDish> sideDish = std::make_shared<SideDish>(ingredientSideDish);
    } catch (const std::exception& e){
        std::cerr << "Wrong Ingredient for Side Dish" << std::endl;
    }

    try {
        std::shared_ptr<Drink> drink = std::make_shared<Drink>(ingredientDrink);
    } catch (const std::exception& e){
        std::cerr << "Wrong Ingredient for Drink" << std::endl;
    }
}

void TaskThree(){
    std::vector<Ingredient> ingredientBurger = {Ingredient::Bread, Ingredient::Cheese, Ingredient::Lettuce};
    std::vector<Ingredient> ingredientSideDish = {Ingredient::FrenchFries};
    std::vector<Ingredient> ingredientDrink = {Ingredient::CaramelMilkTea};

    std::shared_ptr<Burger> burger = std::make_shared<Burger>(ingredientBurger);
    std::shared_ptr<SideDish> sideDish = std::make_shared<SideDish>(ingredientSideDish);
    std::shared_ptr<Drink> drink = std::make_shared<Drink>(ingredientDrink);

    Manager manager;
    manager.SetFood({burger, sideDish, drink});
    manager.MakeFood();

    try {
        manager.MakeFood();
    } catch (const std::exception& e){
        std::cerr << "Wrong for double cook/prepared!" << std::endl;
    }
}

void TaskFour(){
    std::vector<Ingredient> ingredientBurger = {Ingredient::Bread, Ingredient::Cheese, Ingredient::Lettuce};
    std::vector<Ingredient> ingredientSideDish = {Ingredient::FrenchFries};
    std::vector<Ingredient> ingredientDrink = {Ingredient::BlackTea};

    Option optionBurger = Option::LessSalt;
    Option optionSideDish = Option::NoIce;
    Option optionDrink = Option::AddOnions;

    std::shared_ptr<Burger> burger = std::make_shared<Burger>(ingredientBurger);
    std::shared_ptr<SideDish> sideDish = std::make_shared<SideDish>(ingredientSideDish);
    std::shared_ptr<Drink> drink = std::make_shared<Drink>(ingredientDrink);

    try {
        burger->AddOption(optionBurger);
    } catch (const std::exception& e){
        std::cerr << "Wrong option for burger!" << std::endl;
    }

    try {
        sideDish->AddOption(optionSideDish);
    } catch (const std::exception& e){
        std::cerr << "Wrong option for side dish!" << std::endl;
    }

    try {
        drink->AddOption(optionDrink);
    } catch (const std::exception& e){
        std::cerr << "Wrong for double drink!" << std::endl;
    }
}

// ... (TaskFive implementation)
void TaskFive() {
    std::cout << "--- Dessert Test ---" << std::endl;
    std::vector<Ingredient> ingredientDessert = {Ingredient::Chocolate, Ingredient::Pudding};
    std::shared_ptr<Dessert> dessert = std::make_shared<Dessert>(ingredientDessert);

    // Test options (Happy Path)
    try {
        dessert->AddOption(Option::ExtraSugar);
        std::cout << "Added ExtraSugar to Dessert." << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Failed to add option: " << e.what() << std::endl;
    }

    Manager manager;
    manager.SetFood({dessert});
    
    // Test cooking
    manager.MakeFood();
    if (dessert->IsDone()) {
        std::cout << "Dessert cooked successfully." << std::endl;
    } else {
        std::cerr << "Dessert failed to cook!" << std::endl;
    }

    // Test adding option after cooking (Should Fail)
    try {
        dessert->AddOption(Option::HalfSugar);
    } catch (const std::exception& e) {
        std::cout << "Correctly caught exception adding option after cooking: " << e.what() << std::endl;
    }

    // Test invalid ingredient
    try {
        std::vector<Ingredient> badIngredients = {Ingredient::Meat}; 
        std::shared_ptr<Dessert> badDessert = std::make_shared<Dessert>(badIngredients);
    } catch (const std::exception& e) {
        std::cout << "Caught expected invalid ingredient for Dessert." << std::endl;
    }
    std::cout << "--------------------" << std::endl;
}

int main() {
    TaskOne();
    TaskTwo();
    TaskThree();
    TaskFour();
    TaskFive();
    return 0;
}