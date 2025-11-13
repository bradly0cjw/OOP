#include "food_product.hpp"

bool FoodProduct::CheckExpired(int year, int month, int day) {
    if (year>expiredYear){
        price=0;
        return true;
    }else if(year==expiredYear){
        if(month>expiredMonth){
            price=0;
            return true;
        }else if(month==expiredMonth){
            if(day>expiredDay){
                price=0;
                return true;
            }
        }
    }
    return false;
}