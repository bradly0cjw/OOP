#ifndef BUILDING_HPP
#define BUILDING_HPP

#include "Company.hpp"
#include <vector>

class Building {
public:
    Building(int totalFloors);

    int getTotalFloors();
    std::vector<std::shared_ptr<Company>> getCompanies();

    int CountWorkingCompanies();

private:
    int totalFloors;
    std::vector<std::shared_ptr<Company>> companies;
};

#endif
