#ifndef NOODLE_HPP
#define NOODLE_HPP

#include "Food.hpp"

class Noodle : public Food{
public:
    Noodle(Ingredient ingredient);
    ~Noodle() override;
    void Cook() override;
};

#endif