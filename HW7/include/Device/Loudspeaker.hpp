#ifndef LOUDSPEAKER_HPP
#define LOUDSPEAKER_HPP

#include "Device.hpp"

class Loudspeaker : public Device{
public:
    Loudspeaker(std::string name, int power);
    Loudspeaker(std::string name, int power, int volume);

    void setVolume(int volume);
    int getVolume();
private:
    int volume;
};

#endif