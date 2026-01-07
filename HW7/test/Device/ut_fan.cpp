#include <gtest/gtest.h>
#include "Device/Fan.hpp"

TEST(FanTest, Constructor_ValidPower_DefaultSpeedIsLow) {
    Fan fan("DeskFan", 20);

    EXPECT_EQ(fan.getDeviceType(), DeviceType::Fan);
    EXPECT_EQ(fan.getName(), "DeskFan");
    EXPECT_EQ(fan.getPower(), 20);
    EXPECT_EQ(fan.getSpeed(), FanSpeed::Low);
}

TEST(FanTest, Constructor_InvalidPower_TooLow_ThrowsException) {
    EXPECT_THROW(Fan("SmallFan", 10), std::invalid_argument);
}

TEST(FanTest, Constructor_InvalidPower_TooHigh_ThrowsException) {
    EXPECT_THROW(Fan("LargeFan", 50), std::invalid_argument);
}

TEST(FanTest, Constructor_WithSpeed_OverridesDefault) {
    Fan fan("TurboFan", 30, FanSpeed::Turbo);

    EXPECT_EQ(fan.getSpeed(), FanSpeed::Turbo);
}

TEST(FanTest, SetSpeed_ChangesSpeed) {
    Fan fan("RoomFan", 25);

    fan.setSpeed(FanSpeed::High);
    EXPECT_EQ(fan.getSpeed(), FanSpeed::High);

    fan.setSpeed(FanSpeed::Medium);
    EXPECT_EQ(fan.getSpeed(), FanSpeed::Medium);
}
