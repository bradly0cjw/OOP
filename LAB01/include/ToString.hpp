#ifndef TOSTRING_HPP
#define TOSTRING_HPP
#include <string>
#include <vector>
#include "Ingredient.hpp"
#include "FoodType.hpp"

inline std::string ToString(Base b) {
    switch (b) {
    case Base::Bread:  return "Bread";
    case Base::Noodle: return "Noodle";
    case Base::Rice:   return "Rice";
    }
    return "Unknown Base";
}

inline std::string ToString(Meat m) {
    switch (m) {
    case Meat::Beef:    return "Beef";
    case Meat::Pork:    return "Pork";
    case Meat::Chicken: return "Chicken";
    case Meat::Fish:    return "Fish";
    }
    return "Unknown Meat";
}

inline std::string ToString(Veggie v) {
    switch (v) {
    case Veggie::Lettuce:   return "Lettuce";
    case Veggie::Tomato:    return "Tomato";
    case Veggie::Onion:     return "Onion";
    case Veggie::Mushroom:  return "Mushroom";
    case Veggie::Corn:      return "Corn";
    }
    return "Unknown Veggie";
}

inline std::string ToString(Seasoning s) {
    switch (s) {
    case Seasoning::Salt:        return "Salt";
    case Seasoning::Pepper:      return "Pepper";
    case Seasoning::SoySauce:    return "Soy Sauce";
    case Seasoning::ChiliSauce:  return "Chili Sauce";
    case Seasoning::Cheese:      return "Cheese";
    }
    return "Unknown Seasoning";
}

inline std::string ToString(Sweet s) {
    switch (s) {
    case Sweet::Sugar:      return "Sugar";
    case Sweet::Milk:       return "Milk";
    case Sweet::Chocolate:  return "Chocolate";
    }
    return "Unknown Sweet";
}

inline std::string ToString(DrinkBase d) {
    switch (d) {
    case DrinkBase::Tea:        return "Tea";
    case DrinkBase::Coffee:     return "Coffee";
    case DrinkBase::FruitJuice: return "Fruit Juice";
    case DrinkBase::Pepsi:      return "Pepsi";
    case DrinkBase::Cola:       return "Cola";
    case DrinkBase::Sprite:     return "Sprite";
    }
    return "Unknown Drink";
}

inline std::string ToString(FoodType f) {
    switch (f) {
    case FoodType::Burger: return "Burger";
    case FoodType::Drink:  return "Drink";
    case FoodType::Noodle: return "Noodle";
    case FoodType::Salad:  return "Salad";
    case FoodType::Soup:   return "Soup";
    case FoodType::Dessert: return "Dessert";
    case FoodType::None:   return "None";
    }
    return "Unknown FoodType";
}

template <typename T>
std::string ToString(const std::vector<T>& vec) {
    if (vec.empty()) return "(none)";

    std::string result;
    for (size_t i = 0; i < vec.size(); ++i) {
        result += ToString(vec[i]);
        if (i + 1 < vec.size()) result += ", ";
    }
    return result;
}

#endif