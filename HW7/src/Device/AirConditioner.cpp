#include "Device/AirConditioner.hpp"
#include <stdexcept>

AirConditioner::AirConditioner(std::string name, int power):Device(DeviceType::AirConditioner,name,power) {
    if (power<500 || power>2000) {
        throw std::invalid_argument("");
    }
    this->temperature=25;
}

AirConditioner::AirConditioner(std::string name, int power, int temperature):Device(DeviceType::AirConditioner,name,power) {
    if (power<500 || power>2000) {
        throw std::invalid_argument("");
    }
    if (temperature<10 || temperature>35) {
        throw std::invalid_argument("");
    }
    this->temperature = temperature;
}

void AirConditioner::setTemperature(int temperature) {
    if (temperature<10 || temperature>35) {
        throw std::invalid_argument("");
    }
    this->temperature = temperature;
}
int AirConditioner::getTemperature() {
    return this->temperature;
}