#include "AuthController.h"
#include "spdlog/spdlog.h"
#include <iostream>

std::ostream& operator << (std::ostream& os, const User& user) {
    os << "User:" << user.username << ' ' << user.email << ' ' << user.password_hash << ' ' << user.role << '\n';
    return os;
}

//INITIALIZE ALL SERVICES WITH CONSTRUCTOR
AuthController::AuthController(std::shared_ptr<IDatabase> db)
 : Controller(db)
 , userService(std::make_shared<UserService>(db))
    {
        // this->userService.setDatabase(db);
    }


Response AuthController::Register(const std::optional<std::map<std::string, std::string>>& request) {
    try{
        spdlog::info("register contr");
        if(!request.has_value()){
            return Response{"No data for Registration", 100};
        }
        auto req = request.value();
        auto username = req["username"];
        auto email = req["email"];
        auto password = req["password"];
        auto role = std::stoi(req["role"]);
        spdlog::info("{} {} {} {}", username, email, password, role);
        //TODO hashing
        User user{username, email, password, role};
        std::cout << user;
        bool flag = this->userService->addUser(user);
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

//TODO
Response AuthController::Login(const std::optional<std::map<std::string, std::string>>& request) {
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
        bool flag = this->userService->addUser(user);
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
    return Response{"Test", 0, 0};
}