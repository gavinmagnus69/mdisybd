#include "AchievementService.h"


AchievementService::AchievementService() 
: Service()
{}


AchievementService::AchievementService(std::shared_ptr<IDatabase> db)
: Service(db)
{
}


bool AchievementService::addAchievement(const Achievement& obj) const {
    return this->db->insert(this->tableName, {{"name_achievement" , obj.name_achievement}, {"bonus", std::to_string(obj.bonus)}});
}


std::optional<Achievement> AchievementService::getAchievement(const std::map<std::string, std::string>& cond)  const {
    auto resp = this->db->get(this->tableName, cond);
    if(!resp.has_value()){
        return std::nullopt;
    }
    auto firstMap = resp.value().front();
    return Achievement{std::stoi(firstMap["id"]), firstMap["name_achievement"], (u_int16_t)std::stoi(firstMap["bonus"])};      
}


bool AchievementService::updateAchievement(const Achievement& obj) const {
    return this->db->update(this->tableName, {{"name_achievement" , obj.name_achievement}, {"bonus", std::to_string(obj.bonus)}}, {{"id", std::to_string(obj.id)}});
}


bool AchievementService::deleteAchievement(const std::map<std::string, std::string>& cond) const {
    return this->db->remove(this->tableName, cond);
}


std::optional<std::vector<Achievement>> AchievementService::getAll() {
    auto resp = this->db->get(this->tableName, {});
    if(!resp.has_value()){
        return std::nullopt;
    }
    auto firstSubMap = resp.value();
    std::vector<Achievement> subs;
    for(auto m : firstSubMap) {
        subs.push_back(Achievement{std::stoi(m["id"]), m["name_achievement"], (u_int16_t)std::stoi(m["bonus"])});
    }
    return subs;    
}