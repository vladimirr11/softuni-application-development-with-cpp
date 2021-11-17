// Corresponding header
#include "includes/engine/EngineConfigLoader.h"

// C system includes

// C++ system includes
#include <string>
#include <array>

// Third-party includes

// Own includes
#include "includes/game/config/GameConfig.h"
#include "includes/common/CommonDefines.h"

#include "manager_utils/managers/config/DrawManagerCfg.h"
#include "manager_utils/managers/config/ResourceManagerCfg.h"
#include "manager_utils/managers/config/ManagerHandlerCfg.h"

namespace {
    constexpr auto WINDOW_NAME = "Chess Board";
    constexpr int32_t WINDOW_WIDTH = 900;
    constexpr int32_t WINDOW_HEIGHT = 900;

    constexpr int32_t CHESS_BOARD_WIDTH = 900;
    constexpr int32_t CHESS_BOARD_HEIGHT = 900;

    constexpr int32_t CHESS_PIECES_FRAMES = 6;

    constexpr int32_t CHESS_PIECES_WIDTH = 96;
    constexpr int32_t CHEES_PIECES_HEIGHT = 96;

    constexpr int32_t TARGET_IMAGE_WIDTH = 98;
    constexpr int32_t TARGET_IMAGE_HEIGHT = 98;

    constexpr int32_t ANGELINE_VINTAGE_FONT_SIZE = 20;

    constexpr int32_t MAX_FRAME_RATE = 30;
}

static void populateMonitorConfig(MonitorWindowConfig& monitorWindowCfg) {
    monitorWindowCfg.windowName = WINDOW_NAME;
    monitorWindowCfg.windowWidth = WINDOW_WIDTH;
    monitorWindowCfg.windowHeight = WINDOW_HEIGHT;
    monitorWindowCfg.windowFlags = WINDOW_SHOWN;
}

static void populateImageContainerConfig(ImageContainerConfig& imageContainerCfg) {
    ImageConfig imgCfg;

    constexpr int32_t chessTypePiecesCount = 2;
    std::array<std::string, chessTypePiecesCount> piecesResourceTypeArr { "../resources/sprites/whitePieces.png", 
                                                                          "../resources/sprites/blackPieces.png" };
                                                                     
    std::array<int32_t, chessTypePiecesCount> chessTypePiecesResIds { TextureId::ResourceId::WHITE_PIECES, 
                                                                      TextureId::ResourceId::BLACK_PIECES };

    for (int32_t i = 0; i < chessTypePiecesCount; i++) {
        imgCfg.location = piecesResourceTypeArr[i];

        for (int32_t j = 0; j < CHESS_PIECES_FRAMES; j++) {
            imgCfg.frames.emplace_back(j * CHESS_PIECES_WIDTH, // x
                                       0, // y 
                                       CHESS_PIECES_WIDTH, // w
                                       CHEES_PIECES_HEIGHT); // h
        }

        imageContainerCfg.imageConfigs.emplace(chessTypePiecesResIds[i], imgCfg);
        imgCfg.frames.clear();
    }

    imgCfg.location = "../resources/sprites/chessBoard.jpg";
    imgCfg.frames.emplace_back(0, 0, CHESS_BOARD_WIDTH, CHESS_BOARD_HEIGHT);
    imageContainerCfg.imageConfigs.emplace(TextureId::ResourceId::CHESS_BOARD, imgCfg);
    imgCfg.frames.clear();

    imgCfg.location = "../resources/sprites/target.png";
    imgCfg.frames.emplace_back(0, 0, TARGET_IMAGE_WIDTH, TARGET_IMAGE_HEIGHT);
    imageContainerCfg.imageConfigs.emplace(TextureId::ResourceId::TARGET, imgCfg);    
    imgCfg.frames.clear();
}

static void populateTextContainerConfig(TextContainerCfg& textContainerCfg) {
    FontCfg fontCfg;

    fontCfg.location = "../resources/fonts/AngelineVintage.ttf";
    fontCfg.fontSize = ANGELINE_VINTAGE_FONT_SIZE;

    textContainerCfg.textConfigs.insert(std::make_pair(FontId::ANGELINE_VINTAGE, fontCfg));
}

static void populateDrawManagerConfig(DrawManagerConfig& drawMgrCfg) {
    populateMonitorConfig(drawMgrCfg.windowConfig);
    drawMgrCfg.maxFrameRate = MAX_FRAME_RATE;
}

static void populateResourceManagerConfig(ResourceManagerConfig& resourceMgrCfg) {
    populateImageContainerConfig(resourceMgrCfg.imageContainerCfg);
    populateTextContainerConfig(resourceMgrCfg.textContainerCfg);
}

static void populateManagerHandlerConfig(ManagerHandlerConfig& managerHandlerCfg) {
    populateDrawManagerConfig(managerHandlerCfg.drawManagerCfg);
    populateResourceManagerConfig(managerHandlerCfg.resourceManagerCfg);
}

static void populateGameConfig(GameConfig& gameCfg) {
    gameCfg.whitePiecesId = TextureId::ResourceId::WHITE_PIECES;
    gameCfg.blackPiecesId = TextureId::ResourceId::BLACK_PIECES;
    gameCfg.chessBoardId = TextureId::ResourceId::CHESS_BOARD;
    gameCfg.targetId = TextureId::ResourceId::TARGET;
    gameCfg.blinkTargetTimerId = TimerId::Keys::BLINK_TARGET_TIMER_ID;
}

EngineConfig EngineConfigLoader::loadConfig() {
    EngineConfig engineCfg;

    populateGameConfig(engineCfg.gameCfg);
    populateManagerHandlerConfig(engineCfg.managerHandlerCfg);

    return engineCfg;
}
