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

    _mousePosText.create("_", gameCfg.textFontId, Colors::RED);
    _mousePosText.hide();

    return EXIT_SUCCESS;
}

void Game::deinit() {

}

void Game::draw() {
    _mousePosText.draw();
}

void Game::handleEvent(const InputEvent& event) {
    if (event.typeTouchEvent != TouchEvent::TOUCH_RELEASE) {
        return;
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
