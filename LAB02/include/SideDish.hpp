#ifndef SIDE_DISH_HPP
#define SIDE_DISH_HPP

#include "IFood.hpp"
#include "ICookable.hpp"
#include "ICustomizable.hpp"
#include "Ingredient.hpp"
#include <vector>

class SideDish : public IFood, public ICookable, public ICustomizable {
private:
    std::vector<Ingredient> ingredients;
    Option option = Option::None;
    bool isDone = false;
public:
    SideDish(std::vector<Ingredient> ingredient);
    std::vector<Ingredient> GetIngredient() override;
    FoodType GetFoodType() override;
    bool IsDone() override;
    void Cook() override;
    void AddOption(Option option) override;
    Option GetOption() override;
};

#endif