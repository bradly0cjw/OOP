#ifndef DESSERT_HPP
#define DESSERT_HPP

#include "Food.hpp"

class Dessert : public Food {
public:
    Dessert(Ingredient ingredient);
    void Cook() override;
};

#endif
