#include <gtest/gtest.h>
#include <stdexcept>
#include "cost_ratio.hpp"
#include "normal_product.hpp"

TEST(NORMAL_PRODUCT_TEST, test_constructor_should_have_correct_name){
    NormalProduct normalProduct("product", 60);

    ASSERT_EQ(normalProduct.GetName(), "product");
}

TEST(NORMAL_PRODUCT_TEST, test_constructor_should_have_correct_cost){
    NormalProduct normalProduct("product", 60);

    ASSERT_EQ(normalProduct.GetCost(), 60 * NORMAL_PRODUCT_COST_RATIO);
}

TEST(NORMAL_PRODUCT_TEST, test_constructor_with_invalid_price_should_throw_exception){
    ASSERT_THROW(NormalProduct normalProduct("product", -5), std::invalid_argument);
}

TEST(NORMAL_PRODUCT_TEST, test_set_name_should_have_correct_name){
    NormalProduct normalProduct("product", 60);

    normalProduct.SetName("product_new");

    ASSERT_EQ(normalProduct.GetName(), "product_new");
}

TEST(NORMAL_PRODUCT_TEST, test_set_price_should_have_correct_price){
    NormalProduct normalProduct("product", 60);

    normalProduct.SetPrice(180);

    ASSERT_EQ(normalProduct.GetPrice(), 180);
}

TEST(NORMAL_PRODUCT_TEST, test_set_price_should_have_correct_cost){
    NormalProduct normalProduct("product", 60);

    normalProduct.SetPrice(180);

    ASSERT_EQ(normalProduct.GetCost(), 180 * NORMAL_PRODUCT_COST_RATIO);
}

TEST(NORMAL_PRODUCT_TEST, test_set_price_with_invalid_price_should_throw_exception){
    NormalProduct normalProduct("product", 60);

    ASSERT_THROW(normalProduct.SetPrice(-5), std::invalid_argument);
}

TEST(NORMAL_PRODUCT_TEST, test_get_cost_should_have_correct_cost){
    NormalProduct normalProduct("product", 60);

    ASSERT_EQ(normalProduct.GetCost(), 45);
}