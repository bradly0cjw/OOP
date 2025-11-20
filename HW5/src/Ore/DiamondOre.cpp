#include "Ore/DiamondOre.hpp"

DiamondOre::DiamondOre(): Ore(Product::Diamond,10) {
    this->breakexp=4;
}

float DiamondOre::GetBreakExp() {
    return this->breakexp;
}