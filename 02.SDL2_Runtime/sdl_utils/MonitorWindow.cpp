// Corresponding headers
#include "MonitorWindow.h"

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

int32_t MonitorWindow::init(const MonitorWindowCfg& cfg) {
    Point finalPosisition;
    if (cfg.windowPos == Point::UNDEFINED) {
        finalPosisition.x = SDL_WINDOWPOS_UNDEFINED;
        finalPosisition.y = SDL_WINDOWPOS_UNDEFINED;
    } else {
        finalPosisition = cfg.windowPos;
    }

    _window = SDL_CreateWindow(cfg.windowName.c_str(), 
                cfg.windowPos.x, cfg.windowPos.y, cfg.windowWidth, cfg.windowHeight, cfg.windowFlags);
    
    if (_window == nullptr) {
        std::cerr << "SDL_CreateWindow() failed. Reason: " << SDL_GetError() << std::endl;
    }

    return EXIT_SUCCESS;
}

void MonitorWindow::deinit() {
    if (_window != nullptr) {
        SDL_DestroyWindow(_window);
        _window = nullptr;
    }
}

void MonitorWindow::updateWindowSurface() {
    if (EXIT_SUCCESS != SDL_UpdateWindowSurface(_window)) {
        std::cerr << "SDL_UpdateWindowSurface() failed. Reason: " << SDL_GetError() << std::endl;
    }
}

SDL_Surface* MonitorWindow::getWindowSurface() {
    SDL_Surface* screenSurfice = SDL_GetWindowSurface(_window);

    if (screenSurfice == nullptr) {
        std::cerr << "SDL_GetWindowSurface() failed. Reason: " << SDL_GetError() << std::endl;
        return nullptr;
    }

    return screenSurfice;
}
