#ifndef TEST_UTILS_HPP
#define TEST_UTILS_HPP

#include "PowerSwitch/NormalPowerSwitch.hpp"
#include "Device/Device.hpp"
#include <memory>
#include <string>

// Helper to create a NormalPowerSwitch with a specific name and device
// Marked as inline to prevent multiple definition linker errors when included in multiple files.
inline std::shared_ptr<NormalPowerSwitch> makeNormalSwitch(const std::string& switchName, DeviceType devType, const std::string& devName, int devPower) {
    auto dev = std::make_shared<Device>(devType, devName, devPower);
    return std::make_shared<NormalPowerSwitch>(switchName, dev);
}

#endif //TEST_UTILS_HPP
