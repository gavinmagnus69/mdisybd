#ifndef PENALTY_H
#define PENALTY_H

#include <string>
#include "Entity.h"
struct Penalty : public id
{
    std::string name_penalty;
    u_int16_t penalty_value;
    u_int16_t result;
};

#endif