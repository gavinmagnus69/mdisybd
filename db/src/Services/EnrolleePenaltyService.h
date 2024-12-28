#ifndef ENP_H
#define ENP_H


#include "Service.h"
#include "Entities/EnrolleePenalty.h"

class EnrolleePenaltyService : public Service {
    std::string tableName = "enrollee_penalty";
public:
    EnrolleePenaltyService();
    EnrolleePenaltyService(std::shared_ptr<IDatabase>);
public:
    bool addEnrolleePenalty(const EnrolleePenalty&) const;
    std::optional<EnrolleePenalty> getEnrolleePenalty(const std::map<std::string, std::string>&) const;
    bool updateEnrolleePenalty(const EnrolleePenalty&) const;
    bool deleteEnrolleePenalty(const std::map<std::string, std::string>&) const;
    std::optional<std::vector<EnrolleePenalty>> getAll();
};



#endif