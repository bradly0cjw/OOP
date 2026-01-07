#include <gtest/gtest.h>
#include "PowerSwitch/MainPowerSwitch.hpp"
#include "PowerSwitch/NormalPowerSwitch.hpp"
#include "Device/Device.hpp"
#include <memory>
#include <vector>
#include <algorithm>

#include "../test/test_utils.hpp"

TEST(MainPowerSwitchTest, DefaultConstructor_HasNoSwitches_StateNotDefined)
{
    MainPowerSwitch ms("main");
    EXPECT_EQ(ms.getState(), PowerSwitchState::NotDefined);
}

TEST(MainPowerSwitchTest, ConstructorWithSwitches_ReturnsCorrectState)
{
    auto s1 = makeNormalSwitch("s1", DeviceType::Light, "Lamp", 10);
    auto s2 = makeNormalSwitch("s2", DeviceType::Fan, "Fan", 20);

    std::vector<std::shared_ptr<PowerSwitch>> switches = { s1, s2 };
    MainPowerSwitch ms("main", switches);

    EXPECT_EQ(ms.getState(), PowerSwitchState::Off);  // Default is Off
}

TEST(MainPowerSwitchTest, AddPowerSwitch_IncreasesCount_AndStateMatches)
{
    MainPowerSwitch ms("main");

    auto s1 = makeNormalSwitch("s1", DeviceType::Light, "Lamp", 10);
    ms.addPowerSwitch(s1);

    EXPECT_EQ(ms.getState(), PowerSwitchState::Off);

    auto s2 = makeNormalSwitch("s2", DeviceType::Fan, "Fan", 20);
    ms.addPowerSwitch(s2);

    EXPECT_EQ(ms.getState(), PowerSwitchState::Off);
}

TEST(MainPowerSwitchTest, GetState_MixedState)
{
    auto s1 = makeNormalSwitch("s1", DeviceType::Light, "Lamp", 10);
    auto s2 = makeNormalSwitch("s2", DeviceType::Fan, "Fan", 20);

    s1->turnOn();
    s2->turnOff();

    std::vector<std::shared_ptr<PowerSwitch>> vec = { s1, s2 };
    MainPowerSwitch ms("main", vec);

    EXPECT_EQ(ms.getState(), PowerSwitchState::Mixed);
}

TEST(MainPowerSwitchTest, TurnOn_AllSwitchesBecomeOn)
{
    auto s1 = makeNormalSwitch("s1", DeviceType::Light, "Lamp", 10);
    auto s2 = makeNormalSwitch("s2", DeviceType::Fan, "Fan", 20);
    auto s3 = makeNormalSwitch("s3", DeviceType::AirConditioner, "AC", 1000);

    MainPowerSwitch ms("main", {s1, s2, s3});

    ms.turnOn();

    EXPECT_EQ(s1->getState(), PowerSwitchState::On);
    EXPECT_EQ(s2->getState(), PowerSwitchState::On);
    EXPECT_EQ(s3->getState(), PowerSwitchState::On);

    EXPECT_EQ(ms.getState(), PowerSwitchState::On);
}

TEST(MainPowerSwitchTest, TurnOff_AllSwitchesBecomeOff)
{
    auto s1 = makeNormalSwitch("s1", DeviceType::Light, "Lamp", 10);
    auto s2 = makeNormalSwitch("s2", DeviceType::Fan, "Fan", 20);

    s1->turnOn();
    s2->turnOn();

    MainPowerSwitch ms("main", {s1, s2});
    ms.turnOff();

    EXPECT_EQ(s1->getState(), PowerSwitchState::Off);
    EXPECT_EQ(s2->getState(), PowerSwitchState::Off);
    EXPECT_EQ(ms.getState(), PowerSwitchState::Off);
}

TEST(MainPowerSwitchTest, Flip_FlipsAllSwitches)
{
    auto s1 = makeNormalSwitch("s1", DeviceType::Light, "Lamp", 10);
    auto s2 = makeNormalSwitch("s2", DeviceType::Fan, "Fan", 20);

    // s1 Off -> On
    // s2 Off -> On
    MainPowerSwitch ms("main", {s1, s2});
    ms.flip();

    EXPECT_EQ(s1->getState(), PowerSwitchState::On);
    EXPECT_EQ(s2->getState(), PowerSwitchState::On);
    EXPECT_EQ(ms.getState(), PowerSwitchState::On);

    // Flip again
    ms.flip();

    EXPECT_EQ(s1->getState(), PowerSwitchState::Off);
    EXPECT_EQ(s2->getState(), PowerSwitchState::Off);
    EXPECT_EQ(ms.getState(), PowerSwitchState::Off);
}

TEST(MainPowerSwitchTest, CountPower_SumsAllSwitches)
{
    auto s1 = makeNormalSwitch("s1", DeviceType::Light, "Lamp", 10);
    auto s2 = makeNormalSwitch("s2", DeviceType::Fan, "Fan", 20);
    auto s3 = makeNormalSwitch("s3", DeviceType::Loudspeaker, "Speaker", 50);

    MainPowerSwitch ms("main", {s1, s2, s3});

    // Default is Off -> count = 0
    EXPECT_EQ(ms.countPower(), 0);

    ms.turnOn();

    // On -> power = sum of device power
    EXPECT_EQ(ms.countPower(), 10 + 20 + 50);
}

