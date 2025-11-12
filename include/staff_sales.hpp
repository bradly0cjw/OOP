#ifndef SALES_HPP
#define SALES_HPP

#include <string>
#include "staff.hpp"
#include "staff_level.hpp"
class StaffSales final:public Staff{
public:
    StaffSales(std::string name, std::string phone, int ext, StaffLevel level);
    void ApplyBonus(int totalSales, int count);
    int GetBonus();
    int totalSales;
    int count;
};

#endif