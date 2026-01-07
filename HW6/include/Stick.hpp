#ifndef STICK_HPP
#define STICK_HPP

#include "IConsumable.hpp"

class Stick final : public IConsumable {
public:
    Stick();
    Material GetMaterial() override;
};








#endif