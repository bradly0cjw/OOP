#include "product_3c.hpp"
#include "coupon.hpp"

void Product3C::ApplyCoupon(Coupon coupon) {
//    this->coupon=coupon;
    switch (coupon) {
    case(Coupon::TECHLIFE80):
        price*=0.8;
        break;
    case(Coupon::HEALTHY90):
        price*=0.9;
        break;
    case(Coupon::BACK2SCHOOL):
        price*=0.8;
        break;
    case(Coupon::OOPALLPASS):
        price*=1;
        break;
    case(Coupon::FESTIVE80):
        price*=0.8;
        break;
    case(Coupon::OOPALLFAILED):
        price*=0;
        break;
    default:
        price*=1;
        break;
    }
}
void Product3C::SetPrice(int price) {
    if (price<0){
        throw std::invalid_argument("");
    }
    this->price=price;
    this->cost=price*0.6;
}