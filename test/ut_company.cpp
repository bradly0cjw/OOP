#include <gtest/gtest.h>
#include "Company.hpp"
#include "PowerSwitch/NormalPowerSwitch.hpp"
#include "Device/Device.hpp"
#include <memory>
#include <vector>
#include <algorithm>

#include "test_utils.hpp"

TEST(CompanyConstructorTest, InitializesCorrectly) {
    Company company("TestCorp", 42);
    EXPECT_EQ(company.getName(), "TestCorp");
    EXPECT_EQ(company.getFloorNumber(), 42);
    EXPECT_FALSE(company.isWork());
    ASSERT_NE(company.getMainSwitch(), nullptr);
    EXPECT_EQ(company.getMainSwitch()->getName(), "company42_mainPowerSwitch");
    EXPECT_EQ(company.countPower(), 0);
}

// Test Fixture for a company with pre-added switches
class CompanyTest : public ::testing::Test {
protected:
    std::unique_ptr<Company> company;
    std::shared_ptr<NormalPowerSwitch> ns1, ns2, ns3;

    void SetUp() override {
        company = std::make_unique<Company>("Gemini Inc.", 101);
        ns1 = makeNormalSwitch("s1", DeviceType::Light, "Office Light", 50);
        ns2 = makeNormalSwitch("s2", DeviceType::Fan, "Office Fan", 100);
        ns3 = makeNormalSwitch("s3", DeviceType::Light, "Lobby Light", 75);

        company->addPowerSwitch(ns1);
        company->addPowerSwitch(ns2);
        company->addPowerSwitch(ns3);
    }
};

TEST_F(CompanyTest, InitialState) {
    EXPECT_EQ(company->getName(), "Gemini Inc.");
    EXPECT_EQ(company->getFloorNumber(), 101);
    EXPECT_FALSE(company->isWork());
    // Switches are added but off, so power is 0
    EXPECT_EQ(company->countPower(), 0);
}

TEST_F(CompanyTest, WorkAndOffWorkCycle) {
    // Initial state: Off
    ASSERT_FALSE(company->isWork());
    ASSERT_EQ(company->countPower(), 0);
    ASSERT_EQ(ns1->getState(), PowerSwitchState::Off);

    // Action: Start work
    company->work();

    // Post-work state: On
    EXPECT_TRUE(company->isWork());
    EXPECT_EQ(company->countPower(), 50 + 100 + 75);
    EXPECT_EQ(ns1->getState(), PowerSwitchState::On);
    EXPECT_EQ(ns2->getState(), PowerSwitchState::On);
    EXPECT_EQ(ns3->getState(), PowerSwitchState::On);

    // Action: Off work
    company->offWork();

    // Post-offWork state: Off again
    EXPECT_FALSE(company->isWork());
    EXPECT_EQ(company->countPower(), 0);
    EXPECT_EQ(ns1->getState(), PowerSwitchState::Off);
    EXPECT_EQ(ns2->getState(), PowerSwitchState::Off);
    EXPECT_EQ(ns3->getState(), PowerSwitchState::Off);
}

TEST_F(CompanyTest, AddAndRemovePowerSwitch) {
    // Start with power on to see the effect of changes
    company->work();
    ASSERT_EQ(company->countPower(), 225);

    // Remove a switch and check power
    company->removePowerSwitch(ns2);
    EXPECT_EQ(company->countPower(), 50 + 75); // 125

    // Remove company main power switch
    EXPECT_THROW(company->removePowerSwitch(company->getMainSwitch()), std::invalid_argument);

    // Add a new switch while company is working
    auto ns4 = makeNormalSwitch("s4", DeviceType::AirConditioner, "AC", 1500);
    company->addPowerSwitch(ns4);

    // The new switch is off by default, power is unchanged
    EXPECT_EQ(ns4->getState(), PowerSwitchState::Off);
    EXPECT_EQ(company->countPower(), 125);

    // Calling work() again should turn on the newly added switch
    company->work();
    EXPECT_EQ(ns4->getState(), PowerSwitchState::On);
    EXPECT_EQ(company->countPower(), 125 + 1500);
}

TEST_F(CompanyTest, FindPowerSwitchByName) {
    auto foundSwitches = company->findPowerSwitchByName("s1");
    ASSERT_EQ(foundSwitches.size(), 1);
    EXPECT_EQ(foundSwitches[0], ns1);

    auto notFoundSwitches = company->findPowerSwitchByName("nonexistent");
    EXPECT_TRUE(notFoundSwitches.empty());
}

TEST_F(CompanyTest, FindDeviceByName) {
    auto foundDevices = company->findDeviceByName("Office Light");
    ASSERT_EQ(foundDevices.size(), 1);
    EXPECT_EQ(foundDevices[0], ns1->getDevice());

    auto notFoundDevices = company->findDeviceByName("nonexistent");
    EXPECT_TRUE(notFoundDevices.empty());
}

TEST_F(CompanyTest, FindDeviceByType) {
    auto foundLights = company->findDeviceByType(DeviceType::Light);
    ASSERT_EQ(foundLights.size(), 2);
    
    // Check that both light devices are present, regardless of order
    EXPECT_TRUE(std::find(foundLights.begin(), foundLights.end(), ns1->getDevice()) != foundLights.end());
    EXPECT_TRUE(std::find(foundLights.begin(), foundLights.end(), ns3->getDevice()) != foundLights.end());

    auto foundFans = company->findDeviceByType(DeviceType::Fan);
    ASSERT_EQ(foundFans.size(), 1);
    EXPECT_EQ(foundFans[0], ns2->getDevice());

    auto notFound = company->findDeviceByType(DeviceType::Dehumidifier);
    EXPECT_TRUE(notFound.empty());
}