#ifndef VALIDATOR_HPP
#define VALIDATOR_HPP

#include <vector>
#include <iostream>
#include <memory>
#include "Burger.hpp"
#include "Drink.hpp"
#include "SideDish.hpp"

class Validator{
private:
    void ValidateBurger(std::shared_ptr<Burger> food);
    void ValidateDrink(std::shared_ptr<Drink> food);
    void ValidateSideDish(std::shared_ptr<SideDish> food);
public:
    Validator();
    void Validate(std::vector<std::shared_ptr<IFood>> food);
};

#endif