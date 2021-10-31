// Corresponding header
#include "Engine.h"

// C system includes

// C++ system includes
#include <iostream>
#include <array>

// Third-party includes
#include <SDL_surface.h>

// Own includes
#include "sdl_utils/Texture.h"
#include "utils/thread/ThreadUtils.h"
#include "utils/time/Time.h"

int32_t Engine::init() {
    MonitorWindowCfg cfg;

    cfg.windowName = "Input_Events";
    cfg.windowWidth = 640;
    cfg.windowHeight = 480;
    cfg.windowFlags = WINDOW_SHOWN;

    if (_window.init(cfg) != EXIT_SUCCESS) {
        std::cerr << "Minitor::init() failed." << std::endl;
        return EXIT_FAILURE;
    }

    if (loadResources() != EXIT_SUCCESS) {
        std::cerr << "loadResources() failed." << std::endl;
        return EXIT_FAILURE;
    }

    _currChosenImage = _imageSurfaces[ALL_KEYS];

    if (_event.init() != EXIT_SUCCESS) {
        std::cerr << "InputEvent.init() failed." << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
    
void Engine::deinit() {
    for (int32_t i = 0; i < COUNT; i++) {
        Texture::freeSurface(_imageSurfaces[i]);
    }

    _event.deinit();
    _window.deinit();
}
    
void Engine::start() {
    mainLoop();
}

void Engine::mainLoop() {
    Time time;

    while (true) {
        time.getElapsed();

        const bool shouldExit = processFrame();
        if (shouldExit) {
            break;
        }

        limitFPS(time.getElapsed().toMicroseconds());
    }
}

void Engine::drawFrame() {
    _screenSurface = _window.getWindowSurface();
    SDL_BlitSurface(_currChosenImage, nullptr, _screenSurface, nullptr);
    
    _window.updateWindowSurface();
}

bool Engine::processFrame() {
    while (_event.pollEvent()) {
        if (_event.checkForExitRequest()) {
            return true;
        }

        handleEvent();
    }

    drawFrame();

    return false;
}

void Engine::handleEvent() {
    if (_event.typeTouchEvent == TouchEvent::KEYBOARD_RELEASE) {
        _currChosenImage = _imageSurfaces[ALL_KEYS];
        return;
    }

    if (_event.typeTouchEvent != TouchEvent::KEYBOARD_PRESS) {
        return;
    }

    switch (_event.key) {
    case Keyboard::KEY_UP:
        _currChosenImage = _imageSurfaces[UP];
        break;
    case Keyboard::KEY_DOWN:
        _currChosenImage = _imageSurfaces[DOWN];
        break;
    case Keyboard::KEY_LEFT:
        _currChosenImage = _imageSurfaces[LEFT];
        break;
    case Keyboard::KEY_RIGHT:
        _currChosenImage = _imageSurfaces[RIGHT];
        break;

    default:
        break;
    }
}

void Engine::limitFPS(int64_t microsecondsToSleepFor) {
    const int64_t maxFPS = 30;
    const int64_t microsecondsInSecond = 1000000;
    const int64_t microsecondsPerFrame = microsecondsInSecond / maxFPS;
    const int64_t sleepFor = microsecondsPerFrame - microsecondsToSleepFor;

    if (0 > sleepFor) {
        Threading::sleepFor(sleepFor);
    }
}

int32_t Engine::loadResources() {

    const std::array<std::string, COUNT> filePathsArr = {
        "../resources/up.png",
        "../resources/down.png",
        "../resources/left.png",
        "../resources/right.png",
        "../resources/press_keys.png"
    };

    for (int32_t i = 0; i < COUNT; i++) {
        if (EXIT_SUCCESS != Texture::createSurfaceFromFile(filePathsArr[i], _imageSurfaces[i])) {
            std::cerr << "createSurfaceFrom file failed for file: " << filePathsArr[i] << std::endl;
        }
    }

    return EXIT_SUCCESS;
}
