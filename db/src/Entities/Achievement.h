#ifndef ACHIEVEMENT_H
#define ACHIEVEMENT_H

#include <string>
#include "Entity.h"
struct Achievement : public id {
    std::string name_achievement;
    u_int16_t bonus;
};


#endif