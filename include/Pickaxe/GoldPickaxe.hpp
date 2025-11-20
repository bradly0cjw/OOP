#ifndef GOLDENPICKAXE_HPP
#define GOLDENPICKAXE_HPP

#include "Pickaxe.hpp"
class GoldPickaxe: public Pickaxe{
public:
    explicit GoldPickaxe();
    Product Mining(std::shared_ptr<Ore> &ore) override;
};

#endif
