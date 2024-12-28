#include "ConsoleUI.h"
#include <iostream>
#include <format>

ConsoleUI::ConsoleUI(std::shared_ptr<IDatabase> db)
 : router(Router(db))
 , db(db)
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
    // std::cout << "1 - Creat \n";
    // std::cout << "2 - Read \n";
    // std::cout << "3 - Update\n";
    // std::cout << "4 - Delete\n";
    // int n = 0;
    // std::cin >> n;
    std::cout << "Select:\n";
    std::cout << "1 - Achievement:\n";
    std::cout << "2 - Department:\n";
    std::cout << "3 - Enrollee:\n";
    std::cout << "4 - EnrolleeAchievement:\n";
    std::cout << "5 - EnrolleePenalty:\n";
    std::cout << "6 - EnrolleeSubject:\n";
    std::cout << "7 - Penalty:\n";
    std::cout << "8 - Program:\n";
    std::cout << "9 - ProgramEnrollee:\n";
    std::cout << "10 - ProgramSubject:\n";
    std::cout << "11 - Subject:\n";
    std::cout << "12 - User:\n";
    int n = 0;
    std::cin >> n;
    if(n == 1){
        auto ents = this->router.achService->getAll();
        if(!ents.has_value()){
            std::cout << "NO ENTS\n";
            return;
        }
        for(const auto& ent : ents.value()){
            std::cout << ent.id << ' ' << ent.name_achievement << ' ' << ent.bonus << '\n';
        }
        std::cout << "1 - Create 2 - Update 3 - Delete\n";
        std::cin >> n;
        if(n == 1){
            std::cout << "Enter data:\n";
            std::cout << "Enter name_ach:\n";
            std::string name_ach;
            std::cin >> name_ach;
            std::cout << "Enter bonus:\n";
            u_int16_t bonus;
            std::cin >> bonus;
            this->router.achService->addAchievement(Achievement{0, name_ach, bonus});
        }
        if(n == 2){
            std::cout << "Enter ach id\n";
            int id = 0;
            std::cin >> id;
            std::cout << "Enter name_ach:\n";
            std::string name_ach;
            std::cin >> name_ach;
            std::cout << "Enter bonus:\n";
            u_int16_t bonus;
            std::cin >> bonus;
            this->router.achService->updateAchievement(Achievement{id, name_ach, bonus});
        }
        if(n == 3){
            std::cout << "Enter id of achievement to delete\n";
            int id = 0;
            std::cin >> id;
            this->router.achService->deleteAchievement({{"id", std::to_string(id)}});
        }
        AdminPage();
    }
    if(n == 2){
        auto ents = this->router.dpService->getAll();
        if(!ents.has_value()){
            std::cout << "NO ENTS\n";
            return;
        }
        for(const auto& ent : ents.value()){
            std::cout << ent.id << ' ' << ent.name_department << '\n';
        }
        std::cout << "1 - Create 2 - Update 3 - Delete\n";
        std::cin >> n;
        if(n == 1){
            std::cout << "Enter data:\n";
            std::cout << "Enter name_dep:\n";
            std::string name_ach;
            std::cin >> name_ach;
            this->router.dpService->addDepartment(Department{0, name_ach});
        }
        if(n == 2){
            std::cout << "Enter dep id\n";
            int id = 0;
            std::cin >> id;
            std::cout << "Enter name_dep:\n";
            std::string name_ach;
            std::cin >> name_ach;
            this->router.dpService->updateDepartment(Department{id, name_ach});
        }
        if(n == 3){
            std::cout << "Enter id to delete\n";
            int id = 0;
            std::cin >> id;
            this->router.dpService->deleteDepartment({{"id", std::to_string(id)}});
        }
            AdminPage();

    }
    if(n == 3){
        auto ents = this->router.enrService->getAll();
        if(!ents.has_value()){
            std::cout << "NO ENTS\n";
            return;
        }
        for(const auto& ent : ents.value()){
            std::cout << ent.id << ' ' << ent.name_enrollee << ' ' << ent.user_id << '\n';
        }
        std::cout << "1 - Create 2 - Update 3 - Delete\n";
        std::cin >> n;
        if(n == 1){
            std::cout << "Enter data:\n";
            std::cout << "Enter name_enro:\n";
            std::string name_ach;
            std::cin >> name_ach;
            std::cout << "Enter user_id:\n";
            u_int16_t user_id;
            std::cin >> user_id;
            this->router.enrService->addEnrollee(Enrollee{0, name_ach, user_id});
        }
        if(n == 2){
            std::cout << "Enter id to upd\n";
            int id = 0;
            std::cin >> id;
            std::cout << "Enter name_enr:\n";
            std::string name_ach;
            std::cin >> name_ach;
            std::cout << "Enter user_id:\n";
            u_int16_t user_id;
            std::cin >> user_id;
            this->router.enrService->updateEnrollee(Enrollee{id, name_ach, user_id});
        }
        if(n == 3){
            std::cout << "Enter id to delete\n";
            int id = 0;
            std::cin >> id;
            auto enr = this->router.enrService->getEnrollee({{"id", std::to_string(id)}});
            this->router.enrService->deleteEnrollee(enr.value().name_enrollee);
        }
                AdminPage();

    }
    if(n == 4){
        auto ents = this->router.eaService->getAll();
        if(!ents.has_value()){
            std::cout << "NO ENTS\n";
            return;
        }
        for(const auto& ent : ents.value()){
            std::cout << ent.id << ' ' << ent.achievement_id << ' ' << ent.enrollee_id << '\n';
        }
        std::cout << "1 - Create 2 - Update 3 - Delete\n";
        std::cin >> n;
        if(n == 1){
            std::cout << "Enter data:\n";
            std::cout << "Enter acv_id:\n";
           u_int16_t ach;
            std::cin >> ach;
            std::cout << "Enter enr_id:\n";
            u_int16_t enr;
            std::cin >> enr;
            this->router.eaService->addEnrolleeAchievement(EnrolleeAchievement{0, enr, ach});
        }
        if(n == 2){
            std::cout << "Enter id to upd\n";
            int id = 0;
            std::cin >> id;
            std::cout << "Enter acv_id:\n";
           u_int16_t ach;
            std::cin >> ach;
            std::cout << "Enter enr_id:\n";
            u_int16_t enr;
            std::cin >> enr;
            this->router.eaService->updateEnrolleeAchievement(EnrolleeAchievement{id, enr, ach});
        }
        if(n == 3){
            std::cout << "Enter id to delete\n";
            int id = 0;
            std::cin >> id;
            this->router.eaService->deleteEnrolleeAchievement({{"id", std::to_string(id)}});
        }
                AdminPage();

    }
    if(n == 5){
        auto ents = this->router.epService->getAll();
        if(!ents.has_value()){
            std::cout << "NO ENTS\n";
            return;
        }
        for(const auto& ent : ents.value()){
            std::cout << ent.id << ' ' << ent.enrollee_id << ' ' << ent.penalty_id << '\n';
        }
        std::cout << "1 - Create 2 - Update 3 - Delete\n";
        std::cin >> n;
        if(n == 1){
            std::cout << "Enter data:\n";
            std::cout << "Enter enr_id:\n";
           u_int16_t enid;
            std::cin >> enid;
            std::cout << "Enter pen_id:\n";
            u_int16_t achid;
            std::cin >> achid;
            this->router.epService->addEnrolleePenalty(EnrolleePenalty{0, enid, achid});
        }
        if(n == 2){
            std::cout << "Enter id to upd\n";
            int id = 0;
            std::cin >> id;
            std::cout << "Enter pen_id:\n";
           u_int16_t ach;
            std::cin >> ach;
            std::cout << "Enter enr_id:\n";
            u_int16_t enr;
            std::cin >> enr;
            this->router.epService->updateEnrolleePenalty(EnrolleePenalty{id, enr, ach});
        }
        if(n == 3){
            std::cout << "Enter id to delete\n";
            int id = 0;
            std::cin >> id;
            this->router.epService->deleteEnrolleePenalty({{"id", std::to_string(id)}});
        }
                AdminPage();

    }
    if(n == 6){
        auto ents = this->router.esService->getAll();
        if(!ents.has_value()){
            std::cout << "NO ENTS\n";
            return;
        }
        for(const auto& ent : ents.value()){
            std::cout << ent.id << ' ' << ent.enrollee_id << ' ' << ent.subject_id << ' ' << ent.result << '\n';
        }
        std::cout << "1 - Create 2 - Update 3 - Delete\n";
        std::cin >> n;
        if(n == 1){
            std::cout << "Enter data:\n";
            std::cout << "Enter enr_id:\n";
           u_int16_t enid;
            std::cin >> enid;
            std::cout << "Enter sub_id:\n";
            u_int16_t achid;
            std::cin >> achid;
                std::cout << "Enter result:\n";
            u_int16_t res;
            std::cin >> res;
            this->router.esService->addEnrolleeSubject(EnrolleeSubject{0, enid, achid, res});
        }
        if(n == 2){
            std::cout << "Enter id to upd\n";
            int id = 0;
            std::cin >> id;
            std::cout << "Enter sub_id:\n";
           u_int16_t ach;
            std::cin >> ach;
            std::cout << "Enter enr_id:\n";
            u_int16_t enr;
            std::cin >> enr;
             std::cout << "Enter result:\n";
            u_int16_t res;
            std::cin >> res;
            this->router.esService->updateEnrolleeSubject(EnrolleeSubject{id, enr, ach, res});
        }
        if(n == 3){
            std::cout << "Enter id to delete\n";
            int id = 0;
            std::cin >> id;
            this->router.esService->deleteEnrolleeSubject({{"id", std::to_string(id)}});
        }
                AdminPage();

    }
    if(n == 7){
        auto ents = this->router.penService->getAll();
        if(!ents.has_value()){
            std::cout << "NO ENTS\n";
            return;
        }
        for(const auto& ent : ents.value()){
            std::cout << ent.id << ' ' << ent.name_penalty << ' ' << ent.penalty_value << ' ' << ent.result << '\n';
        }
        std::cout << "1 - Create 2 - Update 3 - Delete\n";
        std::cin >> n;
        if(n == 1){
            std::cout << "Enter data:\n";
            std::cout << "Enter name_penalty:\n";
           std::string enid;
            std::cin >> enid;
            std::cout << "Enter penalty_value:\n";
            u_int16_t achid;
            std::cin >> achid;
                std::cout << "Enter result:\n";
            u_int16_t res;
            std::cin >> res;
            this->router.penService->addPenalty(Penalty{0, enid, achid, res});
        }
        if(n == 2){
            std::cout << "Enter id to upd\n";
            int id = 0;
            std::cin >> id;
            std::cout << "Enter name_penalty:\n";
           std::string ach;
            std::cin >> ach;
            std::cout << "Enter penalty_value:\n";
            u_int16_t enr;
            std::cin >> enr;
             std::cout << "Enter result:\n";
            u_int16_t res;
            std::cin >> res;
            this->router.penService->updatePenalty(Penalty{id, ach, enr, res});
        }
        if(n == 3){
            std::cout << "Enter id to delete\n";
            int id = 0;
            std::cin >> id;
            this->router.penService->deletePenalty({{"id", std::to_string(id)}});
        }
                AdminPage();

    }
    if(n == 9){
        auto ents = this->router.peService->getAll();
        if(!ents.has_value()){
            std::cout << "NO ENTS\n";
            return;
        }
        for(const auto& ent : ents.value()){
            std::cout << ent.id << ' ' << ent.program_id << ' ' << ent.enrollee_id  << '\n';
        }
        std::cout << "1 - Create 2 - Update 3 - Delete\n";
        std::cin >> n;
        if(n == 1){
            std::cout << "Enter data:\n";
            std::cout << "Enter program_id:\n";
            u_int16_t achid;
            std::cin >> achid;
                std::cout << "Enter enrollee_id:\n";
            u_int16_t res;
            std::cin >> res;
            this->router.peService->addProgramEnrollee(ProgramEnrollee{0, achid, res});
        }
        if(n == 2){
            std::cout << "Enter id to upd\n";
            int id = 0;
            std::cin >> id;
            std::cout << "Enter program_id:\n";
            u_int16_t enr;
            std::cin >> enr;
             std::cout << "Enter enrollee_id:\n";
            u_int16_t res;
            std::cin >> res;
            this->router.peService->updateProgramEnrollee(ProgramEnrollee{id, enr, res});
        }
        if(n == 3){
            std::cout << "Enter id to delete\n";
            int id = 0;
            std::cin >> id;
            this->router.peService->deleteProgramEnrollee({{"id", std::to_string(id)}});
        }
                AdminPage();

    }
    if(n == 8){
        auto ents = this->router.prgService->getAll();
        if(!ents.has_value()){
            std::cout << "NO ENTS\n";
            return;
        }
        for(const auto& ent : ents.value()){
            std::cout << ent.id << ' ' << ent.name_program << ' '<< ent.department_id << ' ' << ent.plan  << '\n';
        }
        std::cout << "1 - Create 2 - Update 3 - Delete\n";
        std::cin >> n;
        if(n == 1){
            std::cout << "Enter data:\n";
            std::cout << "Enter name_program:\n";
            std::string achid;
            std::cin >> achid;
                     std::cout << "Enter dep_id:\n";
            u_int16_t did;
            std::cin >> did;
                std::cout << "Enter plan:\n";
            u_int16_t res;
            std::cin >> res;
            this->router.prgService->addProgram(Program{0, achid, did,res});
        }
        if(n == 2){
            std::cout << "Enter id to upd\n";
            int id = 0;
            std::cin >> id;
            std::cout << "Enter name_program:\n";
            std::string enr;
            std::cin >> enr;
             std::cout << "Enter dep_id:\n";
            u_int16_t res;
            std::cin >> res;
             std::cout << "Enter plan:\n";
            u_int16_t pl;
            std::cin >> pl;
            this->router.prgService->updateProgram(Program{id, enr, res, pl});
        }
        if(n == 3){
            std::cout << "Enter id to delete\n";
            int id = 0;
            std::cin >> id;
            this->router.prgService->deleteProgram({{"id", std::to_string(id)}});
        }
                AdminPage();

    }
    if(n == 10){
        auto ents = this->router.psubService->getAll();
        if(!ents.has_value()){
            std::cout << "NO ENTS\n";
            return;
        }
        for(const auto& ent : ents.value()){
            std::cout << ent.id << ' ' << ent.program_id << ' '<< ent.subject_id << ' ' << ent.min_result  << '\n';
        }
        std::cout << "1 - Create 2 - Update 3 - Delete\n";
        std::cin >> n;
        if(n == 1){
            std::cout << "Enter data:\n";
            std::cout << "Enter program_id:\n";
            u_int16_t achid;
            std::cin >> achid;
                     std::cout << "Enter subject_id:\n";
            u_int16_t did;
            std::cin >> did;
                std::cout << "Enter min_result:\n";
            u_int16_t res;
            std::cin >> res;
            this->router.psubService->addProgramSubject(ProgramSubject{0, achid, did,res});
        }
        if(n == 2){
            std::cout << "Enter id to upd\n";
            int id = 0;
            std::cin >> id;
            std::cout << "Enter program_id:\n";
            u_int16_t enr;
            std::cin >> enr;
             std::cout << "Enter subject_id:\n";
            u_int16_t res;
            std::cin >> res;
             std::cout << "Enter min_result:\n";
            u_int16_t pl;
            std::cin >> pl;
            this->router.psubService->updateProgramSubject(ProgramSubject{id, enr, res, pl});
        }
        if(n == 3){
            std::cout << "Enter id to delete\n";
            int id = 0;
            std::cin >> id;
            this->router.psubService->deleteProgramSubject({{"id", std::to_string(id)}});
        }
                AdminPage();

    }
     if(n == 11){
        auto ents = this->router.subService->getAll();
        if(!ents.has_value()){
            std::cout << "NO ENTS\n";
            return;
        }
        for(const auto& ent : ents.value()){
            std::cout << ent.id << ' ' << ent.name_subject  << '\n';
        }
        std::cout << "1 - Create 2 - Update 3 - Delete\n";
        std::cin >> n;
        if(n == 1){
            std::cout << "Enter data:\n";
            std::cout << "Enter name_subject:\n";
            std::string achid;
            std::cin >> achid;
            this->router.subService->addSubject(Subject{0, achid});
        }
        if(n == 2){
            std::cout << "Enter id to upd\n";
            int id = 0;
            std::cin >> id;
            std::cout << "Enter name_subject:\n";
            std::string enr;
            std::cin >> enr;
            this->router.subService->updateSubject(Subject{id, enr});
        }
        if(n == 3){
            std::cout << "Enter id to delete\n";
            int id = 0;
            std::cin >> id;
            this->router.subService->deleteSubject({{"id", std::to_string(id)}});
        }
                AdminPage();

    }
     if(n == 12){
        auto ents = this->router.usrService->getAll();
        if(!ents.has_value()){
            std::cout << "NO ENTS\n";
            return;
        }
        for(const auto& ent : ents.value()){
            std::cout << ent.id << ' ' << ent.username << ' ' << ent.email <<' ' << ent.password_hash << ' ' << ent.role  << '\n';
        }
        std::cout << "1 - Create 2 - Update 3 - Delete\n";
        std::cin >> n;
        if(n == 1){
            std::cout << "Enter data:\n";
            std::cout << "Enter username:\n";
            std::string achid;
            std::cin >> achid;
            std::cout << "Enter email:\n";
            std::string email;
            std::cin >> email;
            std::cout << "Enter password_hash:\n";
            std::string password_hash;
            std::cin >> password_hash;
            std::cout << "Enter role:\n";
            u_int16_t role;
            std::cin >> role;
            this->router.usrService->addUser(User{achid, email, password_hash, role});
        }
        if(n == 2){
            std::cout << "Enter id to upd\n";
            int id = 0;
            std::cin >> id;
            std::cout << "Enter username:\n";
            std::string achid;
            std::cin >> achid;
            std::cout << "Enter email:\n";
            std::string email;
            std::cin >> email;
            std::cout << "Enter password_hash:\n";
            std::string password_hash;
            std::cin >> password_hash;
            std::cout << "Enter role:\n";
            u_int16_t role;
            std::cin >> role;
            this->router.usrService->updateUser(User{achid, email, password_hash, role, id});
        }
        if(n == 3){
            std::cout << "Enter username to delete\n";
            std::string name;
            std::cin >> name;
            this->router.usrService->deleteUser(name);
        }
                AdminPage();

    }
    AdminPage();
}


