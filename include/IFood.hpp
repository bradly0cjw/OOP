#ifndef IFOOD_HPP
#define IFOOD_HPP

#include "Ingredient.hpp"
#include "FoodType.hpp"
#include <vector>

class IFood{
public:
    virtual std::vector<Ingredient> GetIngredient() = 0;
    virtual FoodType GetFoodType() = 0;
    virtual bool IsDone() = 0;
};

#endif