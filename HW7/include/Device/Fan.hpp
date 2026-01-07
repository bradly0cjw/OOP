#ifndef FAN_HPP
#define FAN_HPP

#include "Device.hpp"

enum class FanSpeed{
    Low,
    Medium,
    High,
    Turbo
};

class Fan : public Device {
private:
    FanSpeed speed;
public:
    Fan(std::string name, int power);
    Fan(std::string name, int power, FanSpeed speed);

    void setSpeed(FanSpeed speed);
    FanSpeed getSpeed();
};

#endif
