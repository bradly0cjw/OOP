#ifndef NORMAL_PRODUCT_HPP
#define NORMAL_PRODUCT_HPP

#include "cost_ratio.hpp"
#include "product.hpp"
#include "coupon.hpp"

class NormalProduct : public Product{
public:
    NormalProduct(std::string name, int price): Product(name,int(price*0.75),price) {}
    void ApplyCoupon(Coupon coupon);
    Coupon coupon;
    void   SetPrice(int price);
};

#endif