// Corresponding header
#include "includes/game/chess_pieces/types/Rook.h"

// C system includes

// C++ system includes
#include <iostream>

// Third-party includes

// Own includes
#include "includes/game/utility/BoardUtils.h"

std::vector<MoveDirection> Rook::getBoardMoves() const {
    constexpr auto allowedDirs = 4;
    constexpr std::array<Direction, allowedDirs> rookDirs { UP, RIGHT, DOWN, LEFT };

    constexpr auto maxRookMoves = 7;
    std::vector<MoveDirection> boardMoves(allowedDirs);

    BoardPosition futurePos;
    for (int32_t dirIdx = 0; dirIdx < allowedDirs; dirIdx++) {
        boardMoves[dirIdx].reserve(maxRookMoves);
        futurePos = _boardPos;
        futurePos = BoardUtils::getAdjacentPos(rookDirs[dirIdx], futurePos);
        while (BoardUtils::isInsideBoard(futurePos)) {
            boardMoves[dirIdx].push_back(futurePos);
            futurePos = BoardUtils::getAdjacentPos(rookDirs[dirIdx], futurePos);
        }
    }
    
    return boardMoves;
}

std::vector<TileData> Rook::getMoveTiles(const std::array<ChessPiece::PlayerPiecesVec, PLAYERS_COUNT>& activePieces) const {

    std::vector<TileData> moveTiles;

    const std::vector<MoveDirection> boardMoves = getBoardMoves();
    
    const auto opponentId = BoardUtils::getOpponentId(_playerId);

    for (const auto & moveDir : boardMoves) {
        if (moveDir.empty()) {
            continue;
        }
        
        for (const auto& boardPos : moveDir) {
            const TileType tileType = BoardUtils::getTileType(boardPos, activePieces[_playerId], activePieces[opponentId]);

            TileData tileData;
            tileData.boardPos = boardPos;
            tileData.tileType = tileType;

            moveTiles.push_back(tileData);

            if (tileType != TileType::MOVE) {
                break;
            }
        }
    }

    return moveTiles;
}
