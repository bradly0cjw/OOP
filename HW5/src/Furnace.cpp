#include "Furnace.hpp"

#include <stdexcept>

Furnace::Furnace() {
    smeltItem=Product::None;
}
Furnace::~Furnace() {

}
std::vector<std::shared_ptr<Ore>> Furnace::PickupProduct() {
    std::vector<std::shared_ptr<Ore>> temp =Item;
    Item.clear();
    smeltItem=Product::None;
    return temp;
}
void Furnace::AddOre(std::shared_ptr<SmeltableOre> ore) {
    if(Item.size()>=64)
        throw std::invalid_argument("");
    if (smeltItem!=Product::None&&ore->product!=smeltItem)
        throw std::invalid_argument("");
    smeltItem=ore->product;
    Item.push_back(ore);

}
void Furnace::AddAnyOre(std::shared_ptr<Ore> ore) {
    auto smeltable = std::dynamic_pointer_cast<SmeltableOre>(ore);
    if (!smeltable)
        throw std::invalid_argument("");
    AddOre(smeltable);
}
