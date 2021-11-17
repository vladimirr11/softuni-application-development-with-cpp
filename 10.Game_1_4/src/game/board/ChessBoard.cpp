// Corresponding header
#include "includes/game/board/ChessBoard.h"

// C system includes

// C++ system includes
#include <iostream>

// Third-party includes

// Own includes
#include "includes/game/utility/BoardUtils.h"

int32_t ChessBoard::init(int32_t chessBoardImageId, int32_t targetId, int32_t blinkTimerId) {
    _chessBoardImage.create(chessBoardImageId);
    _targetImage.create(targetId);
    _targetImage.hide();

    _blinkTimerId = blinkTimerId;

    return EXIT_SUCCESS;
}

void ChessBoard::draw() {
    _chessBoardImage.draw();
    _targetImage.draw();
}

void ChessBoard::onPieceSelected(const BoardPosition& boardPos) {
    _targetImage.show();
    _targetImage.setPosition(::BoardUtils::getAbsPos(boardPos));

    startTimer(600, _blinkTimerId, TimerType::PULSE);
}

void ChessBoard::onPieceReleased() {
    _targetImage.hide();

    if (isActiveTimerId(_blinkTimerId)) {
        stopTimer(_blinkTimerId);
    }
}

void ChessBoard::onTimeout(int32_t timerId) {
    if (_blinkTimerId == timerId) {
        _targetImage.isVisible() ? _targetImage.hide() : _targetImage.show();
    } else {
        std::cerr << "Received unsupported timerId in ChessBoard::onTimeout()!" << std::endl;
    }
}
