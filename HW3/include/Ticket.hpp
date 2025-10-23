#ifndef TICKET_HPP
#define TICKET_HPP

#include "Train.hpp"
#include <string>

class Ticket{
private:
    std::string dest;
    std::string src;
    int trainNumber;
protected:
    int price;
    int range;
    TrainType type;
public:
    Ticket(std::string dest,std::string src,int range,int trainNumber,TrainType type);
    std::string GetDest();
    std::string GetSrc();
    int GetPrice();
    int GetTrainNumber();
    TrainType GetTrainType();

    void CalculateTicketPrice();
};

#endif