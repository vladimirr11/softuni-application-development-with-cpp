#ifndef CHESSDEFINES_H
#define CHESSDEFINES_H

// C system includes

// C++ system includes
#include <cstdint>

// Third-party includes

// Own includes

// Forward declarations

enum PlayerId {
    WHITE_PLAYER_ID = 0, BLACK_PLAYER_ID,
    PLAYERS_COUNT
};

enum Direction {
    UP_LEFT,
    UP,
    UP_RIGHT,
    RIGHT,
    DOWN_RIGHT,
    DOWN,
    DOWN_LEFT,
    LEFT,
    DIRECTION_COUNT
};

enum PawnDefines {
    WHITE_PLAYER_START_PAWN_ROW = 6,
    WHITE_PLAYER_END_PAWN_ROW = 0,

    BLACK_PLAYER_START_PAWN_ROW = 1,
    BLACK_PLAYER_END_PAWN_ROW = 7
};

enum class TileType : uint8_t {
    MOVE, GUARD, TAKE
};

enum class PieceType : uint8_t {
    KING, QUEEN, BISHOP, KNIGHT, ROOK, PAWN, UNKNOWN
};

#endif // !CHESSDEFINES_H
