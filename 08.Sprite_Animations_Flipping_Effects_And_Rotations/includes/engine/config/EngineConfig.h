#ifndef ENGINECONFIG_H
#define ENGINECONFIG_H

// C system includes

// C++ system includes
#include <cstdint>

// Third-party includes

// Own includes
#include "includes/game/config/GameConfig.h"
#include "manager_utils/managers/config/ManagerHandlerCfg.h"

// Forward declarations

struct EngineConfig {
    ManagerHandlerCfg managerHandlerCfg;
    GameConfig gameCfg;
};

#endif // !ENGINECONFIG_H
