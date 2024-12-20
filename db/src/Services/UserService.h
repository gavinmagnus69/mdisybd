#ifndef USER_SERVICE_H
#define USER_SERVICE_H


#include "Database/IDatabase.h"
#include <memory>
#include "Service.h"

class UserService : public Service {
private:
    std::string tableName = "User";
public:
    void addUser(const std::string& username, const std::string& email, const std::string& hash, uint16_t role);
    
};

#endif