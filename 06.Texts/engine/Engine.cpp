// Corresponding header
#include "Engine.h"

// C system includes

// C++ system includes
#include <iostream>

// Third-party includes

// Own includes
#include "sdl_utils/Texture.h"
#include "utils/thread/ThreadUtils.h"
#include "utils/time/Time.h"
#include "engine/EngineConfigLoader.h"

#include "sdl_utils/Texture.h"

int32_t gTextWidth = 0;
int32_t gTextHeight = 0;
SDL_Texture* gTextTexture = nullptr;

int32_t Engine::init(const EngineConfig& cfg) {

    if (_window.init(cfg.windowConfig) != EXIT_SUCCESS) {
        std::cerr << "MinitorWindow::init() failed." << std::endl;
        return EXIT_FAILURE;
    }

    if (_renderer.init(_window.getWindow()) != EXIT_SUCCESS) {
        std::cerr << "Renderer::init() failed." << std::endl;
        return EXIT_FAILURE;
    }

    if (_imgContainer.init(cfg.imageContainerCfg) != EXIT_SUCCESS) {
        std::cerr << "ImageContainer::init() failed." << std::endl;
        return EXIT_FAILURE;
    }

    if (_textContainer.init(cfg.textContainerCfg) != EXIT_SUCCESS) {
        std::cerr << "TextContainer::init() failed." << std::endl;
        return EXIT_FAILURE;
    }

    if (_event.init() != EXIT_SUCCESS) {
        std::cerr << "InputEvent::init() failed." << std::endl;
        return EXIT_FAILURE;
    }

    if (_game.init(cfg.gameCfg, &_imgContainer, &_textContainer) != EXIT_SUCCESS) {
        std::cerr << "Game::init() failed." << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
    
void Engine::deinit() {
    _game.deinit();
    _event.deinit();
    _textContainer.deinit();
    _imgContainer.deinit();
    _renderer.deinit();
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
    _renderer.clearScreen();

    std::vector<DrawParams> imagesVec;
    _game.draw(imagesVec);

    SDL_Texture* texture = nullptr;
    for (const DrawParams& image : imagesVec) {
        if (image.widgetType == WidgetType::TEXT) {
            texture = _textContainer.getTextTexture(image.rsrcId);
        } else if (image.widgetType == WidgetType::IMAGE) {
            texture = _imgContainer.getImageTexture(image.rsrcId);
        } else {
            std::cerr << "Error, recieved unsupported WidgetType in Engine::drawFrame(): " << static_cast<int32_t>(image.widgetType) 
                      << " for resourceId - " << image.rsrcId << std::endl; 
            continue;
        }

        _renderer.renderTexture(texture, image);
    }

    _renderer.finishFrame();
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
