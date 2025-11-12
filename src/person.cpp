
#include "person.hpp"
#include <stdexcept>
#include "title.hpp"

Person::Person(std::string name, Title title, std::string phone, int ext) {
    if (ext < 0) { throw std::invalid_argument(""); }
    this->ext = ext;
    this->name = name;
    this->title = title;
    this->phone = phone;
}

std::string Person::GetName() {
    //    return "";
    return name;
}

Title Person::GetTitle() {
    //    return Title::CYLINDER_ENGINEER;
    return title;
}

std::string Person::GetPhone() {
    //    return "";
    return phone;
}

int Person::GetExt() {
    //    return 0;
    return ext;
}

void Person::SetName(std::string name) {
    this->name = name;
}

void Person::SetTitle(Title title) {
    this->title = title;
}

void Person::SetPhoneExt(std::string phone, int ext) {
    if (ext < 0) { throw std::invalid_argument(""); }
    this->phone = phone;
    this->ext = ext;
}

bool Person::HaveEMPermission() {
    switch (title) {
    case (Title::PROJECT_MANAGER): return true;
    case (Title::CYLINDER_ENGINEER): return true;
    case (Title::INFRASTRUCTURE_ENGINEER): return true;
    default: return false;
    }
}
