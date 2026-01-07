#ifndef ICUSTOMIZABLE_HPP
#define ICUSTOMIZABLE_HPP

#include "Option.hpp"

class ICustomizable{
public:
    virtual void AddOption(Option option) = 0;
    virtual Option GetOption() = 0;
};

#endif