#include <gtest/gtest.h>
#include "staff.hpp"
#include "staff_level.hpp"
#include "staff_no.hpp"

TEST(STAFF_TEST, test_constructor_should_have_correct_name){
    Staff staff("Alice", Title::STAFF_SALES, "03-1234567", 1234, StaffNo::N, StaffLevel::L1);

    ASSERT_EQ(staff.GetName(), "Alice");
}

TEST(STAFF_TEST, test_constructor_should_have_correct_title){
    Staff staff("Alice", Title::STAFF_SALES, "03-1234567", 1234, StaffNo::N, StaffLevel::L1);

    ASSERT_EQ(staff.GetTitle(), Title::STAFF_SALES);
}

TEST(STAFF_TEST, test_constructor_should_have_correct_phone){
    Staff staff("Alice", Title::STAFF_SALES, "03-1234567", 1234, StaffNo::N, StaffLevel::L1);

    ASSERT_EQ(staff.GetPhone(), "03-1234567");
}

TEST(STAFF_TEST, test_constructor_should_have_correct_ext){
    Staff staff("Alice", Title::STAFF_SALES, "03-1234567", 1234, StaffNo::N, StaffLevel::L1);

    ASSERT_EQ(staff.GetExt(), 1234);
}

TEST(STAFF_TEST, test_constructor_with_invalid_ext_should_throw_exception){
    ASSERT_THROW(Staff staff("Alice", Title::STAFF_SALES, "03-1234567", -8851, StaffNo::N, StaffLevel::L1), std::invalid_argument);
}

TEST(STAFF_TEST, test_set_name_should_have_correct_name){
    Staff staff("Alice", Title::STAFF_SALES, "03-1234567", 1234, StaffNo::N, StaffLevel::L1);

    staff.SetName("Alice Lee");

    ASSERT_EQ(staff.GetName(), "Alice Lee");
}

TEST(STAFF_TEST, test_set_title_should_have_correct_title){
    Staff staff("Alice", Title::STAFF_SALES, "03-1234567", 1234, StaffNo::N, StaffLevel::L1);

    staff.SetTitle(Title::EXTERN_SALES);

    ASSERT_EQ(staff.GetTitle(), Title::EXTERN_SALES);
}

TEST(STAFF_TEST, test_set_phone_exit_should_have_correct_phone_and_ext){
    Staff staff("Alice", Title::STAFF_SALES, "03-1234567", 1234, StaffNo::N, StaffLevel::L1);

    staff.SetPhoneExt("03-7654321", 8812);

    ASSERT_EQ(staff.GetPhone(), "03-7654321");
    ASSERT_EQ(staff.GetExt(), 8812);
}

TEST(STAFF_TEST, test_have_EM_permission_should_return_false){
    Staff staff("Alice", Title::STAFF_SALES, "03-1234567", 1234, StaffNo::N, StaffLevel::L1);

    ASSERT_EQ(staff.HaveEMPermission(), false);
}

TEST(STAFF_TEST, test_get_staff_no_should_have_correct_staff_no){
    Staff staff("Alice", Title::STAFF_SALES, "03-1234567", 1234, StaffNo::N, StaffLevel::L1);

    StaffNo no = staff.GetStaffNo();

    ASSERT_EQ(no, StaffNo::N);
}

TEST(STAFF_TEST, test_get_staff_level_should_have_correct_staff_level){
    Staff staff("Alice", Title::STAFF_SALES, "03-1234567", 1234, StaffNo::N, StaffLevel::L1);

    StaffLevel level = staff.GetStaffLevel();

    ASSERT_EQ(level, StaffLevel::L1);
}