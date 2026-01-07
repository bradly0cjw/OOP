#include "Device/Device.hpp"

Device::Device(DeviceType deviceType, std::string name, int power) {
    this->deviceType = deviceType;
    this->name = name;
    this->power = power;
}

DeviceType Device::getDeviceType() {
    return deviceType;
}
std::string Device::getName() {
    return name;
}
int Device::getPower() {
    return power;
}
