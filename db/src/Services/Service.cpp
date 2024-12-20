#include "Service.h"


Service::Service(std::shared_ptr<IDatabase> db) : db(db) {}


void Service::setDatabase(std::shared_ptr<IDatabase> db) {
    this->db = db;
}