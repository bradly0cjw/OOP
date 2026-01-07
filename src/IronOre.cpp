#include "IronOre.hpp"
#include "Ingot.hpp"
#include "Material.hpp"

IronOre::IronOre() {}

bool IronOre::BreakableBy(Pickaxe pickaxe) {
    PickaxeType type = pickaxe.GetPickaxeType();
    return type == PickaxeType::Stone || type == PickaxeType::Iron || type == PickaxeType::Diamond;
}

std::shared_ptr<Ingot> IronOre::Smelt() {
    return std::make_shared<Ingot>(Material::Iron);
}
