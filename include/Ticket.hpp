#ifndef TICKET_HPP
#define TICKET_HPP

enum class TicketType{
    First,
    Business,
    Economy,
};

struct Ticket{
    TicketType type;
    int count;
};

Ticket MakeTicketOrder(TicketType type);
int CheckTicketPrice(Ticket ticket);
#endif
