#ifndef POWERSWITCH_HPP
#define POWERSWITCH_HPP

#include "PowerSwitchState.hpp"
#include <string>

class PowerSwitch {
private:
    std::string name;
public:
    virtual ~PowerSwitch() = default;
    PowerSwitch(std::string name) : name(name){}

    std::string getName() {
        return name;
    }

    virtual PowerSwitchState getState() = 0;
    virtual void turnOn() = 0;
    virtual void turnOff() = 0;
    virtual void flip() = 0;
    virtual int countPower() = 0;
};

#endif
