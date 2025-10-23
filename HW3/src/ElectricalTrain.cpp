#include "ElectricalTrain.hpp"

ElectricalTrain::ElectricalTrain(int powerLimit, int seatLimit, TrainType type,
                                 int trainNumber, int speedLimit)
    : Train(type, trainNumber, speedLimit) {
    if (powerLimit < 0 || powerLimit > 100) {
        throw std::invalid_argument("Power limit must be between 0 and 100");
    }
    if (seatLimit < 0) {
        throw std::invalid_argument("Seat limit must be non-negative");
    }
    this->powerLimit = powerLimit;
    this->power = 0;
    this->seatLimit = seatLimit;
    this->seat = 0;
}
int ElectricalTrain::GetPowerLimit() {
    return this->powerLimit;
}
int ElectricalTrain::GetSeatLimit() {
    return this->seatLimit;
}
void ElectricalTrain::SetPowerLimit(int powerLimit) {
    if (powerLimit < 0 || powerLimit > 100) {
        throw std::invalid_argument("Power limit must be between 0 and 100");
    }
    this->powerLimit = powerLimit;
}
int ElectricalTrain::GetPower() {
    return this->power;
}
int ElectricalTrain::GetSeat() {
    return this->seat;
}
void ElectricalTrain::SetSeat() {
    if (this->seat + 1 > this->seatLimit) {
        throw std::invalid_argument("Exceeding seat limit");
    }
    this->seat += 1;
}
void ElectricalTrain::Charge(int hour) {
    if (hour < 0) {
        throw std::invalid_argument("Charge hours must be non-negative");
    }
    this->power = std::min(this->power + hour * 18, this->powerLimit);
}
void ElectricalTrain::PowerUp() {
    if (this->power - 1 <= 0) {
        throw std::invalid_argument("Not enough power to power up");
    }
    this->power -= 1;
    Train::PowerUp();
}
void ElectricalTrain::SpeedUp() {
    if (this->power - 3 <= 0) {
        //        throw std::invalid_argument("Not enough power to speed up");
        return;
    }
    if (this->speed >= GetSpeedLimit()) {
        throw std::invalid_argument("Speed limit exceeded");
    }
    this->power -= 3;

//    if (15 + this->speed / 20 + this->speed> GetSpeedLimit()){
//        throw std::invalid_argument("Speed limit exceeded");
//    }
//    this->speed = 15 + this->speed / 20 + this->speed;
    this->speed = std::min(this->speed + 15, GetSpeedLimit());

}
void ElectricalTrain::SpeedDown() {
    if (this->power <= 0) {
        throw std::invalid_argument("Not enough power to speed down");
    }
    this->speed = std::max(this->speed - 15, 0);
}
