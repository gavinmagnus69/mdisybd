#ifndef SUBJECT_SERVICE_H
#define SUBJECT_SERVICE_H


#include "Service.h"
#include "Entities/Subject.h"

class SubjectService : public Service {
private:
    std::string tableName = "subject";
public:
    SubjectService();
    SubjectService(std::shared_ptr<IDatabase>);
public:
    bool addSubject(const Subject&) const;
    std::optional<Subject> getSubject(const std::string&) const;
    bool updateSubject(const Subject&) const;
    bool deleteSubject(const std::string&) const;
};



#endif