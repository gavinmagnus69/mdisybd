#ifndef AUTH_CONTROLLER_H
#define AUTH_CONTROLLER_H

#include "Services/UserService.h"
#include "Controller.h"
#include "Entities/Response.h"
#include "Services/EnrolleeService.h"

class AuthController : public Controller {
private:
    std::shared_ptr<UserService> userService;
    std::shared_ptr<EnrolleeService> enrolleeService;
public:
    AuthController() = default;
    AuthController(std::shared_ptr<IDatabase>);
public:
    Response Register(const std::optional<std::map<std::string, std::string>>&);
    std::tuple<Response, User> Login(const std::optional<std::map<std::string, std::string>>&);
};

#endif