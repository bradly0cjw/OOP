#ifndef LAPIS_LAZULI_HPP
#define LAPIS_LAZULI_HPP

#include "IConsumable.hpp"
#include <memory>

class LapisLazuli final : public IConsumable {
public:
    LapisLazuli();
    Material GetMaterial() override;
};

#endif
