// Corresponding header
#include "includes/game/Game.h"

// C system includes

// C++ system includes
#include <iostream>

// Third-party includes

// Own includes
#include "sdl_utils/InputEvent.h"
#include "utils/drawing/Color.h"

int32_t Game::init(const GameConfig& gameCfg) {
    if (_hero.init(gameCfg.runningGirlId, gameCfg.runningGirlTimerId) != EXIT_SUCCESS) {
        std::cerr << "_hero.init() failed!" << std::endl;
        return EXIT_FAILURE;
    } 

    if (_wheel.init(gameCfg.wheelId, gameCfg.wheelRotationTimerId, gameCfg.scaleWheelId) != EXIT_SUCCESS) {
        std::cerr << "_wheel.init() failed!" << std::endl;
        return EXIT_FAILURE;
    } 

    const int32_t buttonsIds[WHEEL_BUTTONS_COUNT] = { gameCfg.startButtonId, gameCfg.stopButtonId };
    const Point buttonPos[WHEEL_BUTTONS_COUNT] = { Point(650, 100), Point(830, 100) };

    for (int32_t i = 0; i < WHEEL_BUTTONS_COUNT; i++) {
        if (_wheelButtons[i].init(static_cast<GameProxy*>(this), i) != EXIT_SUCCESS) {
            std::cerr << "_wheelButtons[i].init() failed in Game::init()!" << std::endl;
            return EXIT_FAILURE;
        }

        _wheelButtons[i].create(buttonsIds[i], buttonPos[i]);
    }

    _wheelButtons[WHEEL_STOP_BUTTON_IDX].lockInput();

    return EXIT_SUCCESS;
}

void Game::deinit() {
    _hero.deinit();
}

void Game::draw() {
    _wheel.draw();
    _hero.draw();
    for (int32_t i = 0; i < WHEEL_BUTTONS_COUNT; i++) {
        _wheelButtons[i].draw();
    }
}

void Game::handleEvent(const InputEvent& event) {
    for (int32_t i = 0; i < WHEEL_BUTTONS_COUNT; i++) {
        if (_wheelButtons[i].isInputUnlocked() && _wheelButtons[i].containsEvent(event)) {
            _wheelButtons[i].handleEvent(event);
            return;
        }
    }

    _hero.handleEvent(event);
    _wheel.handleEvent(event);
}

void Game::onButtonPressed(int32_t buttonId) {
    
    switch (buttonId) {
    case WHEEL_START_BUTTON_IDX:
        _wheelButtons[WHEEL_START_BUTTON_IDX].lockInput();
        _wheelButtons[WHEEL_STOP_BUTTON_IDX].unlockInput();
        _wheel.startAnimation();
        _hero.startHeroAnimation();
        break;
    case WHEEL_STOP_BUTTON_IDX:
        _wheelButtons[WHEEL_START_BUTTON_IDX].unlockInput();
        _wheelButtons[WHEEL_STOP_BUTTON_IDX].lockInput();
        _wheel.stopAnimation();
        break;

    default:
        std::cerr << "Recieved unsupported buttonId: " << buttonId << std::endl;
        break;
    }
}
