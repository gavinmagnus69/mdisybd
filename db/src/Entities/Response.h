#ifndef RESPONSE_H
#define RESPONSE_H


#include <string>


struct Response {
    std::string msg;
    u_int16_t status;    
};


// Success: 0
// Error codes:
// User exists: 228
// No data: 100
#endif 