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
    UserService();
    UserService(std::shared_ptr<IDatabase>);
public:
    bool addUser(const User&) const;
    std::optional<User> getUser(const std::string&, const std::string&) const;
    bool updateUser(const User&) const;
    bool deleteUser(const std::string&) const;
};

#endif