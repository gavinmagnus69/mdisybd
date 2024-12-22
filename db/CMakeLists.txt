cmake_minimum_required(VERSION 3.20)
project(db)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)


find_package(yaml-cpp CONFIG REQUIRED)
find_package(libpqxx REQUIRED)
find_package(PostgreSQL REQUIRED)
find_package(jwt-cpp CONFIG REQUIRED)




add_library(libs STATIC
 src/Config/Config.cpp
 src/Database/Database.cpp
 src/Application/Application.cpp
 src/Builder/Builder.cpp
 src/Services/AchievementService.cpp
 src/Services/DepartmentService.h
 src/Services/EnrolleeAchievementService.cpp
 src/Services/EnrolleePenaltyService.cpp
 src/Services/EnrolleeService.cpp
 src/Services/EnrolleeSubjectService.cpp
 src/Services/PenaltyService.cpp
 src/Services/ProgramEnrolleeService.cpp
 src/Services/ProgramService.cpp
 src/Services/ProgramSubjectService.cpp
 src/Services/Service.cpp
 src/Services/SubjectService.cpp
 src/Services/TokenService.cpp
 src/Services/UserService.cpp
 src/Controllers/AuthController.cpp
 src/Router/Router.cpp
 src/Middleware/Middleware.cpp
 src/ConsoleInterface/ConsoleUI.cpp
)

target_include_directories(libs PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)

include(FetchContent)

FetchContent_Declare(
    spdlog
    GIT_REPOSITORY https://github.com/gabime/spdlog.git
    GIT_TAG        v1.x
)
    
FetchContent_MakeAvailable(spdlog)

target_link_libraries(libs PUBLIC spdlog yaml-cpp::yaml-cpp pqxx pq PostgreSQL::PostgreSQL jwt-cpp::jwt-cpp) 
add_executable(db src/main.cpp)
target_link_libraries(db PUBLIC libs)