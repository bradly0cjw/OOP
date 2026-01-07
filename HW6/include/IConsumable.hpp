#ifndef ICONSUMABLE_HPP
#define ICONSUMABLE_HPP

#include "Material.hpp"

class IConsumable {
public:
    virtual ~IConsumable() = default;

    virtual Material GetMaterial() = 0;
};

#endif
