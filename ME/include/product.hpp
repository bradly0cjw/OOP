#ifndef PRODUCT_HPP
#define PRODUCT_HPP

#include <stdexcept>
#include <string>

class Product {
public:
    Product(std::string name, int cost, int price) {
        if(cost<0||price<0){
            throw std::invalid_argument("");
        }
        this->name=name;
        this->cost=cost;
        this->price=price;
    }
    std::string GetName();
    int GetCost();
    int GetPrice();
    void SetName(std::string name);
    void SetCost(int cost);
    virtual void SetPrice(int price);
    std::string name;
    int cost;
    int price;
};

#endif