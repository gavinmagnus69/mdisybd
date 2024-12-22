#include "UserService.h"


bool UserService::addUser(const User& user) {
    return this->db->insert(this->tableName, {{"username" , user.username}, {"email", user.email}, {"password_hash", user.password_hash}});
}
