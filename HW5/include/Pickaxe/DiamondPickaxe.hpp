#ifndef DIAMONDPICKAXE_HPP
#define DIAMONDPICKAXE_HPP

#include "Pickaxe.hpp"
class DiamondPickaxe: public Pickaxe{
public:
    explicit DiamondPickaxe();
    Product Mining(std::shared_ptr<Ore> &ore) override;
};

#endif
