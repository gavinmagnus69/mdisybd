#include "ProgramEnrolleeService.h"


ProgramEnrolleeService::ProgramEnrolleeService()
: Service()
{}


ProgramEnrolleeService::ProgramEnrolleeService(std::shared_ptr<IDatabase> db)
: Service(db)
{
}


bool ProgramEnrolleeService::addProgramEnrollee(const ProgramEnrollee& obj) const {
    return this->db->insert(this->tableName, {{"enrollee_id" , std::to_string(obj.enrollee_id)}, {"program_id", std::to_string(obj.program_id)}});   
}


std::optional<ProgramEnrollee> ProgramEnrolleeService::getProgramEnrollee(const std::map<std::string, std::string>& cond) const {
    auto resp = this->db->get(this->tableName, cond);
    if(!resp.has_value()){
        return std::nullopt;
    }
    auto firstMap = resp.value().front();
    return ProgramEnrollee{std::stoi(firstMap["id"]), (u_int16_t)std::stoi(firstMap["program_id"]), (u_int16_t)std::stoi(firstMap["enrollee_id"])};
}


bool ProgramEnrolleeService::updateProgramEnrollee(const ProgramEnrollee& obj) const {
    return this->db->update(this->tableName, {{"program_id" , std::to_string(obj.program_id)}, {"enrollee_id", std::to_string(obj.enrollee_id)}}, {{"id", std::to_string(obj.id)}});
}


bool ProgramEnrolleeService::deleteProgramEnrollee(const std::map<std::string, std::string>& cond)  const {
    return this->db->remove(this->tableName, cond);
}
std::optional<std::vector<ProgramEnrollee>> ProgramEnrolleeService::getAll() {
    auto resp = this->db->get(this->tableName, {});
    if(!resp.has_value()){
        return std::nullopt;
    }
    auto firstSubMap = resp.value();
    std::vector<ProgramEnrollee> subs;
    for(auto m : firstSubMap) {
        subs.push_back(ProgramEnrollee{std::stoi(m["id"]), (u_int16_t)std::stoi(m["program_id"]), (u_int16_t)std::stoi(m["enrollee_id"])});
    }
    return subs;     
}