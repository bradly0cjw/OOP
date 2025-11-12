#include <gtest/gtest.h>
#include <stdexcept>
#include "bonus.hpp"
#include "it_support_engineer.hpp"
#include "service_score.hpp"
#include "title.hpp"

TEST(IT_SUPPORT_ENGINEER_TEST, test_constructor_should_have_correct_name){
    ITSupportEngineer itSupportEngineer("Alice", "03-1234567", 1234);

    ASSERT_EQ(itSupportEngineer.GetName(), "Alice");
}

TEST(IT_SUPPORT_ENGINEER_TEST, test_constructor_should_have_correct_title){
    ITSupportEngineer itSupportEngineer("Alice", "03-1234567", 1234);

    ASSERT_EQ(itSupportEngineer.GetTitle(), Title::IT_SUPPORT_ENGINEER);
}

TEST(IT_SUPPORT_ENGINEER_TEST, test_constructor_should_have_correct_phone){
    ITSupportEngineer itSupportEngineer("Alice", "03-1234567", 1234);

    ASSERT_EQ(itSupportEngineer.GetPhone(), "03-1234567");
}

TEST(IT_SUPPORT_ENGINEER_TEST, test_constructor_should_have_correct_ext){
    ITSupportEngineer itSupportEngineer("Alice", "03-1234567", 1234);

    ASSERT_EQ(itSupportEngineer.GetExt(), 1234);
}

TEST(IT_SUPPORT_ENGINEER_TEST, test_constructor_with_invalid_ext_should_throw_exception){
    ASSERT_THROW(ITSupportEngineer itSupportEngineer("Alice", "03-1234567", -8851), std::invalid_argument);
}

TEST(IT_SUPPORT_ENGINEER_TEST, test_set_name_should_have_correct_name){
    ITSupportEngineer itSupportEngineer("Alice", "03-1234567", 1234);

    itSupportEngineer.SetName("Alice Lee");

    ASSERT_EQ(itSupportEngineer.GetName(), "Alice Lee");
}

TEST(IT_SUPPORT_ENGINEER_TEST, test_set_title_should_have_correct_title){
    ITSupportEngineer itSupportEngineer("Alice", "03-1234567", 1234);

    itSupportEngineer.SetTitle(Title::EXTERN_SALES);

    ASSERT_EQ(itSupportEngineer.GetTitle(), Title::EXTERN_SALES);
}

TEST(IT_SUPPORT_ENGINEER_TEST, test_set_phone_exit_should_have_correct_phone_and_ext){
    ITSupportEngineer itSupportEngineer("Alice", "03-1234567", 1234);

    itSupportEngineer.SetPhoneExt("03-7654321", 8812);

    ASSERT_EQ(itSupportEngineer.GetPhone(), "03-7654321");
    ASSERT_EQ(itSupportEngineer.GetExt(), 8812);
}

TEST(IT_SUPPORT_ENGINEER_TEST, test_have_EM_permission_should_return_false){
    ITSupportEngineer itSupportEngineer("Alice", "03-1234567", 1234);

    ASSERT_EQ(itSupportEngineer.HaveEMPermission(), false);
}

TEST(IT_SUPPORT_ENGINEER_TEST, test_get_bonus_with_A_service_scorre_should_have_correct_bonus){
    ITSupportEngineer itSupportEngineer("Alice", "03-1234567", 1234);

    itSupportEngineer.SetServiceScore(ServiceScore::A);
    
    int bonus = itSupportEngineer.GetBonus();
    ASSERT_EQ(bonus, 0);
}

TEST(IT_SUPPORT_ENGINEER_TEST, test_get_bonus_with_B_service_scorre_should_have_correct_bonus){
    ITSupportEngineer itSupportEngineer("Alice", "03-1234567", 1234);

    itSupportEngineer.SetServiceScore(ServiceScore::B);
    
    int bonus = itSupportEngineer.GetBonus();
    ASSERT_EQ(bonus, 0);
}

TEST(IT_SUPPORT_ENGINEER_TEST, test_get_bonus_with_C_service_scorre_should_have_correct_bonus){
    ITSupportEngineer itSupportEngineer("Alice", "03-1234567", 1234);

    itSupportEngineer.SetServiceScore(ServiceScore::C);
    
    int bonus = itSupportEngineer.GetBonus();
    ASSERT_EQ(bonus, 0);
}

TEST(IT_SUPPORT_ENGINEER_TEST, test_get_bonus_with_D_service_scorre_should_have_correct_bonus){
    ITSupportEngineer itSupportEngineer("Alice", "03-1234567", 1234);

    itSupportEngineer.SetServiceScore(ServiceScore::D);
    
    int bonus = itSupportEngineer.GetBonus();
    ASSERT_EQ(bonus, 0);
}
