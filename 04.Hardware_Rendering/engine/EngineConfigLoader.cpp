// Corresponding header
#include "EngineConfigLoader.h"

// C system includes

// C++ system includes
#include <string>

// Third-party includes
#include "game/config/GameConfig.h"

// Own includes

namespace {
    constexpr int32_t WINDOW_WIDTH = 640;
    constexpr int32_t WINDOW_HEIGHT = 480;
    constexpr auto WINDOW_NAME = "Hardware Rendering";
}

static void populateMonitorConfig(MonitorWindowCfg& monitorWindowCfg) {
    monitorWindowCfg.windowName = WINDOW_NAME;
    monitorWindowCfg.windowWidth = WINDOW_WIDTH;
    monitorWindowCfg.windowHeight = WINDOW_HEIGHT;
    monitorWindowCfg.windowFlags = WINDOW_SHOWN;
}

static void populateGameConfig(GameConfig& gameCfg) {
    gameCfg.imgLoadPaths[UP] = "../resources/up.png";
    gameCfg.imgLoadPaths[DOWN] = "../resources/down.png";
    gameCfg.imgLoadPaths[LEFT] = "../resources/left.png";
    gameCfg.imgLoadPaths[RIGHT] = "../resources/right.png";
    gameCfg.imgLoadPaths[PRESS_KEYS] = "../resources/press_keys.png";
    gameCfg.imgLoadPaths[LAYER_2] = "../resources/layer_2.png";
}

EngineConfig EngineConfigLoader::loadConfig() {
    EngineConfig engineCfg;

    populateMonitorConfig(engineCfg.windowConfig);
    populateGameConfig(engineCfg.gameCfg);

    return engineCfg;
}
