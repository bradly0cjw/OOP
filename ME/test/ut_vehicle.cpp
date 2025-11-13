#include <gtest/gtest.h>
#include <stdexcept>
#include "cost_ratio.hpp"
#include "vehicle.hpp"

TEST(VEHICLE_TEST, test_constructor_should_have_correct_name){
    Vehicle vehicle("product", 60, 2024, 06);

    ASSERT_EQ(vehicle.GetName(), "product");
}

TEST(VEHICLE_TEST, test_constructor_should_have_correct_price){
    Vehicle vehicle("product", 60, 2024, 06);

    ASSERT_EQ(vehicle.GetPrice(), 60);
}

TEST(VEHICLE_TEST, test_constructor_should_have_correct_cost){
    Vehicle vehicle("product", 60, 2024, 06);

    ASSERT_EQ(vehicle.GetCost(), 60 * VEHICLE_COST_RATIO);
}

TEST(VEHICLE_TEST, test_constructor_with_invalid_price_should_throw_exception){
    ASSERT_THROW(Vehicle vehicle("product", -5, 2024, 06), std::invalid_argument);
}

TEST(VEHICLE_TEST, test_constructor_with_invalid_warrenty_year_should_throw_exception){
    ASSERT_THROW(Vehicle vehicle("product", 60, -5, 06), std::invalid_argument);
}

TEST(VEHICLE_TEST, test_constructor_with_invalid_warrenty_month_should_throw_exception){
    ASSERT_THROW(Vehicle vehicle("product", 60, 2024, -5), std::invalid_argument);
}

TEST(VEHICLE_TEST, test_set_name_should_have_correct_name){
    Vehicle vehicle("product", 60, 2024, 06);

    vehicle.SetName("product_new");

    ASSERT_EQ(vehicle.GetName(), "product_new");
}

TEST(VEHICLE_TEST, test_set_price_should_have_correct_price){
    Vehicle vehicle("product", 60, 2024, 06);

    vehicle.SetPrice(180);

    ASSERT_EQ(vehicle.GetPrice(), 180);
}

TEST(VEHICLE_TEST, test_set_price_should_have_correct_cost){
    Vehicle vehicle("product", 60, 2024, 06);

    vehicle.SetPrice(180);

    ASSERT_EQ(vehicle.GetCost(), 180 * VEHICLE_COST_RATIO);
}

TEST(VEHICLE_TEST, test_set_price_with_invalid_price_should_throw_exception){
    Vehicle vehicle("product", 60, 2024, 06);

    ASSERT_THROW(vehicle.SetPrice(-5), std::invalid_argument);
}

TEST(VEHICLE_TEST, test_get_cost_should_have_correct_cost){
    Vehicle vehicle("product", 60, 2024, 06);

    ASSERT_EQ(vehicle.GetCost(), 48);
}

TEST(VEHICLE_TEST, test_is_expired_with_early_expired_date_should_return_false){
    Vehicle vehicle("product", 60, 2024, 06);

    ASSERT_EQ(vehicle.IsExpired(2024, 2, 15), false);
}

TEST(VEHICLE_TEST, test_is_expired_with_old_expired_date_should_return_true){
    Vehicle vehicle("product", 60, 2024, 06);
    
    ASSERT_EQ(vehicle.IsExpired(2024, 8, 15), true);
}

TEST(VEHICLE_TEST, test_is_expired_with_the_same_date_should_return_false){
    Vehicle vehicle("product", 60, 2024, 06);
    
    ASSERT_EQ(vehicle.IsExpired(2024, 6, 15), false);
}

TEST(VEHICLE_TEST, test_age_with_over_18_should_not_throw_anything){
    Vehicle vehicle("product", 60, 2024, 06);
    
    ASSERT_NO_THROW(vehicle.CheckAge(18));
}

TEST(VEHICLE_TEST, test_age_with_less_than_18_should_throw_invalid_arguments){
    Vehicle vehicle("product", 60, 2024, 06);
    
    ASSERT_THROW(vehicle.CheckAge(16), std::invalid_argument);
}