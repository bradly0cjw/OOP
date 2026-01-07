#ifndef BURGER_HPP
#define BURGER_HPP

#include "Ingredient.hpp"

#include "IFood.hpp"
#include "ICookable.hpp"
#include "ICustomizable.hpp"
#include <vector>

class Burger : public IFood, public ICookable, public ICustomizable {
private:
    std::vector<Ingredient> ingredients;
    Option option = Option::None;
    bool isDone = false;
public:
    Burger(std::vector<Ingredient> ingredient);
    std::vector<Ingredient> GetIngredient() override;
    FoodType GetFoodType() override;
    bool IsDone() override;
    void Cook() override;
    void AddOption(Option option) override;
    Option GetOption() override;
};

#endif