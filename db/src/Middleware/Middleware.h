#ifndef MIDDLEWARE_H
#define MIDDLEWARE_H


#include "Entities/User.h"


class Middleware {
public:
    bool checkAccess(const User& , u_int16_t access);
};

#endif 