#include "DiamondOre.hpp"

DiamondOre::DiamondOre() {}

bool DiamondOre::BreakableBy(Pickaxe pickaxe) {
    PickaxeType type = pickaxe.GetPickaxeType();
    return type == PickaxeType::Iron || type == PickaxeType::Diamond;
}
