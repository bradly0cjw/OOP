#ifndef SALAD_HPP
#define SALAD_HPP

#include "Food.hpp"

class Salad: public Food{
public:
    Salad(Ingredient ingredient);
    void Cook() override;
};

#endif

