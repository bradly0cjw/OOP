#ifndef PROJECT_MANAGER_HPP
#define PROJECT_MANAGER_HPP

#include <string>
#include "staff.hpp"
#include "staff_level.hpp"
class ProjectManager final:public Staff {
public:
    ProjectManager(std::string name, std::string phone, int ext, StaffLevel level);
};

#endif