// Corresponding headers
#include "sdl_utils/MonitorWindow.h"

// C system includes

// C++ system includes
#include <cstdlib>
#include <iostream>

// Third-party includes
#include <SDL_video.h>

// Own includes

MonitorWindow::~MonitorWindow() {
    deinit();
}

int32_t MonitorWindow::init(const MonitorWindowConfig& monitorWinCfg) {
    Point finalPosisition;
    if (monitorWinCfg.windowPos == Point::UNDEFINED) {
        finalPosisition.x = SDL_WINDOWPOS_UNDEFINED;
        finalPosisition.y = SDL_WINDOWPOS_UNDEFINED;
    } else {
        finalPosisition = monitorWinCfg.windowPos;
    }

    _window = SDL_CreateWindow(monitorWinCfg.windowName.c_str(), 
                               finalPosisition.x, 
                               finalPosisition.y, 
                               monitorWinCfg.windowWidth, 
                               monitorWinCfg.windowHeight, 
                               monitorWinCfg.windowFlags);
    
    if (_window == nullptr) {
        std::cerr << "SDL_CreateWindow() failed in MonitorWindow::init()! Reason: " << SDL_GetError() << std::endl;
    }

    return EXIT_SUCCESS;
}

void MonitorWindow::deinit() {
    if (_window) {
        SDL_DestroyWindow(_window);
        _window = nullptr;
    }
}

void MonitorWindow::updateWindowSurface() {
    if (SDL_UpdateWindowSurface(_window) != EXIT_SUCCESS) {
        std::cerr << "SDL_UpdateWindowSurface() failed in MonitorWindow::updateWindowSurface()! Reason: " << 
        SDL_GetError() << std::endl;
    }
}

SDL_Window* MonitorWindow::getWindow() {
    return _window;
}
