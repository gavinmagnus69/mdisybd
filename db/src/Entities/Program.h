#ifndef PROGRAM_H
#define PROGRAM_H

#include <string>
#include "Entity.h"

struct Program : public id {
    std::string name_program;
    u_int16_t department_id;
    u_int16_t plan;
};


#endif