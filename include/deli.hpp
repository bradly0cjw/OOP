#ifndef DELI_HPP
#define DELI_HPP

#include <string>
#include "coupon.hpp"
#include "food_product.hpp"

class Deli :public FoodProduct{
public:
    Deli(std::string name, int price, int expiredYear, int expiredMonth, int expiredDay): FoodProduct(name,price*0.8,price,expiredYear,expiredMonth,expiredDay) {}
    void ApplyCoupon(Coupon coupon);
    void ApplyExpireCoupon();
    Coupon coupon;
    void   SetPrice(int price);
};

#endif