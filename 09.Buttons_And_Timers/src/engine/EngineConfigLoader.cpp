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
    constexpr auto WINDOW_NAME = "Buttons and Timers";
    constexpr int32_t WINDOW_WIDTH = 1024;
    constexpr int32_t WINDOW_HEIGHT = 800;

    constexpr int32_t RUNNING_GIRL_FRAMES = 6;

    constexpr int32_t RUNNING_GIRL_IMG_WIDTH = 256;
    constexpr int32_t RUNNING_GIRL_IMG_HEIGHT = 220;

    constexpr int32_t START_STOP_BUTTONS_FRAMES = 3;

    constexpr int32_t START_STOP_BUTTONS_WIDTH = 150;
    constexpr int32_t START_STOP_BUTTONS_HEIGHT = 50;

    constexpr int32_t WHEEL_IMG_WIDTH_AND_HEIGHT = 695;

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

    imgCfg.location = "../resources/sprites/running_girl_small.png";
    for (int32_t i = 0; i < RUNNING_GIRL_FRAMES; i++) {
        imgCfg.frames.emplace_back(i * RUNNING_GIRL_IMG_WIDTH, // x
                                   0, // y 
                                   RUNNING_GIRL_IMG_WIDTH, // w
                                   RUNNING_GIRL_IMG_HEIGHT); // h
    }
    imageContainerCfg.imageConfigs.emplace(TextureId::RUNNING_GIRL, imgCfg);
    imgCfg.frames.clear();

    imgCfg.location = "../resources/buttons/button_start.png";
    for (int32_t i = 0; i < START_STOP_BUTTONS_FRAMES; i++) {
        imgCfg.frames.emplace_back(i * START_STOP_BUTTONS_WIDTH, // x
                                   0, // y 
                                   START_STOP_BUTTONS_WIDTH, // w
                                   START_STOP_BUTTONS_HEIGHT); // h
    }
    imageContainerCfg.imageConfigs.emplace(TextureId::START_BUTTON, imgCfg);
    imgCfg.frames.clear();

    imgCfg.location = "../resources/buttons/button_stop.png";
    for (int32_t i = 0; i < START_STOP_BUTTONS_FRAMES; i++) {
        imgCfg.frames.emplace_back(i * START_STOP_BUTTONS_WIDTH, // x
                                   0, // y 
                                   START_STOP_BUTTONS_WIDTH, // w
                                   START_STOP_BUTTONS_HEIGHT); // h
    }
    imageContainerCfg.imageConfigs.emplace(TextureId::STOP_BUTTON, imgCfg);
    imgCfg.frames.clear();

    imgCfg.location = "../resources/wheel.png";
    imgCfg.frames.emplace_back(0, 0, WHEEL_IMG_WIDTH_AND_HEIGHT, WHEEL_IMG_WIDTH_AND_HEIGHT);
    imageContainerCfg.imageConfigs.emplace(TextureId::WHEEL, imgCfg);    
    imgCfg.frames.clear();
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
    gameCfg.runningGirlId = TextureId::ResourceId::RUNNING_GIRL;
    gameCfg.wheelId = TextureId::ResourceId::WHEEL;

    gameCfg.startButtonId = TextureId::ResourceId::START_BUTTON;
    gameCfg.stopButtonId = TextureId::ResourceId::STOP_BUTTON;
    
    gameCfg.textFontId = FontId::FontIdKeys::ANGELINE_VINTAGE_40;

    gameCfg.wheelRotationTimerId = TimerId::Keys::WHEEL_ROTATION_ANIMATION_ID;
    gameCfg.scaleWheelId = TimerId::Keys::SCALE_WHEEL_ID;
    gameCfg.runningGirlTimerId = TimerId::Keys::RUNNING_GIRL_TIMER_ID;
}

EngineConfig EngineConfigLoader::loadConfig() {
    EngineConfig engineCfg;

    populateGameConfig(engineCfg.gameCfg);
    populateManagerHandlerCfg(engineCfg.managerHandlerCfg);

    return engineCfg;
}
