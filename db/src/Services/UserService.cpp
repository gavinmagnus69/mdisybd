#include "UserService.h"
#include "spdlog/spdlog.h"
#include <iostream>
    
    
UserService::UserService() 
: Service()
{}


UserService::UserService(std::shared_ptr<IDatabase> db) 
: Service(db)
{
    std::cout << "Derived";
}


std::optional<User>  UserService::getUser(const std::string& username, const std::string& password) const {
    spdlog::info("getUser");
    auto resp = this->db->get(this->tableName, {{"username", username}, {"password_hash", password}});
    if(!resp.has_value()){
        return std::nullopt;
    }
    auto firstUserMap = resp.value().front();
    return User{firstUserMap["username"], firstUserMap["email"], firstUserMap["password_hash"], (uint16_t)(std::stoi(firstUserMap["role"])), std::stoi(firstUserMap["id"])};
}


bool UserService::addUser(const User& user) const {
    spdlog::info("addUser service {} {} {} {}", user.username, user.email, user.password_hash, user.role);
    return this->db->insert(this->tableName, {{"username" , user.username}, {"email", user.email}, {"password_hash", user.password_hash}, {"role", std::to_string(user.role)}});
}


bool UserService::updateUser(const User& user) const {
    return this->db->update(this->tableName, {{"username" , user.username}, {"email", user.email}, {"password_hash", user.password_hash}, {"role", std::to_string(user.role)}}, {{"username", user.username}});
}


bool UserService::deleteUser(const std::string& name) const {
    return this->db->remove(this->tableName, {{"username", name}});
}







