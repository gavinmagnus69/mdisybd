#ifndef ENR_SUB_H
#define ENR_SUB_H

#include "Entity.h"
#include <string>

struct EnrolleeSubject : public id
{
    u_int16_t enrollee_id;
    u_int16_t subject_id;
    u_int16_t result; 
};

#endif