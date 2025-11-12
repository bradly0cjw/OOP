#include "project_manager.hpp"
#include "staff.hpp"
#include "staff_no.hpp"

ProjectManager::ProjectManager(std::string name, std::string phone, int ext, StaffLevel level): Staff(name,Title::PROJECT_MANAGER, phone,ext,StaffNo::M,level){

}
