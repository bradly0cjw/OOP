#ifndef EXTERN_SALES_HPP
#define EXTERN_SALES_HPP

#include <string>
#include "vendor.hpp"
class ExternSales final: public Vendor {
private:
    int totalSales;
    int count;

public:
    ExternSales(std::string name, std::string phone, int ext);
    void ApplyBonus(int totalSales, int count);
    int GetBonus();
};

#endif