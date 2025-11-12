#include "extern_sales.hpp"
#include "vendor.hpp"

ExternSales::ExternSales(std::string name, std::string phone, int ext): Vendor(name,Title::EXTERN_SALES,phone,ext){

}

void ExternSales::ApplyBonus(int totalSales, int count){
    this->totalSales = totalSales;
    this->count = count;
}
int ExternSales::GetBonus() {
    int bonus = 0;
    if (count <= 10) {
        bonus = totalSales * 0.1;
    } else if (count <= 20) {
        bonus = totalSales * 0.15;
    } else {
        bonus = totalSales * 0.2;
    }
    return bonus;
}
