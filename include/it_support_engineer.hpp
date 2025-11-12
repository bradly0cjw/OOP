#ifndef IT_SUPPORT_ENGINEER_HPP
#define IT_SUPPORT_ENGINEER_HPP

#include <string>
#include "vendor.hpp"
class ITSupportEngineer final:public Vendor{
public:
    ITSupportEngineer(std::string name, std::string phone, int ext);
};

#endif