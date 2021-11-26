// Corresponding header
#include "includes/game/chess_pieces/types/ChessPiece.h"

// C system includes

// C++ system includes
#include <iostream>

// Third-party includes

// Own includes
#include "includes/game/utility/BoardUtils.h"
#include "sdl_utils/InputEvent.h"

int32_t ChessPiece::init(const ChessPieceConfig& chessPieceCfg) {
    if (chessPieceCfg.pieceType == PieceType::UNKNOWN) {
        std::cerr << "Error, invalid piece type provided: " << static_cast<int32_t>(chessPieceCfg.pieceType) <<
        std::endl;
        return EXIT_FAILURE;
    }

    if (chessPieceCfg.chessPieceResourceId == INVALID_RESOURCE_ID) {
        std::cerr << "Error, invalid chessPieceResourceId provided in ChessPiece::init()!" << std::endl;
        return EXIT_FAILURE; 
    }

    _boardPos = chessPieceCfg.boardPos;
    _playerId = chessPieceCfg.playerId;
    _pieceType = chessPieceCfg.pieceType;

    _pieceImg.create(chessPieceCfg.chessPieceResourceId, BoardUtils::getAbsPos(_boardPos));
    _pieceImg.setFrame(static_cast<int32_t>(_pieceType));

    return EXIT_SUCCESS;
}

void ChessPiece::draw() {
    _pieceImg.draw();
}

bool ChessPiece::containsEvent(const InputEvent& event) const {
    return _pieceImg.containsPoint(event.pointPos);
}

BoardPosition ChessPiece::getBoardPos() const {
    return _boardPos;
}

void ChessPiece::setBoardPos(const BoardPosition& boardPos) {
    _boardPos = boardPos;
    _pieceImg.setPosition(BoardUtils::getAbsPos(_boardPos));
}

int32_t ChessPiece::getPlayerId() const {
    return _playerId;
}
