#ifndef ENAS_H
#define ENAS_H


#include "Service.h"
#include "Entities/EnrolleeAchievement.h"


class EnrolleeAchievementService : public Service {
    std::string tableName = "enrollee_achievement";
public:
    EnrolleeAchievementService();
    EnrolleeAchievementService(std::shared_ptr<IDatabase>);
public:
    bool addEnrolleeAchievement(const EnrolleeAchievement&) const;
    std::optional<EnrolleeAchievement> getEnrolleeAchievement(const std::map<std::string, std::string>&) const;
    bool updateEnrolleeAchievement(const EnrolleeAchievement&) const;
    bool deleteEnrolleeAchievement(const std::map<std::string, std::string>&) const;
    std::optional<std::vector<EnrolleeAchievement>> getAll();
};



#endif