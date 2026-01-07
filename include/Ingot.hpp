#ifndef INGOT_HPP
#define INGOT_HPP

#include "Material.hpp"
#include "IConsumable.hpp"

class Ingot : public IConsumable {
public:
    Ingot(Material material);
    Material GetMaterial() override;

private:
   Material _material;
};

#endif
