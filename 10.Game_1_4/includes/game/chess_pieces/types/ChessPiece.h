#ifndef CHESSPIECE_H
#define CHESSPIECE_H

// C system includes

// C++ system includes
#include <cstdint>

// Third-party includes

// Own includes
#include "manager_utils/drawing/Image.h"
#include "includes/game/chess_defines/ChessDefines.h"
#include "includes/game/utility/BoardPos.h"

// Forward declarations
struct InputEvent;

struct ChessPieceConfig {
    BoardPosition boardPos {};
    int32_t playerId {};
    int32_t chessPieceResourceId = INVALID_RESOURCE_ID;
    PieceType pieceType = PieceType::UNKNOWN;
};

class ChessPiece {
public:
    int32_t init(const ChessPieceConfig& chessPieceCfg);
    void draw();
    bool containsEvent(const InputEvent& event) const;

    BoardPosition getBoardPos() const;
    void setBoardPos(const BoardPosition& boardPos);
    int32_t getPlayerId() const;

private:
    Image _pieceImg;
    BoardPosition _boardPos;
    int32_t _playerId;
    PieceType _pieceType;
};

#endif // !CHESSPIECE_H
