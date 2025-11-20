#ifndef GOLDORE_HPP
#define GOLDORE_HPP

#include "SmeltableOre.hpp"
class GoldOre: public SmeltableOre{
public:
    explicit GoldOre();
    float GetBreakExp() override;
    float GetSmeltExp() override;
};

#endif
