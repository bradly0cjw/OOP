#ifndef DEHUMIDIFIER_HPP
#define DEHUMIDIFIER_HPP

#include "Device.hpp"

class Dehumidifier : public Device {
public:
    Dehumidifier(std::string name, int power);
    Dehumidifier(std::string name, int power, int humidity);

    void setHumidity(int humidity);
    int getHumidity();
private:
    int humidity;
};

#endif
