#include "RandomFood.hpp"

RandomFood::RandomFood() {

}

Ingredient RandomFood::Generate(){
    Ingredient ing;

    // Base: 1 個（3 種）
    ing.base.push_back(randomOne<Base>(3));

    // DrinkBase: 1 個（6 種）
    ing.drinkBase.push_back(randomOne<DrinkBase>(6));

    // Meat: 1~4 個
    ing.meat = randomOneToMany<Meat>(4);

    // Veggie: 1~5 個
    ing.veggie = randomOneToMany<Veggie>(5);

    // Seasoning: 1~5 個
    ing.seasoning = randomOneToMany<Seasoning>(5);

    // Sweet: 1~3 個
    ing.sweet = randomOneToMany<Sweet>(3);

    return ing;
}