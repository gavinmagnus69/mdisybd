#ifndef RESPONSE_H
#define RESPONSE_H


#include <string>


struct Response {
    std::string msg = "";
    u_int16_t status = 0;
    u_int16_t role = 0;    
};

//unknown error: 1337
// Success: 0
// Error codes:
// User exists: 228
// No data: 100
#endif 