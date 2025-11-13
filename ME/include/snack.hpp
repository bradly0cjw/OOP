#ifndef SNACK_HPP
#define SNACK_HPP

#include <string>
#include "coupon.hpp"
#include "food_product.hpp"

class Snack: public FoodProduct {
public:
    Snack(std::string name, int price, int expiredYear, int expiredMonth, int expiredDay): FoodProduct(name,price*0.75,price,expiredYear,expiredMonth,expiredDay) {}

    void ApplyCoupon(Coupon coupon);
    Coupon coupon;
    void   SetPrice(int price);
};

#endif
