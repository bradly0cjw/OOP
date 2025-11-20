#include "Ore/CoalOre.hpp"


CoalOre::CoalOre(): Ore(Product::Coal,1) {
    this->breakexp=2;

}

float CoalOre::GetBreakExp() {
    return this->breakexp;
}