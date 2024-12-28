#ifndef PROGRAM_SERVICE_H
#define PROGRAM_SERVICE_H


#include "Service.h"
#include "Entities/Program.h"

class ProgramService : public Service {
    std::string tableName = "program";
public:
    ProgramService();
    ProgramService(std::shared_ptr<IDatabase>);
public:
    bool addProgram(const Program&) const;
    std::optional<Program> getProgram(const std::map<std::string, std::string>&) const;
    bool updateProgram(const Program&) const;
    bool deleteProgram(const std::map<std::string, std::string>&) const;
    std::optional<std::vector<Program>> getAll();
};



#endif