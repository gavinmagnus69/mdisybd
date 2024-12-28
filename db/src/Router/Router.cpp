#include "Router.h"
#include "spdlog/spdlog.h"
    // AuthController auth;
    // std::shared_ptr<AchievementService> achService;
    // std::shared_ptr<DepartmentService> dpService;    
    // std::shared_ptr<EnrolleeAchievementService> eaService;
    // std::shared_ptr<EnrolleePenaltyService> epService;
    // std::shared_ptr<EnrolleeSubjectService> esService;
    // std::shared_ptr<PenaltyService> penService;
    // std::shared_ptr<ProgramEnrolleeService> peService;
    // std::shared_ptr<ProgramService> prgService;
    // std::shared_ptr<ProgramSubjectService> psubService;
    // std::shared_ptr<SubjectService> subService;
//INITIALIZE ALL CONTROLLERS TH CONSTRUCTOR 
Router::Router(std::shared_ptr<IDatabase> db)
: auth(AuthController(db))
, achService(std::make_shared<AchievementService>(db))
, dpService(std::make_shared<DepartmentService>(db))
, eaService(std::make_shared<EnrolleeAchievementService>(db))
, epService(std::make_shared<EnrolleePenaltyService>(db))
, esService(std::make_shared<EnrolleeSubjectService>(db))
, penService(std::make_shared<PenaltyService>(db))
, peService(std::make_shared<ProgramEnrolleeService>(db))
, prgService(std::make_shared<ProgramService>(db))
, psubService(std::make_shared<ProgramSubjectService>(db))
, subService(std::make_shared<SubjectService>(db))
, enrService(std::make_shared<EnrolleeService>(db))
, usrService(std::make_shared<UserService>(db))
 {
    // this->auth.setDatabase(db);
}

std::tuple<Response, User> Router::Login(const User& user, const std::map<std::string, std::string>& data) {
    auto access = this->middleware.checkAccess(user, 0);
    if(!access){
        return {Response{"Access denied", 1488}, User()};
    }
    return this->auth.Login(data);
}


Response Router::Register(const User& user, const std::map<std::string, std::string>& data) {
    auto access = this->middleware.checkAccess(user, 0);
    if(!access){
        return Response{"Access denied", 1488};
    }
    // db->raw_sql("SELECT * FROM User");
    return this->auth.Register(data);
}
