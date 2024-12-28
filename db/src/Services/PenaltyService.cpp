#include "PenaltyService.h"


PenaltyService::PenaltyService() 
: Service()
{}


PenaltyService::PenaltyService(std::shared_ptr<IDatabase> db)
: Service(db)
{
}


bool PenaltyService::addPenalty(const Penalty& obj) const {
    return this->db->insert(this->tableName, {{"name_penalty" , obj.name_penalty}, {"penalty_value", std::to_string(obj.penalty_value)}, {"result", std::to_string(obj.result)}});   
}


std::optional<Penalty> PenaltyService::getPenalty(const std::map<std::string, std::string>& cond) const {
    auto resp = this->db->get(this->tableName, cond);
    if(!resp.has_value()){
        return std::nullopt;
    }
    auto firstMap = resp.value().front();
    return Penalty{std::stoi(firstMap["id"]), firstMap["name_penalty"], (u_int16_t)std::stoi(firstMap["penalty_value"]), (u_int16_t)std::stoi(firstMap["result"])};     
}


bool PenaltyService::updatePenalty(const Penalty& obj) const {
    return this->db->update(this->tableName, {{"name_penalty" , obj.name_penalty}, {"penalty_value", std::to_string(obj.penalty_value)}, {"result", std::to_string(obj.result)}}, {{"id", std::to_string(obj.id)}});
}


bool PenaltyService::deletePenalty(const std::map<std::string, std::string>& cond) const {
    return this->db->remove(this->tableName, cond); 
}


std::optional<std::vector<Penalty>> PenaltyService::getAll() {
    auto resp = this->db->get(this->tableName, {});
    if(!resp.has_value()){
        return std::nullopt;
    }
    auto firstSubMap = resp.value();
    std::vector<Penalty> subs;
    for(auto m : firstSubMap) {
        subs.push_back(Penalty{std::stoi(m["id"]), m["name_penalty"], (u_int16_t)std::stoi(m["penalty_value"]), (u_int16_t)std::stoi(m["result"])});
    }
    return subs;  
}