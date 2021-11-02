// Corresponding header
#include "EngineConfigLoader.h"

// C system includes

// C++ system includes
#include <string>

// Third-party includes

// Own includes
#include "game/config/GameConfig.h"
#include "common/CommonDefines.h"

namespace {
    constexpr int32_t WINDOW_WIDTH = 640;
    constexpr int32_t WINDOW_HEIGHT = 480;
    constexpr auto WINDOW_NAME = "Scalig and Alpha Blending";

    constexpr int32_t PRESS_KEYS_WIDTH = 640;
    constexpr int32_t PRESS_KEYS_HEIGHT = 480;

    constexpr int32_t LAYER_2_IMG_WIDTH = 150;
    constexpr int32_t LAYER_2_IMG_HEIGHT = 150;
}

static void populateMonitorConfig(MonitorWindowCfg& monitorWindowCfg) {
    monitorWindowCfg.windowName = WINDOW_NAME;
    monitorWindowCfg.windowWidth = WINDOW_WIDTH;
    monitorWindowCfg.windowHeight = WINDOW_HEIGHT;
    monitorWindowCfg.windowFlags = WINDOW_SHOWN;
}

static void populateGameConfig(GameConfig& gameCfg) {
    gameCfg.layer2ResourceId = TextureId::LAYER_2;
    gameCfg.pressKeysResourceId = TextureId::PRESS_KEYS;
}

static void populateImageContainerConfig(ImageContainerConfig& cfg) {
    ImageConfig imgCfg;

    imgCfg.location = "../resources/press_keys.png";
    imgCfg.width = PRESS_KEYS_WIDTH;
    imgCfg.height = PRESS_KEYS_HEIGHT;
    cfg.imageConfigs.insert(std::make_pair(TextureId::PRESS_KEYS, imgCfg));

    imgCfg.location = "../resources/layer_2.png";
    imgCfg.width = LAYER_2_IMG_WIDTH;
    imgCfg.height = LAYER_2_IMG_HEIGHT;
    cfg.imageConfigs.insert(std::make_pair(TextureId::LAYER_2, imgCfg));
}

EngineConfig EngineConfigLoader::loadConfig() {
    EngineConfig engineCfg;

    populateMonitorConfig(engineCfg.windowConfig);
    populateImageContainerConfig(engineCfg.imageContainerCfg);
    populateGameConfig(engineCfg.gameCfg);

    return engineCfg;
}
