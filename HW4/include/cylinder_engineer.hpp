#ifndef CYLINDER_ENGINEER_HPP
#define CYLINDER_ENGINEER_HPP

#include <string>
#include "staff.hpp"
#include "staff_level.hpp"
class  CylinderEngineer final:public Staff {
public:
    CylinderEngineer(std::string name, std::string phone, int ext, StaffLevel level);
};

#endif