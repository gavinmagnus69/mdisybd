#ifndef CONSOLEUI_H
#define CONSOLEUI_H


#include "Entities/User.h"
#include "Router/Router.h"

class ConsoleUI {
private:
    User currentUser;
    Router router;
public:
    ConsoleUI(std::shared_ptr<IDatabase>);
private:
    void HelloMsg();
    void AuthPage();
    void RegisterPage();
    void LoginPage();
public:
    void Run();
};

#endif