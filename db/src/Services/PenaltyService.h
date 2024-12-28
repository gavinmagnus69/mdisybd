#ifndef PENALTY_SERVICE_H
#define PENALTY_SERVICE_H


#include "Service.h"
#include "Entities/Penalty.h"


class PenaltyService : public Service {
    std::string tableName = "penalty";
public:
    PenaltyService();
    PenaltyService(std::shared_ptr<IDatabase>);
public:
    bool addPenalty(const Penalty&) const;
    std::optional<Penalty> getPenalty(const std::map<std::string, std::string>&) const;
    bool updatePenalty(const Penalty&) const;
    bool deletePenalty(const std::map<std::string, std::string>&) const;
    std::optional<std::vector<Penalty>> getAll();
};



#endif