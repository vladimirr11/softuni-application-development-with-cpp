// Corresponding header
#include "manager_utils/input/ButtonBase.h"

// C system includes

// C++ system includes
#include <iostream>

// Third-party includes

// Own includes
#include "sdl_utils/InputEvent.h"

void ButtonBase::draw() {
    Image::draw();
}

void ButtonBase::lockInput() {
    _isInputUnlocked = false;
    Image::setFrame(DISABLED);
}

void ButtonBase::unlockInput() {
    _isInputUnlocked = true;
    Image::setFrame(UNCLICKED);
}

bool ButtonBase::isInputUnlocked() const {
    return _isInputUnlocked;
}

bool ButtonBase::containsEvent(const InputEvent& event) {
    return Image::containsPoint(event.pointPos);
}
