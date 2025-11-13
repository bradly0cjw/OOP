#include <gtest/gtest.h>
#include <stdexcept>
#include "cost_ratio.hpp"
#include "deli.hpp"

TEST(DELI_TEST, test_constructor_should_have_correct_name){
    Deli deli("product", 60, 2025, 4, 25);

    ASSERT_EQ(deli.GetName(), "product");
}

TEST(DELI_TEST, test_constructor_should_have_correct_price){
    Deli deli("product", 60, 2025, 4, 25);

    ASSERT_EQ(deli.GetPrice(), 60);
}

TEST(DELI_TEST, test_constructor_should_have_correct_cost){
    Deli deli("product", 60, 2025, 4, 25);

    ASSERT_EQ(deli.GetCost(), 60 * DELI_COST_RATIO);
}

TEST(DELI_TEST, test_constructor_with_invalid_price_should_throw_exception){
    ASSERT_THROW(Deli deli("product", -5, 2025, 4, 25), std::invalid_argument);
}

TEST(DELI_TEST, test_constructor_with_invalid_expired_year_should_throw_exception){
    ASSERT_THROW(Deli deli("product", 60, -5, 4, 25), std::invalid_argument);
}

TEST(DELI_TEST, test_constructor_with_invalid_expired_month_should_throw_exception){
    ASSERT_THROW(Deli deli("product", 60, 2025, -5, 25), std::invalid_argument);
}

TEST(DELI_TEST, test_constructor_with_invalid_expired_day_should_throw_exception){
    ASSERT_THROW(Deli deli("product", 60, 2025, -5, -5), std::invalid_argument);
}

TEST(DELI_TEST, test_set_name_should_have_correct_name){
    Deli deli("product", 60, 2025, 4, 25);

    deli.SetName("product_new");

    ASSERT_EQ(deli.GetName(), "product_new");
}

TEST(DELI_TEST, test_set_price_should_have_correct_price){
    Deli deli("product", 60, 2025, 4, 25);

    deli.SetPrice(180);

    ASSERT_EQ(deli.GetPrice(), 180);
}

TEST(DELI_TEST, test_set_price_with_invalid_number_should_throw_exception){
    Deli deli("product", 60, 2025, 4, 25);

    ASSERT_THROW(deli.SetPrice(-1), std::invalid_argument);
}

TEST(DELI_TEST, test_get_cost_with_new_price_should_have_correct_cost){
    Deli deli("product", 60, 2025, 4, 25);

    deli.SetPrice(120);

    ASSERT_EQ(deli.GetCost(), 120 * DELI_COST_RATIO);
}

TEST(DELI_TEST, test_set_cost_should_have_correct_cost){
    Deli deli("product", 60, 2025, 4, 25);

    ASSERT_EQ(deli.GetCost(), 48);
}

TEST(DELI_TEST, test_is_expired_with_early_expired_date_should_return_false){
    Deli deli("product", 60, 2025, 4, 25);

    ASSERT_EQ(deli.CheckExpired(2025, 2, 15), false);
}

TEST(DELI_TEST, test_is_expired_with_old_expired_date_should_return_true){
    Deli deli("product", 60, 2025, 4, 25);
    
    ASSERT_EQ(deli.CheckExpired(2025, 6, 15), true);
}

TEST(DELI_TEST, test_is_expired_with_the_same_date_should_return_false){
    Deli deli("product", 60, 2025, 4, 25);
    
    ASSERT_EQ(deli.CheckExpired(2025, 4, 25), false);
}

TEST(DELI_TEST, test_is_expired_with_old_expired_date_should_set_price_zero){
    Deli deli("product", 60, 2025, 4, 25);
    
    deli.CheckExpired(2025, 6, 15);

    ASSERT_EQ(deli.GetPrice(), 0);
}