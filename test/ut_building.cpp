#include <gtest/gtest.h>
#include "Building.hpp"
#include "Company.hpp"
#include <vector>
#include <memory>

// Test fixture for Building tests to avoid repeating setup code
class BuildingTest : public ::testing::Test {
protected:
    std::unique_ptr<Building> building;
    const int floorCount = 5;

    void SetUp() override {
        building = std::make_unique<Building>(floorCount);
    }
};

TEST_F(BuildingTest, ConstructorAndGetters) {
    // Check total floors
    EXPECT_EQ(building->getTotalFloors(), floorCount);

    // Check the companies vector
    auto companies = building->getCompanies();
    ASSERT_EQ(companies.size(), floorCount);

    // Verify each company was created correctly
    for (int i = 0; i < floorCount; ++i) {
        ASSERT_NE(companies[i], nullptr);
        EXPECT_EQ(companies[i]->getFloorNumber(), i + 1);
        EXPECT_EQ(companies[i]->getName(), "company" + std::to_string(i + 1));
        EXPECT_FALSE(companies[i]->isWork());
    }
}

TEST_F(BuildingTest, CountWorkingCompanies) {
    // Initially, no company should be working
    EXPECT_EQ(building->CountWorkingCompanies(), 0);

    auto companies = building->getCompanies();
    
    // Start work at the company on floor 2
    auto companyOnFloor2 = companies[1]; // vector index 1 is floor 2
    ASSERT_NE(companyOnFloor2, nullptr);
    companyOnFloor2->work();
    EXPECT_EQ(building->CountWorkingCompanies(), 1);

    // Start work at the company on floor 4
    auto companyOnFloor4 = companies[3]; // vector index 3 is floor 4
    ASSERT_NE(companyOnFloor4, nullptr);
    companyOnFloor4->work();
    EXPECT_EQ(building->CountWorkingCompanies(), 2);

    // Calling work() again on an already working company should not change the count
    companyOnFloor2->work();
    EXPECT_EQ(building->CountWorkingCompanies(), 2);

    // Stop work at the company on floor 2
    companyOnFloor2->offWork();
    EXPECT_EQ(building->CountWorkingCompanies(), 1);

    // Stop work at the company on floor 4
    companyOnFloor4->offWork();
    EXPECT_EQ(building->CountWorkingCompanies(), 0);
}
