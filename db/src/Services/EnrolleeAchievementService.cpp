#include "EnrolleeAchievementService.h"


EnrolleeAchievementService::EnrolleeAchievementService()
: Service()
{}


EnrolleeAchievementService::EnrolleeAchievementService(std::shared_ptr<IDatabase> db)
: Service(db)
{
}


bool EnrolleeAchievementService::addEnrolleeAchievement(const EnrolleeAchievement& obj) const {
    return this->db->insert(this->tableName, {{"enrollee_id" , std::to_string(obj.enrollee_id)}, {"achievement_id", std::to_string(obj.enrollee_id)}});   
}


std::optional<EnrolleeAchievement> EnrolleeAchievementService::getEnrolleeAchievement(const std::map<std::string, std::string>& cond) const {
    auto resp = this->db->get(this->tableName, cond);
    if(!resp.has_value()){
        return std::nullopt;
    }
    auto firstMap = resp.value().front();
    return EnrolleeAchievement{std::stoi(firstMap["id"]), (u_int16_t)std::stoi(firstMap["enrollee_id"]), (u_int16_t)std::stoi(firstMap["achievement_id"])};      
}


bool EnrolleeAchievementService::updateEnrolleeAchievement(const EnrolleeAchievement& obj) const {
    return this->db->update(this->tableName, {{"enrollee_id" , std::to_string(obj.enrollee_id)}, {"achievement_id", std::to_string(obj.achievement_id)}}, {{"id", std::to_string(obj.id)}});
}


bool EnrolleeAchievementService::deleteEnrolleeAchievement(const std::map<std::string, std::string>& cond) const {
    return this->db->remove(this->tableName, cond);
}


std::optional<std::vector<EnrolleeAchievement>> EnrolleeAchievementService::getAll() {
    auto resp = this->db->get(this->tableName, {});
    if(!resp.has_value()){
        return std::nullopt;
    }
    auto firstSubMap = resp.value();
    std::vector<EnrolleeAchievement> subs;
    for(auto m : firstSubMap) {
        subs.push_back(EnrolleeAchievement{std::stoi(m["id"]), (u_int16_t)std::stoi(m["enrollee_id"]), (u_int16_t)std::stoi(m["achievement_id"])});
    }
    return subs;      
}