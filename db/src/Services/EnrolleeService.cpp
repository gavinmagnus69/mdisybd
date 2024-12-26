#include "EnrolleeService.h"


EnrolleeService::EnrolleeService()
: Service()
{}


EnrolleeService::EnrolleeService(std::shared_ptr<IDatabase>)
: Service(db)
{
}


bool EnrolleeService::addEnrollee(const Enrollee& obj) const {
    return this->db->insert(this->tableName, {{"name_enrollee" , obj.name_enrollee}, {"user_id" , std::to_string(obj.user_id)}});
}


std::optional<Enrollee> EnrolleeService::getEnrollee(const std::string&) const {
    
}
bool EnrolleeService::updateEnrollee(const Enrollee&) const;
bool EnrolleeService::deleteEnrollee(const std::string&) const;