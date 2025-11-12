#ifndef VENDOR_HPP
#define VENDOR_HPP

#include <string>
#include "person.hpp"
#include "service_score.hpp"
#include "title.hpp"

class Vendor:public Person{
public:
    Vendor(std::string name, Title title, std::string phone, int ext);
    void SetServiceScore(ServiceScore score);
    ServiceScore GetServiceScore();
    int GetBonus();
    ServiceScore serviceScore;
};

#endif