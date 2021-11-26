#ifndef BOARDUTILS_H
#define BOARDUTILS_H

// C system includes

// C++ system includes
#include <cstdint>

// Third-party includes

// Own includes
#include "includes/game/utility/BoardPos.h"
#include "utils/drawing/Point.h"
#include "includes/game/chess_pieces/types/ChessPiece.h"

// Forward declarations

class BoardUtils {
public:
    static BoardPosition getBoardPos(const Point& absPos);

    static Point getAbsPos(const BoardPosition& boardPos);

    static bool isInsideBoard(const BoardPosition& boardPos);
    static bool isInsideBoard(const Point& absPos);

    static int32_t getOpponentId(int32_t activePlayerId);
    static BoardPosition getAdjacentPos(Direction dir, const BoardPosition& currPos);

    static bool doCollideWithPiece(const BoardPosition& selectedPos, 
                                   const ChessPiece::PlayerPiecesVec& pieces,
                                   int32_t& outCollisionRelativeId);

    static TileType getTileType(const BoardPosition& boardPos,
                                const ChessPiece::PlayerPiecesVec& playerPieces,
                                const ChessPiece::PlayerPiecesVec& enemyPieces);
};

#endif // !BOARDUTILS_H
