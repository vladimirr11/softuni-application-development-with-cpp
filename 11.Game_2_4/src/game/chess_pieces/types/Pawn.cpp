// Corresponding header
#include "includes/game/chess_pieces/types/Pawn.h"

// C system includes

// C++ system includes
#include <iostream>

// Third-party includes

// Own includes
#include "includes/game/utility/BoardUtils.h"

std::vector<TileData> Pawn::getMoveTiles(
                            const std::array<ChessPiece::PlayerPiecesVec, PLAYERS_COUNT> &activePieces) const {

    if (WHITE_PLAYER_ID == _playerId) {
        return getWhiteMoveTiles(activePieces);
    }

    return getBlackMoveTiles(activePieces);
}

std::unordered_map<Direction, MoveDirection> Pawn::getWhiteBoardMoves() const {
    constexpr auto allowedDirs = 3; //UP_LEFT, UP, UP_RIGHT
    std::unordered_map<Direction, MoveDirection> boardMoves(allowedDirs);

    BoardPosition futurePos;
    futurePos = BoardUtils::getAdjacentPos(UP_LEFT, _boardPos);
    if (BoardUtils::isInsideBoard(futurePos)) {
        boardMoves[UP_LEFT].emplace_back(futurePos);
    }

    futurePos = BoardUtils::getAdjacentPos(UP_RIGHT, _boardPos);
    if (BoardUtils::isInsideBoard(futurePos)) {
        boardMoves[UP_RIGHT].emplace_back(futurePos);
    }

    futurePos = BoardUtils::getAdjacentPos(UP, _boardPos);
    boardMoves[UP].emplace_back(futurePos);

    //do the double pawn move
    if (WHITE_PLAYER_START_PAWN_ROW == _boardPos.boardRow) {
        futurePos = BoardUtils::getAdjacentPos(UP, futurePos);
        boardMoves[UP].emplace_back(futurePos);
    }

    return boardMoves;
}

std::unordered_map<Direction, MoveDirection> Pawn::getBlackBoardMoves() const {
    constexpr auto allowedDirs = 3; //DOWN_LEFT, DOWN, DOWN_RIGHT
    std::unordered_map<Direction, MoveDirection> boardMoves(allowedDirs);

    BoardPosition futurePos;
    futurePos = BoardUtils::getAdjacentPos(DOWN_LEFT, _boardPos);
    if (BoardUtils::isInsideBoard(futurePos)) {
        boardMoves[DOWN_LEFT].emplace_back(futurePos);
    }

    futurePos = BoardUtils::getAdjacentPos(DOWN_RIGHT, _boardPos);
    if (BoardUtils::isInsideBoard(futurePos)) {
        boardMoves[DOWN_RIGHT].emplace_back(futurePos);
    }

    futurePos = BoardUtils::getAdjacentPos(DOWN, _boardPos);
    boardMoves[DOWN].emplace_back(futurePos);

    //do the double pawn move
    if (BLACK_PLAYER_START_PAWN_ROW == _boardPos.boardRow) {
        futurePos = BoardUtils::getAdjacentPos(DOWN, futurePos);
        boardMoves[DOWN].emplace_back(futurePos);
    }

    return boardMoves;
}

std::vector<TileData> Pawn::getWhiteMoveTiles(
                            const std::array<ChessPiece::PlayerPiecesVec, PLAYERS_COUNT> &activePieces) const {
    
    const std::unordered_map<Direction, MoveDirection> boardMoves = getWhiteBoardMoves();

    std::vector<TileData> moveTiles;
    moveTiles.reserve(boardMoves.size());

    const int32_t opponentId = BoardUtils::getOpponentId(_playerId);

    std::unordered_map<Direction, MoveDirection>::const_iterator it = boardMoves.find(UP);
    if (it != boardMoves.end()) {
        for (const auto& pos : it->second) {
            const auto tileType = BoardUtils::getTileType(pos, activePieces[_playerId], activePieces[opponentId]);
            //if first possible move is TAKE or GUARD - second move will be impossible
            if (TileType::MOVE != tileType) {
                break;
            }

            TileData tileData;
            tileData.boardPos = pos;
            tileData.tileType = tileType;

            moveTiles.push_back(tileData);
        }
    }

    constexpr auto diagonalMovesCnt = 2;
    const std::array<Direction, diagonalMovesCnt> diagonalMoves{
        UP_LEFT, UP_RIGHT};

    for (const Direction move : diagonalMoves) {
        it = boardMoves.find(move);
        if (it != boardMoves.end()) {
            for (const auto &pos : it->second) {
                const auto tileType = BoardUtils::getTileType(pos, activePieces[_playerId], activePieces[opponentId]);
                if (TileType::MOVE != tileType) {
                    TileData tileData;
                    tileData.boardPos = pos;
                    tileData.tileType = tileType;

                    moveTiles.push_back(tileData);
                }
            }
        }
    }

    return moveTiles;
}

std::vector<TileData> Pawn::getBlackMoveTiles(
                            const std::array<ChessPiece::PlayerPiecesVec, PLAYERS_COUNT> &activePieces) const {

    const std::unordered_map<Direction, MoveDirection> boardMoves = getBlackBoardMoves();

    std::vector<TileData> moveTiles;
    moveTiles.reserve(boardMoves.size());

    const int32_t opponentId = BoardUtils::getOpponentId(_playerId);

    std::unordered_map<Direction, MoveDirection>::const_iterator it = boardMoves.find(DOWN);
    if (it != boardMoves.end()) {
        for (const auto& pos : it->second) {
            const auto tileType = BoardUtils::getTileType(pos, activePieces[_playerId], activePieces[opponentId]);
            //if first possible move is TAKE or GUARD - second move will be impossible
            if (TileType::MOVE != tileType) {
                break;
            }

            TileData tileData;
            tileData.boardPos = pos;
            tileData.tileType = tileType;

            moveTiles.push_back(tileData);
        }
    }

    constexpr auto diagonalMovesCnt = 2;
    const std::array<Direction, diagonalMovesCnt> diagonalMoves { DOWN_LEFT, DOWN_RIGHT };

    for (const Direction move : diagonalMoves) {
        it = boardMoves.find(move);
        if (it != boardMoves.end()) {
            for (const auto &pos : it->second) {
                const auto tileType = BoardUtils::getTileType(pos, activePieces[_playerId], activePieces[opponentId]);
                if (TileType::MOVE != tileType) {
                    TileData tileData;
                    tileData.boardPos = pos;
                    tileData.tileType = tileType;

                    moveTiles.push_back(tileData);
                }
            }
        }
    }

    return moveTiles;
}
