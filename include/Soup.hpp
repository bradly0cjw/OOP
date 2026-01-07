#ifndef SOUP_HPP
#define SOUP_HPP

#include "Food.hpp"

class Soup: public Food{
public:
    Soup(Ingredient ingredient);
    void Cook() override;
};

#endif