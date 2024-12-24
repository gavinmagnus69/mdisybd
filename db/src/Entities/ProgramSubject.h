#ifndef PR_SUB_H
#define PR_SUB_H


#include <string>
#include "Entity.h"

struct ProgramSubject : public id
{
    u_int16_t program_id;
    u_int16_t subject_id;
    u_int16_t min_result;
};

#endif