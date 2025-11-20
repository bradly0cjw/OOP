#include "Pickaxe/Pickaxe.hpp"

Pickaxe::Pickaxe(PickaxeType pickaxeType, int durability) {
    this->pickaxeType=pickaxeType;
    this->durability=durability;
}

Product Pickaxe::Mining(std::shared_ptr<Ore> &ore) {
    return Product::None;
}
Pickaxe::~Pickaxe() {

}
PickaxeType Pickaxe::GetPickaxeType() const {
    return this->pickaxeType;
}
int Pickaxe::GetDurability() const {
    return this->durability;
}
