#include "Device/Loudspeaker.hpp"
#include <stdexcept>

Loudspeaker::Loudspeaker(std::string name, int power):Device(DeviceType::Loudspeaker,name,power) {
    if (power<5 || power>200) {
        throw std::invalid_argument("");
    }
    this->volume=0;
}

Loudspeaker::Loudspeaker(std::string name, int power, int volume):Device(DeviceType::Loudspeaker,name,power) {
    if (power<5 || power>200) {
        throw std::invalid_argument("");
    }
    if (volume<0||volume>100) {
        throw std::invalid_argument("");
    }
    this->volume=volume;
}

void Loudspeaker::setVolume(int volume) {
    if (volume<0||volume>100) {
        throw std::invalid_argument("");
    }
    this->volume=volume;
}

int Loudspeaker::getVolume() {
    return this->volume;
}

