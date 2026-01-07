#ifndef IRON_ORE_HPP
#define IRON_ORE_HPP

#include "ISmeltable.hpp"
#include "Ore.hpp"

class IronOre final : public Ore, public ISmeltable {
public:
    IronOre();
    bool BreakableBy(Pickaxe pickaxe) override;
    std::shared_ptr<Ingot> Smelt() override;
};

#endif
