#include <gtest/gtest.h>
#include <stdexcept>
#include "cost_ratio.hpp"
#include "product_3c.hpp"

TEST(PRODUCT_3C_TEST, test_constructor_should_have_correct_name){
    Product3C product3C("product", 60, 2024, 06);

    ASSERT_EQ(product3C.GetName(), "product");
}

TEST(PRODUCT_3C_TEST, test_constructor_should_have_correct_price){
    Product3C product3C("product", 60, 2024, 06);

    ASSERT_EQ(product3C.GetPrice(), 60);
}

TEST(PRODUCT_3C_TEST, test_constructor_should_have_correct_cost){
    Product3C product3C("product", 60, 2024, 06);

    ASSERT_EQ(product3C.GetCost(), 60 * PRODUCT_3C_COST_RATIO);
}

TEST(PRODUCT_3C_TEST, test_constructor_with_invalid_price_should_throw_exception){
    ASSERT_THROW(Product3C product3C("product", -5, 2024, 06), std::invalid_argument);
}

TEST(PRODUCT_3C_TEST, test_constructor_with_invalid_warrenty_year_should_throw_exception){
    ASSERT_THROW(Product3C product3C("product", 60, -5, 06), std::invalid_argument);
}

TEST(PRODUCT_3C_TEST, test_constructor_with_invalid_warrenty_month_should_throw_exception){
    ASSERT_THROW(Product3C product3C("product", 60, 2024, -5), std::invalid_argument);
}

TEST(PRODUCT_3C_TEST, test_set_name_should_have_correct_name){
    Product3C product3C("product", 60, 2024, 06);

    product3C.SetName("product_new");

    ASSERT_EQ(product3C.GetName(), "product_new");
}

TEST(PRODUCT_3C_TEST, test_set_price_should_have_correct_price){
    Product3C product3C("product", 60, 2024, 06);

    product3C.SetPrice(180);

    ASSERT_EQ(product3C.GetPrice(), 180);
}

TEST(PRODUCT_3C_TEST, test_get_cost_with_new_price_should_have_correct_cost){
    Product3C product3C("product", 60, 2025, 4);

    product3C.SetPrice(120);

    ASSERT_EQ(product3C.GetCost(), 120 * PRODUCT_3C_COST_RATIO);
}

TEST(PRODUCT_3C_TEST, test_set_price_with_invalid_price_should_have_correct_price){
    Product3C product3C("product", 60, 2024, 06);

    ASSERT_THROW(product3C.SetPrice(-5), std::invalid_argument);
}

TEST(PRODUCT_3C_TEST, test_get_cost_should_have_correct_cost){
    Product3C product3C("product", 60, 2025, 4);

    ASSERT_EQ(product3C.GetCost(), 36);
}

TEST(PRODUCT_3C_TEST, test_is_expired_with_early_expired_date_should_return_false){
    Product3C product3C("product", 60, 2025, 4);

    ASSERT_EQ(product3C.IsExpired(2024, 2, 15), false);
}

TEST(PRODUCT_3C_TEST, test_is_expired_with_old_expired_date_should_return_true){
    Product3C product3C("product", 60, 2024, 6);
    
    ASSERT_EQ(product3C.IsExpired(2024, 8, 15), true);
}

TEST(PRODUCT_3C_TEST, test_is_expired_with_the_same_date_should_return_false){
    Product3C product3C("product", 60, 2024, 6);
    
    ASSERT_EQ(product3C.IsExpired(2024, 6, 15), false);
}