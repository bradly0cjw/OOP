#ifndef VALIDATOR_HPP
#define VALIDATOR_HPP

#include <vector>
#include <iostream>
#include "Food.hpp"
#include "ToString.hpp"

void Validate(const std::vector<std::shared_ptr<Food>> food){
    bool wrong = false;
    for(auto i:food){
        auto t = i->GetPrice();
        auto ing = i->GetIngredient();
        int price = ing.meat.size() *15 + ing.drinkBase.size()*10 + ing.base.size() *20 + ing.veggie.size()*10  + ing.sweet.size()*15;
        std::cout << "Checking Food: " << ToString(i->GetFoodType()) << "\n";
        if(t != price){
            std::cerr << ToString( i->GetFoodType() ) << " has wrong price.\n";
            std::cerr << "Expected " << price << " but get " << t << "\n";
            wrong = true;
        }
    }
    if(!wrong){
        std::cout << "\n All Done! \n It's correct!";
    }
}

#endif