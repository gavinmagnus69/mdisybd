#include "ConsoleUI.h"
#include <iostream>


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


void StudentPage() {
    while(1){
        std::cout << "Student page\n";
    }
}


void ConsoleUI::LoginPage() {
    std::cout << "Login page\n";
    std::cout << "Enter username\n";
    std::string username{""};
    std::cin >> username;
    std::string password{""};
    std::cout << "Enter password\n";
    std::cin >> password;
    auto resp = this->router.Login(User{}, {{"username", username}, {"password", password}});
    if(resp.status) {
        std::cout << resp.msg << '\n';
        return;
    }
    this->currentUser.username = username;
    this->currentUser.role = resp.role;
    StudentPage();

}


void ConsoleUI::RegisterPage() {
    std::cout << "Register page\n";
    std::cout << "Enter username\n";
    std::string username{""};
    std::cin >> username;
    std::cout << "Enter email\n";
    std::string email{""};
    std::cin >> email;
    std::string password{""};
    std::cout << "Enter password\n";
    std::cin >> password;
    auto resp = this->router.Register(User{}, {{"username", username}, {"email", email}, {"password", password}, {"role", "0"}});
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

