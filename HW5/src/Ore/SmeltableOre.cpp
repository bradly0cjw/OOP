#include "Ore/SmeltableOre.hpp"

SmeltableOre::SmeltableOre(Product pro, int durabilityCost): Ore(pro,durabilityCost) {
    this->smeltexp=0;
}

float SmeltableOre::GetSmeltExp() {
    return this->smeltexp;
}
SmeltableOre::~SmeltableOre() {

}
