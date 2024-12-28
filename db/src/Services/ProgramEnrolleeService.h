#ifndef PROGRAM_ENROLLEE_SERVICE_H
#define PROGRAM_ENROLLEE_SERVICE_H


#include "Service.h"
#include "Entities/ProgramEnrollee.h"

class ProgramEnrolleeService : public Service {
    std::string tableName = "program_enrollee";
public:
    ProgramEnrolleeService();
    ProgramEnrolleeService(std::shared_ptr<IDatabase>);
public:
    bool addProgramEnrollee(const ProgramEnrollee&) const;
    std::optional<ProgramEnrollee> getProgramEnrollee(const std::map<std::string, std::string>&) const;
    bool updateProgramEnrollee(const ProgramEnrollee&) const;
    bool deleteProgramEnrollee(const std::map<std::string, std::string>&) const;
    std::optional<std::vector<ProgramEnrollee>> getAll();
};



#endif