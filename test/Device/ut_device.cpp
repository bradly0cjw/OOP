#include <gtest/gtest.h>
#include "Device/Device.hpp"

TEST(DeviceTest, ConstructorAndGetters) {
    Device d(DeviceType::AirConditioner, "AC-01", 1500);

    EXPECT_EQ(d.getDeviceType(), DeviceType::AirConditioner);
    EXPECT_EQ(d.getName(), "AC-01");
    EXPECT_EQ(d.getPower(), 1500);
}

TEST(DeviceTest, DifferentValues) {
    Device d(DeviceType::Light, "Light-01", 60);

    EXPECT_EQ(d.getDeviceType(), DeviceType::Light);
    EXPECT_EQ(d.getName(), "Light-01");
    EXPECT_EQ(d.getPower(), 60);
}
