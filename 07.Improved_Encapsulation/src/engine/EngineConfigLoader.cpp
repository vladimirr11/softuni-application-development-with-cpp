// Corresponding header
#include "includes/engine/EngineConfigLoader.h"

// C system includes

// C++ system includes
#include <string>

// Third-party includes

// Own includes
#include "includes/game/config/GameConfig.h"
#include "includes/common/CommonDefines.h"

#include "manager_utils/managers/config/DrawManagerCfg.h"
#include "manager_utils/managers/config/ResourceManagerCfg.h"
#include "manager_utils/managers/config/ManagerHandlerCfg.h"

namespace {
    constexpr int32_t WINDOW_WIDTH = 800;
    constexpr int32_t WINDOW_HEIGHT = 600;
    constexpr auto WINDOW_NAME = "Scalig and Alpha Blending";

    constexpr int32_t PRESS_KEYS_WIDTH = 640;
    constexpr int32_t PRESS_KEYS_HEIGHT = 480;

    constexpr int32_t LAYER_2_IMG_WIDTH = 150;
    constexpr int32_t LAYER_2_IMG_HEIGHT = 150;

    constexpr int32_t ANGELINE_VINTAGE_40_FONT_SIZE = 40;

    constexpr int32_t MAX_FRAME_RATE = 30;
}

static void populateMonitorConfig(MonitorWindowCfg& monitorWindowCfg) {
    monitorWindowCfg.windowName = WINDOW_NAME;
    monitorWindowCfg.windowWidth = WINDOW_WIDTH;
    monitorWindowCfg.windowHeight = WINDOW_HEIGHT;
    monitorWindowCfg.windowFlags = WINDOW_SHOWN;
}

static void populateImageContainerConfig(ImageContainerConfig& imageContainerCfg) {
    ImageConfig imgCfg;

    imgCfg.location = "../resources/press_keys.png";
    imgCfg.width = PRESS_KEYS_WIDTH;
    imgCfg.height = PRESS_KEYS_HEIGHT;

    imageContainerCfg.imageConfigs.insert(std::make_pair(TextureId::PRESS_KEYS, imgCfg));

    imgCfg.location = "../resources/layer_2.png";
    imgCfg.width = LAYER_2_IMG_WIDTH;
    imgCfg.height = LAYER_2_IMG_HEIGHT;

    imageContainerCfg.imageConfigs.insert(std::make_pair(TextureId::LAYER_2, imgCfg));
}

static void populateTextContainerConfig(TextContainerCfg& textContainerCfg) {
    FontCfg fontCfg;

    fontCfg.location = "../resources/fonts/AngelineVintage.ttf";
    fontCfg.fontSize = ANGELINE_VINTAGE_40_FONT_SIZE;

    textContainerCfg.textConfigs.insert(std::make_pair(FontId::ANGELINE_VINTAGE_40, fontCfg));
}

static void populateDrawManagerConfig(DrawManagerCfg& drawMgrCfg) {
    populateMonitorConfig(drawMgrCfg.windowConfig);
    drawMgrCfg.maxFrameRate = MAX_FRAME_RATE;
}

static void populateResourceManagerConfig(ResourceManagerCfg& resourceMgrCfg) {
    populateImageContainerConfig(resourceMgrCfg.imageContainerCfg);
    populateTextContainerConfig(resourceMgrCfg.textContainerCfg);
}

static void populateManagerHandlerCfg(ManagerHandlerCfg& managerHandlerCfg) {
    populateDrawManagerConfig(managerHandlerCfg.drawManagerCfg);
    populateResourceManagerConfig(managerHandlerCfg.resourceManagerCfg);
}

static void populateGameConfig(GameConfig& gameCfg) {
    gameCfg.layer2ResourceId = TextureId::LAYER_2;
    gameCfg.pressKeysResourceId = TextureId::PRESS_KEYS;
    
    gameCfg.textFontId = FontId::ANGELINE_VINTAGE_40;
}

EngineConfig EngineConfigLoader::loadConfig() {
    EngineConfig engineCfg;

    populateGameConfig(engineCfg.gameCfg);
    populateManagerHandlerCfg(engineCfg.managerHandlerCfg);

    return engineCfg;
}
