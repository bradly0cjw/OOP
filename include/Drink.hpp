#ifndef DRINK_HPP
#define DRINK_HPP

#include "Food.hpp"

class Drink: public Food{
public:
    Drink(Ingredient ingredient);
    void Cook() override;
};

#endif