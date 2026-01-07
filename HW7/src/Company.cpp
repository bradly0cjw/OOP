#include "Company.hpp"
#include <stdexcept>

Company::Company(std::string name, int floorNumber) {
    this->name = name;
    this->floorNumber = floorNumber;
    this->working = false;
    this->mainPowerSwitchName="company"+ std::to_string(floorNumber) + "_mainPowerSwitch";
    this->mainPowerSwitch = std::make_shared<MainPowerSwitch>(this->mainPowerSwitchName);
}
std::string Company::getName() {
    return this->name;
}
int Company::getFloorNumber() {
    return this->floorNumber;
}
std::shared_ptr<PowerSwitch> Company::getMainSwitch() {
    return this->mainPowerSwitch;
}

bool Company::isWork() {
    return working;
}

void Company::addPowerSwitch(std::shared_ptr<PowerSwitch> powerSwitch) {
    this->mainPowerSwitch->addPowerSwitch(powerSwitch);
}
void Company::removePowerSwitch(std::shared_ptr<PowerSwitch> powerSwitch) {
    if (powerSwitch == this->mainPowerSwitch) {
        throw std::invalid_argument("");
    }
    this->mainPowerSwitch->removePowerSwitch(powerSwitch);
}

std::vector<std::shared_ptr<PowerSwitch>> Company::findPowerSwitchByName(std::string name) {
    return this->mainPowerSwitch->findPowerSwitchByName(name);
}
std::vector<std::shared_ptr<Device>> Company::findDeviceByName(std::string name) {
    return this->mainPowerSwitch->findDeviceByName(name);
}
std::vector<std::shared_ptr<Device>> Company::findDeviceByType(DeviceType type) {
    return this->mainPowerSwitch->findDeviceByDeviceType(type);
}

void Company::work() {
    this->mainPowerSwitch->turnOn();
    this->working = true;
}
void Company::offWork() {
    this->mainPowerSwitch->turnOff();
    this->working = false;
}

int Company::countPower() {
    return this->mainPowerSwitch->countPower();
}