#ifndef CHESSBOARD_H
#define CHESSBOARD_H

// C system includes

// C++ system includes
#include <cstdint>

// Third-party includes

// Own includes
#include "manager_utils/drawing/Image.h"
#include "includes/game/proxies/GameBoardProxy.h"
#include "manager_utils/timer/TimerClient.h"

// Forward declarations

class ChessBoard : public GameBoardProxy, public TimerClient {
public:
    int32_t init(int32_t chessBoardImageId, int32_t targetId, int32_t blinkTimerId);
    void draw();

private:
    // GameBoardProxy
    void onPieceSelected(const BoardPosition& boardPos) final;
    void onPieceReleased() final;

    // TimerClient
    void onTimeout(int32_t timerId) final;

    Image _chessBoardImage;
    Image _targetImage;

    int32_t _blinkTimerId {};
};

#endif // !CHESSBOARD_H
