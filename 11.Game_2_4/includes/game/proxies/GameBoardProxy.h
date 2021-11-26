#ifndef GAMEBOARDPROXY_H
#define GAMEBOARDPROXY_H

// C system includes

// C++ system includes
#include <cstdint>
#include <vector>

// Third-party includes

// Own includes
#include "includes/game/utility/BoardPos.h"
#include "includes/game/chess_defines/ChessStructs.h"

// Forward declarations

class GameBoardProxy {
public:
    virtual ~GameBoardProxy() = default;
    
    virtual void onPieceSelected(const BoardPosition& boardPos, const std::vector<TileData>& moveTiles) = 0;
    virtual void onPieceReleased() = 0;
    virtual bool isMoveAllowed(const BoardPosition& pos) const = 0;
};

#endif // !GAMEBOARDPROXY_H
