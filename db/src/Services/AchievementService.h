#ifndef ACHS_H
#define ACHS_H


#include "Service.h"
#include "Entities/Achievement.h"


class AchievementService : public Service {
    std::string tableName = "achievement";
public:
    AchievementService();
    AchievementService(std::shared_ptr<IDatabase>);
public:
    bool addAchievement(const Achievement&) const;
    std::optional<Achievement> getAchievement(const std::map<std::string, std::string>&) const;
    bool updateAchievement(const Achievement&) const;
    bool deleteAchievement(const std::map<std::string, std::string>&) const;
    std::optional<std::vector<Achievement>> getAll();
};



#endif