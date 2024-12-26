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
    std::optional<Department> getDepartment(const std::string&) const;
    bool updateDepartment(const Department&) const;
    bool deleteDepartment(const std::string&) const;    
};


//CRUD <T>
#endif