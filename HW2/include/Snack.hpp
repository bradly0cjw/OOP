#ifndef SNACK_HPP
#define SNACK_HPP

#include <string>

class Snack {
public:
    Snack(std::string snackName);
    Snack(std::string snackName, int snackAmount);

    [[nodiscard]] std::string getName() const;
    [[nodiscard]] int getAmount() const;
    void setAmount(int snackAmount);

private:
    std::string name;
    int amount;
};

#endif
