#include "PowerSwitch/MainPowerSwitch.hpp"
#include "PowerSwitch/NormalPowerSwitch.hpp"

MainPowerSwitch::MainPowerSwitch(std::string name):PowerSwitch(name) {
    this->powerSwitches=std::vector<std::shared_ptr<PowerSwitch>>();
}
MainPowerSwitch::MainPowerSwitch(
    std::string                               name,
    std::vector<std::shared_ptr<PowerSwitch>> powerSwitches
): PowerSwitch(name) {
    this->powerSwitches=powerSwitches;
}

void MainPowerSwitch::addPowerSwitch(std::shared_ptr<PowerSwitch> powerSwitch) {
    this->powerSwitches.push_back(powerSwitch);
}
void MainPowerSwitch::removePowerSwitch(
    std::shared_ptr<PowerSwitch> powerSwitch
) {
    for (auto it = this->powerSwitches.begin(); it != this->powerSwitches.end(); ++it) {
        if (*it == powerSwitch) {
            this->powerSwitches.erase(it);
            return;
        }
    }
}
std::vector<std::shared_ptr<Device>> MainPowerSwitch::findDeviceByDeviceType(
    DeviceType type
) {
    std::vector<std::shared_ptr<Device>> devices;
    for (auto& ps : this->powerSwitches) {
        if (auto nps = std::dynamic_pointer_cast<NormalPowerSwitch>(ps)) {
            auto dev = nps->getDevice();
            if (dev && dev->getDeviceType() == type) {
                devices.push_back(dev);
            }
        } else if (auto mps = std::dynamic_pointer_cast<MainPowerSwitch>(ps)) {
            auto subDevices = mps->findDeviceByDeviceType(type);
            devices.insert(devices.end(), subDevices.begin(), subDevices.end());
        }
    }
    return devices;
}
std::vector<std::shared_ptr<Device>> MainPowerSwitch::findDeviceByName(
    std::string name
) {
    std::vector<std::shared_ptr<Device>> devices;
    for (auto& ps : this->powerSwitches) {
        if (auto nps = std::dynamic_pointer_cast<NormalPowerSwitch>(ps)) {
            auto dev = nps->getDevice();
            if (dev && dev->getName() == name) {
                devices.push_back(dev);
            }
        } else if (auto mps = std::dynamic_pointer_cast<MainPowerSwitch>(ps)) {
            auto subDevices = mps->findDeviceByName(name);
            devices.insert(devices.end(), subDevices.begin(), subDevices.end());
        }
    }
    return devices;
}
std::vector<std::shared_ptr<PowerSwitch>> MainPowerSwitch::
    findPowerSwitchByName(std::string name) {
    std::vector<std::shared_ptr<PowerSwitch>> found;
    for (auto& ps : this->powerSwitches) {
        if (ps->getName() == name) {
            found.push_back(ps);
        }
        if (auto mps = std::dynamic_pointer_cast<MainPowerSwitch>(ps)) {
            if (ps->getName() != name) {
                auto sub = mps->findPowerSwitchByName(name);
                found.insert(found.end(), sub.begin(), sub.end());
            }
        }
    }
    return found;
}
PowerSwitchState MainPowerSwitch::getState() {
    if (this->powerSwitches.empty()) {
        return PowerSwitchState::NotDefined;
    }
    bool hasOn = false;
    bool hasOff = false;
    for (auto& ps : this->powerSwitches) {
        PowerSwitchState s = ps->getState();
        if (s == PowerSwitchState::Mixed) {
            return PowerSwitchState::Mixed;
        }
        if (s == PowerSwitchState::On) {
            hasOn = true;
        }
        if (s == PowerSwitchState::Off) {
            hasOff = true;
        }
    }
    if (hasOn && hasOff) {
        return PowerSwitchState::Mixed;
    }
    if (hasOn) {
        return PowerSwitchState::On;
    }
    return PowerSwitchState::Off;
}
void             MainPowerSwitch::turnOn() {
    for (auto& ps : this->powerSwitches) {
        ps->turnOn();
    }
}
void             MainPowerSwitch::turnOff() {
    for (auto& ps : this->powerSwitches) {
        ps->turnOff();
    }
}
int  MainPowerSwitch::countPower() {
    int total = 0;
    for (auto& ps : this->powerSwitches) {
        total += ps->countPower();
    }
    return total;
}
void MainPowerSwitch::flip() {
    for (auto& ps : this->powerSwitches) {
        ps->flip();
    }
}

