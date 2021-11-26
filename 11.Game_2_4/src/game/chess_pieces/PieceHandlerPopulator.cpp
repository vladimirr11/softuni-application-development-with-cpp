// Corresponding header
#include "includes/game/chess_pieces/PieceHandlerPopulator.h"

// C system includes

// C++ system includes
#include <iostream>

// Third-party includes

// Own includes
#include "includes/game/chess_pieces/types/UnfinishedPiece.h"
#include "includes/game/chess_pieces/types/Rook.h"
#include "includes/game/chess_pieces/types/Pawn.h"
#include "includes/game/chess_defines/ChessDefines.h"

static constexpr auto STARTING_PIECES_COUNT = 16;
static constexpr auto PAWNS_COUNT = 8;

static std::unique_ptr<ChessPiece> createPiece(PieceType pieceType) {
    switch (pieceType) {
    case PieceType::ROOK:
        return std::make_unique<Rook>();
    case PieceType::PAWN:
        return std::make_unique<Pawn>();

    case PieceType::KING:
    case PieceType::QUEEN:
    case PieceType::BISHOP:
    case PieceType::KNIGHT:
        return std::make_unique<UnfinishedPiece>();
        break;
    
    default:
        std::cerr << "Error, received unsupported PieceType - " << static_cast<int32_t>(pieceType) 
                  << std::endl;
        break;
    }

    return nullptr;
}

static int32_t populateWhitePieces(int32_t whitePiecesResourceId, int32_t unfinishedPieceFontId, 
                            ChessPiece::PlayerPiecesVec& whitePieces) {
    whitePieces.reserve(STARTING_PIECES_COUNT);

    ChessPieceConfig pieceCfg;
    pieceCfg.boardPos.boardRow = WHITE_PLAYER_START_PAWN_ROW;
    pieceCfg.playerId = WHITE_PLAYER_ID;
    pieceCfg.chessPieceResourceId = whitePiecesResourceId;
    pieceCfg.pieceType = PieceType::PAWN;
    pieceCfg.unfinishedPieceFontId = unfinishedPieceFontId;

    for (auto i = 0; i < PAWNS_COUNT; i++) {
        whitePieces.push_back(createPiece(pieceCfg.pieceType));

        pieceCfg.boardPos.boardCol = i;
        if (whitePieces[i]->init(pieceCfg) != EXIT_SUCCESS) {
            std::cerr << "Error, piece.init() failed in PieceHandler::populateWhitePieces()!" 
                      << std::endl;
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

        whitePieces.push_back(createPiece(pieceCfg.pieceType));

        if (whitePieces[i]->init(pieceCfg) != EXIT_SUCCESS) {
            std::cerr << "Error, piece.init() failed in PieceHandler::populateWhitePieces()!" 
                      << std::endl;
            return EXIT_FAILURE;
        }
    }

    return EXIT_SUCCESS;
}

static int32_t populateBlackPieces(int32_t blackPiecesResourceId, int32_t unfinishedPieceFontId, 
                            ChessPiece::PlayerPiecesVec& blackPieces) {
    blackPieces.reserve(STARTING_PIECES_COUNT);

    ChessPieceConfig pieceCfg;
    pieceCfg.boardPos.boardRow = BLACK_PLAYER_START_PAWN_ROW;
    pieceCfg.playerId = BLACK_PLAYER_ID;
    pieceCfg.chessPieceResourceId = blackPiecesResourceId;
    pieceCfg.pieceType = PieceType::PAWN;
    pieceCfg.unfinishedPieceFontId = unfinishedPieceFontId;

    for (int32_t i = 0; i < PAWNS_COUNT; i++) {
        blackPieces.push_back(createPiece(pieceCfg.pieceType));

        pieceCfg.boardPos.boardCol = i;
        if (blackPieces[i]->init(pieceCfg) != EXIT_SUCCESS) {
            std::cerr << "Error, piece.init() failed in PieceHandler::populateWhitePieces()!" 
                      << std::endl;
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

        blackPieces.push_back(createPiece(pieceCfg.pieceType));
        
        if (blackPieces[i]->init(pieceCfg) != EXIT_SUCCESS) {
            std::cerr << "Error, piece.init() failed in PieceHandler::populateWhitePieces()!" 
                      << std::endl;
            return EXIT_FAILURE;
        }
    }

    return EXIT_SUCCESS;
}

int32_t PieceHandlerPopulator::populatePieceHandler(int32_t whitePiecesResourceId, 
                                                    int32_t blackPiecesResourceId,
                                                    int32_t unfinishedPieceFontId, 
                                                    std::array<ChessPiece::PlayerPiecesVec, PLAYERS_COUNT>& outPiecesArr) {

    ChessPiece::PlayerPiecesVec& whitePieces = outPiecesArr[WHITE_PLAYER_ID];                                                   
    if (populateWhitePieces(whitePiecesResourceId, unfinishedPieceFontId, whitePieces) != EXIT_SUCCESS) {
        std::cerr << "Error, populateWhitePieces() failed in PieceHandlerPopulator::populatePieceHandler()!" 
                  << std::endl;
        return EXIT_FAILURE;
    }

    ChessPiece::PlayerPiecesVec& blackPieces = outPiecesArr[BLACK_PLAYER_ID];                                                   
    if (populateBlackPieces(blackPiecesResourceId, unfinishedPieceFontId, blackPieces) != EXIT_SUCCESS) {
        std::cerr << "Error, populateBlackPieces() failed in PieceHandlerPopulator::populatePieceHandler()!" 
                  << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
