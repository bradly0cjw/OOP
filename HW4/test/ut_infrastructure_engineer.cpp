#include <gtest/gtest.h>
#include <stdexcept>
#include "bonus.hpp"
#include "infrastructure_engineer.hpp"
#include "service_score.hpp"
#include "title.hpp"

TEST(INFRASTRUCTURE_ENGINEER_TEST, test_constructor_should_have_correct_name){
    InfrastructureEngineer infrastructureEngineer("Alice", "03-1234567", 1234);

    ASSERT_EQ(infrastructureEngineer.GetName(), "Alice");
}

TEST(INFRASTRUCTURE_ENGINEER_TEST, test_constructor_should_have_correct_title){
    InfrastructureEngineer infrastructureEngineer("Alice", "03-1234567", 1234);

    ASSERT_EQ(infrastructureEngineer.GetTitle(), Title::INFRASTRUCTURE_ENGINEER);
}

TEST(INFRASTRUCTURE_ENGINEER_TEST, test_constructor_should_have_correct_phone){
    InfrastructureEngineer infrastructureEngineer("Alice", "03-1234567", 1234);

    ASSERT_EQ(infrastructureEngineer.GetPhone(), "03-1234567");
}

TEST(INFRASTRUCTURE_ENGINEER_TEST, test_constructor_should_have_correct_ext){
    InfrastructureEngineer infrastructureEngineer("Alice", "03-1234567", 1234);

    ASSERT_EQ(infrastructureEngineer.GetExt(), 1234);
}

TEST(INFRASTRUCTURE_ENGINEER_TEST, test_constructor_with_invalid_ext_should_throw_exception){
    ASSERT_THROW(InfrastructureEngineer infrastructureEngineer("Alice", "03-1234567", -8851), std::invalid_argument);
}

TEST(INFRASTRUCTURE_ENGINEER_TEST, test_set_name_should_have_correct_name){
    InfrastructureEngineer infrastructureEngineer("Alice", "03-1234567", 1234);

    infrastructureEngineer.SetName("Alice Lee");

    ASSERT_EQ(infrastructureEngineer.GetName(), "Alice Lee");
}

TEST(INFRASTRUCTURE_ENGINEER_TEST, test_set_title_should_have_correct_title){
    InfrastructureEngineer infrastructureEngineer("Alice", "03-1234567", 1234);

    infrastructureEngineer.SetTitle(Title::EXTERN_SALES);

    ASSERT_EQ(infrastructureEngineer.GetTitle(), Title::EXTERN_SALES);
}

TEST(INFRASTRUCTURE_ENGINEER_TEST, test_set_phone_exit_should_have_correct_phone_and_ext){
    InfrastructureEngineer infrastructureEngineer("Alice", "03-1234567", 1234);

    infrastructureEngineer.SetPhoneExt("03-7654321", 8812);

    ASSERT_EQ(infrastructureEngineer.GetPhone(), "03-7654321");
    ASSERT_EQ(infrastructureEngineer.GetExt(), 8812);
}

TEST(INFRASTRUCTURE_ENGINEER_TEST, test_have_EM_permission_should_return_true){
    InfrastructureEngineer infrastructureEngineer("Alice", "03-1234567", 1234);

    ASSERT_EQ(infrastructureEngineer.HaveEMPermission(), true);
}

TEST(INFRASTRUCTURE_ENGINEER_TEST, test_get_bonus_with_A_service_scorre_should_have_correct_bonus){
    InfrastructureEngineer infrastructureEngineer("Alice", "03-1234567", 1234);

    infrastructureEngineer.SetServiceScore(ServiceScore::A);
    
    int bonus = infrastructureEngineer.GetBonus();
    ASSERT_EQ(bonus, VENDOR_A_EM);
}

TEST(INFRASTRUCTURE_ENGINEER_TEST, test_get_bonus_with_B_service_scorre_should_have_correct_bonus){
    InfrastructureEngineer infrastructureEngineer("Alice", "03-1234567", 1234);

    infrastructureEngineer.SetServiceScore(ServiceScore::B);
    
    int bonus = infrastructureEngineer.GetBonus();
    ASSERT_EQ(bonus, VENDOR_B_EM);
}

TEST(INFRASTRUCTURE_ENGINEER_TEST, test_get_bonus_with_C_service_scorre_should_have_correct_bonus){
    InfrastructureEngineer infrastructureEngineer("Alice", "03-1234567", 1234);

    infrastructureEngineer.SetServiceScore(ServiceScore::C);
    
    int bonus = infrastructureEngineer.GetBonus();
    ASSERT_EQ(bonus, VENDOR_C_EM);
}

TEST(INFRASTRUCTURE_ENGINEER_TEST, test_get_bonus_with_D_service_scorre_should_have_correct_bonus){
    InfrastructureEngineer infrastructureEngineer("Alice", "03-1234567", 1234);

    infrastructureEngineer.SetServiceScore(ServiceScore::D);
    
    int bonus = infrastructureEngineer.GetBonus();
    ASSERT_EQ(bonus, VENDOR_D_EM);
}