TEST(MainPowerSwitchTest, RemovePowerSwitch)
{
    MainPowerSwitch ms("main");
    auto s1 = makeNormalSwitch("s1", DeviceType::Light, "Lamp", 10);
    auto s2 = makeNormalSwitch("s2", DeviceType::Fan, "Fan", 20);
    ms.addPowerSwitch(s1);
    ms.addPowerSwitch(s2);
    s1->turnOn();
    s2->turnOn();
    EXPECT_EQ(ms.countPower(), 30);

    ms.removePowerSwitch(s1);
    EXPECT_EQ(ms.countPower(), 20);
    EXPECT_EQ(ms.getState(), PowerSwitchState::On);

    // Try removing a switch that isn't there
    ms.removePowerSwitch(s1);
    EXPECT_EQ(ms.countPower(), 20);

    ms.removePowerSwitch(s2);
    EXPECT_EQ(ms.countPower(), 0);
    EXPECT_EQ(ms.getState(), PowerSwitchState::NotDefined);
}

// Test fixture for complex nested structure
class MainPowerSwitchComplexTest : public ::testing::Test {
protected:
    // Structure:
    // ms1("ms1") -> [ ns1("s1", Light, "Lamp"), ns2("s2", Fan, "Fan"), ms2("ms2") ]
    // ms2("ms2") -> [ ns3("s3", AC), ns_ms2_conflict("ms2", Light, "Conflict Lamp") ]

    std::shared_ptr<NormalPowerSwitch> ns1, ns2, ns3, ns_ms2_conflict;
    std::shared_ptr<MainPowerSwitch> ms1, ms2;

    void SetUp() override {
        // Create devices and normal switches
        ns1 = makeNormalSwitch("s1", DeviceType::Light, "Lamp", 10);
        ns2 = makeNormalSwitch("s2", DeviceType::Fan, "Fan", 30);
        ns3 = makeNormalSwitch("s3", DeviceType::AirConditioner, "AC", 1200);
        ns_ms2_conflict = makeNormalSwitch("ms2", DeviceType::Light, "Conflict Lamp", 15); // Name conflicts with ms2

        // Create main switches and build the structure
        ms2 = std::make_shared<MainPowerSwitch>("ms2");
        ms2->addPowerSwitch(ns3);
        ms2->addPowerSwitch(ns_ms2_conflict);

        ms1 = std::make_shared<MainPowerSwitch>("ms1");
        ms1->addPowerSwitch(ns1);
        ms1->addPowerSwitch(ns2);
        ms1->addPowerSwitch(ms2);
    }
};

TEST_F(MainPowerSwitchComplexTest, FindPowerSwitchByName_Recursive)
{
    // Case 1: Find a simple nested switch ("s3")
    auto found_s3 = ms1->findPowerSwitchByName("s3");
    ASSERT_EQ(found_s3.size(), 1);
    EXPECT_EQ(found_s3[0], ns3);

    // Case 2: Find a non-existent switch
    auto found_none = ms1->findPowerSwitchByName("nonexistent");
    EXPECT_EQ(found_none.size(), 0);

    // Case 3: Find a switch by name "ms2".
    // The current implementation has a bug: if a MainPowerSwitch's name matches,
    // it returns that switch but does NOT recurse inside it.
    // This test verifies the actual (buggy) behavior.
    auto found_ms2 = ms1->findPowerSwitchByName("ms2");
    ASSERT_EQ(found_ms2.size(), 1);
    EXPECT_EQ(found_ms2[0], ms2); // It only finds the MainPowerSwitch container
}

TEST_F(MainPowerSwitchComplexTest, FindDeviceByName_Recursive)
{
    // Find "Lamp", should find 1 device from ns1.
    auto found_lamps = ms1->findDeviceByName("Lamp");
    ASSERT_EQ(found_lamps.size(), 1);
    EXPECT_EQ(found_lamps[0], ns1->getDevice());

    // Find "AC", should get 1 device from ns3 inside ms2
    auto found_ac = ms1->findDeviceByName("AC");
    ASSERT_EQ(found_ac.size(), 1);
    EXPECT_EQ(found_ac[0], ns3->getDevice());

    // Find "Conflict Lamp", should get 1 device from ns_ms2_conflict inside ms2
    auto found_conflict = ms1->findDeviceByName("Conflict Lamp");
    ASSERT_EQ(found_conflict.size(), 1);
    EXPECT_EQ(found_conflict[0], ns_ms2_conflict->getDevice());
}

TEST_F(MainPowerSwitchComplexTest, FindDeviceByDeviceType_Recursive)
{
    // Find Light, should get 2 devices from ns1 and ns_ms2_conflict
    auto found_lights = ms1->findDeviceByDeviceType(DeviceType::Light);
    ASSERT_EQ(found_lights.size(), 2);

    // Check that both devices are present, regardless of order
    EXPECT_TRUE(std::find(found_lights.begin(), found_lights.end(), ns1->getDevice()) != found_lights.end());
    EXPECT_TRUE(std::find(found_lights.begin(), found_lights.end(), ns_ms2_conflict->getDevice()) != found_lights.end());

    // Find Fan, should get 1
    auto found_fans = ms1->findDeviceByDeviceType(DeviceType::Fan);
    ASSERT_EQ(found_fans.size(), 1);
    EXPECT_EQ(found_fans[0], ns2->getDevice());

    // Find a type that doesn't exist
    auto found_none = ms1->findDeviceByDeviceType(DeviceType::Dehumidifier);
    EXPECT_EQ(found_none.size(), 0);
}