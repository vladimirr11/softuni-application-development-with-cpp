#ifndef ENGINECONFIG_H
#define ENGINECONFIG_H

// C system includes

// C++ system includes
#include <cstdint>

// Third-party includes

// Own includes
#include "sdl_utils/config/MonitorWindowCfg.h"
#include "sdl_utils/config/ImageContainerCfg.h"
#include "game/config/GameConfig.h"

// Forward declarations

struct EngineConfig {
    MonitorWindowCfg windowConfig;
    ImageContainerConfig imageContainerCfg;
    GameConfig gameCfg;
};

#endif // !ENGINECONFIG_H
