#ifndef IENCHANTABLE_HPP
#define IENCHANTABLE_HPP

#include "Enchantment.hpp"

class IEnchantable {
public:
    virtual ~IEnchantable() = default;

    virtual void ApplyEnchantment(const Enchantment e) = 0;
};

#endif