#ifndef DEBUGCONSOLE_H
#define DEBUGCONSOLE_H

// C system includes

// C++ system includes
#include <cstdint>

// Third-party includes

// Own includes
#include "manager_utils/drawing/Text.h"

// Forward declarations
class InputEvent;

enum DebugTextIds {
    FPS_TEXT_IDX,
    ACTIVE_TIMER_IDX,
    DEBUG_TEXTS_COUNTS
};

class DebugConsole {
public:
    int32_t init(int64_t maxFrames, int32_t fontId);

    void handleEvent(const InputEvent& event);
    void update(int64_t elapsedMicroseconds, size_t activeTimers);
    void draw();
    bool isActive() const;

private:
    Text _debugConsoleTexts[DEBUG_TEXTS_COUNTS];

    int64_t _maxFrames = 0; // used to determine the current FPS
    int32_t _updateCounter = 0; // used for skipping turns

    bool _isActive = false;
};

#endif // !DEBUGCONSOLE_H
