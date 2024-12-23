#include "Application.h"
#include <iostream>


Application::Application(std::shared_ptr<IDatabase> db) 
: db(db)
, ui(ConsoleUI(db))
{}

void Application::Run() {
    std::cout << "Application running\n";
    this->ui.Run();
}