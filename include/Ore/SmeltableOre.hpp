#ifndef SMELTABLEORE_HPP
#define SMELTABLEORE_HPP

#include "Ore.hpp"
#include "SmeltExp.hpp"

class SmeltableOre : public Ore {
public:
    explicit SmeltableOre(Product pro, int durabilityCost);
    ~SmeltableOre();

    virtual float GetSmeltExp();
    float smeltexp;
};

#endif
