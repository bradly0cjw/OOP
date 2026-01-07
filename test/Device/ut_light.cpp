#include <gtest/gtest.h>
#include "Device/Light.hpp"

// --- Constructor Tests ---

TEST(LightTest, ConstructorWithoutIntensity) {
    Light light("DeskLight", 10);

    EXPECT_EQ(light.getDeviceType(), DeviceType::Light);
    EXPECT_EQ(light.getName(), "DeskLight");
    EXPECT_EQ(light.getPower(), 10);
    EXPECT_EQ(light.getIntensity(), 0);   // default intensity
}

TEST(LightTest, ConstructorWithIntensity) {
    Light light("CeilingLight", 15, 80);

    EXPECT_EQ(light.getDeviceType(), DeviceType::Light);
    EXPECT_EQ(light.getName(), "CeilingLight");
    EXPECT_EQ(light.getPower(), 15);
    EXPECT_EQ(light.getIntensity(), 80);
}


// --- Power Range Tests ---

TEST(LightTest, ConstructorPowerTooLow) {
    EXPECT_THROW(Light("BadLight", 4), std::invalid_argument);
}

TEST(LightTest, ConstructorPowerTooHigh) {
    EXPECT_THROW(Light("BadLight", 21), std::invalid_argument);
}


// --- Intensity Tests ---

TEST(LightTest, SetIntensityValid) {
    Light light("TestLight", 10);
    light.setIntensity(50);

    EXPECT_EQ(light.getIntensity(), 50);
}

TEST(LightTest, SetIntensityTooLow) {
    Light light("TestLight", 10);
    EXPECT_THROW(light.setIntensity(-1), std::invalid_argument);
}

TEST(LightTest, SetIntensityTooHigh) {
    Light light("TestLight", 10);
    EXPECT_THROW(light.setIntensity(101), std::invalid_argument);
}
