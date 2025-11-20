#ifndef STONEPICKAXE_HPP
#define STONEPICKAXE_HPP

#include "Pickaxe.hpp"
class StonePickaxe:public Pickaxe {
public:
    explicit StonePickaxe();
    Product Mining(std::shared_ptr<Ore> &ore) override;
};

#endif
