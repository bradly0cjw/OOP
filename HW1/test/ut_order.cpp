#include "Order.hpp"
#include <gtest/gtest.h>

std::vector<Ticket> ReturnTicket(){
    std::vector<Ticket> ans;
    for(int i=0;i<15;i++){
        switch (i%3) {
        case 0:
            ans.push_back(MakeTicketOrder(TicketType::First));
            break;
        case 1:
            ans.push_back(MakeTicketOrder(TicketType::Business));
            break;
        case 2:
            ans.push_back(MakeTicketOrder(TicketType::Economy));
            break;
        }
    }
    return ans;
}

/* Make Order Test */

TEST(ORDER_TEST, test_check_make_order_should_give_correct_infor){
    Order order = MakeOrder(ReturnTicket());

    ASSERT_EQ(order.totalCount,4875);
}
TEST(ORDER_TEST, test_check_make_order_should_throw_invaild_argument){
    std::vector<Ticket> tickets = ReturnTicket();
    for(int i=0;i<15;i++){
        tickets[i].count = 0;
    }

    ASSERT_THROW(MakeOrder(tickets),std::invalid_argument);
}

/* Check Specify Type Of Tickets */

TEST(ORDER_TEST, test_check_make_order_should_give_correct_money_first){
    Order order = MakeOrder(ReturnTicket());

    ASSERT_EQ(CheckSpecificTicketSales(TicketType::First,order),2250);
}
TEST(ORDER_TEST, test_check_make_order_should_give_correct_money_business){
    Order order = MakeOrder(ReturnTicket());

    ASSERT_EQ(CheckSpecificTicketSales(TicketType::Business,order),1625);
}
TEST(ORDER_TEST, test_check_make_order_should_give_correct_money_economy){
    Order order = MakeOrder(ReturnTicket());

    ASSERT_EQ(CheckSpecificTicketSales(TicketType::Economy,order),1000);
}
