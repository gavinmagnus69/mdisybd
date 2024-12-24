#ifndef SERVICE_H
#define SERVICE_H


#include "Database/IDatabase.h"
#include <memory>


class Service {
protected:
    std::shared_ptr<IDatabase> db = nullptr;
public:
    Service(std::shared_ptr<IDatabase>);
    Service() = default;
    ~Service() = default;
public:
    void setDatabase(std::shared_ptr<IDatabase>);
};

#endif