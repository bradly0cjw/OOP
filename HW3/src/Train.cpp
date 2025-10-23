#include "Train.hpp"

Train::Train(TrainType type, int trainNumber, int speedLimit) {
    if (trainNumber < 0 || speedLimit < 0) {
        throw std::invalid_argument(
            "Train number and speed limit must be non-negative");
    }
    this->type = type;
    this->trainNumber = trainNumber;
    this->speedLimit = speedLimit;
    this->speed = 0;
    this->open = false;
}

TrainType Train::GetType() {
    return this->type;
}
int Train::GetTrainNumber() {
    return this->trainNumber;
}
int Train::GetSpeedLimit() {
    return this->speedLimit;
}
int Train::GetSpeed() {
    return this->speed;
}
bool Train::IsOpen() {
    return this->open;
}
void Train::PowerUp() {
    this->open = true;

}
void Train::PowerDown() {
    this->open = false;
    this->speed = 0;
}
