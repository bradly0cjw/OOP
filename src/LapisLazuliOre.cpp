#include "LapisLazuliOre.hpp"

LapisLazuliOre::LapisLazuliOre() {}

bool LapisLazuliOre::BreakableBy(Pickaxe pickaxe) {
    PickaxeType type = pickaxe.GetPickaxeType();
    return type == PickaxeType::Stone || type == PickaxeType::Iron || type == PickaxeType::Diamond;
}
