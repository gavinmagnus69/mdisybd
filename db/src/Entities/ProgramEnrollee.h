#ifndef PR_ENR_H
#define PR_ENR_H


#include <string>
#include "Entity.h"

struct ProgramEnrollee : public id {
    u_int16_t program_id;
    u_int16_t enrollee_id;
};
#endif