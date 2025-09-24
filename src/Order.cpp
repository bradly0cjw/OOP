#include "Order.hpp"
#include <stdexcept>

Order MakeOrder(std::vector<Ticket> tickets);
int CheckSpecificTicketSales(TicketType type,Order order);

Order MakeOrder(std::vector<Ticket> tickets){
    Order order;
    order.tickets = tickets;
    order.totalCount = 0;
    for(const auto& ticket : tickets){
        CheckTicketPrice(ticket);
        order.totalCount += ticket.count;
    }
    return order;
}

int CheckSpecificTicketSales(TicketType type,Order order){
    int count = 0;
    for(const auto& ticket : order.tickets){
        if(ticket.type == type){
            count += ticket.count;
        }
    }
    return count;
}