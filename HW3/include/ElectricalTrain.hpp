#ifndef ELECTRICAL_TRAIN_HPP
#define ELECTRICAL_TRAIN_HPP

#include "Train.hpp"

class ElectricalTrain : public Train{
private:
    int powerLimit;
    int power;
    int seatLimit;
    int seat;
public:
    ElectricalTrain(int powerLimit,int seatLimit,TrainType type,int trainNumber,int speedLimit);
    int GetPowerLimit();
    int GetSeatLimit();
    void SetPowerLimit(int powerLimit);
    int GetPower();
    int GetSeat();
    void SetSeat();
    void Charge(int hour);

    void PowerUp() override;
    void SpeedUp() override;
    void SpeedDown() override;
};

#endif