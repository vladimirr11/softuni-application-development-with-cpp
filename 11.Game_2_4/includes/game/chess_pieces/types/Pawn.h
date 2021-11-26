#ifndef PAWN_H
#define PAWN_H

// C system includes

// C++ system includes
#include <cstdint>
#include <unordered_map>

// Third-party includes

// Own includes
#include "includes/game/chess_pieces/types/ChessPiece.h"

// Forward declarations

class Pawn : public ChessPiece {
public:
    std::vector<TileData> getMoveTiles(
        const std::array<ChessPiece::PlayerPiecesVec, PLAYERS_COUNT>& activePieces) const final;

private:
    std::unordered_map<Direction, MoveDirection> getWhiteBoardMoves() const;
    std::unordered_map<Direction, MoveDirection> getBlackBoardMoves() const;
    
    std::vector<TileData> getWhiteMoveTiles(
        const std::array<ChessPiece::PlayerPiecesVec, PLAYERS_COUNT>& activePieces) const;

    std::vector<TileData> getBlackMoveTiles(
        const std::array<ChessPiece::PlayerPiecesVec, PLAYERS_COUNT>& activePieces) const;
};

#endif // !PAWN_H
