#include "Service.h"
#include <iostream>


Service::Service(std::shared_ptr<IDatabase> db) : db(db) {
    std::cout << "base";
    // this->db->raw_sql("Herllodgasdg");
}


void Service::setDatabase(std::shared_ptr<IDatabase> db) {
    this->db = db;

}