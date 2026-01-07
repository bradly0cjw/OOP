#ifndef INGREDIENT_HPP
#define INGREDIENT_HPP

#include <vector>

enum class Base { // 主食
    Bread, Noodle, Rice
};

enum class Meat { // 肉類
    Beef, Pork, Chicken, Fish
};

enum class Veggie { // 蔬菜
    Lettuce, Tomato, Onion, Mushroom, Corn
};

enum class Seasoning { // 調味料
    Salt, Pepper, SoySauce, ChiliSauce, Cheese
};

enum class Sweet { // 甜食
    Sugar, Milk, Chocolate
};

enum class DrinkBase { // 飲料
    Tea, Coffee, FruitJuice, Pepsi, Cola, Sprite
};

class Ingredient{
public:
    Ingredient() {};
    std::vector<Base> base;
    std::vector<Meat> meat;
    std::vector<Veggie> veggie;
    std::vector<Seasoning> seasoning;
    std::vector<Sweet> sweet;
    std::vector<DrinkBase> drinkBase;
};

#endif