#ifndef WARRENTY_PRODUCT_HPP
#define WARRENTY_PRODUCT_HPP

#include <string>
#include "product.hpp"

class WarrentyProduct: public Product {
public:
    WarrentyProduct(std::string name, int cost, int price, int warrentyYear, int warrentyMonth): Product(name,cost,price) {
        if (warrentyMonth<0){
            throw std::invalid_argument("");
        }
        if(warrentyYear<0){
            throw std::invalid_argument("");
        }
        this->warrentyYear=warrentyYear;
        this->warrentyMonth=warrentyMonth;
    }

    bool IsExpired(int year, int month, int day);
    int warrentyYear;
    int warrentyMonth;
};

#endif