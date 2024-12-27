#include "Router.h"
#include "spdlog/spdlog.h"

//INITIALIZE ALL CONTROLLERS TH CONSTRUCTOR 
Router::Router(std::shared_ptr<IDatabase> db)
: auth(AuthController(db))
 {
    // this->auth.setDatabase(db);
}

std::tuple<Response, User> Router::Login(const User& user, const std::map<std::string, std::string>& data) {
    auto access = this->middleware.checkAccess(user, 0);
    if(!access){
        return {Response{"Access denied", 1488}, User()};
    }
    return this->auth.Login(data);
}


Response Router::Register(const User& user, const std::map<std::string, std::string>& data) {
    auto access = this->middleware.checkAccess(user, 0);
    if(!access){
        return Response{"Access denied", 1488};
    }
    // db->raw_sql("SELECT * FROM User");
    return this->auth.Register(data);
}
