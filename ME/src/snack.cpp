#include "snack.hpp"
#include "coupon.hpp"

void Snack::ApplyCoupon(Coupon coupon) {
    switch (coupon) {
    case (Coupon::SAKETIME79):
        price*=0.7;
        break;
    case(Coupon::WEEKEND80):
        price*=0.8;
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
        break;
    }


}
void Snack::SetPrice(int price) {
    if (price<0){
        throw std::invalid_argument("");
    }
    this->price=price;
    this->cost=price*0.75;
}