#ifndef ENROLLEE_H
#define ENROLLEE_H

#include <string>
#include "Entity.h"

struct Enrollee : public id {
    std::string name_enrollee;
    u_int16_t user_id;
};


#endif