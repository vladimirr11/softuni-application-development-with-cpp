// Corresponding header
#include "includes/game/entities/Wheel.h"

// C system includes

// C++ system includes
#include <iostream>

// Third-party includes

// Own includes
#include "sdl_utils/InputEvent.h"

Wheel::~Wheel() {
    if (isActiveTimerId(_rotationWheelTimerId)) {
        TimerClient::stopTimer(_rotationWheelTimerId);
    }
}

int32_t Wheel::init(int32_t wheelResourceId, int32_t rotateWheelTimerId, int32_t scaleTimerId) {
    _wheelImage.create(wheelResourceId);

    Point rotCenter(_wheelImage.getWidth(), _wheelImage.getHeight());
    rotCenter.x /= 2;
    rotCenter.y /= 2;
    _wheelImage.setRotationCenter(rotCenter);

    _rotationWheelTimerId = rotateWheelTimerId;
    _scaleTimerId = scaleTimerId;

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
    case Keyboard::KEY_L:
        break;
        
    default:
        break;
    }
}

void Wheel::startAnimation() {
    if (_isAnimationActive) {
        std::cerr << "Wheel animation is already active!" << std::endl;
        return;
    }

    _isAnimationActive = true;

    TimerClient::startTimer(30, _rotationWheelTimerId, TimerType::PULSE);
    TimerClient::startTimer(100, _scaleTimerId, TimerType::PULSE);
}

void Wheel::stopAnimation() {
    if (!_isAnimationActive) {
        std::cerr << "Wheel animation is already stopped!" << std::endl;
        return;
    }

    _isAnimationActive = false;

    TimerClient::stopTimer(_rotationWheelTimerId);
}

void Wheel::processWheelAnimation() {
    _wheelImage.rotateRight(20);
}

void Wheel::processScaleAnimation() {
    _wheelImage.rotateRight(20);
    
    _scaleSteps--;
    if (_scaleSteps == 0) {
        _isShrinked = !_isShrinked;
    }

    if (_isShrinked) {
        _wheelImage.setWidth(_wheelImage.getWidth() - 5);
        _wheelImage.setHeight(_wheelImage.getHeight() - 5);
    } else {
        _wheelImage.setWidth(_wheelImage.getWidth() + 5);
        _wheelImage.setHeight(_wheelImage.getHeight() + 5);
    }
}

void Wheel::onTimeout(int32_t timerId) {
    if (timerId == _rotationWheelTimerId) {
        processWheelAnimation();
    } else if (timerId == _scaleTimerId) {
        processScaleAnimation();
    } else {
        std::cerr << "Received unsupported timerId: " << timerId << std::endl;
    }
}
