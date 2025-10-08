#include "Snack.hpp"

Snack::Snack(std::string snackName) {
    amount = 1;
    name = snackName;
}

Snack::Snack(std::string snackName, int snackAmount) {
    amount = snackAmount;
    name = snackName;
}

std::string Snack::getName() const {
    return name;
}

int Snack::getAmount() const {
    return amount;
}

void Snack::setAmount(int snackAmount) {
    amount = snackAmount;
}