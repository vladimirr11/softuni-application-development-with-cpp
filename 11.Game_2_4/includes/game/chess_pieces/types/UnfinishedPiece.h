#ifndef UNFINISHEDPIECE_H
#define UNFINISHEDPIECE_H

// C system includes

// C++ system includes
#include <cstdint>
#include <vector>

// Third-party includes

// Own includes
#include "includes/game/chess_pieces/types/ChessPiece.h"
#include "manager_utils/drawing/Text.h"

// Forward declarations

class UnfinishedPiece: public ChessPiece {
public:
    int32_t init(const ChessPieceConfig& chessPieceCfg) final;
    void draw() final;
    void setBoardPos(const BoardPosition& boardPos) final;
    std::vector<TileData> getMoveTiles(const std::array<PlayerPiecesVec, PLAYERS_COUNT>& activePieces) const final;

private:
    Text _notReadyText;
};

#endif // !UNFINISHEDPIECE_H
