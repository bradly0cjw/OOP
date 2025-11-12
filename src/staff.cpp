#include "staff.hpp"
#include "staff_level.hpp"
#include "staff_no.hpp"

#include "iostream"
Staff::Staff(
    std::string name,
    Title       title,
    std::string phone,
    int         ext,
    StaffNo     staffNo,
    StaffLevel  level
)
    : Person(name, title, phone, ext) {
    this->staffNo = staffNo;
    this->staffLevel = level;
}

StaffNo Staff::GetStaffNo() {
    return this->staffNo;
    //    return StaffNo::S;
}

StaffLevel Staff::GetStaffLevel() {
    return this->staffLevel;
    //    return StaffLevel::L1;
}

int Staff::GetBasicSalary() {
    int basic;
    float mul=1;
    float month=16;
    switch (staffNo) {
    case (StaffNo::M):
        basic = 120000;
        if (staffLevel == StaffLevel::L2) {
            mul= 1.68;
        } else if (staffLevel == StaffLevel::L3) {
            mul= 2.32;
        }
        break;
    case (StaffNo::S):
        basic = 73000;
        if (staffLevel == StaffLevel::L2) {
            mul= 1.17;
        } else if (staffLevel == StaffLevel::L3) {
            mul= 1.32;
        }
        break;
    case (StaffNo::E):
        basic = 93000;
        if (staffLevel == StaffLevel::L2) {
            mul= 1.43;
        } else if (staffLevel == StaffLevel::L3) {
            mul= 1.82;
        }
        break;
    case (StaffNo::N):
        basic = 55000;
        if (staffLevel == StaffLevel::L2) {
            mul= 1.12;
        } else if (staffLevel == StaffLevel::L3) {
            mul= 1.24;
        }
        break;
    }
    return basic*mul*month;
}

int Staff::GetTotalSalary() {
    return GetBasicSalary() + GetBonus();
    return 0;
}

int Staff::GetBonus() {
    switch (staffNo) {
    case (StaffNo::M):
        if (staffLevel == StaffLevel::L1) {
            return 60000;
        } else if (staffLevel == StaffLevel::L2) {
            return 73000;
        } else {
            return 94000;
        }
    case (StaffNo::E):
        if (staffLevel == StaffLevel::L1) {
            return 56000;
        } else if (staffLevel == StaffLevel::L2) {
            return 64000;
        } else {
            return 83000;
        }
    }
    return 0;
}
