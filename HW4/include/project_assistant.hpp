#ifndef PROJECT_ASSISTANT_HPP
#define PROJECT_ASSISTANT_HPP

#include <string>
#include "staff.hpp"
#include "staff_level.hpp"

class ProjectAssistant final : public Staff {
public:
    ProjectAssistant(std::string name, std::string phone, int ext, StaffLevel level);
};

#endif