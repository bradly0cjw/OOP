#include "Pickaxe/StonePickaxe.hpp"
#include <stdexcept>

StonePickaxe::StonePickaxe(): Pickaxe(PickaxeType::Stone,131) {

}

Product StonePickaxe::Mining(std::shared_ptr<Ore> &ore) {
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
        return Product::None;
    case Product::Diamond:
        this->durability-=ore->durabilityCost;
        ore= nullptr;
        return Product::None;
    default:
        throw std::invalid_argument("");
    }
}