#ifndef ROUTER_H
#define ROUTER_H


#include <string>
#include "Controllers/AuthController.h"
#include "Database/IDatabase.h"
#include "Middleware/Middleware.h"
#include "Services/AchievementService.h"
#include "Services/DepartmentService.h"
#include "Services/EnrolleeAchievementService.h"
#include "Services/EnrolleePenaltyService.h"
#include "Services/EnrolleeSubjectService.h"
#include "Services/PenaltyService.h"
#include "Services/ProgramEnrolleeService.h"
#include "Services/ProgramService.h"
#include "Services/ProgramSubjectService.h"
#include "Services/SubjectService.h"
#include "Services/EnrolleeService.h"
#include "Services/UserService.h"


class Router {
public:
    Middleware middleware;
    AuthController auth;
    std::shared_ptr<AchievementService> achService;
    std::shared_ptr<DepartmentService> dpService;    
    std::shared_ptr<EnrolleeAchievementService> eaService;
    std::shared_ptr<EnrolleePenaltyService> epService;
    std::shared_ptr<EnrolleeSubjectService> esService;
    std::shared_ptr<PenaltyService> penService;
    std::shared_ptr<ProgramEnrolleeService> peService;
    std::shared_ptr<ProgramService> prgService;
    std::shared_ptr<ProgramSubjectService> psubService;
    std::shared_ptr<SubjectService> subService;
    std::shared_ptr<EnrolleeService> enrService;
    std::shared_ptr<UserService> usrService;

public:
    Router(std::shared_ptr<IDatabase>);
public:
    std::tuple<Response, User> Login(const User& user, const std::map<std::string, std::string>&);
    Response Register(const User& user, const std::map<std::string, std::string>&);
    // std::string ParseRequest(const std::string& req);
};
#endif