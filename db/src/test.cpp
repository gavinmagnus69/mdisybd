#include <iostream>
#include "Builder/Builder.h"
#include "Config/Config.h"
#include "Database/Database.h"
#include "Services/SubjectService.h"


int main(int argc, char** argv) {
    std::filesystem::path path = "/home/roman/Desktop/bsuir/mdisybd/db/config/Prod.yml";
    std::shared_ptr<IConfig> cfg = std::make_shared<Config>(path);
    auto db = std::make_shared<Database>(cfg);
    User user{"test", "sosi@rtea.acsd", "bibuasdas",0};
    SubjectService ss(db);
    // if(!sub.has_value()){
    //     std::cout << "unsuc";
    // }
    if(1){
        ss.addSubject(Subject{ 0, "Proga 228"});
    }
    if(0){
        ss.deleteSubject("Proga 228");
    }
    auto sub = ss.getSubject("Proga 228").value();
    sub.name_subject = "Proga 229";
    if(1){
        ss.updateSubject(sub);
    }

    
}