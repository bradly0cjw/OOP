#include <gtest/gtest.h>
#include <stdexcept>
#include "bonus.hpp"
#include "cylinder_engineer.hpp"
#include "salary.hpp"
#include "staff_level.hpp"
#include "staff_no.hpp"
#include "title.hpp"

TEST(CYLINDER_ENGINEER_TEST, test_constructor_should_have_correct_name){
    CylinderEngineer cylinderEngineer("Alice", "03-1234567", 1234, StaffLevel::L1);

    ASSERT_EQ(cylinderEngineer.GetName(), "Alice");
}

TEST(CYLINDER_ENGINEER_TEST, test_constructor_should_have_correct_title){
    CylinderEngineer cylinderEngineer("Alice", "03-1234567", 1234, StaffLevel::L1);

    ASSERT_EQ(cylinderEngineer.GetTitle(), Title::CYLINDER_ENGINEER);
}

TEST(CYLINDER_ENGINEER_TEST, test_constructor_should_have_correct_phone){
    CylinderEngineer cylinderEngineer("Alice", "03-1234567", 1234, StaffLevel::L1);

    ASSERT_EQ(cylinderEngineer.GetPhone(), "03-1234567");
}

TEST(CYLINDER_ENGINEER_TEST, test_constructor_should_have_correct_ext){
    CylinderEngineer cylinderEngineer("Alice", "03-1234567", 1234, StaffLevel::L1);

    ASSERT_EQ(cylinderEngineer.GetExt(), 1234);
}

TEST(CYLINDER_ENGINEER_TEST, test_constructor_with_invalid_ext_should_throw_exception){
    ASSERT_THROW(CylinderEngineer cylinderEngineer("Alice", "03-1234567", -8851, StaffLevel::L1), std::invalid_argument);
}

TEST(CYLINDER_ENGINEER_TEST, test_set_name_should_have_correct_name){
    CylinderEngineer cylinderEngineer("Alice", "03-1234567", 1234, StaffLevel::L1);

    cylinderEngineer.SetName("Alice Lee");

    ASSERT_EQ(cylinderEngineer.GetName(), "Alice Lee");
}

TEST(CYLINDER_ENGINEER_TEST, test_set_title_should_have_correct_title){
    CylinderEngineer cylinderEngineer("Alice", "03-1234567", 1234, StaffLevel::L1);

    cylinderEngineer.SetTitle(Title::EXTERN_SALES);

    ASSERT_EQ(cylinderEngineer.GetTitle(), Title::EXTERN_SALES);
}

TEST(CYLINDER_ENGINEER_TEST, test_set_phone_exit_should_have_correct_phone_and_ext){
    CylinderEngineer cylinderEngineer("Alice", "03-1234567", 1234, StaffLevel::L1);

    cylinderEngineer.SetPhoneExt("03-7654321", 8812);

    ASSERT_EQ(cylinderEngineer.GetPhone(), "03-7654321");
    ASSERT_EQ(cylinderEngineer.GetExt(), 8812);
}

TEST(CYLINDER_ENGINEER_TEST, test_get_staff_no_should_have_correct_staff_no){
    CylinderEngineer cylinderEngineer("Alice", "03-1234567", 1234, StaffLevel::L1);

    StaffNo no = cylinderEngineer.GetStaffNo();

    ASSERT_EQ(no, StaffNo::E);
}

TEST(CYLINDER_ENGINEER_TEST, test_get_staff_level_should_have_correct_staff_level){
    CylinderEngineer cylinderEngineer("Alice", "03-1234567", 1234, StaffLevel::L1);

    StaffLevel level = cylinderEngineer.GetStaffLevel();

    ASSERT_EQ(level, StaffLevel::L1);
}

TEST(CYLINDER_ENGINEER_TEST, test_get_basic_salary_with_L1_should_have_correct_salary){
    CylinderEngineer cylinderEngineer("Alice", "03-1234567", 1234, StaffLevel::L1);

    int basicSalary = cylinderEngineer.GetBasicSalary();

    ASSERT_EQ(basicSalary, E_SALARY * SALARY_MONTH_COUNT * E_L1_RATIO);
}

TEST(CYLINDER_ENGINEER_TEST, test_have_EM_permission_should_return_true){
    CylinderEngineer cylinderEngineer("Alice", "03-1234567", 1234, StaffLevel::L1);

    ASSERT_EQ(cylinderEngineer.HaveEMPermission(), true);
}

TEST(CYLINDER_ENGINEER_TEST, test_get_bonus_with_L1_should_have_correct_bonus){
    CylinderEngineer cylinderEngineer("Alice", "03-1234567", 1234, StaffLevel::L1);

    int bonus = cylinderEngineer.GetBonus();

    ASSERT_EQ(bonus, STAFF_E_L1_EM);
}

TEST(CYLINDER_ENGINEER_TEST, test_get_basic_salary_with_L2_should_have_correct_salary){
    CylinderEngineer cylinderEngineer("Alice", "03-1234567", 1234, StaffLevel::L2);

    int basicSalary = cylinderEngineer.GetBasicSalary();

    ASSERT_EQ(basicSalary, E_SALARY * SALARY_MONTH_COUNT * E_L2_RATIO);
}

TEST(CYLINDER_ENGINEER_TEST, test_get_bonus_with_L2_should_have_correct_bonus){
    CylinderEngineer cylinderEngineer("Alice", "03-1234567", 1234, StaffLevel::L2);

    int bonus = cylinderEngineer.GetBonus();

    ASSERT_EQ(bonus, STAFF_E_L2_EM);
}

TEST(CYLINDER_ENGINEER_TEST, test_get_basic_salary_with_L3_should_have_correct_salary){
    CylinderEngineer cylinderEngineer("Alice", "03-1234567", 1234, StaffLevel::L3);

    int basicSalary = cylinderEngineer.GetBasicSalary();

    ASSERT_EQ(basicSalary, E_SALARY * SALARY_MONTH_COUNT * E_L3_RATIO);
}

TEST(CYLINDER_ENGINEER_TEST, test_get_bonus_with_L3_should_have_correct_bonus){
    CylinderEngineer cylinderEngineer("Alice", "03-1234567", 1234, StaffLevel::L3);

    int bonus = cylinderEngineer.GetBonus();

    ASSERT_EQ(bonus, STAFF_E_L3_EM);
}