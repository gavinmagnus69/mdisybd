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


std::optional<Subject> SubjectService::getSubject(const std::string& name_sub) const {
    auto resp = this->db->get(this->tableName, {{"name_subject", name_sub}});
    if(!resp.has_value()){
        return std::nullopt;
    }
    auto firstSubMap = resp.value().front();
    return Subject{std::stoi(firstSubMap["id"]), firstSubMap["name_subject"]};
}


bool SubjectService::updateSubject(const Subject& sub) const {
    return this->db->update(this->tableName, {{"name_subject" , sub.name_subject}}, {{"id", std::to_string(sub.id)}});
}


bool SubjectService::deleteSubject(const std::string& name_sub) const {
    return this->db->remove(this->tableName, {{"name_subject", name_sub}});

}