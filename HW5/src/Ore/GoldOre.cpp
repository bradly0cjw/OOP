#include "Ore/GoldOre.hpp"

GoldOre::GoldOre(): SmeltableOre(Product::Gold,5) {
    this->smeltexp=1;
    this->breakexp=0;
};

float GoldOre::GetBreakExp() {
    return this->breakexp;
};
float GoldOre::GetSmeltExp(){
    return this->smeltexp;
}