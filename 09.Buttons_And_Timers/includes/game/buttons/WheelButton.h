#ifndef WHEELBUTTONS_H
#define WHEELBUTTONS_H

// C system includes

// C++ system includes
#include <cstdint>
#include <functional>

// Third-party includes

// Own includes
#include "manager_utils/input/ButtonBase.h"

// Forward declarations
struct GameProxy;

class WheelButton : public ButtonBase {
public:
    int32_t init(GameProxy* gameProxy, int32_t buttonId);
    void handleEvent(const InputEvent& event) final;

private:
    GameProxy* _gameProxy = nullptr;
    int32_t _buttonId { 0 };
};

#endif // !WHEELBUTTONS_H
