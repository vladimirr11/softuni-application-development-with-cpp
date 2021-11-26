#ifndef ROOK_H
#define ROOK_H

// C system includes

// C++ system includes
#include <cstdint>

// Third-party includes

// Own includes
#include "includes/game/chess_pieces/types/ChessPiece.h"

// Forward declarations

class Rook : public ChessPiece {
public:
    std::vector<TileData> getMoveTiles(
        const std::array<ChessPiece::PlayerPiecesVec, PLAYERS_COUNT>& activePieces) const final;

private:
    std::vector<MoveDirection> getBoardMoves() const;
};

#endif // !ROOK_H
