#ifndef BURGER_HPP
#define BURGER_HPP

#include "Food.hpp"

class Burger: public Food{
public:
    Burger(Ingredient ingredient);
    void Cook() override;
};

#endif