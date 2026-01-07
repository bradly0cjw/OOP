#ifndef AIRCONDITIONER_HPP
#define AIRCONDITIONER_HPP

#include "Device.hpp"

class AirConditioner : public Device {
public:
    AirConditioner(std::string name, int power);
    AirConditioner(std::string name, int power, int temperature);

    void setTemperature(int temperature);
    int  getTemperature();

private:
    int temperature;
};

#endif
