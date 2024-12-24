#ifndef ENR_ACH_H
#define ENR_ACH_H


#include <string>
#include "Entity.h"


struct EnrolleeAchievement : public id
{
    u_int16_t enrollee_id;
    u_int16_t achievement_id;
};

#endif