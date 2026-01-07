#include "Validator.hpp"

Validator::Validator() {}

void Validator::Validate(std::vector<std::shared_ptr<IFood>> food) {
    for(auto i: food){
        auto type = i->GetFoodType();
        if (type == FoodType::Drink){
            auto j = std::dynamic_pointer_cast<Drink>(i);
            ValidateDrink(j);
        }
        else if (type == FoodType::SideDish){
            auto j = std::dynamic_pointer_cast<SideDish>(i);
            ValidateSideDish(j);
        }
        else {
            auto j = std::dynamic_pointer_cast<Burger>(i);
            ValidateBurger(j);
        }
    }
}

void Validator::ValidateBurger(std::shared_ptr<Burger> food) {
    auto ingredient = food->GetIngredient();
    auto type = food->GetFoodType();
    auto option = food->GetOption();
    for (auto i:ingredient){
        switch (i) {
        case Ingredient::Bread:
        case Ingredient::Meat:
        case Ingredient::Lettuce:
        case Ingredient::Cheese:
            continue;
        default:
            std::cerr << "Wrong Ingredient For Burger! \n";
            return;
        }
    }
    switch (option) {
    case Option::None:
    case Option::Large:
    case Option::AddOnions:
    case Option::AddPickles:
        break;
    default:
        std::cerr << "Wrong Options For Burger! \n";
        return;
    }
    if (type != FoodType::Burger) {
        std::cerr << "Wrong Type For Burger! \n";
        return;
    }

    std::cout << "All Correct For Burger! \n";
}
void Validator::ValidateDrink(std::shared_ptr<Drink> food) {
    auto ingredient = food->GetIngredient();
    auto type = food->GetFoodType();
    auto option = food->GetOption();

    for (auto i:ingredient){
        switch (i) {
        case Ingredient::Cola:
        case Ingredient::CaramelMilkTea:
        case Ingredient::BlackTea:
            continue;
        default:
            std::cerr << "Wrong Ingredient For Drink! \n";
            return;
        }
    }
    switch (option) {
    case Option::None:
    case Option::LessIce:
    case Option::NoIce:
        break;
    default:
        std::cerr << "Wrong Options For Drink! \n";
        return;
    }
    if (type != FoodType::Drink) {
        std::cerr << "Wrong Type For Drink! \n";
        return;
    }

    std::cout << "All Correct For Drink! \n";
}
void Validator::ValidateSideDish(std::shared_ptr<SideDish> food) {
    auto ingredient = food->GetIngredient();
    auto type = food->GetFoodType();
    auto option = food->GetOption();

    for (auto i:ingredient){
        switch (i) {
        case Ingredient::FrenchFries:
        case Ingredient::Nuggets:
        case Ingredient::HashBrowns:
            continue;
        default:
            std::cerr << "Wrong Ingredient For SideDish! \n";
            return;
        }
    }
    switch (option) {
    case Option::None:
    case Option::NoSalt:
    case Option::LessSalt:
        break;
    default:
        std::cerr << "Wrong Options For SideDish! \n";
        return;
    }
    if (type != FoodType::SideDish) {
        std::cerr << "Wrong Type For SideDish! \n";
        return;
    }

    std::cout << "All Correct For SideDish! \n";
}