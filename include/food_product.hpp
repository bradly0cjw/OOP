#ifndef FOOD_PRODUCT_HPP
#define FOOD_PRODUCT_HPP

#include <string>
#include "product.hpp"

class FoodProduct:public Product {
public:
    FoodProduct(std::string name, int cost, int price, int expiredYear, int expiredMonth, int expiredDay):Product(name,cost,price) {
        if (expiredMonth<0||expiredYear<0||expiredDay<0){
            throw std::invalid_argument("");
        }
        this->expiredDay=expiredDay;
        this->expiredYear=expiredYear;
        this->expiredMonth=expiredMonth;
    }
    bool CheckExpired(int year, int month, int day);
    int expiredYear;
    int expiredMonth;
    int expiredDay;
};

#endif