// Corresponding header
#include "includes/game/board/ChessBoard.h"

// C system includes

// C++ system includes
#include <iostream>

// Third-party includes

// Own includes
#include "includes/game/utility/BoardUtils.h"

ChessBoard::~ChessBoard() {
    if (isActiveTimerId(_blinkTimerId)) {
        stopTimer(_blinkTimerId);
    }
}

int32_t ChessBoard::init(int32_t chessBoardImageId, int32_t targetId, int32_t moveSelectorResId, int32_t blinkTimerId) {
    _chessBoardImage.create(chessBoardImageId);
    _targetImage.create(targetId);
    _targetImage.hide();

    if (_moveSelector.init(moveSelectorResId) != EXIT_SUCCESS) {
        std::cerr << "MoveSelector::init() failed in ChessBoard::init()!" << std::endl;
        return EXIT_FAILURE;
    }

    _blinkTimerId = blinkTimerId;

    return EXIT_SUCCESS;
}

void ChessBoard::draw() {
    _chessBoardImage.draw();
    _targetImage.draw();
    _moveSelector.draw();
}

void ChessBoard::onPieceSelected(const BoardPosition& boardPos, const std::vector<TileData>& moveTiles) {
    _currMoveTiles = moveTiles;
    _moveSelector.markTiles(_currMoveTiles);

    _targetImage.show();
    _targetImage.setPosition(BoardUtils::getAbsPos(boardPos));

    startTimer(600, _blinkTimerId, TimerType::PULSE);
}

void ChessBoard::onPieceReleased() {
    _moveSelector.unmarkTiles();
    _currMoveTiles.clear();
    _targetImage.hide();

    if (isActiveTimerId(_blinkTimerId)) {
        stopTimer(_blinkTimerId);
    }
}

bool ChessBoard::isMoveAllowed(const BoardPosition& pos) const {
    for (const auto& moveTile : _currMoveTiles) {
        if (moveTile.boardPos == pos) {
            if (moveTile.tileType == TileType::MOVE || moveTile.tileType == TileType::TAKE) {
                return true;
            }
        }
    }

    return false;
}

void ChessBoard::onTimeout(int32_t timerId) {
    if (_blinkTimerId == timerId) {
        _targetImage.isVisible() ? _targetImage.hide() : _targetImage.show();
    } else {
        std::cerr << "Received unsupported timerId in ChessBoard::onTimeout()!" << std::endl;
    }
}
