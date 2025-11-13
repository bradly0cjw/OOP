#include <gtest/gtest.h>
#include "alcohol.hpp"
#include "coupon.hpp"
#include "deli.hpp"
#include "furniture.hpp"
#include "normal_product.hpp"
#include "product_3c.hpp"
#include "snack.hpp"
#include "vehicle.hpp"

TEST(COUPON_TEST, test_coupon_apply_with_snack_and_coupon_SAKETIME79_should_discount_price){
    Snack snack("QuiQui", 60, 2025, 06, 25);
    
    snack.ApplyCoupon(Coupon::SAKETIME79);

    ASSERT_EQ(snack.GetPrice(),  (double) 60 * 0.7);
}

TEST(COUPON_TEST, test_coupon_apply_with_alcohol_and_coupon_SAKETIME79_should_discount_price){
    Alcohol alcohol("Sake", 360, 2025, 06, 25);
    
    alcohol.ApplyCoupon(Coupon::SAKETIME79);

    ASSERT_EQ(alcohol.GetPrice(), (double) 360 * 0.9);
}

TEST(COUPON_TEST, test_coupon_apply_with_product_3c_and_coupon_BACK2SCHOOL_should_discount_price){
    Product3C product3C("macbook pro 256GB", 46000, 2027, 06);
    
    product3C.ApplyCoupon(Coupon::BACK2SCHOOL);

    ASSERT_EQ(product3C.GetPrice(), (double) 46000 * 0.8);
}

TEST(COUPON_TEST, test_coupon_apply_with_normal_product_and_coupon_BACK2SCHOOL_should_discount_price){
    NormalProduct normalProduct("sessor", 60);
    
    normalProduct.ApplyCoupon(Coupon::BACK2SCHOOL);

    ASSERT_EQ(normalProduct.GetPrice(), (double) 60 * 0.8);
}

TEST(COUPON_TEST, test_coupon_apply_with_deli_and_coupon_LUNCHTIME90_should_discount_price){
    Deli deli("sushi", 120, 2025, 06, 25);
    
    deli.ApplyCoupon(Coupon::LUNCHTIME90);

    ASSERT_EQ(deli.GetPrice(), (double) 120 * 0.9);
}

TEST(COUPON_TEST, test_coupon_apply_with_furniture_and_coupon_NEWHOME70_should_discount_price){
    Furniture furniture("chair", 4800, 2025, 06);
    
    furniture.ApplyCoupon(Coupon::NEWHOME70);

    ASSERT_EQ(furniture.GetPrice(), (double) 4800 * 0.7);
}

TEST(COUPON_TEST, test_coupon_apply_with_vehicle_and_coupon_DRIVE90_should_discount_price){
    Vehicle vehicle("ninja 256", 870000, 2025, 06);
    
    vehicle.ApplyCoupon(Coupon::DRIVE90);

    ASSERT_EQ(vehicle.GetPrice(), (double) 870000 * 0.9);
}

TEST(COUPON_TEST, test_coupon_apply_with_product_3c_and_coupon_TECHLIFE80_should_discount_price){
    Product3C product3C("macbook pro 256GB", 46000, 2027, 06);
    
    product3C.ApplyCoupon(Coupon::TECHLIFE80);

    ASSERT_EQ(product3C.GetPrice(), (double) 46000 * 0.8);
}

TEST(COUPON_TEST, test_coupon_apply_with_alcohol_and_coupon_WEEKEND80_should_discount_price){
    Alcohol alcohol("Sake", 360, 2027, 06, 25);
    
    alcohol.ApplyCoupon(Coupon::WEEKEND80);

    ASSERT_EQ(alcohol.GetPrice(), (double) 360 * 0.8);
}

TEST(COUPON_TEST, test_coupon_apply_with_snack_and_coupon_WEEKEND80_should_discount_price){
    Snack snack("Sake", 360, 2027, 06, 25);
    
    snack.ApplyCoupon(Coupon::WEEKEND80);

    ASSERT_EQ(snack.GetPrice(), (double) 360 * 0.8);
}

TEST(COUPON_TEST, test_coupon_apply_with_product_3c_and_coupon_FESTIVE80_should_discount_price){
    Product3C product3C("macbook pro 256GB", 46000, 2027, 06);
    
    product3C.ApplyCoupon(Coupon::FESTIVE80);

    ASSERT_EQ(product3C.GetPrice(), (double) 46000 * 0.8);
}

TEST(COUPON_TEST, test_coupon_apply_with_furniture_and_coupon_FESTIVE80_should_discount_price){
    Furniture furniture("chair", 3800, 2027, 06);
    
    furniture.ApplyCoupon(Coupon::FESTIVE80);

    ASSERT_EQ(furniture.GetPrice(), (double) 3800 * 0.8);
}

TEST(COUPON_TEST, test_coupon_apply_with_vehicle_and_coupon_FESTIVE80_should_discount_price){
    Vehicle vehicle("ninja 256", 860000, 2027, 06);
    
    vehicle.ApplyCoupon(Coupon::FESTIVE80);

    ASSERT_EQ(vehicle.GetPrice(), (double) 860000 * 0.8);
}

