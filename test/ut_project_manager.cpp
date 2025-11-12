#include <gtest/gtest.h>
#include <stdexcept>
#include "bonus.hpp"
#include "project_manager.hpp"
#include "salary.hpp"
#include "staff_level.hpp"
#include "staff_no.hpp"
#include "title.hpp"

TEST(PROJECT_MANAGER_TEST, test_constructor_should_have_correct_name){
    ProjectManager projectManager("Alice", "03-1234567", 1234, StaffLevel::L1);

    ASSERT_EQ(projectManager.GetName(), "Alice");
}

TEST(PROJECT_MANAGER_TEST, test_constructor_should_have_correct_title){
    ProjectManager projectManager("Alice", "03-1234567", 1234, StaffLevel::L1);

    ASSERT_EQ(projectManager.GetTitle(), Title::PROJECT_MANAGER);
}

TEST(PROJECT_MANAGER_TEST, test_constructor_should_have_correct_phone){
    ProjectManager projectManager("Alice", "03-1234567", 1234, StaffLevel::L1);

    ASSERT_EQ(projectManager.GetPhone(), "03-1234567");
}

TEST(PROJECT_MANAGER_TEST, test_constructor_should_have_correct_ext){
    ProjectManager projectManager("Alice", "03-1234567", 1234, StaffLevel::L1);

    ASSERT_EQ(projectManager.GetExt(), 1234);
}

TEST(PROJECT_MANAGER_TEST, test_constructor_with_invalid_ext_should_throw_exception){
    ASSERT_THROW(ProjectManager projectManager("Alice", "03-1234567", -8851, StaffLevel::L1), std::invalid_argument);
}

TEST(PROJECT_MANAGER_TEST, test_set_name_should_have_correct_name){
    ProjectManager projectManager("Alice", "03-1234567", 1234, StaffLevel::L1);

    projectManager.SetName("Alice Lee");

    ASSERT_EQ(projectManager.GetName(), "Alice Lee");
}

TEST(PROJECT_MANAGER_TEST, test_set_title_should_have_correct_title){
    ProjectManager projectManager("Alice", "03-1234567", 1234, StaffLevel::L1);

    projectManager.SetTitle(Title::EXTERN_SALES);

    ASSERT_EQ(projectManager.GetTitle(), Title::EXTERN_SALES);
}

TEST(PROJECT_MANAGER_TEST, test_set_phone_exit_should_have_correct_phone_and_ext){
    ProjectManager projectManager("Alice", "03-1234567", 1234, StaffLevel::L1);

    projectManager.SetPhoneExt("03-7654321", 8812);

    ASSERT_EQ(projectManager.GetPhone(), "03-7654321");
    ASSERT_EQ(projectManager.GetExt(), 8812);
}

TEST(PROJECT_MANAGER_TEST, test_have_EM_permission_should_return_true){
    ProjectManager projectManager("Alice", "03-1234567", 1234, StaffLevel::L1);

    ASSERT_EQ(projectManager.HaveEMPermission(), true);
}

TEST(PROJECT_MANAGER_TEST, test_get_staff_no_should_have_correct_staff_no){
    ProjectManager projectManager("Alice", "03-1234567", 1234, StaffLevel::L1);

    StaffNo no = projectManager.GetStaffNo();

    ASSERT_EQ(no, StaffNo::M);
}

TEST(PROJECT_MANAGER_TEST, test_get_staff_level_should_have_correct_staff_level){
    ProjectManager projectManager("Alice", "03-1234567", 1234, StaffLevel::L1);

    StaffLevel level = projectManager.GetStaffLevel();

    ASSERT_EQ(level, StaffLevel::L1);
}

TEST(PROJECT_MANAGER_TEST, test_get_basic_salary_with_L1_should_have_correct_salary){
    ProjectManager projectManager("Alice", "03-1234567", 1234, StaffLevel::L1);

    int basicSalary = projectManager.GetBasicSalary();

    ASSERT_EQ(basicSalary, M_SALARY * SALARY_MONTH_COUNT * M_L1_RATIO);
}

TEST(PROJECT_MANAGER_TEST, test_get_bonus_with_L1_should_have_correct_bonus){
    ProjectManager projectManager("Alice", "03-1234567", 1234, StaffLevel::L1);

    int bonus = projectManager.GetBonus();

    ASSERT_EQ(bonus, STAFF_M_L1_EM);
}

TEST(PROJECT_MANAGER_TEST, test_get_basic_salary_with_L2_should_have_correct_salary){
    ProjectManager projectManager("Alice", "03-1234567", 1234, StaffLevel::L2);

    int basicSalary = projectManager.GetBasicSalary();

    ASSERT_EQ(basicSalary, M_SALARY * SALARY_MONTH_COUNT * M_L2_RATIO);
}

TEST(PROJECT_MANAGER_TEST, test_get_bonus_with_L2_should_have_correct_bonus){
    ProjectManager projectManager("Alice", "03-1234567", 1234, StaffLevel::L2);

    int bonus = projectManager.GetBonus();

    ASSERT_EQ(bonus, STAFF_M_L2_EM);
}

TEST(PROJECT_MANAGER_TEST, test_get_basic_salary_with_L3_should_have_correct_salary){
    ProjectManager projectManager("Alice", "03-1234567", 1234, StaffLevel::L3);

    int basicSalary = projectManager.GetBasicSalary();

    ASSERT_EQ(basicSalary, M_SALARY * SALARY_MONTH_COUNT * M_L3_RATIO);
}

TEST(PROJECT_MANAGER_TEST, test_get_bonus_with_L3_should_have_correct_bonus){
    ProjectManager projectManager("Alice", "03-1234567", 1234, StaffLevel::L3);

    int bonus = projectManager.GetBonus();

    ASSERT_EQ(bonus, STAFF_M_L3_EM);
}