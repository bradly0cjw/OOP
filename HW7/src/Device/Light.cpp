#include "Device/Light.hpp"
#include <stdexcept>

Light::Light(std::string name, int power):Device(DeviceType::Light,name,power) {
    if (power<5 || power>20) {
        throw std::invalid_argument("");
    }
    this->intensity=0;
}

Light::Light(std::string name, int power, int intensity):Device(DeviceType::Light,name,power) {
    if (power<5 || power>20) {
        throw std::invalid_argument("");
    }
    if (intensity<0||intensity>100) {
        throw std::invalid_argument("");
    }
    this->intensity=intensity;
}

int Light::getIntensity() {
    return this->intensity;
}

void Light::setIntensity(int intensity) {
    if (intensity<0||intensity>100) {
        throw std::invalid_argument("");
    }
    this->intensity=intensity;
}
