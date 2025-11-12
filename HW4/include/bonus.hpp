#ifndef BONUS_HPP
#define BONUS_HPP

enum class BonusType {
    EM,
    SALE
};

const double SALE_0_10_RATIO = 0.1;
const double SALE_11_20_RATIO = 0.15;
const double SALE_21_INF_RATIO = 0.2;

const int VENDOR_A_EM = 26300;
const int VENDOR_B_EM = 14900;
const int VENDOR_C_EM = 7900;
const int VENDOR_D_EM = 3000;

const int STAFF_M_L1_EM = 60000;
const int STAFF_M_L2_EM = 73000;
const int STAFF_M_L3_EM = 94000;

const int STAFF_E_L1_EM = 56000;
const int STAFF_E_L2_EM = 64000;
const int STAFF_E_L3_EM = 83000;

#endif