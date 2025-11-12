#include <gtest/gtest.h>
#include "person.hpp"

TEST(PERSON_TEST, test_constructor_should_have_correct_name){
    Person person("Alice", Title::STAFF_SALES, "03-1234567", 1234);

    ASSERT_EQ(person.GetName(), "Alice");
}

TEST(PERSON_TEST, test_constructor_should_have_correct_title){
    Person person("Alice", Title::STAFF_SALES, "03-1234567", 1234);

    ASSERT_EQ(person.GetTitle(), Title::STAFF_SALES);
}

TEST(PERSON_TEST, test_constructor_should_have_correct_phone){
    Person person("Alice", Title::STAFF_SALES, "03-1234567", 1234);

    ASSERT_EQ(person.GetPhone(), "03-1234567");
}

TEST(PERSON_TEST, test_constructor_should_have_correct_ext){
    Person person("Alice", Title::STAFF_SALES, "03-1234567", 1234);

    ASSERT_EQ(person.GetExt(), 1234);
}

TEST(PERSON_TEST, test_constructor_with_invalid_ext_should_throw_exception){
    ASSERT_THROW(Person person("Alice", Title::STAFF_SALES, "03-1234567", -8851), std::invalid_argument);
}

TEST(PERSON_TEST, test_set_name_should_have_correct_name){
    Person person("Alice", Title::STAFF_SALES, "03-1234567", 1234);

    person.SetName("Alice Lee");

    ASSERT_EQ(person.GetName(), "Alice Lee");
}

TEST(PERSON_TEST, test_set_title_should_have_correct_title){
    Person person("Alice", Title::STAFF_SALES, "03-1234567", 1234);

    person.SetTitle(Title::STAFF_SALES);

    ASSERT_EQ(person.GetTitle(), Title::STAFF_SALES);
}

TEST(PERSON_TEST, test_set_phone_exit_should_have_correct_phone_and_ext){
    Person person("Alice", Title::STAFF_SALES, "03-1234567", 1234);

    person.SetPhoneExt("03-7654321", 8812);

    ASSERT_EQ(person.GetPhone(), "03-7654321");
    ASSERT_EQ(person.GetExt(), 8812);
}

TEST(PERSON_TEST, test_have_EM_permission_should_return_false){
    Person person("Alice", Title::STAFF_SALES, "03-1234567", 1234);

    ASSERT_EQ(person.HaveEMPermission(), false);
}