#ifndef DPS_H
#define DPS_H


#include "Service.h"
#include "Entities/Department.h"


class DepartmentService : public Service {
    std::string tableName = "department";
public:
    DepartmentService();
    DepartmentService(std::shared_ptr<IDatabase>);
public:
    bool addDepartment(const Department&) const;
    std::optional<Department> getDepartment(const std::map<std::string, std::string>&) const;
    bool updateDepartment(const Department&) const;
    bool deleteDepartment(const std::map<std::string, std::string>&) const;
    std::optional<std::vector<Department>> getAll();
};


//CRUD <T>
#endif