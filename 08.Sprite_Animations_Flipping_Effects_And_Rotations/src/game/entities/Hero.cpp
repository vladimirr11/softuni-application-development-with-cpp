// Corresponding header
#include "includes/game/entities/Hero.h"

// C system includes

// C++ system includes
#include <iostream>

// Third-party includes

// Own includes
#include "sdl_utils/InputEvent.h"

int32_t Hero::init(int32_t resourceId) {
    _heroImg.create(resourceId, Point(0, 0));
    return EXIT_SUCCESS;
}

void Hero::deinit() {

}

void Hero::draw() {
    _heroImg.draw();
}

void Hero::handleEvent(const InputEvent& event) {
    if (event.typeTouchEvent != TouchEvent::KEYBOARD_PRESS) {
        return;
    }

    switch (event.key) {
    case Keyboard::KEY_RIGHT:
        _heroImg.setFlipType(WidgetFlip::NONE);
        _heroImg.setNextFrame();
        _heroImg.moveRight(8);
        break;
    case Keyboard::KEY_LEFT:
        _heroImg.setFlipType(WidgetFlip::HORIZONTAL);
        _heroImg.setPrevFrame();
        _heroImg.moveLeft(8);
        break;
    case Keyboard::KEY_DOWN:
        _heroImg.setNextFrame();
        _heroImg.moveDown(8);
        break;
    case Keyboard::KEY_UP:
        _heroImg.setNextFrame();
        _heroImg.moveUp(8);
        break;
        
    default:
        break;
    }
}
