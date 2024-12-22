#ifndef APPLICATION_H
#define APPLICATION_H


#include "Database/IDatabase.h"
#include "Config/IConfig.h"
#include <memory>


class Application {
private:
    std::shared_ptr<IDatabase> db;
public:
    Application(std::shared_ptr<IDatabase>);
public:
    void Run();
};
#endif