TEST(COUPON_TEST, test_coupon_apply_with_normal_product_and_coupon_FESTIVE80_should_discount_price){
    NormalProduct normalProduct("sessor", 2400);
    
    normalProduct.ApplyCoupon(Coupon::FESTIVE80);

    ASSERT_EQ(normalProduct.GetPrice(), (double) 2400 * 0.8);
}

TEST(COUPON_TEST, test_coupon_apply_with_deli_and_coupon_FESTIVE80_should_discount_price){
    Deli deli("sushi", 120, 2027, 06, 25);
    
    deli.ApplyCoupon(Coupon::FESTIVE80);

    ASSERT_EQ(deli.GetPrice(), (double) 120 * 0.8);
}

TEST(COUPON_TEST, test_coupon_apply_with_snack_and_coupon_FESTIVE80_should_discount_price){
    Snack snack("cookie", 60, 2027, 06, 25);
    
    snack.ApplyCoupon(Coupon::FESTIVE80);

    ASSERT_EQ(snack.GetPrice(), (double) 60 * 0.8);
}

TEST(COUPON_TEST, test_coupon_apply_with_alcohol_and_coupon_FESTIVE80_should_discount_price){
    Alcohol alcohol("sake", 360, 2027, 06, 25);
    
    alcohol.ApplyCoupon(Coupon::FESTIVE80);

    ASSERT_EQ(alcohol.GetPrice(), (double) 360 * 0.8);
}

TEST(COUPON_TEST, test_coupon_apply_with_deli_and_coupon_TEATIME80_should_discount_price){
    Deli deli("sushi", 120, 2027, 06, 25);
    
    deli.ApplyCoupon(Coupon::TEATIME80);

    ASSERT_EQ(deli.GetPrice(), (double) 120 * 0.8);
}

TEST(COUPON_TEST, test_coupon_apply_with_snacks_and_coupon_TEATIME80_should_discount_price){
    Snack snack("cookie", 60, 2027, 06, 25);
    
    snack.ApplyCoupon(Coupon::TEATIME80);

    ASSERT_EQ(snack.GetPrice(), (double) 60 * 0.8);
}

TEST(COUPON_TEST, test_coupon_apply_with_deli_and_coupon_HEALTHY90_should_discount_price){
    Product3C product3C("macbook pro 64GB", 36000, 2027, 06);
    
    product3C.ApplyCoupon(Coupon::HEALTHY90);

    ASSERT_EQ(product3C.GetPrice(), (double) 36000 * 0.9);
}

TEST(COUPON_TEST, test_coupon_apply_with_product_3c_and_coupon_OOPALLPASS_should_discount_price){
    Product3C product3C("macbook pro 256GB", 46000, 2027, 06);
    
    product3C.ApplyCoupon(Coupon::OOPALLPASS);

    ASSERT_EQ(product3C.GetPrice(), (double) 46000);
}

TEST(COUPON_TEST, test_coupon_apply_with_furniture_and_coupon_OOPALLPASS_should_discount_price){
    Furniture furniture("chair", 3800, 2027, 06);
    
    furniture.ApplyCoupon(Coupon::OOPALLPASS);

    ASSERT_EQ(furniture.GetPrice(), (double) 3800);
}

TEST(COUPON_TEST, test_coupon_apply_with_vehicle_and_coupon_OOPALLPASS_should_discount_price){
    Vehicle vehicle("ninja 256", 860000, 2027, 06);
    
    vehicle.ApplyCoupon(Coupon::OOPALLPASS);

    ASSERT_EQ(vehicle.GetPrice(), (double) 860000);
}

TEST(COUPON_TEST, test_coupon_apply_with_normal_product_and_coupon_OOPALLPASS_should_discount_price){
    NormalProduct normalProduct("sessor", 2400);
    
    normalProduct.ApplyCoupon(Coupon::OOPALLPASS);

    ASSERT_EQ(normalProduct.GetPrice(), (double) 2400);
}

TEST(COUPON_TEST, test_coupon_apply_with_deli_and_coupon_OOPALLPASS_should_discount_price){
    Deli deli("sushi", 120, 2027, 06, 25);
    
    deli.ApplyCoupon(Coupon::OOPALLPASS);

    ASSERT_EQ(deli.GetPrice(), (double) 120);
}

TEST(COUPON_TEST, test_coupon_apply_with_snack_and_coupon_OOPALLPASS_should_discount_price){
    Snack snack("cookie", 60, 2027, 06, 25);
    
    snack.ApplyCoupon(Coupon::OOPALLPASS);

    ASSERT_EQ(snack.GetPrice(), (double) 60);
}

TEST(COUPON_TEST, test_coupon_apply_with_alcohol_and_coupon_OOPALLPASS_should_discount_price){
    Alcohol alcohol("sake", 360, 2027, 06, 25);
    
    alcohol.ApplyCoupon(Coupon::OOPALLPASS);

    ASSERT_EQ(alcohol.GetPrice(), (double) 360);
}

