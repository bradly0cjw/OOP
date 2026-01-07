#ifndef TOSTRING_HPP
#define TOSTRING_HPP
#include <string>
#include "Ingredient.hpp"
#include "Option.hpp"

inline std::string ToString(Ingredient b) {
    switch (b) {
    case Ingredient::Bread:  return "Bread";
    case Ingredient::Meat: return "Meat";
    case Ingredient::Lettuce: return "Lettuce";
    case Ingredient::Cheese: return "Cheese";
    case Ingredient::FrenchFries: return "FrenchFries";
    case Ingredient::Nuggets: return "Nuggets";
    case Ingredient::HashBrowns: return "HashBrowns";
    case Ingredient::Cola: return "Cola";
    case Ingredient::CaramelMilkTea: return "CaramelMilkTea";
    case Ingredient::BlackTea: return "BlackTea";
    case Ingredient::Apple: return "Apple";
    case Ingredient::Chocolate: return "Chocolate";
    case Ingredient::Pudding: return "Pudding";
    }
    return "Unknown Ingredient";
}

inline std::string ToString(Option b) {
    switch (b) {
    case Option::Large:  return "Large";
    case Option::AddOnions: return "AddOnions";
    case Option::AddPickles:   return "AddPickles";
    case Option::LessSalt:  return "LessSalt";
    case Option::NoSalt: return "NoSalt";
    case Option::LessIce:   return "LessIce";
    case Option::NoIce:  return "NoIce";
    case Option::ExtraSugar: return "ExtraSugar";
    case Option::HalfSugar: return "HalfSugar";
    case Option::None: return "None";
    }
    return "Unknown Option";
}

#endif