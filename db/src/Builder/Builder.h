#ifndef BUILDER_H
#define BUILDER_H

#include "Application/Application.h"
#include <filesystem>

class Builder {
private:
    std::shared_ptr<IDatabase> db;
public:
    Application createApplication(std::filesystem::path&);
};


#endif