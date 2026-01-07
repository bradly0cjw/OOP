#include "CopperOre.hpp"
#include "Ingot.hpp"
#include "Material.hpp"

CopperOre::CopperOre() {}

bool CopperOre::BreakableBy(Pickaxe pickaxe) {
    PickaxeType type = pickaxe.GetPickaxeType();
    return type == PickaxeType::Stone || type == PickaxeType::Iron || type == PickaxeType::Diamond;
}

std::shared_ptr<Ingot> CopperOre::Smelt() {
    return std::make_shared<Ingot>(Material::Copper);
}
