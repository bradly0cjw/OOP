#include "deli.hpp"
#include "coupon.hpp"

void Deli::ApplyCoupon(Coupon coupon) {
    //    this->coupon=coupon;
    switch (coupon) {
    case(Coupon::LUNCHTIME90):
        price*=0.9;
        break;
    case(Coupon::TEATIME80):
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
    }
}

void Deli::ApplyExpireCoupon() {
    price*=0.8;
}

void Deli::SetPrice(int price) {
    if (price<0){
        throw std::invalid_argument("");
    }
    this->price=price;
    this->cost=price*0.8;
}
