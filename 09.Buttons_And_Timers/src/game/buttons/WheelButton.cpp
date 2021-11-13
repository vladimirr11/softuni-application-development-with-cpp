// Corresponding header
#include "includes/game/buttons/WheelButton.h"

// C system includes

// C++ system includes
#include <iostream>

// Third-party includes

// Own includes
#include "sdl_utils/InputEvent.h"
#include "includes/game/proxies/GameProxy.h"

int32_t WheelButton::init(GameProxy* gameProxy, int32_t buttonId) {
    if (gameProxy == nullptr) {
        std::cerr << "nullptr provided for GameProxy in WheelButton::init()!" << std::endl;
        return EXIT_FAILURE;
    }

    _gameProxy = gameProxy;
    _buttonId = buttonId;

    return EXIT_SUCCESS;
}

void WheelButton::handleEvent(const InputEvent& event) {
    if (event.typeTouchEvent == TouchEvent::TOUCH_PRESS) {
        setFrame(CLICKED);
    } else if (event.typeTouchEvent == TouchEvent::TOUCH_RELEASE) {
        setFrame(UNCLICKED);
        _gameProxy->onButtonPressed(_buttonId);
    }
}
