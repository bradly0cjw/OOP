#include "Ore/IronOre.hpp"

IronOre::IronOre(): SmeltableOre(Product::Iron,3) {
    this->breakexp=0;
    this->smeltexp=0.7;
}

float IronOre::GetBreakExp() {
    return this->breakexp;
}
float IronOre::GetSmeltExp() {
    return this->smeltexp;
}

