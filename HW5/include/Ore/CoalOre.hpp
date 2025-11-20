#ifndef COALORE_HPP
#define COALORE_HPP

#include "Ore.hpp"
class CoalOre final: public Ore{
public:
    explicit CoalOre() ;
    float GetBreakExp() override;
};

#endif
