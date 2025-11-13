#include "product.hpp"
#include <stdexcept>

std::string Product::GetName() {
    //    return "";
    return this->name;
}

int Product::GetCost() {
    //    return 0;

    return this->cost;
}

int Product::GetPrice() {
//    return 0;
    return this->price;
}

void Product::SetName(std::string name) {
    this->name=name;
}

void Product::SetCost(int cost) {
    if (cost<0){
        throw std::invalid_argument("");
    }
    this->cost=cost;
}

void Product::SetPrice(int price) {
    if (price<0){
        throw std::invalid_argument("");
    }
    this->price=price;
}
