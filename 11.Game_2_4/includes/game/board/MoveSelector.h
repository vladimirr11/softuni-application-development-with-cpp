#ifndef MOVESELECTOR_H
#define MOVESELECTOR_H

// C system includes

// C++ system includes
#include <cstdint>
#include <array>

// Third-party includes

// Own includes
#include "includes/game/chess_defines/ChessStructs.h"
#include "manager_utils/drawing/Image.h"

// Forward declarations

class MoveSelector {
public:
    int32_t init(int32_t resourceId);
    void draw();
    void markTiles(const std::vector<TileData>& markedTiles);
    void unmarkTiles();

    enum InternalDefines {
        MAX_ACTIVE_TILES = 28
    };

    std::array<Image, MAX_ACTIVE_TILES> _tileImgs;
    size_t _activeTiles { 0 };
};

#endif // !MOVESELECTOR_H
