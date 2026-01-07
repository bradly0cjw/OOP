#include "Pickaxe.hpp"

Pickaxe::Pickaxe(PickaxeType pickaxeType) : _type(pickaxeType), _enchantment(Enchantment::NaN) {}

PickaxeType Pickaxe::GetPickaxeType() {
    return _type;
}

Enchantment Pickaxe::GetEnchantment() {
    return _enchantment;
}

void Pickaxe::ApplyEnchantment(const Enchantment e) {
    _enchantment = e;
}
