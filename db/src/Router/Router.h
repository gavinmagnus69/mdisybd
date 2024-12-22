#ifndef ROUTER_H
#define ROUTER_H


#include <string>
#include "Controllers/AuthController.h"
#include "Database/IDatabase.h"


class Router {
private:
    AuthController auth;

public:
    Router(std::shared_ptr<IDatabase>);
public:
    std::string ParseRequest(const std::string& req);
};
#endif