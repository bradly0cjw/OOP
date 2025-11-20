#ifndef DIAMONDORE_HPP
#define DIAMONDORE_HPP

#include "Ore.hpp"
class DiamondOre : public Ore {
public:
    explicit DiamondOre();
    float GetBreakExp() override;
};

#endif
