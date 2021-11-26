#ifndef ENGINECONFIG_H
#define ENGINECONFIG_H

// C system includes

// C++ system includes
#include <cstdint>

// Third-party includes

// Own includes
#include "includes/game/config/GameConfig.h"
#include "manager_utils/managers/config/ManagerHandlerCfg.h"
#include "manager_utils/debug/DebugConsole.h"

// Forward declarations

struct EngineConfig {
    ManagerHandlerConfig managerHandlerCfg;
    GameConfig gameCfg;
    int32_t debugConsoleFontId;
};

#endif // !ENGINECONFIG_H
