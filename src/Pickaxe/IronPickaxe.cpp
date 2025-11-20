#include "Pickaxe/IronPickaxe.hpp"
#include <stdexcept>


IronPickaxe::IronPickaxe(): Pickaxe(PickaxeType::Iron,250) {
    
}

Product IronPickaxe::Mining(std::shared_ptr<Ore> &ore) {
    if (ore== nullptr)
        throw std::invalid_argument("");
    if(this->durability<ore->durabilityCost)
        throw  std::invalid_argument("");
    
    switch(ore->product){
    case Product::Coal:
        this->durability-=ore->durabilityCost;
        ore= nullptr;
        return Product::Coal;
    case Product::Iron:
        this->durability-=ore->durabilityCost;
        ore= nullptr;
        return Product::Iron;
    case Product::Gold:
        this->durability-=ore->durabilityCost;
        ore= nullptr;
        return Product::Gold;
    case Product::Diamond:
        this->durability-=ore->durabilityCost;
        ore= nullptr;
        return Product::Diamond;
    case Product::Obsidian:
        this->durability-=ore->durabilityCost;
        ore= nullptr;
        return Product::None;
    default:
        throw std::invalid_argument("");
    }
}