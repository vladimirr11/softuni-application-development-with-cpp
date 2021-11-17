// Corresponding header
#include "includes/game/utility/BoardUtils.h"

// C system includes

// C++ system includes
#include <iostream>

// Third-party includes

// Own includes
#include "utils/drawing/Rectangle.h"

static constexpr auto BOARD_SIZE = 8;
static constexpr auto FIRST_TILE_X_POS = 58;
static constexpr auto FIRST_TILE_Y_POS = 60;
static constexpr auto TILE_SIZE = 98;

BoardPosition BoardUtils::getBoardPos(const Point& absPos) {
    auto xPos = (absPos.x - FIRST_TILE_X_POS) / TILE_SIZE; 
    auto yPos = (absPos.y - FIRST_TILE_Y_POS) / TILE_SIZE;

    return { yPos, xPos };
}

Point BoardUtils::getAbsPos(const BoardPosition& boardPos) {
    auto xPos = (boardPos.boardRow * TILE_SIZE) + FIRST_TILE_Y_POS;
    auto yPos = (boardPos.boardCol * TILE_SIZE) + FIRST_TILE_X_POS;

    return { yPos, xPos };
}

bool BoardUtils::isInsideBoard(const BoardPosition& boardPos) {
    const Rectangle boardBounds { 0, 0, BOARD_SIZE, BOARD_SIZE };
    const Point pos { boardPos.boardCol, boardPos.boardRow };

    return boardBounds.isPointInsideRect(pos);
}

bool BoardUtils::isInsideBoard(const Point& absPos) {
    const Rectangle boardBounds { FIRST_TILE_X_POS, FIRST_TILE_Y_POS, 
                                  BOARD_SIZE * TILE_SIZE, BOARD_SIZE * TILE_SIZE };
    
    return boardBounds.isPointInsideRect(absPos);
}
