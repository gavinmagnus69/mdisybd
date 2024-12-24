#ifndef USER_H
#define USER_H


#include <string>


struct User {
    std::string username{""};
    std::string email{""};
    std::string password_hash{""};
    u_int16_t role = 0;
    int id = 0;
};



#endif