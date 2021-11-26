cmake_minimum_required(VERSION 3.5.1)

project(chess_2_4 LANGUAGES CXX)

include(${CMAKE_CURRENT_SOURCE_DIR}/cmake_helpers/helpers.cmake)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/cmake_helpers/find_modules)

find_package(SDL2 REQUIRED)

if(UNIX)
    set(SDL2_image_name SDL2_image)
    set(SDL2_ttf_name SDL2_ttf)
    set(SDL2_mixer_name SDL2_mixer)
elseif(WIN32 OR APPLE)
    set(SDL2_image_name SDL2_IMAGE)
    set(SDL2_ttf_name SDL2_TTF)
    set(SDL2_mixer_name SDL2_MIXER)
endif()

find_package(${SDL2_image_name} REQUIRED)
find_package(${SDL2_ttf_name} REQUIRED)
find_package(${SDL2_mixer_name} REQUIRED)

set(_BASE_DIR ${CMAKE_CURRENT_SOURCE_DIR}) 
set(_INC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/includes) 
set(_SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src) 

add_executable(
    ${PROJECT_NAME} 

        ${_INC_DIR}/common/CommonDefines.h

        ${_INC_DIR}/engine/config/EngineConfig.h
        ${_INC_DIR}/engine/Engine.h
        ${_INC_DIR}/engine/EngineConfigLoader.h

        ${_INC_DIR}/game/board/ChessBoard.h
        ${_INC_DIR}/game/board/MoveSelector.h
        ${_INC_DIR}/game/chess_defines/ChessDefines.h
        ${_INC_DIR}/game/chess_defines/ChessStructs.h
        ${_INC_DIR}/game/chess_pieces/types/ChessPiece.h
        ${_INC_DIR}/game/chess_pieces/types/UnfinishedPiece.h
        ${_INC_DIR}/game/chess_pieces/types/Pawn.h
        ${_INC_DIR}/game/chess_pieces/types/Rook.h
        ${_INC_DIR}/game/chess_pieces/PieceHandler.h
        ${_INC_DIR}/game/chess_pieces/PieceHandlerPopulator.h
        ${_INC_DIR}/game/config/GameConfig.h
        ${_INC_DIR}/game/proxies/GameBoardProxy.h
        ${_INC_DIR}/game/utility/BoardPos.h
        ${_INC_DIR}/game/utility/BoardUtils.h
        ${_INC_DIR}/game/Game.h

        
        ${_SRC_DIR}/engine/Engine.cpp
        ${_SRC_DIR}/engine/EngineConfigLoader.cpp
        
        ${_SRC_DIR}/game/board/ChessBoard.cpp
        ${_SRC_DIR}/game/board/MoveSelector.cpp
        ${_SRC_DIR}/game/chess_pieces/types/ChessPiece.cpp
        ${_SRC_DIR}/game/chess_pieces/types/UnfinishedPiece.cpp
        ${_SRC_DIR}/game/chess_pieces/types/Pawn.cpp
        ${_SRC_DIR}/game/chess_pieces/types/Rook.cpp
        ${_SRC_DIR}/game/chess_pieces/PieceHandler.cpp
        ${_SRC_DIR}/game/chess_pieces/PieceHandlerPopulator.cpp
        ${_SRC_DIR}/game/utility/BoardUtils.cpp
        ${_SRC_DIR}/game/Game.cpp
        
        ${_SRC_DIR}/main.cpp
)

set_target_cpp_standard(${PROJECT_NAME} 17)
enable_target_warnings(${PROJECT_NAME})

target_include_directories(
    ${PROJECT_NAME}
        PRIVATE 
            ${_BASE_DIR}
)

target_link_libraries(
    ${PROJECT_NAME}
        PRIVATE 
            manager_utils
)

add_subdirectory(utils)
add_subdirectory(sdl_utils)
add_subdirectory(manager_utils)