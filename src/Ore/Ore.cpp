#include "Ore/Ore.hpp"

#include <stdexcept>

Ore::Ore(Product product, int durabilityCost){
    if (product==Product::None)
        throw std::invalid_argument("");
    this->product=product;
    this->durabilityCost=durabilityCost;
    this->breakexp=0;
};

Product Ore::GetProduct() const {
    return this->product;
};

int Ore::GetDurabilityCost() const{
    return this->durabilityCost;
}

float Ore::GetBreakExp() {
    return this->breakexp;
}
Ore::~Ore() {

}
