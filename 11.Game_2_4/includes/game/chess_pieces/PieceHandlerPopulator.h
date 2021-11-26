#ifndef PIECEHANDLERPOPULATOR_H
#define PIECEHANDLERPOPULATOR_H

// C system includes

// C++ system includes
#include <cstdint>

// Third-party includes

// Own includes
#include "includes/game/chess_defines/ChessDefines.h"
#include "includes/game/chess_pieces/types/ChessPiece.h"

// Forward declarations

class PieceHandlerPopulator {
public:
    PieceHandlerPopulator() = delete;

    ~PieceHandlerPopulator() = default;

    static int32_t populatePieceHandler(int32_t whitePiecesResourceId, 
                                        int32_t blackPiecesResourceId, 
                                        int32_t unfinishedPieceFontId, 
                                        std::array<ChessPiece::PlayerPiecesVec, PLAYERS_COUNT>& outPiecesArr);
};

#endif // !PIECEHANDLERPOPULATOR_H
