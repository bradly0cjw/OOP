#ifndef OBSIDIANORE_HPP
#define OBSIDIANORE_HPP

#include "Ore.hpp"
class ObsidianOre:public Ore {
public:
    explicit ObsidianOre();
    float GetBreakExp() override;
};

#endif
