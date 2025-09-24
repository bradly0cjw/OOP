#ifndef TICKET_SYSTEM_HPP
#define TICKET_SYSTEM_HPP

#include "Ticket.hpp"
#include <string>
#include <vector>

struct Order{
    std::vector<Ticket> tickets;
    int totalCount;
};

Order MakeOrder(std::vector<Ticket> tickets);
int CheckSpecificTicketSales(TicketType type,Order order);
#endif