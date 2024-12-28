#ifndef PROGRAM_SUBJECT_SERVICE_H
#define PROGRAM_SUBJECT_SERVICE_H


#include "Service.h"
#include "Entities/ProgramSubject.h"


class ProgramSubjectService : public Service {
    std::string tableName = "program_subject";
public:
    ProgramSubjectService();
    ProgramSubjectService(std::shared_ptr<IDatabase>);
public:
    bool addProgramSubject(const ProgramSubject&) const;
    std::optional<ProgramSubject> getProgramSubject(const std::map<std::string, std::string>&) const;
    bool updateProgramSubject(const ProgramSubject&) const;
    bool deleteProgramSubject(const std::map<std::string, std::string>&) const;
    std::optional<std::vector<ProgramSubject>> getAll();
};



#endif