TEST(COUPON_TEST, test_coupon_apply_with_product_3c_and_coupon_OOPALLFAILED_should_discount_price){
    Product3C product3C("macbook pro 256GB", 46000, 2027, 06);
    
    product3C.ApplyCoupon(Coupon::OOPALLFAILED);

    ASSERT_EQ(product3C.GetPrice(), (double) 0);
}

TEST(COUPON_TEST, test_coupon_apply_with_furniture_and_coupon_OOPALLFAILED_should_discount_price){
    Furniture furniture("chair", 3800, 2027, 06);
    
    furniture.ApplyCoupon(Coupon::OOPALLFAILED);

    ASSERT_EQ(furniture.GetPrice(), (double) 0);
}

TEST(COUPON_TEST, test_coupon_apply_with_vehicle_and_coupon_OOPALLFAILED_should_discount_price){
    Vehicle vehicle("ninja 256", 860000, 2027, 06);
    
    vehicle.ApplyCoupon(Coupon::OOPALLFAILED);

    ASSERT_EQ(vehicle.GetPrice(), (double) 0);
}

TEST(COUPON_TEST, test_coupon_apply_with_normal_product_and_coupon_OOPALLFAILED_should_discount_price){
    NormalProduct normalProduct("sessor", 2400);
    
    normalProduct.ApplyCoupon(Coupon::OOPALLFAILED);

    ASSERT_EQ(normalProduct.GetPrice(), (double) 0);
}

TEST(COUPON_TEST, test_coupon_apply_with_deli_and_coupon_OOPALLFAILED_should_discount_price){
    Deli deli("sushi", 120, 2027, 06, 25);
    
    deli.ApplyCoupon(Coupon::OOPALLFAILED);

    ASSERT_EQ(deli.GetPrice(), (double) 0);
}

TEST(COUPON_TEST, test_coupon_apply_with_snack_and_coupon_OOPALLFAILED_should_discount_price){
    Snack snack("cookie", 60, 2027, 06, 25);
    
    snack.ApplyCoupon(Coupon::OOPALLFAILED);

    ASSERT_EQ(snack.GetPrice(), (double) 0);
}

TEST(COUPON_TEST, test_coupon_apply_with_alcohol_and_coupon_OOPALLFAILED_should_discount_price){
    Alcohol alcohol("sake", 360, 2027, 06, 25);
    
    alcohol.ApplyCoupon(Coupon::OOPALLFAILED);

    ASSERT_EQ(alcohol.GetPrice(), (double) 0);
}

TEST(COUPON_TEST, test_coupon_apply_with_product_3c_and_coupon_SAKETIME79_should_not_discount_price){
    Product3C product3C("macbook pro 256GB", 86400, 2027, 06);
    
    product3C.ApplyCoupon(Coupon::SAKETIME79);

    ASSERT_EQ(product3C.GetPrice(), (double) 86400);
}

TEST(COUPON_TEST, test_coupon_apply_with_product_3c_and_coupon_LUNCHTIME90_should_not_discount_price){
    Product3C product3C("macbook pro 256GB", 86400, 2027, 06);
    
    product3C.ApplyCoupon(Coupon::LUNCHTIME90);

    ASSERT_EQ(product3C.GetPrice(), (double) 86400);
}

TEST(COUPON_TEST, test_coupon_apply_with_product_3c_and_coupon_NEWHOME70_should_not_discount_price){
    Product3C product3C("macbook pro 256GB", 86400, 2027, 06);
    
    product3C.ApplyCoupon(Coupon::NEWHOME70);

    ASSERT_EQ(product3C.GetPrice(), (double) 86400);
}

TEST(COUPON_TEST, test_coupon_apply_with_product_3c_and_coupon_DRIVE90_should_not_discount_price){
    Product3C product3C("macbook pro 256GB", 86400, 2027, 06);
    
    product3C.ApplyCoupon(Coupon::DRIVE90);

    ASSERT_EQ(product3C.GetPrice(), (double) 86400);
}

TEST(COUPON_TEST, test_coupon_apply_with_product_3c_and_coupon_WEEKEND80_should_not_discount_price){
    Product3C product3C("macbook pro 256GB", 86400, 2027, 06);
    
    product3C.ApplyCoupon(Coupon::WEEKEND80);

    ASSERT_EQ(product3C.GetPrice(), (double) 86400);
}

TEST(COUPON_TEST, test_coupon_apply_with_product_3c_and_coupon_TEATIME80_should_not_discount_price){
    Product3C product3C("macbook pro 256GB", 86400, 2027, 06);
    
    product3C.ApplyCoupon(Coupon::TEATIME80);

    ASSERT_EQ(product3C.GetPrice(), (double) 86400);
}

TEST(COUPON_TEST, test_expire_coupon_apply_with_deli_should_discount_price){
    Deli deli("sushi", 120, 2027, 06, 25);
    
    deli.ApplyExpireCoupon();

    ASSERT_EQ(deli.GetPrice(), (double) 120 * 0.8);
}
