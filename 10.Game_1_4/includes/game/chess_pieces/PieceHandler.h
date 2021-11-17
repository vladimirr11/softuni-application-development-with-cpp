#ifndef PIECEHANDLER_H
#define PIECEHANDLER_H

// C system includes

// C++ system includes
#include <cstdint>
#include <array>
#include <vector>

// Third-party includes

// Own includes
#include "includes/game/chess_defines/ChessDefines.h"
#include "includes/game/chess_pieces/types/ChessPiece.h"

// Forward declarations
struct GameBoardProxy;

class PieceHandler {
public:
    int32_t init(GameBoardProxy* gameBoardProxy, int32_t whitePiecesResourceId, int32_t blackPiecesResourceId);
    void draw();
    void handleEvent(const InputEvent& event);

private:
    void handleSelectedPieceEvent(const InputEvent& event);
    void handleReleasedPieceEvent(const InputEvent& event);

    int32_t populateWhitePieces(int32_t resourceId);
    int32_t populateBlackPieces(int32_t resourceId);

    using PlayerPiecesVec = std::vector<ChessPiece>;

    std::array<PlayerPiecesVec, PLAYERS_COUNT> _piecesArr;

    int32_t _selectedPieceId = 0;
    int32_t _selectedPiecePlayerId = 0;

    bool _isPieceSelected = false;

    GameBoardProxy* _gameBoardProxy;
};

#endif // !PIECEHANDLER_H
