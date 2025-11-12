#include <gtest/gtest.h>
#include <stdexcept>
#include "project_assistant.hpp"
#include "salary.hpp"
#include "staff_level.hpp"
#include "staff_no.hpp"
#include "title.hpp"

TEST(PROJECT_ASSISTANT_TEST, test_constructor_should_have_correct_name){
    ProjectAssistant projectAssistant("Alice", "03-1234567", 1234, StaffLevel::L1);

    ASSERT_EQ(projectAssistant.GetName(), "Alice");
}

TEST(PROJECT_ASSISTANT_TEST, test_constructor_should_have_correct_title){
    ProjectAssistant projectAssistant("Alice", "03-1234567", 1234, StaffLevel::L1);

    ASSERT_EQ(projectAssistant.GetTitle(), Title::PROJECT_ASSISTANT);
}

TEST(PROJECT_ASSISTANT_TEST, test_constructor_should_have_correct_phone){
    ProjectAssistant projectAssistant("Alice", "03-1234567", 1234, StaffLevel::L1);

    ASSERT_EQ(projectAssistant.GetPhone(), "03-1234567");
}

TEST(PROJECT_ASSISTANT_TEST, test_constructor_should_have_correct_ext){
    ProjectAssistant projectAssistant("Alice", "03-1234567", 1234, StaffLevel::L1);

    ASSERT_EQ(projectAssistant.GetExt(), 1234);
}

TEST(PROJECT_ASSISTANT_TEST, test_constructor_with_invalid_ext_should_throw_exception){
    ASSERT_THROW(ProjectAssistant projectAssistant("Alice", "03-1234567", -8851, StaffLevel::L1), std::invalid_argument);
}

TEST(PROJECT_ASSISTANT_TEST, test_set_name_should_have_correct_name){
    ProjectAssistant projectAssistant("Alice", "03-1234567", 1234, StaffLevel::L1);

    projectAssistant.SetName("Alice Lee");

    ASSERT_EQ(projectAssistant.GetName(), "Alice Lee");
}

TEST(PROJECT_ASSISTANT_TEST, test_set_title_should_have_correct_title){
    ProjectAssistant projectAssistant("Alice", "03-1234567", 1234, StaffLevel::L1);

    projectAssistant.SetTitle(Title::EXTERN_SALES);

    ASSERT_EQ(projectAssistant.GetTitle(), Title::EXTERN_SALES);
}

TEST(PROJECT_ASSISTANT_TEST, test_set_phone_exit_should_have_correct_phone_and_ext){
    ProjectAssistant projectAssistant("Alice", "03-1234567", 1234, StaffLevel::L1);

    projectAssistant.SetPhoneExt("03-7654321", 8812);

    ASSERT_EQ(projectAssistant.GetPhone(), "03-7654321");
    ASSERT_EQ(projectAssistant.GetExt(), 8812);
}

TEST(PROJECT_ASSISTANT_TEST, test_have_EM_permission_should_return_false){
    ProjectAssistant projectAssistant("Alice", "03-1234567", 1234, StaffLevel::L1);

    ASSERT_EQ(projectAssistant.HaveEMPermission(), false);
}

TEST(PROJECT_ASSISTANT_TEST, test_get_staff_no_should_have_correct_staff_no){
    ProjectAssistant projectAssistant("Alice", "03-1234567", 1234, StaffLevel::L1);

    StaffNo no = projectAssistant.GetStaffNo();

    ASSERT_EQ(no, StaffNo::N);
}

TEST(PROJECT_ASSISTANT_TEST, test_get_staff_level_should_have_correct_staff_level){
    ProjectAssistant projectAssistant("Alice", "03-1234567", 1234, StaffLevel::L1);

    StaffLevel level = projectAssistant.GetStaffLevel();

    ASSERT_EQ(level, StaffLevel::L1);
}

TEST(PROJECT_ASSISTANT_TEST, test_get_basic_salary_with_L1_should_have_correct_salary){
    ProjectAssistant projectAssistant("Alice", "03-1234567", 1234, StaffLevel::L1);

    int basicSalary = projectAssistant.GetBasicSalary();

    ASSERT_NEAR(basicSalary, N_SALARY * SALARY_MONTH_COUNT * N_L1_RATIO, 0.01);
}

TEST(PROJECT_ASSISTANT_TEST, test_get_bonus_with_L1_should_have_correct_bonus){
    ProjectAssistant projectAssistant("Alice", "03-1234567", 1234, StaffLevel::L1);

    int bonus = projectAssistant.GetBonus();

    ASSERT_EQ(bonus, 0);
}

TEST(PROJECT_ASSISTANT_TEST, test_get_basic_salary_with_L2_should_have_correct_salary){
    ProjectAssistant projectAssistant("Alice", "03-1234567", 1234, StaffLevel::L2);

    int basicSalary = projectAssistant.GetBasicSalary();

    ASSERT_NEAR(basicSalary, N_SALARY * SALARY_MONTH_COUNT * N_L2_RATIO, 0.01);
}

TEST(PROJECT_ASSISTANT_TEST, test_get_bonus_with_L2_should_have_correct_bonus){
    ProjectAssistant projectAssistant("Alice", "03-1234567", 1234, StaffLevel::L2);

    int bonus = projectAssistant.GetBonus();

    ASSERT_EQ(bonus, 0);
}

TEST(PROJECT_ASSISTANT_TEST, test_get_basic_salary_with_L3_should_have_correct_salary){
    ProjectAssistant projectAssistant("Alice", "03-1234567", 1234, StaffLevel::L3);

    int basicSalary = projectAssistant.GetBasicSalary();

    ASSERT_NEAR(basicSalary, N_SALARY * SALARY_MONTH_COUNT * N_L3_RATIO, 0.01);
}

TEST(PROJECT_ASSISTANT_TEST, test_get_bonus_with_L3_should_have_correct_bonus){
    ProjectAssistant projectAssistant("Alice", "03-1234567", 1234, StaffLevel::L3);

    int bonus = projectAssistant.GetBonus();

    ASSERT_EQ(bonus, 0);
}