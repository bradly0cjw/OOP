#ifndef INFRASTRUCTURE_ENGINEER_HPP
#define INFRASTRUCTURE_ENGINEER_HPP

#include <string>
#include "vendor.hpp"
class InfrastructureEngineer final:public Vendor {
public:
    InfrastructureEngineer(std::string name, std::string phone, int ext);
};

#endif