#include <gtest/gtest.h>
#include <stdexcept>
#include "alcohol.hpp"
#include "cost_ratio.hpp"

TEST(ALCOHOL_TEST, test_constructor_should_have_correct_name){
    Alcohol alcohol("product", 60, 2025, 4, 25);

    ASSERT_EQ(alcohol.GetName(), "product");
}

TEST(ALCOHOL_TEST, test_constructor_should_have_correct_price){
    Alcohol alcohol("product", 60, 2025, 4, 25);

    ASSERT_EQ(alcohol.GetPrice(), 60);
}

TEST(ALCOHOL_TEST, test_constructor_should_have_correct_cost){
    Alcohol alcohol("product", 60, 2025, 4, 25);

    ASSERT_EQ(alcohol.GetCost(), 60 * ALOCOHOL_COST_RATIO);
}

TEST(ALCOHOL_TEST, test_constructor_with_invalid_price_should_throw_exception){
    ASSERT_THROW(Alcohol alcohol("product", -5, 2025, 4, 25), std::invalid_argument);
}

TEST(ALCOHOL_TEST, test_constructor_with_invalid_expired_year_should_throw_exception){
    ASSERT_THROW(Alcohol alcohol("product", 60, -5, 4, 25), std::invalid_argument);
}

TEST(ALCOHOL_TEST, test_constructor_with_invalid_expired_month_should_throw_exception){
    ASSERT_THROW(Alcohol alcohol("product", 60, 2025, -5, 25), std::invalid_argument);
}

TEST(ALCOHOL_TEST, test_constructor_with_invalid_expired_day_should_throw_exception){
    ASSERT_THROW(Alcohol alcohol("product", 60, 2025, -5, -5), std::invalid_argument);
}

TEST(ALCOHOL_TEST, test_set_name_should_have_correct_name){
    Alcohol alcohol("product", 60, 2025, 4, 25);

    alcohol.SetName("product_new");

    ASSERT_EQ(alcohol.GetName(), "product_new");
}

TEST(ALCOHOL_TEST, test_set_price_should_have_correct_price){
    Alcohol alcohol("product", 60, 2025, 4, 25);

    alcohol.SetPrice(180);

    ASSERT_EQ(alcohol.GetPrice(), 180);
}

TEST(ALCOHOL_TEST, test_set_price_with_invalid_price_should_have_correct_price){
    Alcohol alcohol("product", 60, 2025, 4, 25);

    ASSERT_THROW(alcohol.SetPrice(-5), std::invalid_argument);
}

TEST(ALCOHOL_TEST, test_get_cost_should_have_correct_cost){
    Alcohol alcohol("product", 60, 2025, 4, 25);

    ASSERT_EQ(alcohol.GetCost(), 36);
}

TEST(ALCOHOL_TEST, test_get_cost_with_new_price_should_have_correct_cost){
    Alcohol alcohol("product", 60, 2025, 4, 25);

    alcohol.SetPrice(120);

    ASSERT_EQ(alcohol.GetCost(), 120 * ALOCOHOL_COST_RATIO);
}

TEST(ALCOHOL_TEST, test_is_expired_with_early_expired_date_should_return_false){
    Alcohol alcohol("product", 60, 2025, 4, 25);

    ASSERT_EQ(alcohol.CheckExpired(2025, 2, 15), false);
}

TEST(ALCOHOL_TEST, test_is_expired_with_old_expired_date_should_return_true){
    Alcohol alcohol("product", 60, 2025, 4, 25);
    
    ASSERT_EQ(alcohol.CheckExpired(2025, 6, 15), true);
}

TEST(ALCOHOL_TEST, test_is_expired_with_the_same_date_should_return_false){
    Alcohol alcohol("product", 60, 2025, 4, 25);
    
    ASSERT_EQ(alcohol.CheckExpired(2025, 4, 25), false);
}

TEST(ALCOHOL_TEST, test_is_expired_with_old_expired_date_should_set_price_zero){
    Alcohol alcohol("product", 60, 2025, 4, 25);
    
    alcohol.CheckExpired(2025, 6, 15);

    ASSERT_EQ(alcohol.GetPrice(), 0);
}

TEST(ALCOHOL_TEST, test_check_age_with_less_than_18_should_throw_exception) {
    Alcohol alcohol("product", 60, 2025, 4, 25);
    
    ASSERT_THROW(alcohol.CheckAge(16), std::invalid_argument);
}

TEST(ALCOHOL_TEST, test_check_age_with_large_than_18_should_throw_exception) {
    Alcohol alcohol("product", 60, 2025, 4, 25);
    
    ASSERT_NO_THROW(alcohol.CheckAge(19));
}