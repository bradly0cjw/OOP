#include "Ingot.hpp"

Ingot::Ingot(Material material) : _material(material) {}

Material Ingot::GetMaterial() {
    return _material;
}
