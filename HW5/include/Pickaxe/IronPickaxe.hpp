#ifndef IRONPICKAXE_HPP
#define IRONPICKAXE_HPP

#include "Pickaxe.hpp"
class IronPickaxe: public Pickaxe{
public:
    explicit IronPickaxe();
    Product Mining(std::shared_ptr<Ore> &ore) override;

};

#endif
