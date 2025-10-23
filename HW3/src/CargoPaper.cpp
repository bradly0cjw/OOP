#include "CargoPaper.hpp"

CargoPaper::CargoPaper(std::string dest, std::string src, int range,
                         int volume, CargoType cargoType)
    : Ticket(dest, src, range, 0, TrainType::Cargo) {
    if (volume < 0) {
        throw std::invalid_argument("Volume must be non-negative");
    }
    this->volume = volume;
    this->cargoType = cargoType;
    CalculateTicketPrice();
}

int CargoPaper::GetVolume() {
    return this->volume;
}
CargoType CargoPaper::GetCargoType() {
    return this->cargoType;
}
void CargoPaper::CalculateTicketPrice() {
    int basePricePerKm = 4; // Base price for cargo trains
    float weightFactor;
    float typeMultiplier = 1;

    if (this->cargoType == CargoType::Vehicle) {
        weightFactor = 75 * this->volume;
    } else {
        weightFactor = (this->volume/100)*75;
    }
    switch (this->cargoType) {
        case CargoType::Food:
            typeMultiplier = 1.1;
            break;
        case CargoType::Drink:
            typeMultiplier = 1.1;
            break;
        case CargoType::Vehicle:
            typeMultiplier = 1.2;
            break;
        case CargoType::Electronics:
            typeMultiplier = 1.15;
            break;
        case CargoType::Furniture:
            typeMultiplier = 1.15;
            break;
    }

    this->price = (this->range * basePricePerKm + weightFactor)* typeMultiplier ;
}