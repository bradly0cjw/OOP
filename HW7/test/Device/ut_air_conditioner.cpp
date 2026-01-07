#include <gtest/gtest.h>
#include "Device/AirConditioner.hpp"

TEST(AirConditionerTest, Constructor_DefaultTemperatureIs25) {
    AirConditioner ac("RoomAC", 1000);

    EXPECT_EQ(ac.getDeviceType(), DeviceType::AirConditioner);
    EXPECT_EQ(ac.getName(), "RoomAC");
    EXPECT_EQ(ac.getPower(), 1000);
    EXPECT_EQ(ac.getTemperature(), 25);
}

TEST(AirConditionerTest, Constructor_WithTemperature_SetsTemperature) {
    AirConditioner ac("LivingRoomAC", 1200, 18);

    EXPECT_EQ(ac.getTemperature(), 18);
}

TEST(AirConditionerTest, Constructor_WithInvalidTemperature_TooLow_Throws) {
    EXPECT_THROW(AirConditioner("BadAC1", 1000, 5), std::invalid_argument);
}

TEST(AirConditionerTest, Constructor_WithInvalidTemperature_TooHigh_Throws) {
    EXPECT_THROW(AirConditioner("BadAC2", 1000, 40), std::invalid_argument);
}

TEST(AirConditionerTest, SetTemperature_ValidValue_UpdatesCorrectly) {
    AirConditioner ac("WorkAC", 900);

    ac.setTemperature(22);
    EXPECT_EQ(ac.getTemperature(), 22);

    ac.setTemperature(30);
    EXPECT_EQ(ac.getTemperature(), 30);
}

TEST(AirConditionerTest, SetTemperature_InvalidTooLow_Throws) {
    AirConditioner ac("OfficeAC", 900);

    EXPECT_THROW(ac.setTemperature(8), std::invalid_argument);
}

TEST(AirConditionerTest, SetTemperature_InvalidTooHigh_Throws) {
    AirConditioner ac("OfficeAC", 900);

    EXPECT_THROW(ac.setTemperature(40), std::invalid_argument);
}
