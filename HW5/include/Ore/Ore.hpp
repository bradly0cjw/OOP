#ifndef ORE_HPP
#define ORE_HPP

#include "Product.hpp"
#include "BreakExp.hpp"
#include "DurabilityCost.hpp"


class Ore {
public:
    explicit Ore(Product product, int durabilityCost);
    ~Ore();

    [[nodiscard]] Product GetProduct() const;
    [[nodiscard]] int GetDurabilityCost() const;

    virtual float GetBreakExp() ;
    Product product;
    int durabilityCost;
    int breakexp;
};

#endif
