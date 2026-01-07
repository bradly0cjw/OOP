#ifndef DRINK_HPP
#define DRINK_HPP

#include "Ingredient.hpp"

#include "IFood.hpp"
#include "IPreparable.hpp"
#include "ICustomizable.hpp"
#include <vector>

class Drink : public IFood, public IPreparable, public ICustomizable {
private:
    std::vector<Ingredient> ingredients;
    Option option = Option::None;
    bool isDone = false;
public:
    Drink(std::vector<Ingredient> ingredient);
    std::vector<Ingredient> GetIngredient() override;
    FoodType GetFoodType() override;
    bool IsDone() override;
    void Prepare() override;
    void AddOption(Option option) override;
    Option GetOption() override;
};

#endif