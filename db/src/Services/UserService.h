#ifndef USER_SERVICE_H
#define USER_SERVICE_H


#include "Database/IDatabase.h"
#include <memory>
#include "Service.h"
#include "Entities/User.h"


class UserService : public Service {
private:
    std::string tableName = "User";
public:
    void addUser(const User&);
};

#endif