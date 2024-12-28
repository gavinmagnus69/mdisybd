#ifndef ESS_H
#define ESS_H


#include "Service.h"
#include "Entities/EnrolleeSubject.h"


class EnrolleeSubjectService : public Service {
    std::string tableName = "enrollee_subject";
public:
    EnrolleeSubjectService();
    EnrolleeSubjectService(std::shared_ptr<IDatabase>);
public:
    bool addEnrolleeSubject(const EnrolleeSubject&) const;
    std::optional<EnrolleeSubject> getEnrolleeSubject(const std::map<std::string, std::string>&) const;
    bool updateEnrolleeSubject(const EnrolleeSubject&) const;
    bool deleteEnrolleeSubject(const std::map<std::string, std::string>&) const;
    std::optional<std::vector<EnrolleeSubject>> getAll();
};



#endif