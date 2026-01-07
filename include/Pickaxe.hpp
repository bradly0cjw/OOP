#ifndef PICKAXE_HPP
#define PICKAXE_HPP

#include "IEnchantable.hpp"

enum class PickaxeType {
    Wood,
    Stone,
    Gold,
    Iron,
    Diamond,
};

class Pickaxe final : public IEnchantable {
public:
    Pickaxe(PickaxeType pickaxeType);
    PickaxeType GetPickaxeType();
    Enchantment GetEnchantment();
    void ApplyEnchantment(const Enchantment e) override;

private:
   PickaxeType _type;
   Enchantment _enchantment;
};

#endif
