#include <gtest/gtest.h>
#include "service_score.hpp"
#include "vendor.hpp"

TEST(VENDOR_TEST, test_constructor_should_have_correct_name){
    Vendor vendor("Alice", Title::STAFF_SALES, "03-1234567", 1234);

    ASSERT_EQ(vendor.GetName(), "Alice");
}

TEST(VENDOR_TEST, test_constructor_should_have_correct_title){
    Vendor vendor("Alice", Title::STAFF_SALES, "03-1234567", 1234);

    ASSERT_EQ(vendor.GetTitle(), Title::STAFF_SALES);
}

TEST(VENDOR_TEST, test_constructor_should_have_correct_phone){
    Vendor vendor("Alice", Title::STAFF_SALES, "03-1234567", 1234);

    ASSERT_EQ(vendor.GetPhone(), "03-1234567");
}

TEST(VENDOR_TEST, test_constructor_should_have_correct_ext){
    Vendor vendor("Alice", Title::STAFF_SALES, "03-1234567", 1234);

    ASSERT_EQ(vendor.GetExt(), 1234);
}

TEST(VENDOR_TEST, test_constructor_with_invalid_ext_should_throw_exception){
    ASSERT_THROW(Vendor vendor("Alice", Title::STAFF_SALES, "03-1234567", -8851), std::invalid_argument);
}

TEST(VENDOR_TEST, test_set_name_should_have_correct_name){
    Vendor vendor("Alice", Title::STAFF_SALES, "03-1234567", 1234);

    vendor.SetName("Alice Lee");

    ASSERT_EQ(vendor.GetName(), "Alice Lee");
}

TEST(VENDOR_TEST, test_set_title_should_have_correct_title){
    Vendor vendor("Alice", Title::STAFF_SALES, "03-1234567", 1234);

    vendor.SetTitle(Title::EXTERN_SALES);

    ASSERT_EQ(vendor.GetTitle(), Title::EXTERN_SALES);
}

TEST(VENDOR_TEST, test_set_phone_exit_should_have_correct_phone_and_ext){
    Vendor vendor("Alice", Title::STAFF_SALES, "03-1234567", 1234);

    vendor.SetPhoneExt("03-7654321", 8812);

    ASSERT_EQ(vendor.GetPhone(), "03-7654321");
    ASSERT_EQ(vendor.GetExt(), 8812);
}

TEST(VENDOR_TEST, test_have_EM_permission_should_return_false){
    Vendor vendor("Alice", Title::STAFF_SALES, "03-1234567", 1234);

    ASSERT_EQ(vendor.HaveEMPermission(), false);
}

TEST(VENDOR_TEST, test_set_service_score_should_have_correct_service_score){
    Vendor vendor("Alice", Title::STAFF_SALES, "03-1234567", 1234);

    vendor.SetServiceScore(ServiceScore::A);
    ASSERT_EQ(vendor.GetServiceScore(), ServiceScore::A);
}