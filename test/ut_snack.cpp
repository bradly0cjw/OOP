#include <gtest/gtest.h>
#include <stdexcept>
#include "cost_ratio.hpp"
#include "snack.hpp"

TEST(SNACK_TEST, test_constructor_should_have_correct_name){
    Snack snack("product", 60, 2025, 4, 25);

    ASSERT_EQ(snack.GetName(), "product");
}

TEST(SNACK_TEST, test_constructor_should_have_correct_price){
    Snack snack("product", 60, 2025, 4, 25);

    ASSERT_EQ(snack.GetPrice(), 60);
}

TEST(SNACK_TEST, test_constructor_should_have_correct_cost){
    Snack snack("product", 60, 2025, 4, 25);

    ASSERT_EQ(snack.GetCost(), 60 * SNACK_COST_RATIO);
}

TEST(SNACK_TEST, test_constructor_with_invalid_price_should_throw_exception){
    ASSERT_THROW(Snack snack("product", -5, 2025, 4, 25), std::invalid_argument);
}

TEST(SNACK_TEST, test_constructor_with_invalid_expired_year_should_throw_exception){
    ASSERT_THROW(Snack snack("product", 60, -5, 4, 25), std::invalid_argument);
}

TEST(SNACK_TEST, test_constructor_with_invalid_expired_month_should_throw_exception){
    ASSERT_THROW(Snack snack("product", 60, 2025, -5, 25), std::invalid_argument);
}

TEST(SNACK_TEST, test_constructor_with_invalid_expired_day_should_throw_exception){
    ASSERT_THROW(Snack snack("product", 60, 2025, 4, -5), std::invalid_argument);
}

TEST(SNACK_TEST, test_set_name_should_have_correct_name){
    Snack snack("product", 60, 2025, 4, 25);

    snack.SetName("product_new");

    ASSERT_EQ(snack.GetName(), "product_new");
}

TEST(SNACK_TEST, test_set_price_should_have_correct_price){
    Snack snack("product", 60, 2025, 4, 25);

    snack.SetPrice(180);

    ASSERT_EQ(snack.GetPrice(), 180);
}

TEST(SNACK_TEST, test_set_price_should_have_correct_cost){
    Snack snack("product", 60, 2025, 4, 25);

    snack.SetPrice(180);

    ASSERT_EQ(snack.GetCost(), 180 * SNACK_COST_RATIO);
}

TEST(SNACK_TEST, test_set_price_with_invalid_price_should_throw_exception){
    Snack snack("product", 60, 2025, 4, 25);

    ASSERT_THROW(snack.SetPrice(-5), std::invalid_argument);
}

TEST(SNACK_TEST, test_set_cost_should_have_correct_cost){
    Snack snack("product", 60, 2025, 4, 25);

    ASSERT_EQ(snack.GetCost(), 45);
}

TEST(SNACK_TEST, test_is_expired_with_early_expired_date_should_return_false){
    Snack snack("product", 60, 2025, 4, 25);

    ASSERT_EQ(snack.CheckExpired(2025, 2, 15), false);
}

TEST(SNACK_TEST, test_is_expired_with_old_expired_date_should_return_true){
    Snack snack("product", 60, 2025, 4, 25);
    
    ASSERT_EQ(snack.CheckExpired(2025, 6, 15), true);
}

TEST(SNACK_TEST, test_is_expired_with_the_same_date_should_return_false){
    Snack snack("product", 60, 2025, 4, 25);
    
    ASSERT_EQ(snack.CheckExpired(2025, 4, 25), false);
}

TEST(SNACK_TEST, test_is_expired_with_old_expired_date_should_set_price_zero){
    Snack snack("product", 60, 2025, 4, 25);
    
    snack.CheckExpired(2025, 6, 15);

    ASSERT_EQ(snack.GetPrice(), 0);
}