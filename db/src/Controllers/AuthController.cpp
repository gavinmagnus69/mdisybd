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
 , enrolleeService(std::make_shared<EnrolleeService>(db))
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
        auto name_enrollee = req["name_enrollee"];
        auto usr = this->userService->getUser(username, password).value();
        flag = this->enrolleeService->addEnrollee(Enrollee{0, name_enrollee, (u_int16_t)usr.id});
        if(!flag) {
            spdlog::error("Cannot add enrollee");
            return Response{"Error registering enrollee", 228, 0};
        }
        return Response{"User registered", 0, 0};
    }
    catch(const std::exception& exp) {
        spdlog::error("Unknown error");
        return Response{"Register uknown error", 1337, 0};
    }
}

//TODO
std::tuple<Response, User> AuthController::Login(const std::optional<std::map<std::string, std::string>>& request) {
     try{
        if(!request.has_value()){
            return std::make_tuple(Response{"No data for LOGIN", 100}, User());
        }
        auto req = request.value();
        auto username = req["username"];
        auto password = req["password"];
        //TODO hashing
        // User user{username, email, password, role};
        auto user = this->userService->getUser(username, password);
        if(!user.has_value()) {
            spdlog::error("Invalid credentials");
            return std::make_tuple(Response{"Ivalid creds", 1337}, User());
        }
        spdlog::info("user found");
        return {Response{"User registered", 0, 0}, user.value()};
    }
    catch(const std::exception& exp) {
        spdlog::error("Unknown error");
        return {Response{"Register uknown error", 1337, 0}, User()};
    }
}