#include <iostream>
#include "Builder/Builder.h"
#include "Config/Config.h"
#include "Database/Database.h"
int main(int argc, char** argv) {
    std::filesystem::path path = "/home/roman/Desktop/bsuir/mdisybd/db/config/Prod.yml";
    std::shared_ptr<IConfig> cfg = std::make_shared<Config>(path);
    auto db = std::make_shared<Database>(cfg);
    User user{"test", "sosi@rtea.acsd", "bibuasdas",0};
    UserService us(db);
   auto usr = us.getUser("bob", "hashed_password_4");
   if(usr.has_value()){
    std::cout << usr.value().id << '\n';
   }
    std::cout << us.deleteUser("test");
}