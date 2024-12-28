#ifndef ENROLLEE_SERVICE_H
#define ENROLLEE_SERVICE_H


#include "Service.h"
#include "Entities/Enrollee.h"


class EnrolleeService : public Service {
    std::string tableName = "enrollee";
public:
    EnrolleeService();
    EnrolleeService(std::shared_ptr<IDatabase>);
public:
    bool addEnrollee(const Enrollee&) const;
    std::optional<Enrollee> getEnrollee(const std::map<std::string, std::string>&) const;
    bool updateEnrollee(const Enrollee&) const;
    bool deleteEnrollee(const std::string&) const;
    std::optional<std::vector<Enrollee>> getAll();

};



#endif