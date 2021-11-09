// Corresponding header
#include "includes/game/entities/Wheel.h"

// C system includes

// C++ system includes
#include <iostream>

// Third-party includes

// Own includes
#include "sdl_utils/InputEvent.h"

int32_t Wheel::init(int32_t wheelResourceId) {
    _wheelImage.create(wheelResourceId);

    return EXIT_SUCCESS;
}

void Wheel::draw() {
    _wheelImage.draw();
}

void Wheel::handleEvent(const InputEvent& event) {
    if (event.typeTouchEvent != TouchEvent::KEYBOARD_PRESS) {
        return;
    }

    switch (event.key) {
    case Keyboard::KEY_P:
        _wheelImage.rotateRight(20);
        break;
    case Keyboard::KEY_O:
        _wheelImage.rotateLeft(20); 
        break;
    case Keyboard::KEY_K:
        _wheelImage.setRotationCenter(Point::ZERO);
        break;
    case Keyboard::KEY_L: {
        Point rotCenter(_wheelImage.getWidth(), _wheelImage.getHeight());
        rotCenter.x /= 2;
        rotCenter.y /= 2;
        _wheelImage.setRotationCenter(rotCenter);
    }
        break;
        
    default:
        break;
    }
}
