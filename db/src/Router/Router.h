#ifndef ROUTER_H
#define ROUTER_H


#include <string>
#include "Controllers/AuthController.h"
#include "Database/IDatabase.h"
#include "Middleware/Middleware.h"


class Router {
private:
    Middleware middleware;
    AuthController auth;
public:
    Router(std::shared_ptr<IDatabase>);
public:
    Response Login(const User& user, const std::map<std::string, std::string>&);
    Response Register(const User& user, const std::map<std::string, std::string>&);
    // std::string ParseRequest(const std::string& req);
};
#endif