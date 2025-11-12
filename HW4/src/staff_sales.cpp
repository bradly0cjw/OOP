#include "staff_sales.hpp"
#include "title.hpp"

StaffSales::StaffSales(
    std::string name,
    std::string phone,
    int         ext,
    StaffLevel  level
)
    : Staff(name, Title::STAFF_SALES, phone, ext, StaffNo::S, level) {}

void StaffSales::ApplyBonus(int totalSales, int count) {
    this->totalSales = totalSales;
    this->count = count;
}
int StaffSales::GetBonus() {
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
