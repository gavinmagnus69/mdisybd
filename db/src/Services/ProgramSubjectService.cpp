#include "ProgramSubjectService.h"


ProgramSubjectService::ProgramSubjectService()
: Service()
{}


ProgramSubjectService::ProgramSubjectService(std::shared_ptr<IDatabase> db)
: Service(db)
{
}


bool ProgramSubjectService::addProgramSubject(const ProgramSubject& obj) const {
    return this->db->insert(this->tableName, {{"program_id" , std::to_string(obj.program_id)}, {"subject_id", std::to_string(obj.subject_id)}, {"min_result", std::to_string(obj.min_result)}});   
}


std::optional<ProgramSubject> ProgramSubjectService::getProgramSubject(const std::map<std::string, std::string>& cond) const {
    auto resp = this->db->get(this->tableName, cond);
    if(!resp.has_value()){
        return std::nullopt;
    }
    auto firstMap = resp.value().front();
    return ProgramSubject{std::stoi(firstMap["id"]), (u_int16_t)std::stoi(firstMap["program_id"]), (u_int16_t)std::stoi(firstMap["subject_id"]), (u_int16_t)std::stoi(firstMap["min_result"])};
}


bool ProgramSubjectService::updateProgramSubject(const ProgramSubject& obj) const {
    return this->db->update(this->tableName, {{"program_id" , std::to_string(obj.program_id)}, {"subject_id", std::to_string(obj.subject_id)}, {"min_result", std::to_string(obj.min_result)}}, {{"id", std::to_string(obj.id)}});
}


bool ProgramSubjectService::deleteProgramSubject(const std::map<std::string, std::string>& cond) const {
    return this->db->remove(this->tableName, cond);
}


std::optional<std::vector<ProgramSubject>> ProgramSubjectService::getAll() {
    auto resp = this->db->get(this->tableName, {});
    if(!resp.has_value()){
        return std::nullopt;
    }
    auto firstSubMap = resp.value();
    std::vector<ProgramSubject> subs;
    for(auto m : firstSubMap) {
        subs.push_back(ProgramSubject{std::stoi(m["id"]), (u_int16_t)std::stoi(m["program_id"]), (u_int16_t)std::stoi(m["subject_id"]), (u_int16_t)std::stoi(m["min_result"])});
    }
    return subs;      
}