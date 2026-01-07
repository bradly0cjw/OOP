#ifndef LAPIS_LAZULI_ORE_HPP
#define LAPIS_LAZULI_ORE_HPP

#include "IConsumable.hpp"
#include "Ore.hpp"

class LapisLazuliOre final : public Ore {
public:
    LapisLazuliOre();
    bool BreakableBy(Pickaxe pickaxe) override;
};

#endif
