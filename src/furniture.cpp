#include "furniture.hpp"

void Furniture::ApplyCoupon(Coupon coupon) {
    //    this->coupon=coupon;
    switch (coupon) {
    case(Coupon::NEWHOME70):
        price*=0.7;
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

void Furniture::SetPrice(int price) {
    if (price<0){
        throw std::invalid_argument("");
    }
    this->price=price;
    this->cost=price*0.9;
}
