#include "AuthController.h"
#include "spdlog/spdlog.h"


Response AuthController::Register(const std::optional<std::map<std::string, std::string>>& request) {
    if(!request.has_value()){
        return Response{"No data for Registration", 100};
    }
    
    // bool flag = this->userService.addUser(user);
    if(!flag) {
        spdlog::error("Cannot add user");
        return Response{"Error registering user", 228};
    }
    spdlog::info("user added");
    return Response{"User registered", 0};
}


Response Login(const std::optional<std::map<std::string, std::string>>& request) {
    return Response{"Test", 0};
}