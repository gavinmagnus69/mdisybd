#include "AuthController.h"
#include "spdlog/spdlog.h"

Response AuthController::Register(const User& user) {
    bool flag = this->userService.addUser(user);
    if(!flag) {
        spdlog::error("Cannot add user");
        return Response{"Error registering user", 228};
    }
    spdlog::info("user added");
    return Response{"User registered", 0};
}


Response Login(const std::string& username, const std::string& password) {

}