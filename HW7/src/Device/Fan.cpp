#include "Device/Fan.hpp"

#include <stdexcept>

Fan::Fan(std::string name, int power):Device(DeviceType::Fan,name,power) {
    if (power<15 || power>40) {
        throw std::invalid_argument("");
    }
    this->speed = FanSpeed::Low;
}

Fan::Fan(std::string name, int power, FanSpeed speed):Device(DeviceType::Fan,name,power) {
    if (power<15 || power>40) {
        throw std::invalid_argument("");
    }
    this->speed = speed;
}

void Fan::setSpeed(FanSpeed speed) {
    this->speed = speed;
}
FanSpeed Fan::getSpeed() {
    return speed;
}
