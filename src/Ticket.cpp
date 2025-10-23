#include "Ticket.hpp"

Ticket::Ticket(std::string dest, std::string src, int range, int trainNumber,
               TrainType type) {
    if (range < 0) {
        throw std::invalid_argument("Range must be non-negative");
    }

    this->dest = dest;
    this->src = src;
    this->range = range;
    this->trainNumber = trainNumber;
    this->type = type;
    this->price = 0;
}
std::string Ticket::GetDest() {
    return this->dest;
}
std::string Ticket::GetSrc() {
    return this->src;
}
int Ticket::GetPrice() {
    return this->price;
}
int Ticket::GetTrainNumber() {
    return this->trainNumber;
}
TrainType Ticket::GetTrainType() {
    return this->type;
}
void Ticket::CalculateTicketPrice() {
    switch (this->type) {
    case TrainType::Express:
        this->price = this->range * 2 * 1.4 + this->range / 100 * 25;
        break;
    case TrainType::Limited:
        this->price = this->range * 2 * 1.2;
        break;
    case TrainType::Local:
        this->price = this->range * 2;
        break;
    case TrainType::Cargo:
        this->price = this->range * 2;
        break;
    }
}
