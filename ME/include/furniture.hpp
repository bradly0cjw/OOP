#ifndef FURNITURE_HPP
#define FURNITURE_HPP

#include <string>
#include "coupon.hpp"
#include "warrenty_product.hpp"

class Furniture :public WarrentyProduct{
public:
    Furniture(std::string name, int price, int warrentyYear, int warrentyMonth): WarrentyProduct(name,price*0.9,price,warrentyYear,warrentyMonth) {}
    void ApplyCoupon(Coupon coupon);
    Coupon coupon;
    void   SetPrice(int price);
};

#endif