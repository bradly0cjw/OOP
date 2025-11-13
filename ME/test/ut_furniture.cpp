#include <gtest/gtest.h>
#include <stdexcept>
#include "cost_ratio.hpp"
#include "furniture.hpp"

TEST(FURNIURE_TEST, test_constructor_should_have_correct_name){
    Furniture furniture("product", 60, 2025, 4);

    ASSERT_EQ(furniture.GetName(), "product");
}

TEST(FURNIURE_TEST, test_constructor_should_have_correct_price){
    Furniture furniture("product", 60, 2025, 4);

    ASSERT_EQ(furniture.GetPrice(), 60);
}

TEST(FURNIURE_TEST, test_constructor_should_have_correct_cost){
    Furniture furniture("product", 60, 2025, 4);

    ASSERT_EQ(furniture.GetCost(), 60 * FURNITURE_COST_RATIO);
}

TEST(FURNIURE_TEST, test_constructor_with_invalid_price_should_throw_exception){
    ASSERT_THROW(Furniture furniture("product", -5, 2025, 4), std::invalid_argument);
}

TEST(FURNIURE_TEST, test_constructor_with_invalid_expired_year_should_throw_exception){
    ASSERT_THROW(Furniture furniture("product", 60, -5, 4), std::invalid_argument);
}

TEST(FURNIURE_TEST, test_constructor_with_invalid_expired_month_should_throw_exception){
    ASSERT_THROW(Furniture furniture("product", 60, 2025, -5), std::invalid_argument);
}

TEST(FURNIURE_TEST, test_set_name_should_have_correct_name){
    Furniture furniture("product", 60, 2024, 06);

    furniture.SetName("product_new");

    ASSERT_EQ(furniture.GetName(), "product_new");
}

TEST(FURNIURE_TEST, test_set_price_should_have_correct_price){
    Furniture furniture("product", 60, 2024, 06);

    furniture.SetPrice(180);

    ASSERT_EQ(furniture.GetPrice(), 180);
}

TEST(FURNIURE_TEST, test_set_price_with_invalid_price_should_throw_exception){
    Furniture furniture("product", 60, 2024, 06);

    ASSERT_THROW(furniture.SetPrice(-5), std::invalid_argument);
}

TEST(FURNIURE_TEST, test_get_cost_should_have_correct_cost){
    Furniture furniture("product", 60, 2024, 06);

    ASSERT_EQ(furniture.GetCost(), 54);
}

TEST(FURNIURE_TEST, test_is_expired_with_early_expired_date_should_return_false){
    Furniture furniture("product", 60, 2024, 06);

    ASSERT_EQ(furniture.IsExpired(2024, 2, 15), false);
}

TEST(FURNIURE_TEST, test_is_expired_with_old_expired_date_should_return_true){
    Furniture furniture("product", 60, 2024, 06);
    
    ASSERT_EQ(furniture.IsExpired(2024, 8, 15), true);
}

TEST(FURNIURE_TEST, test_is_expired_with_the_same_date_should_return_false){
    Furniture furniture("product", 60, 2024, 06);
    
    ASSERT_EQ(furniture.IsExpired(2024, 6, 15), false);
}