#include <gtest/gtest.h>
#include <stdexcept>
#include "product.hpp"

TEST(PRODUCT_TEST, test_constructor_should_have_correct_name){
    Product product("product", 36, 60);

    ASSERT_EQ(product.GetName(), "product");
}

TEST(PRODUCT_TEST, test_constructor_should_have_correct_price){
    Product product("product", 36, 60);

    ASSERT_EQ(product.GetPrice(), 60);
}

TEST(PRODUCT_TEST, test_constructor_should_have_correct_cost){
Product product("product", 36, 60);

    ASSERT_EQ(product.GetCost(), 36);
}

TEST(PRODUCT_TEST, test_constructor_with_invalid_cost_should_have_correct_price){
    ASSERT_THROW(Product product("product", -5, 60), std::invalid_argument);
}

TEST(PRODUCT_TEST, test_constructor_with_invalid_price_should_have_correct_cost){
    ASSERT_THROW(Product product("product", 36, -5), std::invalid_argument);
}

TEST(PRODUCT_TEST, test_product_set_name_should_have_correct_name) {
    Product product("Item", 60, 30);

    product.SetName("Item 2");

    ASSERT_EQ(product.GetName(), "Item 2");
}

TEST(PRODUCT_TEST, test_product_set_price_should_have_correct_price) {
    Product product("Item", 60, 30);

    product.SetPrice(60);

    ASSERT_EQ(product.GetPrice(), 60);
}

TEST(PRODUCT_TEST, test_product_set_price_with_invalid_price_should_throw_exception) {
    Product product("Item", 60, 30);

    ASSERT_THROW(product.SetPrice(-5), std::invalid_argument);
}

TEST(PRODUCT_TEST, test_product_set_cost_should_have_correct_cost) {
    Product product("Item", 60, 30);

    product.SetCost(90);

    ASSERT_EQ(product.GetCost(), 90);
}

TEST(PRODUCT_TEST, test_product_set_cost_with_invalid_cost_should_throw_exception) {
    Product product("Item", 60, 30);

    ASSERT_THROW(product.SetCost(-5), std::invalid_argument);
}
