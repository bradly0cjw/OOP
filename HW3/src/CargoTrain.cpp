#include "CargoTrain.hpp"

CargoTrain::CargoTrain(int fuelLimit, int cargoLimit, TrainType type,
                       int trainNumber, int speedLimit)
    : Train(type, trainNumber, speedLimit) {
    if (fuelLimit < 0 || cargoLimit < 0) {
        throw std::invalid_argument(
            "Fuel limit and cargo limit must be non-negative");
    }
    this->fuelLimit = fuelLimit;
    this->fuel = 0;
    this->cargoLimit = cargoLimit;
    this->cargo = 0;
}
int CargoTrain::GetFuelLimit() {
    return this->fuelLimit;
}
int CargoTrain::GetCargoLimit() {
    return this->cargoLimit;
}
void CargoTrain::SetFuelLimit(int fuelLimit) {
    if (fuelLimit < 0 || fuelLimit > 1000) {
        throw std::invalid_argument("Fuel limit must be non-negative");
    }
    this->fuelLimit = fuelLimit;
}
int CargoTrain::GetFuel() {
    return this->fuel;
}
int CargoTrain::GetCargo() {
    return this->cargo;
}
void CargoTrain::AddCargo(int cargo) {
    if (cargo < 0) {
        throw std::invalid_argument("Cargo to add must be non-negative");
    }
    if (this->cargo + cargo > this->cargoLimit) {
        throw std::invalid_argument("Exceeding cargo limit");
    }
    this->cargo += cargo;
}
void CargoTrain::AddFuel(int fuel) {
    if (fuel < 0) {
        throw std::invalid_argument("Fuel to add must be non-negative");
    }
    if (this->fuel + fuel > this->fuelLimit) {
        throw std::invalid_argument("Exceeding fuel limit");
    }
    this->fuel += fuel;
}
void CargoTrain::PowerUp() {
    if (this->fuel - 5 < 0) {
        throw std::invalid_argument("Not enough fuel to power up");
    }
    if (this->IsOpen()){
        return;
    }
    this->fuel -= 5;
    Train::PowerUp();
}
void CargoTrain::SpeedUp() {
    if (this->fuel <= 0) {
                throw std::invalid_argument("Not enough fuel to speed up");
        return;
    }
    if (this->speed > GetSpeedLimit()) {
        throw std::invalid_argument("Speed limit exceeded");
    }
    if (this->fuel < 10){
        return;
    }
    this->fuel -= 10;
    float weightRatio = static_cast<float>(this->cargo) / this->cargoLimit;
    //    if (weightRatio < 0.3) {
    //        if (15 + this->speed / 20 + this->speed > GetSpeedLimit())
    //            throw std::invalid_argument("Speed limit exceeded");
    //        this->speed = 15 + this->speed / 20 + this->speed;
    //
    //    } else if (weightRatio < 0.7) {
    //        if (15 + this->speed / 25 + this->speed > GetSpeedLimit())
    //            throw std::invalid_argument("Speed limit exceeded");
    //        this->speed = 15 + this->speed / 25 + this->speed;
    //    } else {
    //        if (15 + this->speed / 30 + this->speed > GetSpeedLimit())
    //            throw std::invalid_argument("Speed limit exceeded");
    //        this->speed = 15 + this->speed / 30 + this->speed;
    //    }
    if (weightRatio < 0.3) {
        this->speed =
            std::min(15 + this->speed / 20 + this->speed, GetSpeedLimit());
    } else if (weightRatio < 0.7) {
        this->speed =
            std::min(15 + this->speed / 25 + this->speed, GetSpeedLimit());
    } else {
        this->speed =
            std::min(15 + this->speed / 30 + this->speed, GetSpeedLimit());
    }

}
void CargoTrain::SpeedDown() {
    if (this->fuel <= 0) {
        throw std::invalid_argument("Not enough fuel to speed down");
    }

    this->speed = std::max(this->speed - 15, 0);
}