#include <gtest/gtest.h>
#include <stdexcept>
#include "food_product.hpp"

TEST(FOOD_PRODUCT_TEST, test_constructor_should_have_correct_name){
    FoodProduct foodProduct("product", 36, 60, 2025, 4, 25);

    ASSERT_EQ(foodProduct.GetName(), "product");
}

TEST(FOOD_PRODUCT_TEST, test_constructor_should_have_correct_price){
    FoodProduct foodProduct("product", 36, 60, 2025, 4, 25);

    ASSERT_EQ(foodProduct.GetPrice(), 60);
}

TEST(FOOD_PRODUCT_TEST, test_constructor_should_have_correct_cost){
    FoodProduct foodProduct("product", 36, 60, 2025, 4, 25);

    ASSERT_EQ(foodProduct.GetCost(), 36);
}

TEST(FOOD_PRODUCT_TEST, test_constructor_with_invalid_cost_should_throw_exception){
    ASSERT_THROW(FoodProduct foodProduct("product", -5, 60, 2025, 4, 25), std::invalid_argument);
}

TEST(FOOD_PRODUCT_TEST, test_constructor_with_invalid_price_should_throw_exception){
    ASSERT_THROW(FoodProduct foodProduct("product", 36, -5, 2025, 4, 25), std::invalid_argument);
}

TEST(FOOD_PRODUCT_TEST, test_constructor_with_invalid_expired_year_should_throw_exception){
    ASSERT_THROW(FoodProduct foodProduct("product", 36, 60, -5, 4, 25), std::invalid_argument);
}

TEST(FOOD_PRODUCT_TEST, test_constructor_with_invalid_expired_month_should_throw_exception){
    ASSERT_THROW(FoodProduct foodProduct("product", 36, 60, 2025, -5, 25), std::invalid_argument);
}

TEST(FOOD_PRODUCT_TEST, test_constructor_with_invalid_expired_day_should_throw_exception){
    ASSERT_THROW(FoodProduct foodProduct("product", 36, 60, 2025, 4, -5), std::invalid_argument);
}

TEST(FOOD_PRODUCT_TEST, test_set_name_should_have_correct_name){
    FoodProduct foodProduct("product", 30, 60, 2025, 4, 25);

    foodProduct.SetName("product_new");

    ASSERT_EQ(foodProduct.GetName(), "product_new");
}

TEST(FOOD_PRODUCT_TEST, test_set_price_should_have_correct_price){
    FoodProduct foodProduct("product", 30, 60, 2025, 4, 25);

    foodProduct.SetPrice(180);

    ASSERT_EQ(foodProduct.GetPrice(), 180);
}

TEST(FOOD_PRODUCT_TEST, test_set_price_with_invalid_price_should_throw_exception){
    FoodProduct foodProduct("product", 30, 60, 2025, 4, 25);

    ASSERT_THROW(foodProduct.SetPrice(-5), std::invalid_argument);
}

TEST(FOOD_PRODUCT_TEST, test_set_cost_should_have_correct_cost){
    FoodProduct foodProduct("product", 30, 60, 2025, 4, 25);

    foodProduct.SetCost(120);

    ASSERT_EQ(foodProduct.GetCost(), 120);
}

TEST(FOOD_PRODUCT_TEST, test_set_cost_with_invalid_cost_should_throw_exception){
    FoodProduct foodProduct("product", 30, 60, 2025, 4, 25);

    ASSERT_THROW(foodProduct.SetCost(-5), std::invalid_argument);
}

TEST(FOOD_PRODUCT_TEST, test_is_expired_with_early_expired_date_should_return_false){
    FoodProduct foodProduct("product", 30, 60, 2025, 4, 25);

    ASSERT_EQ(foodProduct.CheckExpired(2025, 2, 15), false);
}

TEST(FOOD_PRODUCT_TEST, test_is_expired_with_old_expired_date_should_return_true){
    FoodProduct foodProduct("product", 30, 60, 2025, 4, 25);
    
    ASSERT_EQ(foodProduct.CheckExpired(2025, 6, 15), true);
}

TEST(FOOD_PRODUCT_TEST, test_is_expired_with_the_same_date_should_return_false){
    FoodProduct foodProduct("product", 30, 60, 2025, 4, 25);
    
    ASSERT_EQ(foodProduct.CheckExpired(2025, 4, 25), false);
}

TEST(FOOD_PRODUCT_TEST, test_is_expired_with_old_expired_date_should_set_price_zero){
    FoodProduct foodProduct("product", 30, 60, 2025, 4, 25);
    
    foodProduct.CheckExpired(2025, 6, 15);

    ASSERT_EQ(foodProduct.GetPrice(), 0);
}
