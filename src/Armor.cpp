#include "Armor.hpp"

Armor::Armor(ArmorType armorType) : _type(armorType), _enchantment(Enchantment::NaN) {}

ArmorType Armor::GetArmorType() {
    return _type;
}

Enchantment Armor::GetEnchantment() {
    return _enchantment;
}

void Armor::ApplyEnchantment(const Enchantment e) {
    _enchantment = e;
}
