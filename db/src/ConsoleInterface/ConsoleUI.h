#ifndef CONSOLEUI_H
#define CONSOLEUI_H


#include "Entities/User.h"
#include "Router/Router.h"

class ConsoleUI {
private:
    User currentUser;
    Enrollee currentEnrollee;
    Router router;
    std::shared_ptr<IDatabase> db;
public:
    ConsoleUI(std::shared_ptr<IDatabase>);
private:
    void HelloMsg();
    void AuthPage();
    void RegisterPage();
    void LoginPage();
    void StudentPage();
    void AdminPage();
public:
    void Run();
};

#endif