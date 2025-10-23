#include <gtest/gtest.h>

#include "Ticket.hpp"

/* Make Ticket Test */
TEST(TICKET_TEST, test_check_make_ticket_should_give_correct_information){
    Ticket ticket = Ticket("Taipei","Xizhi",20,17,TrainType::Local);
    ticket.CalculateTicketPrice();

    ASSERT_EQ(ticket.GetTrainNumber(),17);
    ASSERT_EQ(ticket.GetSrc(),"Xizhi");
    ASSERT_EQ(ticket.GetDest(),"Taipei");
    ASSERT_EQ(ticket.GetTrainType(),TrainType::Local);
    ASSERT_EQ(ticket.GetPrice(),40);
}
TEST(TICKET_TEST, test_check_make_ticket_should_give_calculate_diff_price){
    Ticket ticket = Ticket("Taipei","Xizhi",20,17,TrainType::Limited);
    ticket.CalculateTicketPrice();

    ASSERT_EQ(ticket.GetPrice(),48);
}
TEST(TICKET_TEST, test_check_make_ticket_should_give_diff_price_express_one){
    Ticket ticket = Ticket("Taipei","Xizhi",20,17,TrainType::Express);
    ticket.CalculateTicketPrice();

    ASSERT_EQ(ticket.GetPrice(),56);
}

TEST(TICKET_TEST, test_check_make_ticket_should_give_diff_price_express_two){
    Ticket ticket = Ticket("Taipei","Taichung",200,17,TrainType::Express);
    ticket.CalculateTicketPrice();

    ASSERT_EQ(ticket.GetPrice(),610);
}