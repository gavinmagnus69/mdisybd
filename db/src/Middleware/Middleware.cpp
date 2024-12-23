#include "Middleware.h"


bool Middleware::checkAccess(const User& user, u_int16_t access) {
    if(user.role >= access){
        return true;
    }
    return false;
}
