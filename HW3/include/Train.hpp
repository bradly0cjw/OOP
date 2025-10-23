#ifndef TRAIN_HPP
#define TRAIN_HPP

#include <stdexcept>
#include <cmath>

enum class  TrainType{
    Express,
    Limited,
    Local,
    Cargo
};

class Train{
private:
    TrainType type;
    int trainNumber;
    int speedLimit;
protected:
    int speed = 0;
    bool open = false;
public:
    Train(TrainType type,int trainNumber,int speedLimit);
    TrainType GetType();
    int GetTrainNumber();
    int GetSpeedLimit();
    int GetSpeed();
    bool IsOpen();

    virtual void PowerUp();
    virtual void PowerDown();
    virtual void SpeedUp() =0;
    virtual void SpeedDown()=0;
};

#endif