#include "vehicle.hpp"

void Vehicle::CheckAge(int ages) {
    if (ages < 18) {
        throw std::invalid_argument("");
    }
    this->ages = ages;
}

void Vehicle::ApplyCoupon(Coupon coupon) {
    //    this->coupon=coupon;
    switch (coupon) {
    case(Coupon::DRIVE90):
        price *=0.9;
        break;
    case (Coupon::OOPALLPASS):
        price *= 1;
        break;
    case (Coupon::FESTIVE80):
        price *= 0.8;
        break;
    case (Coupon::OOPALLFAILED):
        price *= 0;
        break;
    default:
        price *= 1;
        break;
    }
}
void Vehicle::SetPrice(int price) {
    if (price<0){
        throw std::invalid_argument("");
    }
    this->price=price;
    this->cost=price*0.8;
}
