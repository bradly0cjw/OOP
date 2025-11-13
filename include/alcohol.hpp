#ifndef ALHOCOL_HPP
#define ALHOCOL_HPP

#include <string>
#include "coupon.hpp"
#include "food_product.hpp"
class Alcohol:public FoodProduct {
public:
    Alcohol(std::string name, int price, int expiredYear, int expiredMonth, int expiredDay): FoodProduct(name,price*0.6,price,expiredYear,expiredMonth,expiredDay) {}
    void CheckAge(int ages);
    void ApplyCoupon(Coupon coupon);
    int ages;
    Coupon coupon;
    void   SetPrice(int price);
};

#endif