#include "DepartmentService.h"

DepartmentService::DepartmentService()
: Service()
{}


DepartmentService::DepartmentService(std::shared_ptr<IDatabase> db)
: Service(db)
{
}


bool DepartmentService::addDepartment(const Department& obj) const {
    return this->db->insert(this->tableName, {{"name_department" , obj.name_department}});
}

//get by name_dep
std::optional<Department> DepartmentService::getDepartment(const std::string& name) const {
    auto resp = this->db->get(this->tableName, {{"name_department", name}});
    if(!resp.has_value()){
        return std::nullopt;
    }
    auto firstMap = resp.value().front();
    return Department{std::stoi(firstMap["id"]), firstMap["name_department"]};    
}

//update by id
bool DepartmentService::updateDepartment(const Department& obj) const {
    return this->db->update(this->tableName, {{"name_department" , obj.name_department}}, {{"id", std::to_string(obj.id)}});
}

//delete by name_dep
bool DepartmentService::deleteDepartment(const std::string& name) const {
    return this->db->remove(this->tableName, {{"name_department", name}});
}