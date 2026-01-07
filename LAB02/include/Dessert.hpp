#ifndef DESSERT_HPP
#define DESSERT_HPP

#include "IFood.hpp"
#include "ICookable.hpp"
#include "ICustomizable.hpp"
#include <vector>

class Dessert : public IFood, public ICookable, public ICustomizable {
private:
    std::vector<Ingredient> ingredients;
    Option option = Option::None;
    bool isDone = false;
public:
    Dessert(std::vector<Ingredient> ingredient);
    std::vector<Ingredient> GetIngredient() override;
    FoodType GetFoodType() override;
    bool IsDone() override;
    void Cook() override;
    void AddOption(Option option) override;
    Option GetOption() override;
};

#endif
