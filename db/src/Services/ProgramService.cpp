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
std::optional<Program> ProgramService::getProgram(const std::string& name_pr) const {
    auto resp = this->db->get(this->tableName, {{"name_program", name_pr}});
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
bool ProgramService::deleteProgram(const std::string& name) const {
    return this->db->remove(this->tableName, {{"name_program", name}});
}