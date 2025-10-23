#include "MaglevTrain.hpp"

MaglevTrain::MaglevTrain(int powerLimit, int seatLimit, TrainType type,
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
int MaglevTrain::GetPowerLimit() {
    return this->powerLimit;
}
int MaglevTrain::GetSeatLimit() {
    return this->seatLimit;
}
void MaglevTrain::SetPowerLimit(int powerLimit) {
    if (powerLimit < 0 || powerLimit > 100) {
        throw std::invalid_argument("Power limit must be between 0 and 100");
    }
    this->powerLimit = powerLimit;
}
int MaglevTrain::GetPower() {
    return this->power;
}
int MaglevTrain::GetSeat() {
    return this->seat;
}
void MaglevTrain::SetSeat() {
    if (this->seat + 1 > this->seatLimit) {
        throw std::invalid_argument("Exceeding seat limit");
    }
    this->seat += 1;
}
void MaglevTrain::Charge(int hour) {
    if (hour < 0) {
        throw std::invalid_argument("Charge hours must be non-negative");
    }
    this->power = std::min(this->power + hour * 25, this->powerLimit);
}
void MaglevTrain::PowerUp() {
    if (this->power - 1 <= 0) {
        throw std::invalid_argument("Not enough power to power up");
    }
    this->power -= 1;
    Train::PowerUp();
}
void MaglevTrain::SpeedUp() {
    if (this->power - 3 <= 0) {
        //        throw std::invalid_argument("Not enough power to speed up");
        return;
    }
    if (this->speed >= GetSpeedLimit()) {
        throw std::invalid_argument("Speed limit exceeded");
    }
    this->power -= 3;
//    if (30 + this->speed / 15 + this->speed > GetSpeedLimit())
//        throw std::invalid_argument("Speed limit exceeded");
//    this->speed = 30 + this->speed / 15 + this->speed;
    this->speed =std::min(this->speed + 30 + this->speed / 15, GetSpeedLimit());
}
void MaglevTrain::SpeedDown() {
    if (this->power <= 0) {
        throw std::invalid_argument("Not enough power to speed down");
    }
    this->speed = std::max(this->speed - 30, 0);
}
