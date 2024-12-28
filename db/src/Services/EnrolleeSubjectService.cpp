#include "EnrolleeSubjectService.h"


EnrolleeSubjectService::EnrolleeSubjectService()
: Service()
{}


EnrolleeSubjectService::EnrolleeSubjectService(std::shared_ptr<IDatabase> db)
: Service(db)
{
}


bool EnrolleeSubjectService::addEnrolleeSubject(const EnrolleeSubject& obj) const {
    return this->db->insert(this->tableName, {{"enrollee_id" , std::to_string(obj.enrollee_id)}, {"subject_id", std::to_string(obj.subject_id)}, {"result", std::to_string(obj.result)}});    
}


std::optional<EnrolleeSubject> EnrolleeSubjectService::getEnrolleeSubject(const std::map<std::string, std::string>& cond) const {
    auto resp = this->db->get(this->tableName, cond);
    if(!resp.has_value()){
        return std::nullopt;
    }
    auto firstMap = resp.value().front();
    return EnrolleeSubject{std::stoi(firstMap["id"]), (u_int16_t)std::stoi(firstMap["enrollee_id"]), (u_int16_t)std::stoi(firstMap["subject_id"]), (u_int16_t)std::stoi(firstMap["result"])};
}


bool EnrolleeSubjectService::updateEnrolleeSubject(const EnrolleeSubject& obj) const {
    return this->db->update(this->tableName, {{"enrollee_id" , std::to_string(obj.enrollee_id)}, {"subject_id", std::to_string(obj.subject_id)}, {"result", std::to_string(obj.result)}}, {{"id", std::to_string(obj.id)}});
}


bool EnrolleeSubjectService::deleteEnrolleeSubject(const std::map<std::string, std::string>& cond) const {
    return this->db->remove(this->tableName, cond);
}


std::optional<std::vector<EnrolleeSubject>> EnrolleeSubjectService::getAll() {
    auto resp = this->db->get(this->tableName, {});
    if(!resp.has_value()){
        return std::nullopt;
    }
    auto firstSubMap = resp.value();
    std::vector<EnrolleeSubject> subs;
    for(auto m : firstSubMap) {
        subs.push_back(EnrolleeSubject{std::stoi(m["id"]), (u_int16_t)std::stoi(m["enrollee_id"]), (u_int16_t)std::stoi(m["subject_id"]), (u_int16_t)std::stoi(m["result"])});
    }
    return subs;          
}