#include "UserService.h"


void UserService::addUser(const User& user) {
    this->db->insert(this->tableName, {{"username" , user.username}, {"email", user.email}, {"password_hash", user.password_hash}});
}
