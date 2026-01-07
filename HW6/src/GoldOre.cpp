#include "GoldOre.hpp"
#include "Ingot.hpp"
#include "Material.hpp"

GoldOre::GoldOre() {}

bool GoldOre::BreakableBy(Pickaxe pickaxe) {
    PickaxeType type = pickaxe.GetPickaxeType();
    return type == PickaxeType::Iron || type == PickaxeType::Diamond;
}

std::shared_ptr<Ingot> GoldOre::Smelt() {
    return std::make_shared<Ingot>(Material::Gold);
}
