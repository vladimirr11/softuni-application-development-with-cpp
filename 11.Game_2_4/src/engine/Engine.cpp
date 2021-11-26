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
        std::cerr << "ManagerHandler::init() failed in Engine::init()" << std::endl;
        return EXIT_FAILURE;
    }

    if (_event.init() != EXIT_SUCCESS) {
        std::cerr << "InputEvent::init() failed!" << std::endl;
        return EXIT_FAILURE;
    }

    if (_game.init(cfg.gameCfg) != EXIT_SUCCESS) {
        std::cerr << "Game::init() failed in Engine::init()!" << std::endl;
        return EXIT_FAILURE;
    }

    if (_debugConsole.init(cfg.managerHandlerCfg.drawManagerCfg.maxFrameRate, cfg.debugConsoleFontId) != EXIT_SUCCESS) {
        std::cerr << "DebugConsole::init() failed in Engine::init()!" << std::endl;
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

        const auto elapsedTime = time.getElapsed().toMicroseconds();
        if (_debugConsole.isActive() && elapsedTime != 0) {
            _debugConsole.update(elapsedTime, gTimerManager->getActiveTimersCount());
        }

        limitFPS(elapsedTime);
    }
}

void Engine::drawFrame() {
    gDrawManager->clearScreen();

    _game.draw();

    if (_debugConsole.isActive()) {
        _debugConsole.draw();
    }

    gDrawManager->finishFrame();
}

bool Engine::processFrame() {
    _managerHandler.process();
    
    while (_event.pollEvent()) {
        if (_event.checkForExit()) {
            return true;
        }

        handleEvent();
    }

    drawFrame();

    return false;
}

void Engine::handleEvent() {
    _game.handleEvent(_event);
    _debugConsole.handleEvent(_event);
}

void Engine::limitFPS(int64_t microsecondsToSleepFor) {
    constexpr int64_t microsecondsInSecond = 1'000'000;
    int64_t microsecondsPerFrame = microsecondsInSecond / gDrawManager->getMaxFrameRate();
    const int64_t sleepFor = microsecondsPerFrame - microsecondsToSleepFor;

    if (sleepFor > 0) {
        Threading::sleepFor(sleepFor);
    }
}
