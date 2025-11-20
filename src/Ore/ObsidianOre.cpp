#include "Ore/ObsidianOre.hpp"

ObsidianOre::ObsidianOre(): Ore(Product::Obsidian,40) {
    this->breakexp=8;
}
float ObsidianOre::GetBreakExp() {
    return this->breakexp;
}