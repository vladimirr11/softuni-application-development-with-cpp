// Corresponding header
#include "includes/engine/Engine.h"

// C system includes

// C++ system includes
#include <iostream>

// Third-party includes

// Own includes
#include "sdl_utils/Texture.h"

#include "utils/thread/ThreadUtils.h"
#include "utils/time/Time.h"

#include "includes/engine/EngineConfigLoader.h"

#include "manager_utils/managers/DrawManager.h"
#include "manager_utils/managers/TimerManager.h"

int32_t Engine::init(const EngineConfig& cfg) {
    if (_managerHandler.init(cfg.managerHandlerCfg) != EXIT_SUCCESS) {
        std::cerr << "ManagerHandler::init() failed." << std::endl;
        return EXIT_FAILURE;
    }

    if (_event.init() != EXIT_SUCCESS) {
        std::cerr << "InputEvent::init() failed." << std::endl;
        return EXIT_FAILURE;
    }

    if (_game.init(cfg.gameCfg) != EXIT_SUCCESS) {
        std::cerr << "Game::init() failed." << std::endl;
        return EXIT_FAILURE;
    }

    gTimerManager->onInitEnd();

    return EXIT_SUCCESS;
}
    
void Engine::deinit() {
    _game.deinit();
    _event.deinit();
    _managerHandler.deinit();
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
    gDrawMgr->clearScreen();

    _game.draw();

    gDrawMgr->finishFrame();
}

bool Engine::processFrame() {
    _managerHandler.process();
    
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
    _game.handleEvent(_event);
}

void Engine::limitFPS(int64_t microsecondsToSleepFor) {
    constexpr int64_t maxFPS = 30;
    constexpr int64_t microsecondsInSecond = 1000000;
    constexpr int64_t microsecondsPerFrame = microsecondsInSecond / maxFPS;
    const int64_t sleepFor = microsecondsPerFrame - microsecondsToSleepFor;

    if (0 < sleepFor) {
        Threading::sleepFor(sleepFor);
    }
}
