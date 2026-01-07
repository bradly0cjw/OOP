#include <gtest/gtest.h>
#include "PowerSwitch/NormalPowerSwitch.hpp"
#include "Device/Device.hpp"
#include <memory>

TEST(NormalPowerSwitchTest, DefaultConstructor_InitialStateOff_NoDevice)
{
    NormalPowerSwitch sw("normal");

    EXPECT_EQ(sw.getState(), PowerSwitchState::Off);
    EXPECT_EQ(sw.getDevice(), nullptr);
}

TEST(NormalPowerSwitchTest, ConstructorWithDevice_InitialStateOff)
{
    auto dev = std::make_shared<Device>(DeviceType::Light, "Lamp", 50);
    NormalPowerSwitch sw("normal", dev);

    EXPECT_EQ(sw.getState(), PowerSwitchState::Off);
    EXPECT_EQ(sw.getDevice(), dev);
}

TEST(NormalPowerSwitchTest, TurnOn_TurnOff)
{
    auto dev = std::make_shared<Device>(DeviceType::Fan, "Fan", 30);
    NormalPowerSwitch sw("normal", dev);

    sw.turnOn();
    EXPECT_EQ(sw.getState(), PowerSwitchState::On);

    sw.turnOff();
    EXPECT_EQ(sw.getState(), PowerSwitchState::Off);
}

TEST(NormalPowerSwitchTest, FlipSwitch)
{
    NormalPowerSwitch sw("normal");

    sw.flip();
    EXPECT_EQ(sw.getState(), PowerSwitchState::On);

    sw.flip();
    EXPECT_EQ(sw.getState(), PowerSwitchState::Off);
}

TEST(NormalPowerSwitchTest, CountPower_WhenOff_ReturnZero)
{
    auto dev = std::make_shared<Device>(DeviceType::AirConditioner, "AC", 1200);
    NormalPowerSwitch sw("normal", dev);

    sw.turnOff();
    EXPECT_EQ(sw.countPower(), 0);
}

TEST(NormalPowerSwitchTest, CountPower_WhenOn_ReturnDevicePower)
{
    auto dev = std::make_shared<Device>(DeviceType::Dehumidifier, "Dehumidifier", 88);
    NormalPowerSwitch sw("normal", dev);

    sw.turnOn();
    EXPECT_EQ(sw.countPower(), 88);
}

TEST(NormalPowerSwitchTest, GetDeviceName)
{
    auto dev = std::make_shared<Device>(DeviceType::Light, "Lamp", 50);
    NormalPowerSwitch sw("normal", dev);
    EXPECT_EQ(sw.getDeviceName(), "Lamp");
}

TEST(NormalPowerSwitchTest, AddDevice_Success)
{
    NormalPowerSwitch sw("normal");
    EXPECT_EQ(sw.getDevice(), nullptr);

    auto dev = std::make_shared<Device>(DeviceType::Fan, "Fan", 30);
    sw.addDevice(dev);

    EXPECT_EQ(sw.getDevice(), dev);
}

TEST(NormalPowerSwitchTest, AddDevice_DeviceAlreadyExists_ThrowsException)
{
    auto dev1 = std::make_shared<Device>(DeviceType::Light, "Lamp", 50);
    NormalPowerSwitch sw("normal", dev1);
    auto dev2 = std::make_shared<Device>(DeviceType::Fan, "Fan", 30);

    EXPECT_THROW(sw.addDevice(dev2), std::invalid_argument);
}

TEST(NormalPowerSwitchTest, RemoveDevice_Success)
{
    auto dev = std::make_shared<Device>(DeviceType::Dehumidifier, "Dehumidifier", 88);
    NormalPowerSwitch sw("normal", dev);

    auto removed_dev = sw.removeDevice();

    EXPECT_EQ(removed_dev, dev);
    EXPECT_EQ(sw.getDevice(), nullptr);
}

TEST(NormalPowerSwitchTest, RemoveDevice_NoDevice_ThrowsException)
{
    NormalPowerSwitch sw("normal");
    EXPECT_THROW(sw.removeDevice(), std::invalid_argument);
}

TEST(NormalPowerSwitchTest, ChangeDevice_Success)
{
    auto dev1 = std::make_shared<Device>(DeviceType::Light, "Lamp", 50);
    auto dev2 = std::make_shared<Device>(DeviceType::Fan, "Fan", 30);
    NormalPowerSwitch sw("normal", dev1);

    auto old_dev = sw.changeDevice(dev2);

    EXPECT_EQ(old_dev, dev1);
    EXPECT_EQ(sw.getDevice(), dev2);
}

TEST(NormalPowerSwitchTest, ChangeDevice_FromNull)
{
    NormalPowerSwitch sw("normal");
    auto dev = std::make_shared<Device>(DeviceType::Fan, "Fan", 30);

    EXPECT_THROW(sw.changeDevice(dev), std::invalid_argument);
}