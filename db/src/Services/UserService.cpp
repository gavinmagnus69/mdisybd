#include "UserService.h"
#include "spdlog/spdlog.h"

bool UserService::addUser(const User& user) {
    spdlog::info("addUser service {} {} {} {}", user.username, user.email, user.password_hash, user.role);
    return this->db->insert(this->tableName, {{"username" , user.username}, {"email", user.email}, {"password_hash", user.password_hash}, {"role", std::to_string(user.role)}});
}
