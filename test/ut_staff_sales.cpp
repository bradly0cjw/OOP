#include <gtest/gtest.h>
#include <stdexcept>
#include "bonus.hpp"
#include "salary.hpp"
#include "staff_sales.hpp"
#include "staff_level.hpp"
#include "staff_no.hpp"
#include "title.hpp"

TEST(STAFF_SALES_TEST, test_constructor_should_have_correct_name){
    StaffSales staffSales("Alice", "03-1234567", 1234, StaffLevel::L1);

    ASSERT_EQ(staffSales.GetName(), "Alice");
}

TEST(STAFF_SALES_TEST, test_constructor_should_have_correct_title){
    StaffSales staffSales("Alice", "03-1234567", 1234, StaffLevel::L1);

    ASSERT_EQ(staffSales.GetTitle(), Title::STAFF_SALES);
}

TEST(STAFF_SALES_TEST, test_constructor_should_have_correct_phone){
    StaffSales staffSales("Alice", "03-1234567", 1234, StaffLevel::L1);

    ASSERT_EQ(staffSales.GetPhone(), "03-1234567");
}

TEST(STAFF_SALES_TEST, test_constructor_should_have_correct_ext){
    StaffSales staffSales("Alice", "03-1234567", 1234, StaffLevel::L1);

    ASSERT_EQ(staffSales.GetExt(), 1234);
}

TEST(STAFF_SALES_TEST, test_constructor_with_invalid_ext_should_throw_exception){
    ASSERT_THROW(StaffSales staffSales("Alice", "03-1234567", -8851, StaffLevel::L1), std::invalid_argument);
}

TEST(STAFF_SALES_TEST, test_set_name_should_have_correct_name){
    StaffSales staffSales("Alice", "03-1234567", 1234, StaffLevel::L1);

    staffSales.SetName("Alice Lee");

    ASSERT_EQ(staffSales.GetName(), "Alice Lee");
}

TEST(STAFF_SALES_TEST, test_set_title_should_have_correct_title){
    StaffSales staffSales("Alice", "03-1234567", 1234, StaffLevel::L1);

    staffSales.SetTitle(Title::EXTERN_SALES);

    ASSERT_EQ(staffSales.GetTitle(), Title::EXTERN_SALES);
}

TEST(STAFF_SALES_TEST, test_set_phone_exit_should_have_correct_phone_and_ext){
    StaffSales staffSales("Alice", "03-1234567", 1234, StaffLevel::L1);

    staffSales.SetPhoneExt("03-7654321", 8812);

    ASSERT_EQ(staffSales.GetPhone(), "03-7654321");
    ASSERT_EQ(staffSales.GetExt(), 8812);
}

TEST(STAFF_SALES_TEST, test_have_EM_permission_should_return_false){
    StaffSales staffSales("Alice", "03-1234567", 1234, StaffLevel::L1);

    ASSERT_EQ(staffSales.HaveEMPermission(), false);
}

TEST(STAFF_SALES_TEST, test_get_staff_no_should_have_correct_staff_no){
    StaffSales staffSales("Alice", "03-1234567", 1234, StaffLevel::L1);

    StaffNo no = staffSales.GetStaffNo();

    ASSERT_EQ(no, StaffNo::S);
}

TEST(STAFF_SALES_TEST, test_get_staff_level_should_have_correct_staff_level){
    StaffSales staffSales("Alice", "03-1234567", 1234, StaffLevel::L1);

    StaffLevel level = staffSales.GetStaffLevel();

    ASSERT_EQ(level, StaffLevel::L1);
}

TEST(STAFF_SALES_TEST, test_get_basic_salary_with_L1_should_have_correct_salary){
    StaffSales staffSales("Alice", "03-1234567", 1234, StaffLevel::L1);

    int basicSalary = staffSales.GetBasicSalary();

    ASSERT_NEAR(basicSalary, S_SALARY * SALARY_MONTH_COUNT * S_L1_RATIO, 0.01);
}

TEST(STAFF_SALES_TEST, test_get_basic_salary_with_L2_should_have_correct_salary){
    StaffSales staffSales("Alice", "03-1234567", 1234, StaffLevel::L2);

    int basicSalary = staffSales.GetBasicSalary();

    ASSERT_NEAR(basicSalary, S_SALARY * SALARY_MONTH_COUNT * S_L2_RATIO, 0.01);
}

TEST(STAFF_SALES_TEST, test_get_basic_salary_with_L3_should_have_correct_salary){
    StaffSales staffSales("Alice", "03-1234567", 1234, StaffLevel::L3);

    int basicSalary = staffSales.GetBasicSalary();

    ASSERT_NEAR(basicSalary, S_SALARY * SALARY_MONTH_COUNT * S_L3_RATIO, 0.01);
}

TEST(STAFF_SALES_TEST, test_apply_bonus_with_5_cases_should_have_correct_bonus){
    StaffSales staffSales("Alice", "03-1234567", 1234, StaffLevel::L1);

    staffSales.ApplyBonus(87000, 5);
    
    int bonus = staffSales.GetBonus();
    ASSERT_EQ(bonus, 87000 * SALE_0_10_RATIO);
}

TEST(STAFF_SALES_TEST, test_apply_bonus_with_10_cases_should_have_correct_bonus){
    StaffSales staffSales("Alice", "03-1234567", 1234, StaffLevel::L1);

    staffSales.ApplyBonus(180000, 15);
    
    int bonus = staffSales.GetBonus();
    ASSERT_EQ(bonus, 180000 * SALE_11_20_RATIO);
}

TEST(STAFF_SALES_TEST, test_apply_bonus_with_45_cases_should_have_correct_bonus){
    StaffSales staffSales("Alice", "03-1234567", 1234, StaffLevel::L1);

    staffSales.ApplyBonus(580000, 45);
    
    int bonus = staffSales.GetBonus();
    ASSERT_EQ(bonus, 580000 * SALE_21_INF_RATIO);
}