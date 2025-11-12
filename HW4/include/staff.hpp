#ifndef STAFF_HPP
#define STAFF_HPP

#include <string>
#include "person.hpp"
#include "staff_level.hpp"
#include "staff_no.hpp"
#include "title.hpp"

class Staff: public Person {
public:
    Staff(std::string name, Title title, std::string phone, int ext, StaffNo staffNo, StaffLevel level) ;
    StaffNo GetStaffNo();
    StaffLevel GetStaffLevel();
    int GetBasicSalary();
    int GetTotalSalary();
    int GetBonus();

    StaffNo staffNo;
    StaffLevel staffLevel;
};

#endif