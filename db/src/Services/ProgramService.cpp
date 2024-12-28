#include "ProgramService.h"

//DO NOT USE, IF NOT AFTER CALL setDatabase()
ProgramService::ProgramService()
: Service()
{}


ProgramService::ProgramService(std::shared_ptr<IDatabase> db)
: Service(db)
{
}


bool ProgramService::addProgram(const Program& pr) const {
    return this->db->insert(this->tableName, {{"name_program" , pr.name_program}, {"department_id" , std::to_string(pr.department_id)}, {"plan" , std::to_string(pr.plan)}});
}

//get by name_program
std::optional<Program> ProgramService::getProgram(const std::map<std::string, std::string>& cond) const {
    auto resp = this->db->get(this->tableName, cond);
    if(!resp.has_value()){
        return std::nullopt;
    }
    auto firstMap = resp.value().front();
    return Program{std::stoi(firstMap["id"]), firstMap["name_program"], (u_int16_t)std::stoi(firstMap["department_id"]), (u_int16_t)std::stoi(firstMap["plan"])};
}

//update by id
bool ProgramService::updateProgram(const Program& pr) const {
    return this->db->update(this->tableName, {{"name_program" , pr.name_program}, {"department_id" , std::to_string(pr.department_id)}, {"plan" , std::to_string(pr.plan)}}, {{"id", std::to_string(pr.id)}});

}

//delete by name_program
bool ProgramService::deleteProgram(const std::map<std::string, std::string>& cond) const {
    return this->db->remove(this->tableName, cond);
}


std::optional<std::vector<Program>> ProgramService::getAll() {
    auto resp = this->db->get(this->tableName, {});
    if(!resp.has_value()){
        return std::nullopt;
    }
    auto firstSubMap = resp.value();
    std::vector<Program> subs;
    for(auto m : firstSubMap) {
        subs.push_back(Program{std::stoi(m["id"]), m["name_program"], (u_int16_t)std::stoi(m["department_id"]), (u_int16_t)std::stoi(m["plan"])});
    }
    return subs;    
}
