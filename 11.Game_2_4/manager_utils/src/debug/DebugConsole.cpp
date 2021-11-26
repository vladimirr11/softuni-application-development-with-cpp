// Corresponding header
#include "manager_utils/debug/DebugConsole.h"

// C system includes

// C++ system includes
#include <iostream>
#include <string>

// Third-party includes

// Own includes
#include "sdl_utils/InputEvent.h"

int32_t DebugConsole::init(int64_t maxFrames, int32_t fontId) {
    _maxFrames = maxFrames;

    Point textPos = Point(0, 40);
    _debugConsoleTexts[FPS_TEXT_IDX].create("0", fontId, Colors::GREEN, textPos);

    textPos.y += 40;
    _debugConsoleTexts[ACTIVE_TIMER_IDX].create("0", fontId, Colors::GREEN, textPos);

    return EXIT_SUCCESS;
}

void DebugConsole::handleEvent([[maybe_unused]]const InputEvent& event) {
    if (event.typeTouchEvent != TouchEvent::KEYBOARD_PRESS) {
        return;
    }

    if (event.key == Keyboard::KEY_A) {
        _isActive = !_isActive;
    }
}

void DebugConsole::update(int64_t elapsedMicroseconds, size_t activeTimers) {
    constexpr int64_t microsecondsInASecond = 1'000'000;
    int64_t currFps = microsecondsInASecond / elapsedMicroseconds;
    if (currFps > _maxFrames) {
        currFps = _maxFrames;
    }

    std::string textContent = "FPS: ";
    textContent.append(std::to_string(currFps));

    _debugConsoleTexts[FPS_TEXT_IDX].setText(textContent);

    textContent = "Active Timers: ";
    textContent.append(std::to_string(activeTimers));

    _debugConsoleTexts[ACTIVE_TIMER_IDX].setText(textContent);
}

void DebugConsole::draw() {
    for (int32_t i = 0; i < DEBUG_TEXTS_COUNTS; i++) {
        _debugConsoleTexts[i].draw();
    }
}   

bool DebugConsole::isActive() const {
    return _isActive;
}
