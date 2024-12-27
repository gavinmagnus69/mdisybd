#include "ConsoleUI.h"
#include <iostream>
#include <format>

ConsoleUI::ConsoleUI(std::shared_ptr<IDatabase> db)
 : router(Router(db))
  {
  }

void ConsoleUI::HelloMsg() {
    std::cout << "\nHello, welcome to the UNI service\n";
}


void ConsoleUI::Run() {
    while (true)
    {
        HelloMsg();
        AuthPage();
    }
}

int inputCode() {
    std::cout << "Input number:\n";
    int code = 0;
    std::string input{""};
    std::cin >> input;
    try{
        code = std::stoi(input);
        if(code < 0 ) {
            throw std::exception();
        }
        return code;
    }
    catch(const std::exception& exp){
        std::cout << "Incorrect input\n";
        code = inputCode();
        return code;
    }   
}


void ConsoleUI::AdminPage() {
    std::cout << std::format("Welcome to the admin system, {}", this->currentUser.username);
    
}


void ConsoleUI::StudentPage() {
    std::cout << std::format("Welcome to the system, {}", this->currentUser.username);
}


void ConsoleUI::LoginPage() {
    std::cout << "Login page\n";
    std::cout << "Enter username\n";
    std::string username{""};
    std::cin >> username;
    std::string password{""};
    std::cout << "Enter password\n";
    std::cin >> password;
    auto [resp, user] = this->router.Login(User{}, {{"username", username}, {"password", password}});
    if(resp.status) {
        std::cout << resp.msg << '\n';
        return;
    }
    this->currentUser = user;
    if(user.role == 0){
        StudentPage();
    }
    if(user.role == 1){}
    if(user.role == 2){
        AdminPage();
    }
}


void ConsoleUI::RegisterPage() {
    std::cout << "Register page\n";
    std::cout << "Enter username\n";
    std::string username{""};
    std::cin >> username;
    std::cout << "Enter your name\n";
    std::string name{""};
    std::cin >> name;
    std::cout << "Enter email\n";
    std::string email{""};
    std::cin >> email;
    std::string password{""};
    std::cout << "Enter password\n";
    std::cin >> password;
    auto resp = this->router.Register(User{}, {{"username", username},{"name_enrollee", name}, {"email", email}, {"password", password}, {"role", "0"}});
    std::cout << resp.msg << '\n';
    if(resp.status){
        return;
    }
    return;
    
}


void ConsoleUI::AuthPage() {
    std::cout << "Choose operation:\n";
    std::cout << "1 - Registration\n";
    std::cout << "2 - Login\n";
    auto code = inputCode();
    switch (code)
    {
    case 1:
        RegisterPage();
        break;
    case 2:
        LoginPage();
        break;
    default:
        break;
    }
}

