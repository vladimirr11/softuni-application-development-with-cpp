// Corresponding header
#include "includes/game/chess_pieces/types/UnfinishedPiece.h"

// C system includes

// C++ system includes
#include <iostream>
#include <array>

// Third-party includes

// Own includes
#include "includes/game/utility/BoardUtils.h"

int32_t UnfinishedPiece::init(const ChessPieceConfig& chessPieceCfg) {
    if (ChessPiece::init(chessPieceCfg) != EXIT_SUCCESS) {
        std::cerr << "ChessPiece::init() failed in UnfinishedPiece::init()!" << std::endl;
        return EXIT_FAILURE;
    }

    const auto pieceAbsPos = BoardUtils::getAbsPos(_boardPos);
    _notReadyText.create("!", chessPieceCfg.unfinishedPieceFontId, Colors::RED, pieceAbsPos);

    return EXIT_SUCCESS;
}

void UnfinishedPiece::draw() {
    ChessPiece::draw();
    _notReadyText.draw();
}

void UnfinishedPiece::setBoardPos(const BoardPosition& boardPos) {
    ChessPiece::setBoardPos(boardPos);
    const auto pieceAbsPos = BoardUtils::getAbsPos(_boardPos);
    _notReadyText.setPosition(pieceAbsPos);
}

std::vector<TileData> UnfinishedPiece::getMoveTiles(
            [[maybe_unused]]const std::array<ChessPiece::PlayerPiecesVec, PLAYERS_COUNT>& activePieces) const {
    return std::vector<TileData> {};
}
