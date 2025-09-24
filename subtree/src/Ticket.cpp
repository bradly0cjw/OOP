#include "Ticket.hpp"
#include <stdexcept>

Ticket MakeTicketOrder(TicketType type);
int CheckTicketPrice(Ticket ticket);

Ticket MakeTicketOrder(TicketType type){
    Ticket ticket;
    ticket.type = type;
    switch(type){
        case TicketType::First:
            ticket.count = 450;
            break;
        case TicketType::Business:
            ticket.count = 325;
            break;
        case TicketType::Economy:
            ticket.count = 200;
            break;
        default:
            throw std::invalid_argument("Invalid ticket type");
    }
    return ticket;
}

int CheckTicketPrice(Ticket ticket){
    switch(ticket.type){
        case TicketType::First:
            if (ticket.count == 450) {
                return 450;
            } else {
                throw std::invalid_argument("Invalid ticket count for First class");
            }
        case TicketType::Business:
            if (ticket.count == 325) {
                return 325;
            } else {
                throw std::invalid_argument("Invalid ticket count for Business class");
            }
        case TicketType::Economy:
            if (ticket.count == 200) {
                return 200;
            } else {
                throw std::invalid_argument("Invalid ticket count for Economy class");
            }
        default:
            throw std::invalid_argument("Invalid ticket type");
    }
}