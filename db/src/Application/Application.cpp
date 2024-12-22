#include "Application.h"
#include <iostream>


Application::Application(std::shared_ptr<IDatabase> db)
: db(db)
{}

void Application::Run() {
    std::cout << "Application running\n";
}