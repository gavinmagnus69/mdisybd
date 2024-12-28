#include "EnrolleeService.h"


EnrolleeService::EnrolleeService()
: Service()
{}


EnrolleeService::EnrolleeService(std::shared_ptr<IDatabase> db)
: Service(db)
{
}

//get enrollee by params
bool EnrolleeService::addEnrollee(const Enrollee& obj) const {
    return this->db->insert(this->tableName, {{"name_enrollee" , obj.name_enrollee}, {"user_id" , std::to_string(obj.user_id)}});
}

// search by params, to map<string ,string>
std::optional<Enrollee> EnrolleeService::getEnrollee(const std::map<std::string, std::string>& cond) const {
    auto resp = this->db->get(this->tableName, cond);
    if(!resp.has_value()){
        return std::nullopt;
    }
    auto firstMap = resp.value().front();
    return Enrollee{std::stoi(firstMap["id"]), firstMap["name_enrollee"], (u_int16_t)std::stoi(firstMap["user_id"])};    
}


bool EnrolleeService::updateEnrollee(const Enrollee& obj) const {
    return this->db->update(this->tableName, {{"name_enrollee" , obj.name_enrollee}, {"user_id" , std::to_string(obj.user_id)}}, {{"id", std::to_string(obj.id)}});
}


bool EnrolleeService::deleteEnrollee(const std::string& name) const {
    return this->db->remove(this->tableName, {{"name_enrollee", name}});
}


std::optional<std::vector<Enrollee>> EnrolleeService::getAll() {
    auto resp = this->db->get(this->tableName, {});
    if(!resp.has_value()){
        return std::nullopt;
    }
    auto firstSubMap = resp.value();
    std::vector<Enrollee> subs;
    for(auto m : firstSubMap) {
        subs.push_back(Enrollee{std::stoi(m["id"]), m["name_enrollee"], (u_int16_t)std::stoi(m["user_id"])});
    }
    return subs;    
}