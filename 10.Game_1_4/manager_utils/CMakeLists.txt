cmake_minimum_required(VERSION 3.5.1)

project(manager_utils LANGUAGES CXX)

set(_BASE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/includes) 
set(_INC_DIR ${_BASE_DIR}/manager_utils) 
set(_SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src) 

add_library(
    ${PROJECT_NAME} STATIC

        ${_INC_DIR}/drawing/Image.h
        ${_INC_DIR}/drawing/Text.h
        ${_INC_DIR}/drawing/Widget.h

        ${_INC_DIR}/input/ButtonBase.h

        ${_INC_DIR}/managers/config/DrawManagerCfg.h
        ${_INC_DIR}/managers/config/ManagerHandlerCfg.h
        ${_INC_DIR}/managers/config/ResourceManagerCfg.h
        ${_INC_DIR}/managers/DrawManager.h
        ${_INC_DIR}/managers/ManagerBase.h
        ${_INC_DIR}/managers/ManagerHandler.h
        ${_INC_DIR}/managers/ResourceManager.h
        ${_INC_DIR}/managers/TimerManager.h

        ${_INC_DIR}/timer/TimerClient.h
        ${_INC_DIR}/timer/TimerData.h


        ${_SRC_DIR}/drawing/Image.cpp
        ${_SRC_DIR}/drawing/Text.cpp
        ${_SRC_DIR}/drawing/Widget.cpp

        ${_SRC_DIR}/input/ButtonBase.cpp

        ${_SRC_DIR}/managers/DrawManager.cpp
        ${_SRC_DIR}/managers/ManagerHandler.cpp
        ${_SRC_DIR}/managers/ResourceManager.cpp
        ${_SRC_DIR}/managers/TimerManager.cpp
        
        ${_SRC_DIR}/timer/TimerClient.cpp
        ${_SRC_DIR}/timer/TimerData.cpp
)

set_target_cpp_standard(${PROJECT_NAME} 17)
enable_target_warnings(${PROJECT_NAME})

target_include_directories(
    ${PROJECT_NAME}
        PUBLIC 
            ${_BASE_DIR}
)

target_link_libraries(
    ${PROJECT_NAME}
        PUBLIC 
            sdl_utils
)