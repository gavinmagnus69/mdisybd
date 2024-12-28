#include "EnrolleePenaltyService.h"


EnrolleePenaltyService::EnrolleePenaltyService()
: Service()
{}


EnrolleePenaltyService::EnrolleePenaltyService(std::shared_ptr<IDatabase> db)
: Service(db)
{
}


bool EnrolleePenaltyService::addEnrolleePenalty(const EnrolleePenalty& obj) const {
    return this->db->insert(this->tableName, {{"enrollee_id" , std::to_string(obj.enrollee_id)}, {"penalty_id", std::to_string(obj.penalty_id)}});   
}


std::optional<EnrolleePenalty> EnrolleePenaltyService::getEnrolleePenalty(const std::map<std::string, std::string>& cond) const {
    auto resp = this->db->get(this->tableName, cond);
    if(!resp.has_value()){
        return std::nullopt;
    }
    auto firstMap = resp.value().front();
    return EnrolleePenalty{std::stoi(firstMap["id"]), (u_int16_t)std::stoi(firstMap["enrollee_id"]), (u_int16_t)std::stoi(firstMap["penalty_id"])};
}


bool EnrolleePenaltyService::updateEnrolleePenalty(const EnrolleePenalty& obj) const {
    return this->db->update(this->tableName, {{"enrollee_id" , std::to_string(obj.enrollee_id)}, {"penalty_id", std::to_string(obj.penalty_id)}}, {{"id", std::to_string(obj.id)}});
}


bool EnrolleePenaltyService::deleteEnrolleePenalty(const std::map<std::string, std::string>& cond) const {
    return this->db->remove(this->tableName, cond); 
}


std::optional<std::vector<EnrolleePenalty>> EnrolleePenaltyService::getAll() {
    auto resp = this->db->get(this->tableName, {});
    if(!resp.has_value()){
        return std::nullopt;
    }
    auto firstSubMap = resp.value();
    std::vector<EnrolleePenalty> subs;
    for(auto m : firstSubMap) {
        subs.push_back(EnrolleePenalty{std::stoi(m["id"]), (u_int16_t)std::stoi(m["enrollee_id"]), (u_int16_t)std::stoi(m["penalty_id"])});
    }
    return subs;    
}