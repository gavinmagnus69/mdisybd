#include "Router.h"



Router::Router(std::shared_ptr<IDatabase> db) {
    this->auth.setDatabase(db);
}

Response Router::Login(const User& user, const std::map<std::string, std::string>& data) {
    auto access = this->middleware.checkAccess(user, 0);
    if(!access){
        return Response{"Access denied", 1488};
    }
    return this->auth.Login(data);
}


Response Router::Register(const User& user, const std::map<std::string, std::string>& data) {
    auto access = this->middleware.checkAccess(user, 0);
    if(!access){
        return Response{"Access denied", 1488};
    }
    return this->auth.Register(data);
}
