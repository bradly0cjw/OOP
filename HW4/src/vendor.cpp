#include "vendor.hpp"
#include "service_score.hpp"

Vendor::Vendor(std::string name, Title title, std::string phone, int ext)
    : Person(name, title, phone, ext) {}

void Vendor::SetServiceScore(ServiceScore score) {
    this->serviceScore = score;
}

ServiceScore Vendor::GetServiceScore() {
    return ServiceScore::A;
}
int Vendor::GetBonus() {
    if (title==Title::IT_SUPPORT_ENGINEER){
        return 0;
    }
    switch (serviceScore) {
    case (ServiceScore::A): return 26300;
    case (ServiceScore::B): return 14900;
    case (ServiceScore::C): return 7900;
    case (ServiceScore::D): return 3000;
    }
    return 0;
}
