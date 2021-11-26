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

int32_t BoardUtils::getOpponentId(int32_t activePlayerId) {
    if (activePlayerId == WHITE_PLAYER_ID) {
        return BLACK_PLAYER_ID;
    }

    return WHITE_PLAYER_ID;
}

BoardPosition BoardUtils::getAdjacentPos(Direction dir, const BoardPosition& currPos) {
    BoardPosition boardPos = currPos;

    switch (dir) {
    case UP_LEFT:
        boardPos.boardRow--;
        boardPos.boardCol--;
        break;
    case UP:
        boardPos.boardRow--;
        break;
    case UP_RIGHT:
        boardPos.boardRow--;
        boardPos.boardCol++;
        break;
    case RIGHT:
        boardPos.boardCol++;
        break;
    case DOWN_RIGHT:
        boardPos.boardRow++;
        boardPos.boardCol++;
        break;
    case DOWN:
        boardPos.boardRow++;
        break;
    case DOWN_LEFT:
        boardPos.boardRow++;
        boardPos.boardCol--;
        break;
    case LEFT:
        boardPos.boardCol--;
        break;
    
    default:
        std::cerr << "Recieved invalid directory - " << dir << std::endl;
        break;
    }

    return boardPos;
}

bool BoardUtils::doCollideWithPiece(const BoardPosition& selectedPos, 
                                    const ChessPiece::PlayerPiecesVec& pieces,
                                    int32_t& outCollisionRelativeId) {
    
    const int32_t size = static_cast<int32_t>(pieces.size());
    for (int32_t i = 0; i < size; i++) {
        if (selectedPos == pieces[i]->getBoardPos()) {
            outCollisionRelativeId = i;
            return true;
        }
    }

    return false;
}

TileType BoardUtils::getTileType(const BoardPosition& boardPos,
                                 const ChessPiece::PlayerPiecesVec& playerPieces,
                                 const ChessPiece::PlayerPiecesVec& enemyPieces) {
    int32_t collisionIdx = -1;
    if (doCollideWithPiece(boardPos, playerPieces, collisionIdx)) {
        return TileType::GUARD;
    }

    if (doCollideWithPiece(boardPos, enemyPieces, collisionIdx)) {
        return TileType::TAKE;
    }

    return TileType::MOVE;
}
