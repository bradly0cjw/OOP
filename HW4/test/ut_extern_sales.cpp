#include <gtest/gtest.h>
#include <stdexcept>
#include "bonus.hpp"
#include "extern_sales.hpp"
#include "title.hpp"

TEST(EXTERN_SALES_TEST, test_constructor_should_have_correct_name){
    ExternSales externSales("Alice", "03-1234567", 1234);

    ASSERT_EQ(externSales.GetName(), "Alice");
}

TEST(EXTERN_SALES_TEST, test_constructor_should_have_correct_title){
    ExternSales externSales("Alice", "03-1234567", 1234);

    ASSERT_EQ(externSales.GetTitle(), Title::EXTERN_SALES);
}

TEST(EXTERN_SALES_TEST, test_constructor_should_have_correct_phone){
    ExternSales externSales("Alice", "03-1234567", 1234);

    ASSERT_EQ(externSales.GetPhone(), "03-1234567");
}

TEST(EXTERN_SALES_TEST, test_constructor_should_have_correct_ext){
    ExternSales externSales("Alice", "03-1234567", 1234);

    ASSERT_EQ(externSales.GetExt(), 1234);
}

TEST(EXTERN_SALES_TEST, test_constructor_with_invalid_ext_should_throw_exception){
    ASSERT_THROW(ExternSales externSales("Alice", "03-1234567", -8851), std::invalid_argument);
}

TEST(EXTERN_SALES_TEST, test_set_name_should_have_correct_name){
    ExternSales externSales("Alice", "03-1234567", 1234);

    externSales.SetName("Alice Lee");

    ASSERT_EQ(externSales.GetName(), "Alice Lee");
}

TEST(EXTERN_SALES_TEST, test_set_title_should_have_correct_title){
    ExternSales externSales("Alice", "03-1234567", 1234);

    externSales.SetTitle(Title::EXTERN_SALES);

    ASSERT_EQ(externSales.GetTitle(), Title::EXTERN_SALES);
}

TEST(EXTERN_SALES_TEST, test_set_phone_exit_should_have_correct_phone_and_ext){
    ExternSales externSales("Alice", "03-1234567", 1234);

    externSales.SetPhoneExt("03-7654321", 8812);

    ASSERT_EQ(externSales.GetPhone(), "03-7654321");
    ASSERT_EQ(externSales.GetExt(), 8812);
}

TEST(EXTERN_SALES_TEST, test_have_EM_permission_should_return_false){
    ExternSales externSales("Alice", "03-1234567", 1234);

    ASSERT_EQ(externSales.HaveEMPermission(), false);
}

TEST(EXTERN_SALES_TEST, test_apply_bonus_with_5_cases_should_have_correct_bonus){
    ExternSales externSales("Alice", "03-1234567", 1234);

    externSales.ApplyBonus(87000, 5);
    
    int bonus = externSales.GetBonus();
    ASSERT_EQ(bonus, 87000 * SALE_0_10_RATIO);
}

TEST(EXTERN_SALES_TEST, test_apply_bonus_with_10_cases_should_have_correct_bonus){
    ExternSales externSales("Alice", "03-1234567", 1234);

    externSales.ApplyBonus(180000, 15);
    
    int bonus = externSales.GetBonus();
    ASSERT_EQ(bonus, 180000 * SALE_11_20_RATIO);
}

TEST(EXTERN_SALES_TEST, test_apply_bonus_with_45_cases_should_have_correct_bonus){
    ExternSales externSales("Alice", "03-1234567", 1234);

    externSales.ApplyBonus(580000, 45);
    
    int bonus = externSales.GetBonus();
    ASSERT_EQ(bonus, 580000 * SALE_21_INF_RATIO);
}