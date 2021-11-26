// Corresponding header
#include "includes/game/Game.h"

// C system includes

// C++ system includes
#include <iostream>

// Third-party includes

// Own includes
#include "sdl_utils/InputEvent.h"
#include "includes/game/chess_defines/ChessDefines.h"

int32_t Game::init(const GameConfig& gameCfg) {
    if (_chessBoard.init(gameCfg.chessBoardId, 
                         gameCfg.targetId, 
                         gameCfg.moveTilesResourceId, 
                         gameCfg.blinkTargetTimerId) != EXIT_SUCCESS) {
        std::cerr << "_chessBoard.init() in Game::init() failed!" << std::endl;
        return EXIT_FAILURE;
    }

    if (_pieceHandler.init(static_cast<GameBoardProxy*>(&_chessBoard), 
                           gameCfg.whitePiecesId, gameCfg.blackPiecesId, gameCfg.unfinishedPieceFontId) != EXIT_SUCCESS) {
        std::cerr << "_pieceHandler.init() in Game::init() failed!" << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

void Game::deinit() {

}

void Game::draw() {
    _chessBoard.draw();
    _pieceHandler.draw();
}

void Game::handleEvent(const InputEvent& event) {
    _pieceHandler.handleEvent(event);
}
