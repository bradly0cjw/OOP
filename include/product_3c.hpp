#ifndef PRODUCT_3C_HPP
#define PRODUCT_3C_HPP

#include <string>
#include "coupon.hpp"
#include "warrenty_product.hpp"

class Product3C: public WarrentyProduct {
public:
    Product3C(std::string name, int price, int warrentyYear, int warrentyMonth): WarrentyProduct(name,price*0.6,price,warrentyYear,warrentyMonth) {}
    void ApplyCoupon(Coupon coupon);
    Coupon coupon;
    void   SetPrice(int price);
};

#endif