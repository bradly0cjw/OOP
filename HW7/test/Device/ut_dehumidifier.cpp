#include <gtest/gtest.h>
#include "Device/Dehumidifier.hpp"

TEST(DehumidifierTest, Constructor_DefaultHumidityIs0) {
    Dehumidifier deh("RoomDeh", 50);

    EXPECT_EQ(deh.getDeviceType(), DeviceType::Dehumidifier);
    EXPECT_EQ(deh.getName(), "RoomDeh");
    EXPECT_EQ(deh.getPower(), 50);
    EXPECT_EQ(deh.getHumidity(), 0);
}

TEST(DehumidifierTest, Constructor_WithHumidity_SetsHumidity) {
    Dehumidifier deh("LivingDeh", 60, 40);

    EXPECT_EQ(deh.getHumidity(), 40);
}

TEST(DehumidifierTest, SetHumidity_ValidValue_UpdatesCorrectly) {
    Dehumidifier deh("OfficeDeh", 55);

    deh.setHumidity(25);
    EXPECT_EQ(deh.getHumidity(), 25);

    deh.setHumidity(75);
    EXPECT_EQ(deh.getHumidity(), 75);
}

TEST(DehumidifierTest, SetHumidity_InvalidTooLow_Throws) {
    Dehumidifier deh("BadDeh", 50);

    EXPECT_THROW(deh.setHumidity(-1), std::invalid_argument);
}

TEST(DehumidifierTest, SetHumidity_InvalidTooHigh_Throws) {
    Dehumidifier deh("BadDeh", 50);

    EXPECT_THROW(deh.setHumidity(101), std::invalid_argument);
}
