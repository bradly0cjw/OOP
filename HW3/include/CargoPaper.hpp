#ifndef CARGO_PAPER_HPP
#define CARGO_PAPER_HPP

#include "Ticket.hpp"
#include <string>

enum class CargoType{
    Food,
    Drink,
    Vehicle,
    Electronics,
    Furniture
};

class CargoPaper : public Ticket{
private:
    int volume;
    CargoType cargoType;
public:
    CargoPaper(std::string dest,std::string src,int range,int volume,CargoType cargoType);
    int GetVolume();
    CargoType GetCargoType();

    virtual void CalculateTicketPrice() override;
};

#endif