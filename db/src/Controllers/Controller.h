#ifndef CONTROLLER_H
#define CONTROLLER_H


#include <memory>
#include "Database/IDatabase.h"


class Controller {
protected:
    std::shared_ptr<IDatabase> db;
public:
    Controller(std::shared_ptr<IDatabase> db) : db(db) {}
public:
    void setDatabase(std::shared_ptr<IDatabase> db) {
        this->db = db;
    }
};
#endif