#include <gtest/gtest.h>

#include "Ticket.hpp"

/* Make Ticket Test */
TEST(TICKET_TEST, test_check_make_ticket_should_give_first_class){
    Ticket ticket = MakeTicketOrder(TicketType::First);

    ASSERT_EQ(ticket.count,450);
    ASSERT_EQ(ticket.type,TicketType::First);
}
TEST(TICKET_TEST, test_check_make_ticket_should_give_bussiness_class){
    Ticket ticket = MakeTicketOrder(TicketType::Business);

    ASSERT_EQ(ticket.count,325);
    ASSERT_EQ(ticket.type,TicketType::Business);
}
TEST(TICKET_TEST, test_check_make_ticket_should_give_economy_class){
    Ticket ticket = MakeTicketOrder(TicketType::Economy);

    ASSERT_EQ(ticket.count,200);
    ASSERT_EQ(ticket.type,TicketType::Economy);
}

/* Check Price Test */
TEST(TICKET_PRICE_TEST, test_check_make_ticket_should_give_correct_price){
    Ticket ticket = MakeTicketOrder(TicketType::First);

    ASSERT_EQ(CheckTicketPrice(ticket),450);
}
TEST(TICKET_PRICE_TEST, test_check_make_ticket_should_give_correct_price_two){
    Ticket ticket = MakeTicketOrder(TicketType::Business);

    ASSERT_EQ(CheckTicketPrice(ticket),325);
}
TEST(TICKET_PRICE_TEST, test_check_make_ticket_should_give_correct_price_three){
    Ticket ticket = MakeTicketOrder(TicketType::Economy);

    ASSERT_EQ(CheckTicketPrice(ticket),200);
}

TEST(TICKET_PRICE_TEST, test_check_make_ticket_should_throw_invaild_argument){
    Ticket ticket = MakeTicketOrder(TicketType::First);
    ticket.count = 200;

    ASSERT_THROW(CheckTicketPrice(ticket),std::invalid_argument);
}
TEST(TICKET_PRICE_TEST, test_check_make_ticket_should_throw_invaild_argument_two){
    Ticket ticket = MakeTicketOrder(TicketType::Business);
    ticket.count = 450;

    ASSERT_THROW(CheckTicketPrice(ticket),std::invalid_argument);
}
TEST(TICKET_PRICE_TEST, test_check_make_ticket_should_throw_invaild_argument_three){
    Ticket ticket = MakeTicketOrder(TicketType::Economy);
    ticket.count = 300;

    ASSERT_THROW(CheckTicketPrice(ticket),std::invalid_argument);
}