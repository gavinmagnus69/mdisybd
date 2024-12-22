#include "Builder.h"
#include "Config/Config.h"
#include "Database/Database.h"

Application Builder::createApplication(std::filesystem::path& configPath) {
    std::shared_ptr<IConfig> cfg = std::make_shared<Config>(configPath);
    std::shared_ptr<IDatabase> db = std::make_shared<Database>(cfg);
    
}

