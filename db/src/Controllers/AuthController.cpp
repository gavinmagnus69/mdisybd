#include "AuthController.h"
#include "spdlog/spdlog.h"

AuthController::AuthController(std::shared_ptr<IDatabase> db)
 : Controller(db)
    {
        this->userService.setDatabase(db);
    }


Response AuthController::Register(const std::optional<std::map<std::string, std::string>>& request) {
    try{
        if(!request.has_value()){
            return Response{"No data for Registration", 100};
        }
        auto req = request.value();
        auto username = req["username"];
        auto email = req["email"];
        auto password = req["password"];
        auto role = std::stoi(req["role"]);
        //TODO hashing
        User user{username, email, password, role};
        bool flag = this->userService.addUser(user);
        if(!flag) {
            spdlog::error("Cannot add user");
            return Response{"Error registering user", 228, 0};
        }
        spdlog::info("user added");
        return Response{"User registered", 0, 0};
    }
    catch(const std::exception& exp) {
        spdlog::error("Unknown error");
        return Response{"Register uknown error", 1337, 0};
    }
}


Response Login(const std::optional<std::map<std::string, std::string>>& request) {
    return Response{"Test", 0, 0};
}