void ConsoleUI::StudentPage() {
    std::cout << std::format("Welcome to the system, {}\n", this->currentUser.username);
    std::cout << "1 - Achievements\n 2 - Penalties \n3 - Subject \n4 - Departments \n5- Programs\n";
    int n = 0;
    std::cin >> n;
    if(n == 1){
        auto ents = this->router.eaService->getAll().value();
        auto ach = this->router.achService->getAll().value();
        for(const auto& ent : ents){
            if(ent.enrollee_id == currentEnrollee.id) {
                for(const auto& a : ach){
                    if(ent.enrollee_id == a.id){
                        std::cout << a.name_achievement << ' ' << a.bonus <<'\n';
                    }
                }
            }
        }
    }
    if(n == 2) {
        auto ents = this->router.epService->getAll().value();
        auto ach = this->router.penService->getAll().value();
        for(const auto& ent : ents){
            if(ent.enrollee_id == currentEnrollee.id) {
                for(const auto& a : ach){
                    if(ent.enrollee_id == a.id){
                        std::cout << a.name_penalty << ' ' << a.penalty_value <<'\n';
                    }
                }
            }
        }
    }
       if(n == 3) {
        auto ents = this->router.esService->getAll().value();
        auto ach = this->router.subService->getAll().value();
        for(const auto& ent : ents){
                if(ent.enrollee_id == currentEnrollee.id) {
                    for(const auto& a : ach){
                        if(ent.subject_id == a.id){
                            std::cout << a.name_subject << ' ' << ent.result <<'\n';
                        }
                    }
                }
        }
    }
    if(n == 4) {
        auto ents = this->router.dpService->getAll().value();
        // auto ach = this->router.subService->getAll().value();
        for(const auto& ent : ents){
            std::cout << ent.name_department << '\n';
        }
    }
    if(n == 5) {
        auto ents = this->router.prgService->getAll().value();
        auto deps = this->router.dpService->getAll().value();
        // auto ach = this->router.subService->getAll().value();
        for(const auto& ent : ents){
            for(const auto& d : deps){
                if(ent.department_id == d.id){
                    std::cout << ent.name_program << ' ' << ent.plan << ' ' << d.name_department << '\n';
                }
            }
        }
    }
    StudentPage();
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
    if(user.role != 2){
        this->currentEnrollee = this->router.enrService->getEnrollee({{"id", std::to_string(user.id)}}).value();
    }
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

