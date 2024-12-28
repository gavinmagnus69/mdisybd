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
std::optional<Department> DepartmentService::getDepartment(const std::map<std::string, std::string>& cond) const {
    auto resp = this->db->get(this->tableName, cond);
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
bool DepartmentService::deleteDepartment(const std::map<std::string, std::string>& cond) const {
    return this->db->remove(this->tableName, cond);
}



std::optional<std::vector<Department>> DepartmentService::getAll() {
    auto resp = this->db->get(this->tableName, {});
    if(!resp.has_value()){
        return std::nullopt;
    }
    auto firstSubMap = resp.value();
    std::vector<Department> subs;
    for(auto m : firstSubMap) {
        subs.push_back(Department{std::stoi(m["id"]), m["name_department"]});
    }
    return subs;    
}