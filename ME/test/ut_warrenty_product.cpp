#include <gtest/gtest.h>
#include <stdexcept>
#include "warrenty_product.hpp"

TEST(WARRENTY_PRODUCT_TEST, test_constructor_should_have_correct_name){
    WarrentyProduct warrentyProduct("product", 30, 60, 2025, 4);

    ASSERT_EQ(warrentyProduct.GetName(), "product");
}

TEST(WARRENTY_PRODUCT_TEST, test_constructor_should_have_correct_price){
    WarrentyProduct warrentyProduct("product", 30, 60, 2025, 4);

    ASSERT_EQ(warrentyProduct.GetPrice(), 60);
}

TEST(WARRENTY_PRODUCT_TEST, test_constructor_should_have_correct_cost){
    WarrentyProduct warrentyProduct("product", 30, 60, 2025, 4);

    ASSERT_EQ(warrentyProduct.GetCost(), 30);
}

TEST(WARRENTY_PRODUCT_TEST, test_constructor_with_invalid_cost_should_throw_exception){
    ASSERT_THROW(WarrentyProduct warrentyProduct("product", -5, 60, 2025, 4), std::invalid_argument);
}

TEST(WARRENTY_PRODUCT_TEST, test_constructor_with_invalid_price_should_throw_exception){
    ASSERT_THROW(WarrentyProduct warrentyProduct("product", 30, -5, 2025, 4), std::invalid_argument);
}

TEST(WARRENTY_PRODUCT_TEST, test_constructor_with_invalid_warrenty_year_should_throw_exception){
    ASSERT_THROW(WarrentyProduct warrentyProduct("product", 30, 60, -5, 4), std::invalid_argument);
}

TEST(WARRENTY_PRODUCT_TEST, test_constructor_with_invalid_warrenty_month_should_throw_exception){
    ASSERT_THROW(WarrentyProduct warrentyProduct("product", 30, 60, 2025, -5), std::invalid_argument);
}

TEST(WARRENTY_PRODUCT_TEST, test_set_name_should_have_correct_name){
    WarrentyProduct warrentyProduct("product", 30, 60, 2025, 4);

    warrentyProduct.SetName("product_new");

    ASSERT_EQ(warrentyProduct.GetName(), "product_new");
}

TEST(WARRENTY_PRODUCT_TEST, test_set_price_should_have_correct_price){
    WarrentyProduct warrentyProduct("product", 30, 60, 2025, 4);

    warrentyProduct.SetPrice(180);

    ASSERT_EQ(warrentyProduct.GetPrice(), 180);
}

TEST(WARRENTY_PRODUCT_TEST, test_set_cost_should_have_correct_cost){
    WarrentyProduct warrentyProduct("product", 30, 60, 2025, 4);

    warrentyProduct.SetCost(120);

    ASSERT_EQ(warrentyProduct.GetCost(), 120);
}

TEST(WARRENTY_PRODUCT_TEST, test_is_expired_with_early_expired_date_should_return_false){
    WarrentyProduct warrentyProduct("product", 30, 60, 2025, 4);

    ASSERT_EQ(warrentyProduct.IsExpired(2025, 2, 15), false);
}

TEST(WARRENTY_PRODUCT_TEST, test_is_expired_with_old_expired_date_should_return_true){
    WarrentyProduct warrentyProduct("product", 30, 60, 2025, 4);
    
    ASSERT_EQ(warrentyProduct.IsExpired(2025, 6, 15), true);
}

TEST(WARRENTY_PRODUCT_TEST, test_is_expired_with_the_same_date_should_return_false){
    WarrentyProduct warrentyProduct("product", 30, 60, 2025, 4);
    
    ASSERT_EQ(warrentyProduct.IsExpired(2025, 4, 15), false);
}