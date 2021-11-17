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

static constexpr auto STARTING_PIECES_COUNT = 16;
static constexpr auto PAWNS_COUNT = 8;

static constexpr auto WHITE_PLAYER_START_PAWN_ROW = 6;
static constexpr auto BLACK_PLAYER_START_PAWN_ROW = 1;

int32_t PieceHandler::init(GameBoardProxy* gameBoardProxy, int32_t whitePiecesResourceId, int32_t blackPiecesResourceId) {
    if (gameBoardProxy == nullptr) {
        std::cerr << "Error, nullptr provided for gameBoardProxy in PieceHandler::init()!" << std::endl;
        return EXIT_FAILURE;
    }

    _gameBoardProxy = gameBoardProxy;

    if (populateWhitePieces(whitePiecesResourceId) != EXIT_SUCCESS) {
        std::cerr << "Error, populateWhitePieces() failed in PieceHandler::init()!" << std::endl;
        return EXIT_FAILURE;
    }

    if (populateBlackPieces(blackPiecesResourceId) != EXIT_SUCCESS) {
        std::cerr << "Error, populateBlackPieces() failed in PieceHandler::init()!" << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

void PieceHandler::draw() {
    for (auto& playerPieces : _piecesArr) {
        for (auto& piece : playerPieces) {
            piece.draw();
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

    _isPieceSelected = false;

    const BoardPosition boardPos = BoardUtils::getBoardPos(event.pointPos);
    _piecesArr[_selectedPiecePlayerId][_selectedPieceId].setBoardPos(boardPos);

    _gameBoardProxy->onPieceReleased();
}

void PieceHandler::handleReleasedPieceEvent(const InputEvent& event) {
    if (event.typeTouchEvent != TouchEvent::TOUCH_RELEASE) {
        return;
    }
    
    int32_t currPlayerId = WHITE_PLAYER_ID;
    for (const auto& playerPieces : _piecesArr) {
        for (size_t i = 0; i < playerPieces.size(); i++) {
            if (playerPieces[i].containsEvent(event)) {
                _selectedPieceId = i;
                _selectedPiecePlayerId = currPlayerId;

                _isPieceSelected = true;
                _gameBoardProxy->onPieceSelected(BoardUtils::getBoardPos(event.pointPos));

                return;
            }

        }

        currPlayerId++;
    }
}

int32_t PieceHandler::populateWhitePieces(int32_t resourceId) {
    auto& whitePieces = _piecesArr[WHITE_PLAYER_ID];
    whitePieces.resize(STARTING_PIECES_COUNT);

    ChessPieceConfig pieceCfg;

    pieceCfg.boardPos.boardRow = WHITE_PLAYER_START_PAWN_ROW;
    pieceCfg.playerId = WHITE_PLAYER_ID;
    pieceCfg.chessPieceResourceId = resourceId;
    pieceCfg.pieceType = PieceType::PAWN;

    for (auto i = 0; i < PAWNS_COUNT; i++) {
        pieceCfg.boardPos.boardCol = i;
        if (whitePieces[i].init(pieceCfg) != EXIT_SUCCESS) {
            std::cerr << "Error, piece.init() failed in PieceHandler::populateWhitePieces()!" << std::endl;
            return EXIT_FAILURE;
        }
    }

    constexpr PieceType nonPawnPieces[PAWNS_COUNT] = { 
        PieceType::ROOK, PieceType::KNIGHT, PieceType::BISHOP, PieceType::QUEEN, 
        PieceType::KING, PieceType::BISHOP, PieceType::KNIGHT, PieceType::ROOK 
    };
    
    pieceCfg.boardPos.boardRow = WHITE_PLAYER_START_PAWN_ROW + 1;
    for (auto i = PAWNS_COUNT; i < STARTING_PIECES_COUNT; i++) {
        pieceCfg.boardPos.boardCol = i - PAWNS_COUNT;
        pieceCfg.pieceType = nonPawnPieces[i - PAWNS_COUNT];
        if (whitePieces[i].init(pieceCfg) != EXIT_SUCCESS) {
            std::cerr << "Error, piece.init() failed in PieceHandler::populateWhitePieces()!" << std::endl;
            return EXIT_FAILURE;
        }
    }

    return EXIT_SUCCESS;
}

int32_t PieceHandler::populateBlackPieces(int32_t resourceId) {
    auto& blackPieces = _piecesArr[BLACK_PLAYER_ID];
    blackPieces.resize(STARTING_PIECES_COUNT);

    ChessPieceConfig pieceCfg;

    pieceCfg.boardPos.boardRow = BLACK_PLAYER_START_PAWN_ROW;
    pieceCfg.playerId = BLACK_PLAYER_ID;
    pieceCfg.chessPieceResourceId = resourceId;
    pieceCfg.pieceType = PieceType::PAWN;

    for (int32_t i = 0; i < PAWNS_COUNT; i++) {
        pieceCfg.boardPos.boardCol = i;
        if (blackPieces[i].init(pieceCfg) != EXIT_SUCCESS) {
            std::cerr << "Error, piece.init() failed in PieceHandler::populateWhitePieces()!" << std::endl;
            return EXIT_FAILURE;
        }
    }

    constexpr PieceType nonPawnPieces[PAWNS_COUNT] = { 
        PieceType::ROOK, PieceType::KNIGHT, PieceType::BISHOP, PieceType::QUEEN, 
        PieceType::KING, PieceType::BISHOP, PieceType::KNIGHT, PieceType::ROOK 
    };
    
    pieceCfg.boardPos.boardRow = BLACK_PLAYER_START_PAWN_ROW - 1;
    for (auto i = PAWNS_COUNT; i < STARTING_PIECES_COUNT; i++) {
        pieceCfg.boardPos.boardCol = i - PAWNS_COUNT;
        pieceCfg.pieceType = nonPawnPieces[i - PAWNS_COUNT];
        if (blackPieces[i].init(pieceCfg) != EXIT_SUCCESS) {
            std::cerr << "Error, piece.init() failed in PieceHandler::populateWhitePieces()!" << std::endl;
            return EXIT_FAILURE;
        }
    }

    return EXIT_SUCCESS;
}
