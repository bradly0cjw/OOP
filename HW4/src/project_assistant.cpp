#include "project_assistant.hpp"
#include "staff.hpp"
#include "staff_no.hpp"
#include "title.hpp"

ProjectAssistant::ProjectAssistant(std::string name, std::string phone, int ext, StaffLevel level):Staff(name,Title::PROJECT_ASSISTANT, phone,ext,StaffNo::N,level) {

}
