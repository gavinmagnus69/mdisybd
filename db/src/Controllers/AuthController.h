#ifndef AUTH_CONTROLLER_H
#define AUTH_CONTROLLER_H

#include "Services/UserService.h"
#include "Controller.h"
#include "Entities/Response.h"


class AuthController : public Controller {
private:
    UserService userService;
public:
    AuthController(std::shared_ptr<IDatabase>);
public:
    Response Register(const User&);
    Response Login(const std::string& username, const std::string& password);
};

#endif