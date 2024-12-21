#ifndef TOKEN_H
#define TOKEN_H


#include <string>


struct Token {
    u_int16_t user_id;
    std::string token;
    u_int16_t exp_days;
};
#endif