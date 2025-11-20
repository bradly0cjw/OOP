#ifndef WOODENPACKAXE_HPP
#define WOODENPACKAXE_HPP

#include "Pickaxe.hpp"
class WoodenPickaxe :public Pickaxe {
public:
    explicit WoodenPickaxe();
    Product Mining(std::shared_ptr<Ore> &ore) override;

};

#endif
