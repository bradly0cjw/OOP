#ifndef MAINPOWERSWITCH_HPP
#define MAINPOWERSWITCH_HPP

#include <memory>
#include <vector>
#include "Device/Device.hpp"
#include "PowerSwitch.hpp"

class MainPowerSwitch : public PowerSwitch {
public:
    MainPowerSwitch(std::string name);
    MainPowerSwitch(std::string name, std::vector<std::shared_ptr<PowerSwitch>> powerSwitches);

    void addPowerSwitch(std::shared_ptr<PowerSwitch> powerSwitch);
    void removePowerSwitch(std::shared_ptr<PowerSwitch> powerSwitch);
    std::vector<std::shared_ptr<PowerSwitch>> findPowerSwitchByName(std::string name);
    std::vector<std::shared_ptr<Device>> findDeviceByName(std::string name);
    std::vector<std::shared_ptr<Device>> findDeviceByDeviceType(DeviceType type);

    PowerSwitchState getState() override;
    void turnOn() override;
    void turnOff() override;
    void flip() override;
    int countPower() override;
private:
    std::vector<std::shared_ptr<PowerSwitch>> powerSwitches;

};

#endif
