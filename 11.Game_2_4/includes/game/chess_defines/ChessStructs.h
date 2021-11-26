#ifndef CHESSSTRUCTS_H
#define CHESSSTRUCTS_H

// C system includes

// C++ system includes
#include <cstdint>
#include <vector>

// Third-party includes

// Own includes
#include "includes/game/chess_defines/ChessDefines.h"
#include "includes/game/utility/BoardPos.h"

// Forward declarations

struct TileData {
    BoardPosition boardPos;
    TileType tileType = TileType::MOVE;
};

using MoveDirection = std::vector<BoardPosition>;

#endif // !CHESSSTRUCTS_H
