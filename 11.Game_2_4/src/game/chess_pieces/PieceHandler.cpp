// Corresponding header
#include "includes/game/chess_pieces/PieceHandler.h"

// C system includes

// C++ system includes
#include <iostream>

// Third-party includes

// Own includes
#include "sdl_utils/InputEvent.h"
#include "includes/game/utility/BoardUtils.h"
#include "includes/game/proxies/GameBoardProxy.h"

int32_t PieceHandler::init(GameBoardProxy* gameBoardProxy, int32_t whitePiecesResourceId, 
                           int32_t blackPiecesResourceId, int32_t unfinishedPieceFontId) {
    if (gameBoardProxy == nullptr) {
        std::cerr << "Error, nullptr provided for gameBoardProxy in PieceHandler::init()!" << std::endl;
        return EXIT_FAILURE;
    }

    if (PieceHandlerPopulator::populatePieceHandler(whitePiecesResourceId, blackPiecesResourceId, 
                                                    unfinishedPieceFontId, _piecesArr) != EXIT_SUCCESS) {
        std::cerr << "PieceHandlerPopulator::populatePieceHandler() failed in PieceHandle::init()!" << std::endl;
        return EXIT_FAILURE;
    }

    _gameBoardProxy = gameBoardProxy;

    return EXIT_SUCCESS;
}

void PieceHandler::draw() {
    for (auto& playerPieces : _piecesArr) {
        for (auto& piece : playerPieces) {
            piece->draw();
        }
    }
}

void PieceHandler::handleEvent(const InputEvent& event) {
    _isPieceSelected ? handleSelectedPieceEvent(event) : handleReleasedPieceEvent(event);
}

void PieceHandler::handleSelectedPieceEvent(const InputEvent& event) {
    if (event.typeTouchEvent != TouchEvent::TOUCH_RELEASE) {
        return;
    }

    if (!BoardUtils::isInsideBoard(event.pointPos)) {
        return;
    }
    
    const BoardPosition boardPos = BoardUtils::getBoardPos(event.pointPos);
    if (!_gameBoardProxy->isMoveAllowed(boardPos)) {
        return;
    }

    _isPieceSelected = false;

    doMovePiece(boardPos);
}

void PieceHandler::handleReleasedPieceEvent(const InputEvent& event) {
    if (event.typeTouchEvent != TouchEvent::TOUCH_RELEASE) {
        return;
    }
    
    int32_t currPlayerId = WHITE_PLAYER_ID;
    for (const auto& playerPieces : _piecesArr) {
        for (size_t i = 0; i < playerPieces.size(); i++) {
            if (playerPieces[i]->containsEvent(event)) {
                _selectedPieceId = i;
                _selectedPiecePlayerId = currPlayerId;

                _isPieceSelected = true;

                const auto moveTile = _piecesArr[_selectedPiecePlayerId][_selectedPieceId]->getMoveTiles(_piecesArr);

                _gameBoardProxy->onPieceSelected(BoardUtils::getBoardPos(event.pointPos), moveTile);

                return;
            }

        }

        currPlayerId++;
    }
}

void PieceHandler::doMovePiece(const BoardPosition& boardPos) {
    _piecesArr[_selectedPiecePlayerId][_selectedPieceId]->setBoardPos(boardPos);
    const auto opponentId = BoardUtils::getOpponentId(_piecesArr[_selectedPiecePlayerId][_selectedPieceId]->getPlayerId());

    int32_t collisionIdx = -1;
    if (BoardUtils::doCollideWithPiece(boardPos, _piecesArr[opponentId], collisionIdx)) {
        _piecesArr[opponentId].erase(_piecesArr[opponentId].begin() + collisionIdx);
    }

    _gameBoardProxy->onPieceReleased();
}
