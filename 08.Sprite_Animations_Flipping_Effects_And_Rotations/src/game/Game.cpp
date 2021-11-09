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
    if (_hero.init(gameCfg.runnungGirlId) != EXIT_SUCCESS) {
        std::cerr << "_hero.init() failed!" << std::endl;
        return EXIT_FAILURE;
    } 

    if (_wheel.init(gameCfg.wheelId) != EXIT_SUCCESS) {
        std::cerr << "_wheel.init() failed!" << std::endl;
        return EXIT_FAILURE;
    } 

    _mousePosText.create("_", gameCfg.textFontId, Colors::RED);
    _mousePosText.hide();

    return EXIT_SUCCESS;
}

void Game::deinit() {
    _hero.deinit();
}

void Game::draw() {
    _wheel.draw();
    _hero.draw();
    _mousePosText.draw();
}

void Game::handleEvent(const InputEvent& event) {
    _hero.handleEvent(event);
    _wheel.handleEvent(event);
    
    if (event.typeTouchEvent == TouchEvent::KEYBOARD_PRESS) {
        if (event.key == Keyboard::KEY_A) {
            _mousePosText.rotateRight(30);
        }
    }

    setMousePosText(event.pointPos);
}

void Game::setMousePosText(const Point& mousePos) {
    _mousePosText.show();
    _mousePosText.setPosition(mousePos);

    std::string textContent = "X: ";
    textContent.append(std::to_string(mousePos.x))
               .append(", Y: ")
               .append(std::to_string(mousePos.y));

    _mousePosText.setText(textContent);
}
