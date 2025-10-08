#include <gtest/gtest.h>

#include "Snack.hpp"

TEST(SnackTest, test_construct_with_name) {
    Snack snack = Snack("Chips");
    ASSERT_EQ("Chips", snack.getName());
    ASSERT_EQ(1, snack.getAmount());
}

TEST(SnackTest, test_construct_with_name_and_amount) {
    Snack snack = Snack("Chocolate", 5);
    ASSERT_EQ("Chocolate", snack.getName());
    ASSERT_EQ(5, snack.getAmount());
}

TEST(SnackTest, test_set_amount_works) {
    Snack snack = Snack("Cookie");
    snack.setAmount(10);
    ASSERT_EQ(10, snack.getAmount());
}

TEST(SnackTest, test_different_objects_are_independent) {
    Snack snack1 = Snack("Juice", 2);
    Snack snack2 = Snack("Candy", 3);

    snack1.setAmount(8);

    ASSERT_EQ("Juice", snack1.getName());
    ASSERT_EQ(8, snack1.getAmount());

    ASSERT_EQ("Candy", snack2.getName());
    ASSERT_EQ(3, snack2.getAmount());
}
