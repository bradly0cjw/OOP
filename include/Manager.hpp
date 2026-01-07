#ifndef MANAGER_HPP
#define MANAGER_HPP

#include <memory>
#include <vector>
#include "IFood.hpp"

class Manager{
private:
    std::vector<std::shared_ptr<IFood>> foods;
public:
    Manager();
    void SetFood(std::vector<std::shared_ptr<IFood>> food);
    void MakeFood();
    std::vector<std::shared_ptr<IFood>> GetFood();
};

#endif