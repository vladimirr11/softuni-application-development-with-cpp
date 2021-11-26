#ifndef CHESSPIECE_H
#define CHESSPIECE_H

// C system includes

// C++ system includes
#include <cstdint>
#include <array>
#include <vector>
#include <memory>

// Third-party includes

// Own includes
#include "manager_utils/drawing/Image.h"
#include "includes/game/chess_defines/ChessDefines.h"
#include "includes/game/utility/BoardPos.h"
#include "includes/game/chess_defines/ChessStructs.h"

// Forward declarations
struct InputEvent;

struct ChessPieceConfig {
    BoardPosition boardPos {};
    int32_t playerId {};
    int32_t chessPieceResourceId = INVALID_RESOURCE_ID;
    PieceType pieceType = PieceType::UNKNOWN;

    int32_t unfinishedPieceFontId {};
};

class ChessPiece {
public:
    virtual ~ChessPiece() = default;

    using PlayerPiecesVec = std::vector<std::unique_ptr<ChessPiece>>;

    virtual int32_t init(const ChessPieceConfig& chessPieceCfg);
    virtual void draw();
    virtual void setBoardPos(const BoardPosition& boardPos);
    virtual std::vector<TileData> getMoveTiles(const std::array<PlayerPiecesVec, PLAYERS_COUNT>& activePieces) const = 0;

    bool containsEvent(const InputEvent& event) const;

    BoardPosition getBoardPos() const;
    int32_t getPlayerId() const;

protected:
    Image _pieceImg;
    BoardPosition _boardPos;
    int32_t _playerId;
    PieceType _pieceType;
};

#endif // !CHESSPIECE_H
