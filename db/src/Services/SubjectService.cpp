#include "SubjectService.h"


SubjectService::SubjectService()
: Service()
{}

//SHOOO?????
SubjectService::SubjectService(std::shared_ptr<IDatabase> db)
: Service(db)
{
}


bool SubjectService::addSubject(const Subject& sub) const {
    return this->db->insert(this->tableName, {{"name_subject" , sub.name_subject}});
}


std::optional<Subject> SubjectService::getSubject(const std::map<std::string, std::string>& cond) const {
    auto resp = this->db->get(this->tableName, cond);
    if(!resp.has_value()){
        return std::nullopt;
    }
    auto firstSubMap = resp.value().front();
    return Subject{std::stoi(firstSubMap["id"]), firstSubMap["name_subject"]};
}


bool SubjectService::updateSubject(const Subject& sub) const {
    return this->db->update(this->tableName, {{"name_subject" , sub.name_subject}}, {{"id", std::to_string(sub.id)}});
}


bool SubjectService::deleteSubject(const std::map<std::string, std::string>& cond) const {
    return this->db->remove(this->tableName, cond);

}


std::optional<std::vector<Subject>> SubjectService::getAll() {
    auto resp = this->db->get(this->tableName, {});
    if(!resp.has_value()){
        return std::nullopt;
    }
    auto firstSubMap = resp.value();
    std::vector<Subject> subs;
    for(auto m : firstSubMap) {
        subs.push_back(Subject{std::stoi(m["id"]), m["name_subject"]});
    }
    return subs;    
}
