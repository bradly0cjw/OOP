#include "warrenty_product.hpp"

bool WarrentyProduct::IsExpired(int year, int month, int day){
    if (year>warrentyYear){
        return true;
    }else if(year==warrentyYear){
        if(month>warrentyMonth){
            return true;
        }
    }

    return false;
}