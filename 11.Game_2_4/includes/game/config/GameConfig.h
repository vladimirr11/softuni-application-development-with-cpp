#ifndef GAMECONFIG_H
#define GAMECONFIG_H

// C system includes

// C++ system includes
#include <cstdint>
#include <unordered_map>
#include <string>

// Third-party includes

// Own includes

// Forward declarations

struct GameConfig {
    int32_t whitePiecesId;
    int32_t blackPiecesId;
    int32_t chessBoardId;
    int32_t targetId;
    int32_t moveTilesResourceId;

    int32_t unfinishedPieceFontId;
    int32_t blinkTargetTimerId;
};

#endif // !GAMECONFIG_H
