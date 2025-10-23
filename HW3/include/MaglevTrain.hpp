#ifndef MAGLEV_TRAIN_HPP
#define MAGLEV_TRAIN_HPP

#include "Train.hpp"

class MaglevTrain : public Train{
private:
    int powerLimit;
    int power;
    int seatLimit;
    int seat;
public:
    MaglevTrain(int powerLimit,int seatLimit,TrainType type,int trainNumber,int speedLimit);
    int GetPowerLimit();
    int GetSeatLimit();
    void SetPowerLimit(int powerLimit);
    int GetPower();
    int GetSeat();
    void SetSeat();
    void Charge(int hour);

    void PowerUp();
    void SpeedUp();
    void SpeedDown();
};

#endif