#ifndef MANAGER_HPP
#define MANAGER_HPP

#include "Food.hpp"
#include <memory>
#include <vector>


#include "Food.hpp"
#include <memory>
#include <vector>

class Manager{
public:
    Manager(std::vector<std::shared_ptr<Food>> food);
    void CookAllFood();
    void CountAllFoodPrice();
    std::vector<std::shared_ptr<Food>> GetFood();
private:
    std::vector<std::shared_ptr<Food>> foods;
};

#endif