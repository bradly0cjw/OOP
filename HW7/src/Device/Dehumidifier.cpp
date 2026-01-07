#include "Device/Dehumidifier.hpp"
#include <stdexcept>

Dehumidifier::Dehumidifier(std::string name, int power):Device(DeviceType::Dehumidifier,name,power) {
    if (power<50 || power>350) {
        throw std::invalid_argument("");
    }
    this->humidity=0;
}
Dehumidifier::Dehumidifier(std::string name, int power, int humidity):Device(DeviceType::Dehumidifier,name,power) {
    if (power<50 || power>350) {
        throw std::invalid_argument("");
    }
    if (humidity<0||humidity>100) {
        throw std::invalid_argument("");
    }
    this->humidity=humidity;
}

void Dehumidifier::setHumidity(int humidity) {
    if (humidity<0||humidity>100) {
        throw std::invalid_argument("");
    }
    this->humidity=humidity;
}
int Dehumidifier::getHumidity() {
    return this->humidity;
}