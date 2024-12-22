#ifndef BUILDER_H
#define BUILDER_H

#include "Application/Application.h"
#include <filesystem>

class Builder {
public:
    Application createApplication(std::filesystem::path&);
};


#endif