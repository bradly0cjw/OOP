#ifndef PICKAXE_HPP
#define PICKAXE_HPP

#include <memory>

#include "Ore/Ore.hpp"
#include "PickaxeType.hpp"
#include "Durability.hpp"

class Pickaxe{
protected:
    PickaxeType pickaxeType;
    int durability;
public:
    Pickaxe(PickaxeType pickaxeType, int durability);
    ~Pickaxe();

    [[nodiscard]] PickaxeType GetPickaxeType() const;
    [[nodiscard]] int GetDurability() const;

    virtual Product Mining(std::shared_ptr<Ore> &ore);
};

#endif
